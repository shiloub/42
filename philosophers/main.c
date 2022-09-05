#include "philo.h"



int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->forks[philo->index - 1]);
	pthread_mutex_lock(&philo->all->print);
	if (philo->all->dead == 1)
	{
		pthread_mutex_unlock(&philo->all->forks[philo->index - 1]);
		pthread_mutex_unlock(&philo->all->print);
		return(1);
	}
	printf("%ld %d has taken a fork %d\n", g_t(philo), philo->index, philo->index - 1);
	pthread_mutex_unlock(&philo->all->print);
	if (philo->index == philo->all->nb_philo)
	{
		pthread_mutex_lock(&philo->all->forks[0]);
		pthread_mutex_lock(&philo->all->print);
		if (philo->all->dead == 1)
		{
			pthread_mutex_unlock(&philo->all->forks[philo->index - 1]);
			pthread_mutex_unlock(&philo->all->forks[0]);
			pthread_mutex_unlock(&philo->all->print);
			return(1);
		}
		printf("%ld %d has taken a fork %d\n", g_t(philo), philo->index, 0);
		pthread_mutex_unlock(&philo->all->print);
	}
	else
	{
		pthread_mutex_lock(&philo->all->forks[philo->index]);
		pthread_mutex_lock(&philo->all->print);
		if (philo->all->dead == 1)
		{
			pthread_mutex_unlock(&philo->all->forks[philo->index - 1]);
			pthread_mutex_unlock(&philo->all->forks[philo->index]);
			pthread_mutex_unlock(&philo->all->print);
			return(1);
		}
		printf("%ld %d has taken a fork %d\n", g_t(philo), philo->index, philo->index);
		pthread_mutex_unlock(&philo->all->print);
	}
	return (0);
}

// void	unlock_all_forks(t_philo *philo)
// {
// 	int	i;

// 	i = 0;
// 	while (i < philo->all->nb_philo)
// 	{
// 		pthread_mutex_lock(&philo->all->forks[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < philo->all->nb_philo)
// 	{
// 		pthread_mutex_unlock(&philo->all->forks[i]);
// 		i++;
// 	}
// }
//void	do_i_die_verbose(t_philo *philo);

void	ft_monitoring_real(t_philo *philos)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philos[0].all->nb_philo)
		{
			if (!philos[i].is_eating && do_i_die(&philos[i]) == 1)
			{
				philos->all->dead = 1;
				pthread_mutex_lock(&philos->all->print);
				printf("%ld %d died cuz last meal was %ld\n", g_t(philos), i + 1, philos[i].last_meal);
				pthread_mutex_unlock(&philos->all->print);
				return ;
			}
			i++;
		}
	}
}

void	*ft_monitoring(void *arg)
{
	ft_monitoring_real(arg);
	return (NULL);
}

int	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->all->forks[philo->index - 1]);
	if (philo->index == philo->all->nb_philo)
		pthread_mutex_unlock(&philo->all->forks[0]);
	else
		pthread_mutex_unlock(&philo->all->forks[philo->index]);
	return (0);
}

int	eat(t_philo *philo)
{
	philo->is_eating = 1;
	pthread_mutex_lock(&philo->all->print);
	if (philo->all->dead == 1)
	{

		pthread_mutex_unlock(&philo->all->forks[philo->index - 1]);
		if (philo->index == philo->all->nb_philo)
			pthread_mutex_unlock(&philo->all->forks[0]);
		else
			pthread_mutex_unlock(&philo->all->forks[philo->index]);
		pthread_mutex_unlock(&philo->all->print);
		return(1);
	}
	printf("%ld %d is eating\n", g_t(philo), philo->index);
	pthread_mutex_unlock(&philo->all->print);
	my_usleep(philo->all->eat * 1000, philo);
	philo->last_meal = g_t(philo);
	philo->is_eating = 0;
	return (0);
}

int	go_to_bed(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->print);
	if (philo->all->dead == 1)
	{
		pthread_mutex_unlock(&philo->all->print);
		return(1);
	}
	printf("%ld %d is sleeping\n", g_t(philo), philo->index);
	pthread_mutex_unlock(&philo->all->print);
	my_usleep(philo->all->sleep * 1000, philo);
	pthread_mutex_lock(&philo->all->print);
	if (philo->all->dead == 1)
	{
		pthread_mutex_unlock(&philo->all->print);
		return(1);
	}
	printf("%ld %d is thinking\n", g_t(philo), philo->index);
	pthread_mutex_unlock(&philo->all->print);
	return (0);
}

void	routine_real(t_philo *philo)
{
	while (1)
	{
		if (take_forks(philo) == 1)
			break;
		if (eat(philo) == 1)
			break;
		if (drop_forks(philo) == 1)
			break;
		if (go_to_bed(philo) == 1)
			break;
	}
	//printf("philo %d : je termine ma routine\n", philo->index);
}

void	*routine(void *arg)
{
	routine_real(arg);
	return (NULL);
}

void	set_forks(t_all *all)
{
	int	i;

	i = 0;
	all->forks = malloc(sizeof(pthread_mutex_t) * all->nb_philo);
	while (i < all->nb_philo)
	{
		pthread_mutex_init(&all->forks[i], NULL);
		i++;
	}

	pthread_mutex_init(&all->print, NULL);
}

int	main(int ac, char **av)
{
	t_philo		*philos;
	t_all		*all;
	pthread_mutex_t fork;
	pthread_t	monitoring;

	int i = 0;

	all = malloc(sizeof(t_all));
	all->time_start = get_actual_time();
	all->nb_eat = -1;
	all->dead = 0;
	//all->forks = malloc(sizeof(pthread_mutex_t));
	philos = parsing(all, ac, av);
	set_forks(all);
	pthread_create(&monitoring, NULL, ft_monitoring, philos);
	start_routine(philos);
	join_philos(philos);
	return (0);
}

void	start_routine(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].all->nb_philo)
	{	
		if (philos[i].index % 2 == 0)
			pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
		i++;
	}
	my_usleep(10000, NULL);
	i = 0;
	while (i < philos[0].all->nb_philo)
	{	
		if (philos[i].index % 2 == 1)
			pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
		i++;
	}
}

void	join_philos(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].all->nb_philo)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}