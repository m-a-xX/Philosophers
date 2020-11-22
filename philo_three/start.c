/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 06:03:01 by mavileo           #+#    #+#             */
/*   Updated: 2020/04/18 15:32:38 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	correct_sems(t_phil *phil)
{
	int forks;
	int i;
	int j;

	forks = 0;
	j = 0;
	i = 0;
	sem_getvalue(phil->forks, &forks);
	sem_getvalue(phil->inc_sem, &i);
	sem_getvalue(phil->print_sem, &j);
	while (forks < phil->nb_philosophers / 2)
	{
		sem_post(phil->forks);
		sem_getvalue(phil->forks, &forks);
	}
	if (i == 0)
		sem_post(phil->inc_sem);
	else if (i == 2)
		sem_wait(phil->inc_sem);
	if (j == 0)
		sem_post(phil->print_sem);
	else if (j == 2)
		sem_wait(phil->print_sem);
}

int		malloc_process_sems(t_phil *phil)
{
	if (!(phil->last_eat = malloc(sizeof(struct timeval) *
		phil->nb_philosophers)))
		return (1);
	if (!(phil->pids = malloc(sizeof(pid_t) * phil->nb_philosophers)))
		return (1);
	phil->forks = sem_open("pForks", O_CREAT, 0644, phil->nb_philosophers / 2);
	phil->inc_sem = sem_open("pInc", O_CREAT, 0644, 1);
	phil->print_sem = sem_open("pPrint", O_CREAT, S_IRWXU, 1);
	correct_sems(phil);
	if (phil->forks == SEM_FAILED || phil->inc_sem == SEM_FAILED ||
		phil->print_sem == SEM_FAILED)
		return (1);
	return (0);
}

int		get_args(int ac, char **av, t_phil *phil)
{
	if (ac < 5)
		ft_putstr("Too few arguments passed\n");
	else if (ac > 6)
		ft_putstr("Too much arguments passed\n");
	if (ac != 5 && ac != 6)
		return (1);
	phil->nb_philosophers = ft_atoi(av[1]);
	phil->time_to_die = ft_atoi(av[2]);
	phil->time_to_eat = ft_atoi(av[3]);
	phil->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		phil->nb_must_eat = ft_atoi(av[5]);
	else
		phil->nb_must_eat = -1;
	if (phil->nb_must_eat < -2 || phil->nb_philosophers < 1 ||
		phil->time_to_eat < 1 || phil->time_to_die < 1 ||
		phil->time_to_sleep < 1)
	{
		ft_putstr("Arguments passed are wrong, verify them and retry\n");
		return (1);
	}
	if (malloc_process_sems(phil))
		return (1);
	return (0);
}
