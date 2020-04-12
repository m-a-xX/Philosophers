/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 05:50:29 by mavileo           #+#    #+#             */
/*   Updated: 2020/04/12 07:14:53 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int main(int ac, char **av)
{
	t_phil	*phil;

	if (!(phil = create_struct_pointer()))
		return (1);
	if (get_args(ac, av, phil))
		return (1);
	print_struct(phil);
	return (0);	
}
