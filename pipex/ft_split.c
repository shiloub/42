/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiloub <shiloub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:37:20 by amontant          #+#    #+#             */
/*   Updated: 2022/02/24 14:21:50 by shiloub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	go_to_next(char const *str, char quote, int i)
{
	printf("je rentre dans go next avec i = %d et str[i] = %c\n",i,(int)str[i]);
	i++;
	while (str[i])
	{
		if (str[i] == quote)
		{
			//printf("go to next renvoie %d et s[i] = %c\n", i, (int)str[i]);
			return (i);
		}
		i++;
	}
	return (i--);
}

char	*setnewstr(char *s, int start, char c)
{
	char	*str;
	int		i;
	int		strl;

	strl = 0;
	i = 0;
	while (s[strl + start] && s[strl + start] != c)
	{
		if (s[strl + start] == '\"' || s[strl + start] == '\'')
		{
			printf("\n");
			strl = go_to_next(s, s[start + strl], strl + start) - start;
		}
		strl++;
	}
	str = malloc(sizeof(char) * (strl + 1));
	if (!str)
		return (0);
	while (i < strl)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	f_countdel(const char *s, char c)
{
	int	count;
	int	i;
	int	new;

	new = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			if (s[i] == '\'' || s[i] == '\"')
			{
				//printf("je dois aller dans go to next\n");
				i = go_to_next(s, s[i], i);
			}
			new = 1;
			//printf("i = %d est s[i] = %c\n", i, (int)s[i]);
			i++;
		}
		if (new)
			count++;
		new = 0;
		if (s[i])
			i++;
	}
	printf("je cree un tableau de %d cases\n", count);
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (f_countdel((char *)s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		//if (s[i] == '\'' || s[i] == '\"')
		//	i = go_to_next(s, s[i], i);
		if (s[i] != c)
		{
			tab[j] = setnewstr((char *)s, i, c);
			j++;
		}
		while (s[i] != c && s[i])
			i++;
		if (s[i])
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
#include <stdio.h>
int main(int ac, char **av)
{
	char **tab = ft_split(av[1], ' ');	
	int i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return 0;
}
