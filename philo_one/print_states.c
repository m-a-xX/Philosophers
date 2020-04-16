/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 17:03:19 by mavileo           #+#    #+#             */
/*   Updated: 2020/04/16 18:40:38 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	declare_fork(t_phil *phil, int index)
{
	struct timeval end;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(&phil->print_mutex);
	ft_putnbr_long(get_time(phil, end));
	ft_putchar(' ');
	ft_putnbr_long((long)index);
	ft_putstr(" has taken a fork\n");
	pthread_mutex_unlock(&phil->print_mutex);
}

void	declare_eat(t_phil *phil, int index)
{
	struct timeval end;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(&phil->print_mutex);
	ft_putnbr_long(get_time(phil, end));
	ft_putchar(' ');
	ft_putnbr_long((long)index);
	ft_putstr(" is eating\n");
	pthread_mutex_unlock(&phil->print_mutex);
}

void	declare_sleep(t_phil *phil, int index)
{
	struct timeval end;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(&phil->print_mutex);
	ft_putnbr_long(get_time(phil, end));
	ft_putchar(' ');
	ft_putnbr_long((long)index);
	ft_putstr(" is sleeping\n");
	pthread_mutex_unlock(&phil->print_mutex);
}

void	declare_think(t_phil *phil, int index)
{
	struct timeval end;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(&phil->print_mutex);
	ft_putnbr_long(get_time(phil, end));
	ft_putchar(' ');
	ft_putnbr_long((long)index);
	ft_putstr(" is thinking\n");
	pthread_mutex_unlock(&phil->print_mutex);
}

void	declare_died(t_phil *phil, int index)
{
	struct timeval end;

	gettimeofday(&end, NULL);
	pthread_mutex_lock(&phil->print_mutex);
	ft_putnbr_long(get_time(phil, end));
	ft_putchar(' ');
	ft_putnbr_long((long)index);
	ft_putstr(" died\n");
	pthread_mutex_unlock(&phil->print_mutex);
}
