/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:35:09 by scaussin          #+#    #+#             */
/*   Updated: 2014/06/24 14:07:28 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>
#include <term.h>

int		ft_prompt_start(char *env)
{
	int		i;
	int		j;

	i = 3;
	j = 0;
	while (env[j] != '\0')
		j++;
	j--;
	while (env[j] && i != 0 && j != -1)
	{
		if (env[j] == '/')
			i--;
		j--;
	}
	j += 2;
	return (j);
}

char	*ft_create_prompt(char *env)
{
	char	*prmt;
	int		j;
	int		l;

	j = ft_prompt_start(env);
	l = 0;
	while (env[j + l] != '\0')
		l++;
	prmt = (char *)malloc(sizeof(char) * (l + 1));
	l = 0;
	while (env[j] != '\0')
	{
		prmt[l] = env[j];
		j++;
		l++;
	}
	prmt[l] = '\0';
	return (prmt);
}

int		tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_fill_termios(struct termios *config)
{
	if (tcgetattr(0, config) == -1)
		return ;
	config->c_lflag &= ~(ICANON);
	config->c_lflag &= ~(ECHO);
	config->c_cc[VMIN] = 1;
	config->c_cc[VTIME] = 0;
}

void	ft_prmpt(void)
{
	char			*cwd;
	char			*pt;
	char			*term;
	struct termios	config;
	struct termios	save;

	cwd = getcwd(NULL, 0);
	pt = ft_create_prompt(cwd);
	if ((term = getenv("TERM")) != NULL)
	{
		if (tgetent(NULL, term) == 1)
		{
			ft_fill_termios(&config);
			if (tcgetattr(0, &save) == 1)
				tcsetattr(0, TCSADRAIN, &config);
		}
		tputs(tgetstr("dl", NULL), 1, tputs_putchar);
		tputs(tgetstr("cr", NULL), 1, tputs_putchar);
		tcsetattr(0, TCSADRAIN, &save);
	}
	ft_printf("\033[36m42sh: \033[0m\033[32m%s\033[0m\033[33m $> \033[0m", pt);
	ft_strdel(&pt);
	ft_strdel(&cwd);
}
