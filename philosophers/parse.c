/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:19:13 by amontant          #+#    #+#             */
/*   Updated: 2022/09/05 16:35:09 by amontant         ###   ########.fr       */
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
		exit(0);  
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
			exit(0);
		}
		i++;
	}
	return (1);
}

t_philo	*parsing(t_all *all, int ac, char **av)
{
	int	i;
	t_philo *philos;
	
	all->nb_eat = -1;
	i = 0;
	if (check_arg(ac, av) == 0)
        printf("args are valid\n");
	else
		return (0);
	all->nb_philo = ft_atoi(av[1]);
	all->die = ft_atoi(av[2]);
	all->eat = ft_atoi(av[3]);
	all->sleep = ft_atoi(av[4]);
	philos = malloc(sizeof(t_philo) * all->nb_philo);
	while (i < all->nb_philo)
	{
		philos[i].index = i + 1;
		philos[i].all = all;
		philos[i].is_eating = 0;
		philos[i].last_meal = 0;
		i++;
	}
	if (ac == 6)
		all->nb_eat = ft_atoi(av[5]);
	return (philos);
}