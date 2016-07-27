/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaussin <scaussin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 16:14:44 by scaussin          #+#    #+#             */
/*   Updated: 2014/06/26 18:19:07 by scaussin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_H
# define FT_42SH_H

# include "struct.h"

/*
**	Common
*/
void	ft_prmpt(void);
void	ft_ctrl(int sig);
void	ft_signal_on(void);
void	ft_signal_off(void);
void	start(char *line, char ***env);

/*
**	Parsing
*/
void	add_opp_logic(char **split, t_line *tree, int *type_logic);
void	debug(t_line *tree);
void	parse_postfix_logic(t_line *tree);
int		count_str(char *line, char *str);
int		parse_logic_opp(char *line, t_line *tree);
int		*type_logic_opp(char *s);
char	**ft_strsplit_spe(char *s);
void	clean_line(char *line);
void	free_tab_2d(char ***tab);
int		ft_strlen_2d(char **tab);
char	**strtrim_2d(char **tab);
int		check_nb_optr(char *cmd);
int		check_operator(char *cmd);
void	free_postfix(t_line *tree);
int		ft_prompt_start(char *env);
int		parse_postfix(t_line *tree);
char	*ft_create_prompt(char *env);
int		ft_nbr_tab(char *s, char *c);
char	*rplc(char *cmd, char ***env);
t_line	*new_link(int type, char *cmd);
int		count_char(char *line, char c);
int		check_valid_operator(char *cmd);
void	add_cmd(t_line *link, char *cmd);
void	rplc_tilde(char **cmd, char ***env);
char	**ft_strsplit_str(char *s, char *c);
int		check_var_in_cmd(char *cmd, char c);
int		parse_pipe(char *line, t_line *tree);
char	*check_var_in_env(char *var, char ***env);
void	rplc_var_env_postfix(t_line *tree, char ***env);
void	add_pipe(t_line *link, char *left, char *right);
void	manage_line(char *line, t_line *tree, char ***env);
int		parse_redirection(t_line *tree, char *key, int type);
char	**ft_create_tab(char **split, char *s, char *c, int m);
void	add_operator(t_line *link, char *left, char *right, int type);

/*
**	Execute
*/
void	ft_strdel2d(char ***str);
char	**ft_get_path(char **env);
int		ft_open_left(t_line *tree);
char	**ft_strcpy_2d(char **str);
int		ft_start_left(t_line *tree);
int		ft_envl(char **env, char *str);
void	ft_dup(int fd[2], int c, int d);
int		ft_single_ret(int newret, int f);
int		ft_file_error(char *file, int r);
void	ft_left(t_line *tree, char ***env);
void	ft_execve(char **cmd, char ***env);
char	*ft_cpy_cnt(char ***env, char *str);
int		ft_start_right(t_line *tree, int n);
void	ft_sh2(t_line *tree, char ***newenv);
void	ft_right(t_line *tree, char ***env, int n);
void	ft_execcmd(char *tcmd, char ***env);
int		ft_open_right(t_line *tree, int n, int flag);
char	*ft_splitjoin(char *s1, char const *s2, char c);
void	ft_pipe(t_line *tree, char ***env, int fd[2]);
void	ft_logic_opp(t_line *tree, char ***env);

/*
**	Builtins
*/
void	ft_errno(void);
void	ft_error(char *str);
void	ft_dash(char ***env);
void	cd_trime(char **tmp2);
void	free_ptr(t_ptr **ptr_f);
void	ft_ptr_fct(t_ptr **ptr_f);
void	ft_envrealloc(char ***env);
char	*get_pwd(char *s1, char *s2);
void	cd_init(char **tmp, int t[3]);
char	*ft_max_strdup(const char *s1);
void	ft_cd(char ***env, char **arg);
void	ft_env(char ***env, char **arg);
void	ft_exit(char ***env, char **arg);
void	ft_echo(char ***env, char **arg);
void	ft_unset(char ***env, char *tmp);
void	ft_write_echo(char **arg, int *i);
int		ft_check_section(char *s, char c);
void	ft_setenv(char ***env, char **arg);
void	ft_get_arg(char ***arg, char *line);
int		ft_builtin(char ***env, char **arg);
void	ft_unsetenv(char ***env, char **arg);
void	pwd_modif(char **tmp2d, char **tmp2);
void	ft_set(char ***env, char **arg, int i);
char	*ft_max_strchr(const char *src, int c);
void	envtmp_ifi(char **env, char ***envtmp);
void	get_env(char **env, char ***cpy, int bool);
void	ft_find_env(char **env, int *i, char *arg);
int		get_var(char ***env, char *var, char **tmp);
void	set_new_arg(char **arg, char **arg2, int i);
int		ft_cd_opt(char ***env, char **arg, int t[3]);
void	envtmp_add_var(char ***env, char **arg, int i);
void	ft_mk_arg(char ***env, char *arg1, char *arg2);
void	cd_prime(char ***env, char *tmp, char *tmp2, int t[3]);
char	*cd_tild(char ***env, char **arg, int t[3], char *tmp);
void	cd_secnd(char ***env, char **arg, int t[3], char **tmp2);

#endif
