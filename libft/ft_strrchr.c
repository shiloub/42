/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:40:54 by amontant          #+#    #+#             */
/*   Updated: 2021/11/22 12:40:56 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		i;
	int		cursor;
	int		find;

	i = 0;
	p = (char *)s;
	find = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			cursor = i;
			find = 1;
		}
		i++;
	}
	if (find == 1)
		return (&p[cursor]);
	if (c == '\0')
		return (&p[i]);
	return (0);
}
