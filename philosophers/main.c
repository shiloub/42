#include "philo.h"



int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->forks[philo->index - 1]);
	pthread_mutex_lock(&philo->all->print);
	pthread_mutex_lock(&philo->all->is_dead);
	if (philo->all->dead == 1)
	{
		pthread_mutex_unlock(&philo->all->is_dead);
		pthread_mutex_unlock(&philo->all->print);
		pthread_mutex_unlock(&philo->all->forks[philo->index - 1]);
		return(1);
	}
	pthread_mutex_unlock(&philo->all->is_dead);
	printf("%ld %d has taken a fork %d\n", g_t(philo), philo->index, philo->index - 1);
	pthread_mutex_unlock(&philo->all->print);
	if (philo->index == philo->all->nb_philo)
	{
		pthread_mutex_lock(&philo->all->forks[0]);
		pthread_mutex_lock(&philo->all->print);
		pthread_mutex_lock(&philo->all->is_dead);
		if (philo->all->dead == 1)
		{
			pthread_mutex_unlock(&philo->all->is_dead);
			pthread_mutex_unlock(&philo->all->print);
			pthread_mutex_unlock(&philo->all->forks[0]);
			pthread_mutex_unlock(&philo->all->forks[philo->index - 1]);
			return(1);
		}
		pthread_mutex_unlock(&philo->all->is_dead);
		printf("%ld %d has taken a fork %d\n", g_t(philo), philo->index, 0);
		pthread_mutex_unlock(&philo->all->print);
	}
	else
	{
		pthread_mutex_lock(&philo->all->forks[philo->index]);
		pthread_mutex_lock(&philo->all->print);
		pthread_mutex_lock(&philo->all->is_dead);
		if (philo->all->dead == 1)
		{
			pthread_mutex_unlock(&philo->all->is_dead);
			pthread_mutex_unlock(&philo->all->print);
			pthread_mutex_unlock(&philo->all->forks[philo->index]);
			pthread_mutex_unlock(&philo->all->forks[philo->index - 1]);
			return(1);
		}
		pthread_mutex_unlock(&philo->all->is_dead);
		printf("%ld %d has taken a fork %d\n", g_t(philo), philo->index, philo->index);
		pthread_mutex_unlock(&philo->all->print);
	}
	return (0);
}

void	ft_monitoring_real(t_philo *philos)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philos[0].all->nb_philo)
		{
			pthread_mutex_lock(&philos[i].last_meal_mut);
			if (do_i_die(&philos[i]) == 1)
			{
				pthread_mutex_unlock(&philos[i].last_meal_mut);
				pthread_mutex_lock(&philos->all->is_dead);
				philos->all->dead = 1;
				pthread_mutex_unlock(&philos->all->is_dead);
				pthread_mutex_lock(&philos->all->print);
				printf("%ld %d died cuz last meal was %ld\n", g_t(philos), i + 1, philos[i].last_meal);
				pthread_mutex_unlock(&philos->all->print);
				return ;
			}
			pthread_mutex_unlock(&philos[i].last_meal_mut);
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
	if (philo->index == philo->all->nb_philo)
		pthread_mutex_unlock(&philo->all->forks[0]);
	else
		pthread_mutex_unlock(&philo->all->forks[philo->index]);
	pthread_mutex_unlock(&philo->all->forks[philo->index - 1]);
	return (0);
}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->print);
	pthread_mutex_lock(&philo->all->is_dead);
	if (philo->all->dead == 1)
	{
		pthread_mutex_unlock(&philo->all->is_dead);
		pthread_mutex_unlock(&philo->all->print);
		if (philo->index == philo->all->nb_philo)
			pthread_mutex_unlock(&philo->all->forks[0]);
		else
			pthread_mutex_unlock(&philo->all->forks[philo->index]);
		pthread_mutex_unlock(&philo->all->forks[philo->index - 1]);
		return(1);
	}
	pthread_mutex_unlock(&philo->all->is_dead);
	printf("%ld %d is eating\n", g_t(philo), philo->index);
	pthread_mutex_unlock(&philo->all->print);
	my_usleep(philo->all->eat * 1000, philo);
	pthread_mutex_lock(&philo->last_meal_mut);
	philo->last_meal = g_t(philo);
	pthread_mutex_unlock(&philo->last_meal_mut);
	philo->eaten++;
	return (0);
}

int	go_to_bed(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->print);
	pthread_mutex_lock(&philo->all->is_dead);
	if (philo->all->dead == 1)
	{
		pthread_mutex_unlock(&philo->all->is_dead);
		pthread_mutex_unlock(&philo->all->print);
		return(1);
	}
	pthread_mutex_unlock(&philo->all->is_dead);
	printf("%ld %d is sleeping\n", g_t(philo), philo->index);
	pthread_mutex_unlock(&philo->all->print);
	my_usleep(philo->all->sleep * 1000, philo);
	pthread_mutex_lock(&philo->all->print);
	pthread_mutex_lock(&philo->all->is_dead);
	if (philo->all->dead == 1)
	{
		pthread_mutex_unlock(&philo->all->is_dead);
		pthread_mutex_unlock(&philo->all->print);
		return(1);
	}
	pthread_mutex_unlock(&philo->all->is_dead);
	printf("%ld %d is thinking\n", g_t(philo), philo->index);
	pthread_mutex_unlock(&philo->all->print);
	return (0);
}

void	routine_real(t_philo *philo)
{
	philo->eaten = 0;
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
		if (philo->eaten == philo->all->nb_eat)
			break;
	}
	printf("je break\n");
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
	pthread_mutex_init(&all->is_dead, NULL);
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
	philos = parsing(all, ac, av);
	set_forks(all);
	pthread_create(&monitoring, NULL, ft_monitoring, philos);
	start_routine(philos);
	join_philos(philos);
	pthread_join(monitoring, NULL);
	free(all);
	free(philos);
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