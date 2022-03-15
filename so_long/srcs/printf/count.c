/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:52:26 by amontant          #+#    #+#             */
/*   Updated: 2021/12/23 18:52:31 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_decimal_si(int nb)
{
	int				count;
	unsigned int	n;

	count = 1;
	if (nb < 0)
	{
		count += 1;
		n = -nb;
	}
	else
		n = nb;
	while (n >= 10)
	{
		count += 1;
		n = n / 10;
	}
	return (count);
}

int	ft_count_decimal_ui(unsigned int nb)
{
	int				count;

	count = 1;
	while (nb >= 10)
	{
		count += 1;
		nb = nb / 10;
	}
	return (count);
}

int	ft_count_hexa_ull(unsigned long long nb)
{
	int				count;

	count = 1;
	while (nb >= 16)
	{
		count += 1;
		nb = nb / 16;
	}
	return (count);
}

int	ft_count_hexa_ui(unsigned int nb)
{
	int				count;

	count = 1;
	while (nb >= 16)
	{
		count += 1;
		nb = nb / 16;
	}
	return (count);
}
