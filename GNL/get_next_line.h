#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1000

char	*ft_strjoin(char const *s1, char const *s2);
int ft_strlen(char *str);
int ft_strchr(char *str, char c);
char	*get_next_line(int fd);
void	save_after_cr(char *str);
char	*save_before_cr(char *str);

#endif
