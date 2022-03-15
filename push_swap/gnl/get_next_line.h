/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiloub <shiloub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:06:50 by amontant          #+#    #+#             */
/*   Updated: 2022/01/26 23:10:11 by shiloub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# define BUFFER_SIZE 1

char	*ft_strjoin_f(char *s1, const char *s2);
char	*ft_strdup_gnl(const char *s);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
int		ft_strlen_gnl(char *str);
int		ft_strchr_gnl(char *str, char c);
char	*get_next_line(int fd);
void	save_after_cr(char *str);
char	*save_before_cr(char *str);

#endif
