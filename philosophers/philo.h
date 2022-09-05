/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shiloub <shiloub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:37:17 by amontant          #+#    #+#             */
/*   Updated: 2022/06/28 14:06:36 by shiloub          ###   ########.fr       */
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
	unsigned long				time_start;
	int				dead;
	unsigned int	nb_philo;
	unsigned int	die;
	unsigned int	eat;
	unsigned int	sleep;
	unsigned int	nb_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t print;
}	t_all;

typedef struct	s_philo
{
	int			index;
	t_all		*all;
	int			is_eating;
	pthread_t	thread;
	int			dead;
	unsigned long last_meal;
}	t_philo;

int	ft_atoi(const char *nptr);
int	check_arg(int ac, char **av);
int	check_numbers(char *number);
t_philo	*parsing(t_all *all, int ac, char **av);
unsigned long	get_actual_time(void);
void	my_usleep(unsigned long usec, t_philo *philo);
void	join_philos(t_philo *philos);
void	start_routine(t_philo *philos);
unsigned long	g_t(t_philo *philo);
int	do_i_die(t_philo *philo);


#endif