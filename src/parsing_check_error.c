/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:30:58 by scaussin          #+#    #+#             */
/*   Updated: 2014/03/27 16:39:20 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_nb_optr(char *cmd)
{
	int		i;
	int		nb_cmd;
	int		nb_optr;
	char	c;

	nb_cmd = 0;
	nb_optr = 0;
	i = 0;
	while (cmd[i])
	{
		c = cmd[i];
		if (cmd[i] != '<' && cmd[i] != '>')
		{
			nb_cmd++;
			while (cmd[i] != '<' && cmd[i] != '>' && cmd[i])
				i++;
		}
		else
		{
			while (cmd[i] == c && (c == '>' || c == '<'))
				i++;
			nb_optr++;
		}
	}
	return (nb_cmd - nb_optr);
}

int		check_valid_operator(char *cmd)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '<' || cmd[i] == '>')
		{
			c = cmd[i];
			j = 0;
			while (cmd[i] && cmd[i] == c)
			{
				i++;
				j++;
			}
			if (j > 2)
				return (0);
		}
		i++;
	}
	return (1);
}

int		check_operator(char *cmd)
{
	if (check_nb_optr(cmd) != 1 || !check_valid_operator(cmd))
		return (0);
	return (1);
}
