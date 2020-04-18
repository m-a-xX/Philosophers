/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 06:07:26 by mavileo           #+#    #+#             */
/*   Updated: 2020/04/17 20:57:04 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_long(long nb)
{
	if (nb > 9)
	{
		ft_putnbr_long(nb / 10);
		ft_putnbr_long(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

double	get_time(struct timeval begin, struct timeval end)
{
	double elapsed;

	elapsed = ((end.tv_sec - begin.tv_sec) * 1000000) +
				((end.tv_usec - begin.tv_usec));
	return (elapsed / 1000);
}

void	unlock_sems(t_phil *phil)
{
	int i;

	i = 0;
	while (i++ < phil->nb_philosophers)
		sem_post(phil->forks);
	sem_post(phil->inc_sem);
	sem_post(phil->print_sem);
}
