/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 17:03:19 by mavileo           #+#    #+#             */
/*   Updated: 2020/04/17 09:41:41 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	declare_fork(t_phil *phil, int index)
{
	struct timeval end;

	if (phil->dead || check_dead(phil))
		return (1);
	gettimeofday(&end, NULL);
	pthread_mutex_lock(&phil->print_mutex);
	if (phil->dead || check_dead(phil))
		return (1);
	ft_putnbr_long(get_time(phil->begin, end));
	ft_putchar(' ');
	ft_putnbr_long((long)index);
	ft_putstr(" has taken a fork\n");
	pthread_mutex_unlock(&phil->print_mutex);
	return (0);
}

int	declare_eat(t_phil *phil, int index)
{
	struct timeval end;

	if (phil->dead || check_dead(phil))
		return (1);
	gettimeofday(&end, NULL);
	pthread_mutex_lock(&phil->print_mutex);
	if (phil->dead || check_dead(phil))
		return (1);
	ft_putnbr_long(get_time(phil->begin, end));
	ft_putchar(' ');
	ft_putnbr_long((long)index);
	ft_putstr(" is eating\n");
	pthread_mutex_unlock(&phil->print_mutex);
	return (0);
}

int	declare_sleep(t_phil *phil, int index)
{
	struct timeval	end;

	if (phil->dead || check_dead(phil))
		return (1);
	gettimeofday(&end, NULL);
	pthread_mutex_lock(&phil->print_mutex);
	if (phil->dead || check_dead(phil))
		return (1);
	ft_putnbr_long(get_time(phil->begin, end));
	ft_putchar(' ');
	ft_putnbr_long((long)index);
	ft_putstr(" is sleeping\n");
	pthread_mutex_unlock(&phil->print_mutex);
	return (0);
}

int	declare_think(t_phil *phil, int index)
{
	struct timeval end;

	if (phil->dead || check_dead(phil))
		return (1);
	gettimeofday(&end, NULL);
	pthread_mutex_lock(&phil->print_mutex);
	if (phil->dead || check_dead(phil))
		return (1);
	ft_putnbr_long(get_time(phil->begin, end));
	ft_putchar(' ');
	ft_putnbr_long((long)index);
	ft_putstr(" is thinking\n");
	pthread_mutex_unlock(&phil->print_mutex);
	return (0);
}

int	declare_died(t_phil *phil, int index, struct timeval now)
{
	pthread_mutex_lock(&phil->print_mutex);
	if (phil->print_dead)
	{
		pthread_mutex_unlock(&phil->print_mutex);
		return (1);
	}
	ft_putnbr_long(get_time(phil->begin, now));
	ft_putchar(' ');
	ft_putnbr_long((long)index);
	ft_putstr(" died\n");
	pthread_mutex_unlock(&phil->print_mutex);
	phil->dead = 1;
	phil->print_dead = 1;
	return (0);
}
