/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 05:50:29 by mavileo           #+#    #+#             */
/*   Updated: 2020/04/16 18:40:14 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <sys/time.h>

void	*philo_thread(void	*arg)
{
	t_phil			*phil;
	int				i;

	phil = (t_phil *)arg;
	pthread_mutex_lock(&phil->inc_mutex);
	i = ++phil->index;
	pthread_mutex_unlock(&phil->inc_mutex);

	pthread_mutex_lock(&phil->mutex[i]);
	if (i < phil->nb_philosophers - 1)
		pthread_mutex_lock(&phil->mutex[i + 1]);
	else
		pthread_mutex_lock(&phil->mutex[0]);
	declare_fork(phil, i + 1);
	declare_fork(phil, i + 1);

	declare_eat(phil, i + 1);
	usleep(phil->time_to_eat * 1000);
	declare_sleep(phil, i + 1);
	usleep(phil->time_to_sleep * 1000);
	declare_think(phil, i + 1);

	pthread_mutex_unlock(&phil->mutex[i]);
	if (i < phil->nb_philosophers - 1)
		pthread_mutex_unlock(&phil->mutex[i + 1]);
	else
		pthread_mutex_unlock(&phil->mutex[0]);
	return (NULL);
}

int		main(int ac, char **av)
{
	t_phil	*phil;
	int		j;
	int		k;

	j = 0;
	if (!(phil = create_struct_pointer()))
		return (1);
	if (get_args(ac, av, phil))
		return (1);
	gettimeofday(&phil->begin, NULL);
	while (j < 2)
	{
		k = 0;
		phil->index = -1;
		while (k < phil->nb_philosophers)
		{
			pthread_create(&phil->thread[k++], NULL, philo_thread, phil);
		}
		k--;
		while (k >= 0)
			pthread_join(phil->thread[k--], NULL);
		j++;
	}
	free_struct(phil);
	return (0);	
}
