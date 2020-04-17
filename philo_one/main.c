/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 05:50:29 by mavileo           #+#    #+#             */
/*   Updated: 2020/04/17 10:08:36 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		check_dead(t_phil *phil)
{
	struct timeval	now;
	int				i;
	int				dead;

	dead = 0;
	i = 0;
	gettimeofday(&now, NULL);
	while (i < phil->nb_philosophers)
	{
		if (((int)get_time(phil->last_eat[i++], now)) > phil->time_to_die)
		{
			dead = i;
			break ;
		}
	}
	if (!dead || phil->dead)
		return (0);
	declare_died(phil, dead, now);
	unlock_mutexs(phil);
	return (1);
}

int		take_fork(t_phil *phil, int i)
{
	if (phil->dead || check_dead(phil))
		return (1);
	pthread_mutex_lock(&phil->mutex[i]);
	if (i < phil->nb_philosophers - 1 || phil->nb_philosophers == 1)
		pthread_mutex_lock(&phil->mutex[i + 1]);
	else
		pthread_mutex_lock(&phil->mutex[0]);
	if (phil->dead || check_dead(phil))
		return (1);
	declare_fork(phil, i + 1);
	declare_fork(phil, i + 1);
	return (0);
}

void	put_fork(t_phil *phil, int i)
{
	pthread_mutex_unlock(&phil->mutex[i]);
	if (i < phil->nb_philosophers - 1 || phil->nb_philosophers == 1)
		pthread_mutex_unlock(&phil->mutex[i + 1]);
	else
		pthread_mutex_unlock(&phil->mutex[0]);
}

void	*philo_thread(void *arg)
{
	t_phil			*phil;
	int				i;

	phil = (t_phil *)arg;
	if (phil->dead || check_dead(phil))
		return (arg);
	pthread_mutex_lock(&phil->inc_mutex);
	i = ++phil->index;
	pthread_mutex_unlock(&phil->inc_mutex);
	if (take_fork(phil, i))
		return (arg);
	if (declare_eat(phil, i + 1))
		return (arg);
	gettimeofday(&phil->last_eat[i], NULL);
	usleep(phil->time_to_eat * 1000);
	gettimeofday(&phil->last_eat[i], NULL);
	put_fork(phil, i);
	if (declare_sleep(phil, i + 1))
		return (arg);
	usleep(phil->time_to_sleep * 1000);
	if (declare_think(phil, i + 1))
		return (arg);
	return (NULL);
}

int		main(int ac, char **av)
{
	t_phil	*phil;
	int		i;

	if (!(phil = create_struct_pointer()))
		return (1);
	if (get_args(ac, av, phil))
		return (1);
	gettimeofday(&phil->begin, NULL);
	while (phil->nb_must_eat-- != 0 && !phil->dead)
	{
		i = 0;
		phil->index = -1;
		while (i < phil->nb_philosophers)
			pthread_create(&phil->thread[i++], NULL, philo_thread, phil);
		i--;
		while (i >= 0)
			pthread_join(phil->thread[i--], NULL);
	}
	free_struct(phil);
	return (0);
}
