/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:32:22 by amontant          #+#    #+#             */
/*   Updated: 2021/12/12 15:20:43 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_memsize(const char *s, size_t n)
{
	size_t	i;
	size_t	memsize;

	i = 0;
	memsize = 0;
	while (s[i] && i < n)
	{
		if (s[i] >= 0)
			memsize += s[i];
		else
			memsize -= s[i];
			i++;
	}
	return (memsize);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*s1_;
	const char	*s2_;
	int		s1size;
	int		s2size;

	s1_ = s1;
	s2_ = s2;
	s1size = ft_memsize(s1_, n);
	s2size = ft_memsize(s2_, n);
	return (s1size - s2size);
}
