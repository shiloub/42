/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiloub <shiloub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:02:28 by shiloub           #+#    #+#             */
/*   Updated: 2023/01/28 09:50:01 by shiloub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
char	*ft_straddchar(char *str, char c)
{
	int		i;
	char	*new_str;
	
	i = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(str) + 2));
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i + 1] = c;
	new_str[i + 2] = 0;
	free(str);
	return (new_str);
}

int	ft_strfind(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	print_tab(char **tab)
{
	int i;
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void    ft_putchar(char c)
{
	write(1, &c, 1);
}
void    ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}