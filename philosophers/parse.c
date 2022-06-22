/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:19:13 by amontant          #+#    #+#             */
/*   Updated: 2022/06/20 16:06:08 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(int ac, char **av)
{
	int	i;
	i = 1;
	
	if (ac < 5 || ac > 6)
	{
		printf("wrong number of arguments\n");
		return (-1);  
	}
	while (i < ac)
	{
		if (!check_numbers(av[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	check_numbers(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9')
		{
			printf("arg isnt valid\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	parsing(t_all *all, int ac, char **av)
{
	int	i;

	i = 0;
	if (check_arg(ac, av) == 0)
        printf("args are valid\n");
	else
		return (0);
	all->nb_philo = ft_atoi(av[1]);
	all->die = ft_atoi(av[2]);
	all->eat = ft_atoi(av[3]);
	all->sleep = ft_atoi(av[4]);
	if (ac == 6)
		all->nb_eat = ft_atoi(av[5]);
	return (1);
}