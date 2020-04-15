/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 05:50:29 by mavileo           #+#    #+#             */
/*   Updated: 2020/04/15 14:07:13 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*hello(void	*arg)
{
	t_phil	*phil;
	int j;

	phil = (t_phil *)arg;
	j = phil->i;
	pthread_mutex_lock(&phil->mutex[j]);
	if (j < phil->nb_philosophers - 1)
		pthread_mutex_lock(&phil->mutex[j + 1]);
	else
		pthread_mutex_lock(&phil->mutex[0]);
	printf("philo %d eat\n", phil->i);
	printf("philo %d sleep\n", phil->i);
	phil->i++;
	pthread_mutex_unlock(&phil->mutex[j]);
	if (j < phil->nb_philosophers - 1)
		pthread_mutex_unlock(&phil->mutex[j + 1]);
	else
		pthread_mutex_unlock(&phil->mutex[0]);
	return (NULL);
}

int		main(int ac, char **av)
{
	t_phil	*phil;
	int		j;
	int		l;

	l = 0;
	j = 0;
	if (!(phil = create_struct_pointer()))
		return (1);
	if (get_args(ac, av, phil))
		return (1);
	print_struct(phil);
	while (j < 10)
	{
		phil->i = 0;
		l = 0;
		while (l < phil->nb_philosophers)
			pthread_create(&phil->thread[l++], NULL, hello, phil);
		l--;
		while (l >= 0)
			pthread_join(phil->thread[l--], NULL);
		j++;
	}
	free_struct(phil);
	return (0);	
}
