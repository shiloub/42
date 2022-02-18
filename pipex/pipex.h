/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:19:44 by amontant          #+#    #+#             */
/*   Updated: 2022/02/18 20:20:33 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <sys/wait.h>

char	**create_paths(char **env);
char	*find_path(char *cmd, char **env, char ***cmd_params);
void	exec_cmd_1(char **av, char **env, int pipefd[2]);
void	exec_cmd_2(char **av, char **env, int pipefd[2]);
void	free_tab(char **tab);
char	*ft_strjoin_f(char *s1, char const *s2);
void	error(char *str);

#endif