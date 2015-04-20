/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 21:52:28 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/19 18:19:20 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_begin(char *param, int *neg)
{
	int	i;

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

int		check_param(char *param)
{
	int	i;
	int	neg;
	int	size;

	neg = 0;
	size = 0;
	i = check_begin(param, &neg);
	if (ft_strlen(param) - i > 10)
		return (0);
	if (!param[i] && param[i - 1] == '0')
		return (1);
	if (!ft_isdigit(param[i]))
		return (0);
	while (param[++i])
	{
		if (!ft_isdigit(param[i]))
			return (0);
		size += param[i];
	}
	if ((!neg && size > 476) || (neg && size > 477))
		return (0);
	return (1);
}
