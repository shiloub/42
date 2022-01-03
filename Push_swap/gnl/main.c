/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 01:48:22 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/18 16:22:10 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define _ODYSSEE	11866
# define _BIBLE		99812

int main(void)
{
	int	i;
	int	fd = open("odyssee", O_RDONLY);	//Change le fichier de lecture si tu veux par bible ou autre
	char	*str;
	i = 0;
	clock_t t;
    t = clock();
	str = get_next_line(fd);
	while (i++ < _ODYSSEE) //Valeur modifiable pour le nombre de ligne exact que tu veux, sinon utilise direct les DEFINE pour la taille exact des fichiers 
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\n\n~GNL() took %f secondes to execute and it produced %d lines.\n", time_taken, i - 1);
	close (fd);
	return (0);
}
