/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 09:26:32 by scaussin          #+#    #+#             */
/*   Updated: 2014/06/26 14:59:45 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "libft.h"
#include <stdlib.h>
#include <errno.h>

void	ft_set(char ***env, char **arg, int i)
{
	char	*tmp;

	if ((*env)[i])
	{
		ft_strdel(&(*env)[i]);
		tmp = ft_strjoin(arg[1], "=");
		(*env)[i] = ft_strjoin(tmp, arg[2]);
		ft_strdel(&tmp);
	}
	else
	{
		ft_envrealloc(env);
		tmp = ft_strjoin(arg[1], "=");
		(*env)[i] = ft_strjoin(tmp, arg[2]);
		ft_strdel(&tmp);
	}
}

void	ft_envrealloc(char ***env)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = NULL;
	get_env((*env), &tmp, 0);
	ft_strdel2d(&(*env));
	while (tmp[i])
		i++;
	if (((*env) = (char **)malloc(sizeof(char *) * (i + 2))) == NULL)
		ft_error("Realloc setenv fail");
	i = 0;
	while (tmp[i])
	{
		(*env)[i] = ft_strdup(tmp[i]);
		i++;
	}
	(*env)[i] = NULL;
	(*env)[i + 1] = NULL;
	ft_strdel2d(&tmp);
}

void	ft_errno(void)
{
	if (errno == EACCES)
		ft_putendl_fd("cd: Permission denied", 2);
	if (errno == ELOOP)
		ft_putendl_fd("cd: Loop of symbolic links", 2);
	if (errno == ENAMETOOLONG)
		ft_putendl_fd("cd: Path too long", 2);
	if (errno == ENOENT)
		ft_putendl_fd("cd: Directory does not exist", 2);
	if (errno == ENOTDIR)
		ft_putendl_fd("cd: Component of the path is not a directory", 2);
}

char	*ft_max_strchr(const char *src, int c)
{
	int		i;

	i = 0;
	while (src[i])
	{
		if (src[i] == (char)c)
			return (&((char *)src)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)src)[i]);
	return (NULL);
}

char	*ft_max_strdup(const char *s1)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	while (s1 && s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
