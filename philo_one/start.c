/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 06:03:01 by mavileo           #+#    #+#             */
/*   Updated: 2020/04/15 15:47:52 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		malloc_threads_mutexs(t_phil *phil)
{
	int i;

	i = 0;
	if (!(phil->thread = malloc(sizeof(pthread_t) * phil->nb_philosophers)))
		return (1);
	if (!(phil->mutex = malloc(sizeof(pthread_mutex_t) * phil->nb_philosophers)))
		return (1);
	while (i < phil->nb_philosophers)
		pthread_mutex_init(&phil->mutex[i++], NULL);
	pthread_mutex_init(&phil->inc_mutex, NULL);
	return (0);
}

int		get_args(int ac, char **av, t_phil *phil)
{
	if (ac < 5)
		ft_putstr("Too few arguments passed\n");
	else if (ac > 6)
		ft_putstr("Too much arguments passed\n");
	if (ac != 5 && ac != 6)
		return (1);
	phil->nb_philosophers = ft_atoi(av[1]);
	phil->time_to_die = ft_atoi(av[2]);
	phil->time_to_eat = ft_atoi(av[3]);
	phil->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		phil->nb_must_eat = ft_atoi(av[5]);
	else
		phil->nb_must_eat = 0;
	if (phil->nb_must_eat < 0 || phil->nb_philosophers < 1 ||
		phil->time_to_eat < 1 || phil->time_to_die < 1 ||
		phil->time_to_sleep < 1)
	{
		ft_putstr("Arguments passed are wrong, verify them and retry\n");
		return (1);
	}
	if (malloc_threads_mutexs(phil))
		return (1);
	return (0);
}