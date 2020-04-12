/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 06:07:26 by mavileo           #+#    #+#             */
/*   Updated: 2020/04/12 08:12:41 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void    ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

t_phil	*create_struct_pointer()
{
	t_phil *phil;

	if (!(phil = malloc(sizeof(t_phil))))
		return (NULL);
	phil->nb_philosophers = 0;
	phil->time_to_sleep = 0;
	phil->time_to_eat = 0;
	phil->time_to_die = 0;
	phil->nb_must_eat = 0;
	phil->threads = NULL;
	phil->mutexs = NULL;
	return (phil);
}

void	print_struct(t_phil *phil)
{
	printf("nb_philosophers : %d\n", phil->nb_philosophers);
	printf("time_to_die : %d\n", phil->time_to_die);
	printf("time_to_eat : %d\n", phil->time_to_eat);
	printf("time_to_sleep : %d\n", phil->time_to_sleep);
	printf("nb_must_eat : %d\n", phil->nb_must_eat);
}