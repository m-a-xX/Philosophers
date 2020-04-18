/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 15:25:54 by mavileo           #+#    #+#             */
/*   Updated: 2020/04/18 15:26:45 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct	s_phil
{
	int				nb_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	int				dead;
	int				print_dead;
	pid_t			*pids;
	sem_t			*forks;
	sem_t			*inc_sem;
	sem_t			*print_sem;
	struct timeval	begin;
	struct timeval	*last_eat;
}				t_phil;

void			ft_putstr(char *s);
int				ft_atoi(char *str);
int				get_args(int ac, char **av, t_phil *phil);
t_phil			*create_struct_pointer();
void			print_struct(t_phil *phil);
void			free_struct(t_phil *phil);
void			ft_putnbr_long(long nb);
void			ft_putchar(char c);
double			get_time(struct timeval begin, struct timeval end);
int				declare_fork(t_phil *phil, int index);
int				declare_eat(t_phil *phil, int index);
int				declare_sleep(t_phil *phil, int index);
int				declare_think(t_phil *phil, int index);
int				declare_died(t_phil *phil, int index, struct timeval now);
int				check_dead(t_phil *phil);
void			unlock_sems(t_phil *phil);

#endif
