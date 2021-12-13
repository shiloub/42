/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:40:24 by amontant          #+#    #+#             */
/*   Updated: 2021/12/13 13:12:06 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strsize(const char *str, size_t n)
{
	size_t	i;
	int	size;

	size = 0;
	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] >= 0)
			size += str[i];
		else
			size -= str[i];
		i++;
	}
	return (size);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	s1_size;
	int	s2_size;

	s1_size = ft_strsize(s1, n);
	s2_size = ft_strsize(s2, n);
	return (s1_size - s2_size);
}
