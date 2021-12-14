/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:22:22 by amontant          #+#    #+#             */
/*   Updated: 2021/12/14 19:14:43 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <stdio.h>
// #include <ctype.h>
// #include <unistd.h>

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (c);
	else if (c >= '0' && c <= '9')
		return (c);
	else
		return (0);
}
// int main()
// {
// 	int i = -1;
// 	// while( i < 530)
// 	// {
// 	// 	printf("%d ok: %d\n",i,ft_isalnum(i));
// 	// 	printf("%d !ok: %d\n",i,isalnum(i));
// 	// 	i++;
// 	// }
// 	write(1,"HAH\n",4);
// 	i = 262;
// 	write(1,&i,1);
// 	write(1,"HAH\n",4);

// }