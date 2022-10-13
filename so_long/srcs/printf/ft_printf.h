/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:22:32 by amontant          #+#    #+#             */
/*   Updated: 2021/12/23 18:53:20 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *str, ...);
int		count_putchar(char c);
void	ft_putchar(char c);
int		ft_strlen(const char *str);
int		count_putstr(char *str);
void	ft_putnbr_si(int nb);
void	ft_putnbr_ui(unsigned int nb);
void	ft_putnbr_hexa_ull(unsigned long long nb);
void	ft_putnbr_hexa_ui(unsigned int nb);
void	ft_putnbr_hexa_upper_ui(unsigned int nb);
int		ft_count_decimal_si(int nb);
int		ft_count_decimal_ui(unsigned int nb);
int		ft_count_hexa_ull(unsigned long long nb);
int		ft_count_hexa_ui(unsigned int nb);
int		treat_id(int nb);
int		treat_p(void *p);
int		treat_uxx(unsigned int nb, char c);
int		treat_s(char *str);

#endif
