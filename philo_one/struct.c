/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 21:01:19 by mavileo           #+#    #+#             */
/*   Updated: 2020/04/17 09:33:28 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_phil	*create_struct_pointer(void)
{
	t_phil *phil;

	if (!(phil = malloc(sizeof(t_phil))))
		return (NULL);
	phil->index = -1;
	phil->nb_philosophers = 0;
	phil->time_to_sleep = 0;
	phil->time_to_eat = 0;
	phil->time_to_die = 0;
	phil->nb_must_eat = 0;
	phil->index = 0;
	phil->dead = 0;
	phil->print_dead = 0;
	phil->thread = NULL;
	phil->mutex = NULL;
	return (phil);
}

void	destroy_mutexs(t_phil *phil)
{
	int i;

	i = 0;
	while (i < phil->nb_philosophers)
		pthread_mutex_destroy(&phil->mutex[i++]);
}

void	free_struct(t_phil *phil)
{
	destroy_mutexs(phil);
	free(phil->thread);
	free(phil->mutex);
	free(phil->last_eat);
	free(phil);
}
