#include "philo.h"

void    print_tf(t_philo *philo)
{
    t_mutex_lock(&philo->all->print);
	printf("%ld %d : has taken a fork %d\n", g_t(philo), philo->index, philo->index - 1);
}