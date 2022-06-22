/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:37:17 by amontant          #+#    #+#             */
/*   Updated: 2022/06/20 17:07:28 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_all
{
	int				dead;
	unsigned int	nb_philo;
	unsigned int	die;
	unsigned int	eat;
	unsigned int	sleep;
	unsigned int	nb_eat;
}	t_all;

typedef struct	s_philo
{
	pthread_t	*thread;
	int			dead;
}	t_philo;

int	ft_atoi(const char *nptr);
int	check_arg(int ac, char **av);
int	check_numbers(char *number);
int	parsing(t_all *all, int ac, char **av);

#endif