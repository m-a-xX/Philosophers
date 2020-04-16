/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 06:01:43 by mavileo           #+#    #+#             */
/*   Updated: 2020/04/16 19:39:19 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_phil
{
	int				nb_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	int				index;
	int				end;
	int				*last_eat;
	pthread_t		*thread;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	inc_mutex;
	pthread_mutex_t	print_mutex;
	struct timeval	begin;
}				t_phil;

void			ft_putstr(char *s);
int				ft_atoi(char *str);
int				get_args(int ac, char **av, t_phil *phil);
t_phil			*create_struct_pointer();
void			print_struct(t_phil *phil);
void			free_struct(t_phil *phil);
void			ft_putnbr_long(long nb);
void			ft_putchar(char c);
double			get_time(t_phil *phil, struct timeval end);
void			declare_fork(t_phil *phil, int index);
void			declare_eat(t_phil *phil, int index);
void			declare_sleep(t_phil *phil, int index);
void			declare_think(t_phil *phil, int index);
void			declare_died(t_phil *phil, int index);

#endif
