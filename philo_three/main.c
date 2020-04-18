/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 05:50:29 by mavileo           #+#    #+#             */
/*   Updated: 2020/04/18 15:34:32 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		check_dead(t_phil *phil)
{
	struct timeval	now;
	int				i;
	int				dead;

	dead = 0;
	i = 0;
	gettimeofday(&now, NULL);
	while (i < phil->nb_philosophers)
	{
		if (((int)get_time(phil->last_eat[i++], now)) > phil->time_to_die)
		{
			dead = i;
			break ;
		}
	}
	if (!dead || phil->dead)
		return (0);
	declare_died(phil, dead, now);
	unlock_sems(phil);
	return (1);
}

int		take_fork(t_phil *phil, int i)
{
	if (phil->dead || check_dead(phil))
		return (1);
	sem_wait(phil->forks);
	if (phil->dead || check_dead(phil))
		return (1);
	declare_fork(phil, i + 1);
	declare_fork(phil, i + 1);
	return (0);
}

void	put_fork(t_phil *phil)
{
	sem_post(phil->forks);
}

int		philo_process(t_phil *phil, int i)
{
	if (phil->dead || check_dead(phil))
		return (1);
	if (take_fork(phil, i))
		return (1);
	if (declare_eat(phil, i + 1))
		return (1);
	gettimeofday(&phil->last_eat[i], NULL);
	usleep(phil->time_to_eat * 1000);
	gettimeofday(&phil->last_eat[i], NULL);
	put_fork(phil);
	if (declare_sleep(phil, i + 1))
		return (1);
	usleep(phil->time_to_sleep * 1000);
	if (declare_think(phil, i + 1))
		return (1);
	exit(EXIT_SUCCESS);
	return (0);
}

int		main(int ac, char **av)
{
	t_phil	*phil;
	pid_t	pid;
	int		i;

	if (!(phil = create_struct_pointer()))
		return (1);
	if (get_args(ac, av, phil))
		return (1);
	pid = getppid();
	gettimeofday(&phil->begin, NULL);
	while (phil->nb_must_eat-- != 0 && !phil->dead)
	{
		i = 0;
		while (i < phil->nb_philosophers && pid)
		{
			pid = fork();
			phil->pids[i] = pid;
			if (i++ > -1 && pid == 0)
				philo_process(phil, i - 1);
		}
		while (--i >= 0)
			waitpid(phil->pids[i], NULL, 0);
	}
	free_struct(phil);
	return (0);
}
