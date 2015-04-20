/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coeffs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 11:46:56 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/24 20:50:07 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"
#include <stdio.h>

static int	parse_number(char *str, double *nbr)
{
	int		i;
	int		j;

	i = 0;
	j = 10;
	if (ft_isdigit(str[0]))
	{
		while (str[i] && ft_isdigit(str[i]) && str[i] != '=')
		{
			*nbr = *nbr * 10 + (str[i] - '0');
			i++;
		}
		if (str[i] == '.' || str[i] == ',')
		{
			while (str[++i] && ft_isdigit(str[i]) && str[i] != '=')
			{
				*nbr = *nbr + (double)(str[i] - '0') / j;
				j *= 10;
			}
		}
	}
	return (i);
}

static int	get_coeff(char *str, int *coeff)
{
	int		i;
	int		x;
	int		power;

	x = 0;
	i = -1;
	power = 0;
	while (str[++i] != '+' && str[i] != '-' && str[i] && str[i] != '=')
	{
		if (str[i] == 'X' || str[i] == 'x')
			x = 1;
		if (x && str[i] == '^')
			power = 1;
		if (x && power != 2 && ft_isdigit(str[i]))
		{
			power = 2;
			*coeff = str[i] - '0';
		}
		if (!x && ft_isdigit(str[i]))
			exit (!ft_putendl_fd(ERROR_4, 2));
	}
	if (x && power < 2)
		*coeff = 1;
	return (i);
}

static void	get_right(t_env *poly, char *str)
{
	int		i;
	t_calc	c;

	i = 0;
	c.sign = 1;
	while (str[i])
	{
		c = (t_calc){0, -1, c.sign, 0};
		if (str[i - 1] == '+')
			c.sign = 1;
		if (str[i - 1] == '-')
			c.sign *= -1;
		if (ft_isdigit(str[i]) || str[i] == 'X' || str[i] == 'x')
		{
			c.check = 1;
			i += parse_number(&str[i], &c.nbr);
			if (ft_strchr("Xx", str[i]) && ft_strchr("+-=", str[i - 1]))
				c.nbr = 1;
			i += get_coeff(&str[i], &c.coeff);
		}
		if (c.check)
			COEFF[c.coeff + 1] = fma(-c.sign, c.nbr, COEFF[c.coeff + 1]);
		i = str[i] ? i + 1 : i;
	}
}

void		get_coeffs(t_env *poly, char *str)
{
	int		i;
	t_calc	c;

	i = 0;
	c.sign = 1;
	while (str[i] && str[i] != '=')
	{
		c = (t_calc){0, -1, c.sign, 0};
		if (str[i - 1] == '+')
			c.sign = 1;
		if (str[i - 1] == '-')
			c.sign *= -1;
		if (ft_isdigit(str[i]) || str[i] == 'X' || str[i] == 'x')
		{
			c.check = 1;
			i += parse_number(&str[i], &c.nbr);
			if ((str[i] == 'X' || str[i] == 'x') && ft_strchr("+-", str[i - 1]))
				c.nbr = 1;
			i += get_coeff(&str[i], &c.coeff);
		}
		if (c.check)
			COEFF[c.coeff + 1] = fma(c.sign, c.nbr, COEFF[c.coeff + 1]);
		i = str[i] && str[i] != '=' ? i + 1 : i;
	}
	get_right(poly, &str[i]);
}
