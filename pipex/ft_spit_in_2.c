/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spit_in_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:03:27 by amontant          #+#    #+#             */
/*   Updated: 2022/02/23 17:09:06 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_split_in_2(char *str, char del)
{
	int		i;
	int		size1;
	char	**splited;

	i = 0;
	size = 0;
	splited = malloc(sizeof(char *) * 3);
	splited[0] = get_string_1(str, del);
	splited[1] = get_string_2(str, del);
}
