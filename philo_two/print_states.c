/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 17:03:19 by mavileo           #+#    #+#             */
/*   Updated: 2020/04/17 20:19:09 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	declare_fork(t_phil *phil, int index)
{
	struct timeval end;

	if (phil->dead || check_dead(phil))
		return (1);
	gettimeofday(&end, NULL);
	sem_wait(phil->print_sem);
	if (phil->dead || check_dead(phil))
		return (1);
	ft_putnbr_long(get_time(phil->begin, end));
	ft_putchar(' ');
	ft_putnbr_long((long)index);
	ft_putstr(" has taken a fork\n");
	sem_post(phil->print_sem);
	return (0);
}

int	declare_eat(t_phil *phil, int index)
{
	struct timeval end;

	if (phil->dead || check_dead(phil))
		return (1);
	gettimeofday(&end, NULL);
	sem_wait(phil->print_sem);
	if (phil->dead || check_dead(phil))
		return (1);
	ft_putnbr_long(get_time(phil->begin, end));
	ft_putchar(' ');
	ft_putnbr_long((long)index);
	ft_putstr(" is eating\n");
	sem_post(phil->print_sem);
	return (0);
}

int	declare_sleep(t_phil *phil, int index)
{
	struct timeval	end;

	if (phil->dead || check_dead(phil))
		return (1);
	gettimeofday(&end, NULL);
	sem_wait(phil->print_sem);
	if (phil->dead || check_dead(phil))
		return (1);
	ft_putnbr_long(get_time(phil->begin, end));
	ft_putchar(' ');
	ft_putnbr_long((long)index);
	ft_putstr(" is sleeping\n");
	sem_post(phil->print_sem);
	return (0);
}

int	declare_think(t_phil *phil, int index)
{
	struct timeval end;

	if (phil->dead || check_dead(phil))
		return (1);
	gettimeofday(&end, NULL);
	sem_wait(phil->print_sem);
	if (phil->dead || check_dead(phil))
		return (1);
	ft_putnbr_long(get_time(phil->begin, end));
	ft_putchar(' ');
	ft_putnbr_long((long)index);
	ft_putstr(" is thinking\n");
	sem_post(phil->print_sem);
	return (0);
}

int	declare_died(t_phil *phil, int index, struct timeval now)
{
	sem_wait(phil->print_sem);
	if (phil->print_dead)
	{
		sem_post(phil->print_sem);
		return (1);
	}
	ft_putnbr_long(get_time(phil->begin, now));
	ft_putchar(' ');
	ft_putnbr_long((long)index);
	ft_putstr(" died\n");
	sem_post(phil->print_sem);
	phil->dead = 1;
	phil->print_dead = 1;
	return (0);
}
