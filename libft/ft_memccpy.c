/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:31:58 by amontant          #+#    #+#             */
/*   Updated: 2021/11/22 12:32:00 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memccpy(void *dest, const void *src, int c, int n)
{
	int			i;
	const char	*src_;
	char		*dest_;

	i = 0;
	src_ = src;
	dest_ = dest;
	while (i < n)
	{
		dest_[i] = src_[i];
		if (src_[i] == c)
			return (&dest_[i] + 1);
		i++;
	}
	return (0);
}
