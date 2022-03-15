/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:29:49 by amontant          #+#    #+#             */
/*   Updated: 2021/12/23 18:57:36 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_id(int nb)
{
	ft_putnbr_si(nb);
	return (ft_count_decimal_si(nb));
}

int	treat_p(void *p)
{
	unsigned long long	nb;

	if (!p)
		return (count_putstr("0x0"));
	nb = (unsigned long long)p;
	write(1, "0x", 2);
	ft_putnbr_hexa_ull(nb);
	return (ft_count_hexa_ull(nb) + 2);
}

int	treat_uxx(unsigned int nb, char c)
{
	if (c == 'u')
	{
		ft_putnbr_ui(nb);
		return (ft_count_decimal_ui(nb));
	}
	if (c == 'x')
		ft_putnbr_hexa_ui(nb);
	else if (c == 'X')
		ft_putnbr_hexa_upper_ui(nb);
	return (ft_count_hexa_ui(nb));
}

int	treat_s(char *str)
{
	if (!str)
		return (count_putstr("(null)"));
	return (count_putstr(str));
}
