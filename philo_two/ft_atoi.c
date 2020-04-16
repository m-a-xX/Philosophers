/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:51:43 by mavileo           #+#    #+#             */
/*   Updated: 2020/04/16 19:37:36 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_char_is_numeric(char c)
{
	if (c > '9' || c < '0')
		return (0);
	else
		return (1);
}

int		ft_c_is_alpha(char c)
{
	if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
		return (1);
	else
		return (0);
}

int		calcul(char *str, int count)
{
	int res;

	res = 0;
	while (ft_char_is_numeric(str[count]))
	{
		res = (res * 10) + (str[count] - 48);
		count++;
	}
	return (res);
}

int		ft_atoi(char *str)
{
	int count;
	int neg;
	int res;

	count = 0;
	neg = 0;
	res = 0;
	while (str[count] < 33)
		count++;
	if (ft_c_is_alpha(str[count]))
		return (0);
	while (str[count] == '+' || str[count] == '-')
	{
		if (str[count] == '-')
			neg++;
		count++;
	}
	if (ft_c_is_alpha(str[count]))
		return (0);
	res = calcul(str, count);
	if (neg % 2 != 0)
		res = res * (-1);
	return (res);
}
