/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:28:11 by amontant          #+#    #+#             */
/*   Updated: 2021/12/23 18:54:30 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat(char c, va_list arg)
{
	if (c == 'd' || c == 'i')
		return (treat_id(va_arg(arg, int)));
	if (c == 's')
		return (treat_s(va_arg(arg, char *)));
	if (c == 'X' || c == 'x' || c == 'u')
		return (treat_uxx(va_arg(arg, unsigned int), c));
	if (c == 'p')
		return (treat_p(va_arg(arg, void *)));
	if (c == 'c')
		return (count_putchar((char)va_arg(arg, int)));
	if (c == '%')
		return (count_putchar('%'));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		count;
	va_list	arg;

	va_start(arg, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			count = count + write(1, &str[i], 1);
		else if (str[i + 1])
			count = count + treat(str[++i], arg);
		else
			count = count + write(1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (count);
}
