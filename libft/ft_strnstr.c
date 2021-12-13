/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:40:38 by amontant          #+#    #+#             */
/*   Updated: 2021/12/12 15:34:33 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		where;
	char		*p;

	p = (char *)s1;
	i = 0;
	if (s2[0] == '\0')
		return (&p[0]);
	while (s1[i] && i < size)
	{
		j = 0;
		if (s1[i] == s2[j])
			where = i;
		while (s1[i] == s2[j])
		{
			i++;
			j++;
		}
		if (s2[j] == '\0' && i < size)
			return (&p[where]);
		i++;
	}
	return (0);
}
