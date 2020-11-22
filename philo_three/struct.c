/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 21:01:19 by mavileo           #+#    #+#             */
/*   Updated: 2020/04/18 15:31:15 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

t_phil	*create_struct_pointer(void)
{
	t_phil *phil;

	if (!(phil = malloc(sizeof(t_phil))))
		return (NULL);
	phil->nb_philosophers = 0;
	phil->time_to_sleep = 0;
	phil->time_to_eat = 0;
	phil->time_to_die = 0;
	phil->nb_must_eat = 0;
	phil->dead = 0;
	phil->print_dead = 0;
	phil->pids = NULL;
	phil->forks = NULL;
	phil->inc_sem = NULL;
	phil->print_sem = NULL;
	phil->last_eat = NULL;
	return (phil);
}

void	destroy_sems(void)
{
	sem_unlink("pForks");
	sem_unlink("pInc");
	sem_unlink("pPrint");
}

void	free_struct(t_phil *phil)
{
	destroy_sems();
	free(phil->last_eat);
	free(phil->pids);
	free(phil);
}
