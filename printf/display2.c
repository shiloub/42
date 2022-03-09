/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:31:23 by shiloub           #+#    #+#             */
/*   Updated: 2021/12/23 18:53:07 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_si(int nb)
{
	unsigned int	n;

	if (nb < 0)
	{
		n = -nb;
		ft_putchar('-');
	}
	else
		n = nb;
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr_si(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

void	ft_putnbr_ui(unsigned int nb)
{
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr_ui(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}

void	ft_putnbr_hexa_ull(unsigned long long nb)
{
	if (nb < 16)
	{
		if (nb < 10)
			ft_putchar(nb + '0');
		else
			ft_putchar((nb % 10) + 'a');
	}
	else
	{
		ft_putnbr_hexa_ull(nb / 16);
		ft_putnbr_hexa_ull(nb % 16);
	}
}

void	ft_putnbr_hexa_ui(unsigned int nb)
{
	if (nb < 16)
	{
		if (nb < 10)
			ft_putchar(nb + '0');
		else
			ft_putchar((nb % 10) + 'a');
	}
	else
	{
		ft_putnbr_hexa_ui(nb / 16);
		ft_putnbr_hexa_ui(nb % 16);
	}
}

void	ft_putnbr_hexa_upper_ui(unsigned int nb)
{
	if (nb < 16)
	{
		if (nb < 10)
			ft_putchar(nb + '0');
		else
			ft_putchar((nb % 10) + 'A');
	}
	else
	{
		ft_putnbr_hexa_upper_ui(nb / 16);
		ft_putnbr_hexa_upper_ui(nb % 16);
	}
}
