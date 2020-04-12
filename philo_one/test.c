#include "philo_one.h"

void	*philo_one(void	*arg)
{
	pthread_mutex_trylock(&arg[0]);
	pthread_mutex_trylock(&arg[1]);
	ft_putstr("philo 1 eat\n");
	usleep(1000);
	ft_putstr("philo 1 sleep\n");
	pthread_mutex_unlock(&arg[0]);
	pthread_mutex_unlock(&arg[0]);
	return NULL;
}

void	*philo_two(void	*arg)
{
	pthread_mutex_trylock(&arg[0]);
	pthread_mutex_trylock(&arg[1]);
	ft_putstr("philo 2 eat\n");
	usleep(1000);
	ft_putstr("philo 2 sleep\n");
	return NULL;
	pthread_mutex_unlock(&arg[0]);
	pthread_mutex_unlock(&arg[1]);
}

int main()
{
	t_phil *phil = create_struct_pointer();
	pthread_t thread1;
	pthread_t thread2;
	pthread_mutex_t mutex[2];

	pthread_mutex_init(&mutex[0], NULL);
	pthread_mutex_init(&mutex[1], NULL);
	pthread_create(&thread1, NULL, philo_one, mutex);
	pthread_create(&thread2, NULL, philo_two, mutex);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
}