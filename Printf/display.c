/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:00:22 by amontant          #+#    #+#             */
/*   Updated: 2021/12/22 19:06:18 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int	count_putchar(char c)
{
	return (write(1, &c, 1));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_putstr(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (ft_strlen(str));
}

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
		ft_putnbr_hexa_ui(nb / 16);
		ft_putnbr_hexa_ui(nb % 16);
	}
}

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