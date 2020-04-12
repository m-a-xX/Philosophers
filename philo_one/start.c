/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 06:03:01 by mavileo           #+#    #+#             */
/*   Updated: 2020/04/12 08:29:34 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		create_thread_mutexs(t_phil *phil)
{
	if (!(phil->threads = malloc(sizeof(pthread_t) * phil->nb_philosophers)))
		return (1);
	if (!(phil->mutexs = malloc(sizeof(pthread_mutex_t) * phil->nb_philosophers)))
		return (1);
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
	create_thread_mutexs(phil);
	return (0);
}