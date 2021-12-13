/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:41:27 by amontant          #+#    #+#             */
/*   Updated: 2021/11/22 12:41:29 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int				count;
	char			*str;
	unsigned int	i;

	count = 0;
	i = 0;
	while (i < len && s[i + start])
	{
		i++;
		count ++;
	}
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (0);
	i = 0;
	while (s[start + i] && count > 0)
	{
		str[i] = s[i + start];
		i++;
		count --;
	}
	str[i] = '\0';
	return (str);
}
