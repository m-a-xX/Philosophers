/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 06:07:26 by mavileo           #+#    #+#             */
/*   Updated: 2020/04/16 19:40:23 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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
	phil->thread = NULL;
	phil->mutex = NULL;
	return (phil);
}

void	free_struct(t_phil *phil)
{
	free(phil->thread);
	free(phil->mutex);
	free(phil);
}

void	print_struct(t_phil *phil)
{
	printf("nb_philosophers : %d\n", phil->nb_philosophers);
	printf("time_to_die : %d\n", phil->time_to_die);
	printf("time_to_eat : %d\n", phil->time_to_eat);
	printf("time_to_sleep : %d\n", phil->time_to_sleep);
	printf("nb_must_eat : %d\n", phil->nb_must_eat);
}
