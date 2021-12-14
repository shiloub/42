/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:32:34 by amontant          #+#    #+#             */
/*   Updated: 2021/12/14 19:26:10 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	const char		*src_;
	char			*dest_;

	i = 0;
	src_ = src;
	dest_ = (char *)dest;
	while (i < n)
	{
		*dest_ = *src_;
		dest_++;
		src_++;
		i++;
	}
	return (dest);
}
