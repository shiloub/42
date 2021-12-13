/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:40:04 by amontant          #+#    #+#             */
/*   Updated: 2021/11/22 13:44:03 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, const char *src, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while ((j + i) < n && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	if ((j + i) == n)
	{
		dest[i + j - 1] = '\0';
	}
	else
		dest[i + j] = '\0';
	return (dest);
}
