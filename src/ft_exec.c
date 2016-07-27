/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:50:16 by scaussin          #+#    #+#             */
/*   Updated: 2014/06/24 17:46:22 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_42sh.h"
#include "libft.h"

int		ft_envl(char **env, char *str)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str) - 1;
	if (len == 0)
	{
		while (env[i] != '\0')
		{
			if (env[i][0] == str[0] && env[i][1] == '=')
				return (i);
			i++;
		}
	}
	else
	{
		while (env[i] != '\0')
		{
			if (ft_strncmp(env[i], str, len) == 0)
				return (i);
			i++;
		}
	}
	return (-1);
}

char	*ft_cpy_cnt(char ***env, char *str)
{
	int		i;
	int		start;
	int		j;
	char	*cpy;

	j = 0;
	i = ft_envl((*env), str);
	if (i == -1)
		return (NULL);
	start = ft_strlen(str);
	cpy = (char *)malloc(sizeof(char) * (ft_strlen((*env)[i]) - start + 1));
	while ((*env)[i][start])
	{
		cpy[j] = (*env)[i][start];
		j++;
		start++;
	}
	cpy[j] = '\0';
	return (cpy);
}

char	*ft_splitjoin(char *s1, char const *s2, char c)
{
	size_t	len;
	size_t	size;
	char	*str;
	size_t	j;

	j = 0;
	len = (s1 != NULL) ? ft_strlen((char *)s1) : 0;
	size = ft_strlen((char *)s2);
	str = (char *)malloc(sizeof(char) * (size + len + 3));
	if (str == NULL)
		return (NULL);
	str = ft_strcpy(str, s1);
	while (str[j] != '\0')
		j++;
	str[j] = c;
	j = 0;
	while (j <= (size + 1))
	{
		str[(len + 1) + j] = *s2;
		j++;
		s2++;
	}
	if (s1)
		free(s1);
	return (str);
}

char	**ft_get_path(char **env)
{
	char	**path;
	char	*cpath;

	if (ft_envl(env, "PATH=") != -1)
	{
		cpath = ft_cpy_cnt(&env, "PATH=");
		path = ft_strsplit(cpath, ':');
		ft_strdel(&cpath);
		return (path);
	}
	else
		return (NULL);
}

void	ft_execve(char **cmd, char ***env)
{
	char	*exec;
	char	**path;
	int		i;

	i = 0;
	path = NULL;
	execve(cmd[0], cmd, (*env));
	path = ft_get_path(*env);
	if (path)
	{
		while (path[i])
		{
			exec = ft_splitjoin(path[i], cmd[0], '/');
			execve(exec, cmd, (*env));
			i++;
		}
	}
	ft_putstr_fd("42sh: command not found: ", 2);
	ft_putendl_fd(cmd[0], 2);
	exit(-1);
}
