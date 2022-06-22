#include "philo.h"

void *routine(void *arg)
{
	(void)arg;
	printf("salut je commence ma routine\n");
	return (NULL);
}

int main(int ac, char **av)
{
	pthread_t *thread;
	t_all		*all;
	pthread_mutex_t *forks;

	all = malloc(sizeof(t_all));
	all->nb_eat = -1;
	if (parsing(all, ac, av))
	{
		printf("nb of  philo : %d\n", all->nb_philo);
		printf("time to die : %d\n", all->die);
		printf("time to eat : %d\n", all->eat);
		printf("time to sleep : %d\n", all->sleep);
		printf("nb de tours : %d\n", all->nb_eat);
	}
	forks = malloc(sizeof(pthread_mutex_t) * all->nb_philo);
	int	i = 0;

	while (i < all->nb_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	
	
	thread = malloc(sizeof(pthread_t));
	pthread_create(thread, NULL, &routine, NULL);
	routine(NULL);
	return(0);
}