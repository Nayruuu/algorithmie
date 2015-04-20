/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:35:19 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/04 14:04:28 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			check_begin(const char *param, int *neg)
{
	int				i;

	i = 0;
	while (param[i] == '0' || param[i] == '-' || param[i] == '+')
	{
		while (param[i] == '-' || param[i] == '+')
		{
			if (param[i] == '-')
				*neg = (*neg + 1) % 2;
			i++;
		}
		while (param[i] == '0')
			i++;
	}
	return (i);
}

int					ft_atoi(const char *str)
{
	int				i;
	int				neg;
	int				size;
	long int		value;

	neg = 0;
	size = 0;
	value = 0;
	i = check_begin(str, &neg);
	if (ft_strlen(str) - i > 10)
		return (0);
	if (!str[i] && str[i - 1] == '0')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = (value * 10) + (str[i] - 48);
		size += str[i];
		i++;
	}
	if ((!neg && size > 476) || (neg && size > 477))
		return (0);
	if (value > 0 && neg == 1)
		value = -value;
	return (value);
}
