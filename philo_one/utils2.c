/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 16:01:48 by mavileo           #+#    #+#             */
/*   Updated: 2020/04/15 17:04:46 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_putnbr_long(long nb)
{
	if (nb > 9)
		{ft_putnbr_long(nb / 10);
		ft_putnbr_long(nb % 10);}
	else 
		ft_putchar(nb + 48);
}


double	get_time(t_phil *phil, struct timeval end)
{
	double elapsed = ((end.tv_sec - phil->begin.tv_sec) * 1000000) + 
              ((end.tv_usec - phil->begin.tv_usec));
	return (elapsed / 1000);
}