/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiloub <shiloub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:22:32 by amontant          #+#    #+#             */
/*   Updated: 2021/12/22 12:25:32 by shiloub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

int		count_putchar(char c);
int		count_putstr(char *str);
void	ft_putnbr_si(int nb);
void	ft_putnbr_ui(unsigned int nb);
void	ft_putnbr_hexa_ul(unsigned long nb);
void	ft_putnbr_hexa_ui(unsigned int nb);

#endif
