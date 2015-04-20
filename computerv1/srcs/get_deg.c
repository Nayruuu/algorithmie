/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_deg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 11:28:07 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/23 18:14:56 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static int	get_info(char *str, int *deg)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '+' && str[i] != '-' && str[i] != '=')
	{
		while (str[i] == '^')
			i++;
		if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i]))
			{
				*deg = *deg * 10 + (str[i] - '0');
				i++;
			}
		}
		if ((str[i] == '.' || str[i] == ',') && ft_isdigit(str[i + 1]) &&
			str[i + 1] - '0' != 0)
			exit (!ft_putendl_fd(ERROR_2, 2));
		i = str[i] && !ft_strchr("+-=", str[i]) ? i + 1 : i;
	}
	return (i);
}

static int	get_coeff(char *str, int i)
{
	int		j;

	j = i;
	while (j >= 0 && str[j] != '+' && str[j] != '-' && str[j] != '=')
	{
		if (ft_isdigit(str[j]) && str[j] - '0' > 0)
			return (1);
		j--;
	}
	if (j - 1 >= 0 && ft_strchr("+-=", str[j - 1]))
		return (1);
	return (0);
}

int			get_deg(char *str)
{
	int		i;
	int		coeff;
	int		deg;
	int		temp;
	int		power;

	i = -1;
	deg = -1;
	power = 0;
	while (str[++i])
	{
		if (str[i] == 'X' || str[i] == 'x')
		{
			temp = 0;
			coeff = get_coeff(str, i);
			i += get_info(&str[i], &temp);
			if (temp > deg && temp <= 2 && coeff)
				deg = temp;
			if (temp > 2 && coeff)
				exit (!ft_putendl_fd(ERROR_1, 2));
		}
	}
	return (deg);
}
