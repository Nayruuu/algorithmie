/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 23:08:43 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/24 20:40:50 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"
#include <stdio.h>

static int	get_preci(int n)
{
	int		i;

	i = 1;
	if (n)
	{
		while (n--)
			i *= 10;
	}
	return (i);
}

double		get_double(double nbr, int preci)
{
	double	x;
	double	new;

	if (!preci)
		nbr = (nbr > 0) ? nbr + 0.5 : nbr - 0.5;
	new = (int)nbr;
	if (preci)
	{
		x = fma(nbr, 1, -new);
		x = fma(x, get_preci(preci), 0);
		x = lrint(x);
		while (preci--)
			x /= 10;
		new += x;
	}
	return (new);
}

void		print_ratio(double x, int preci, int s)
{
	int		i;

	i = -1;
	while (++i < s - 1 && i < preci)
		ft_putchar('0');
	x = fma(x, get_preci(preci), 0);
	ft_putnbr(x < 0 ? lrint(-x) : lrint(x));
	if (x == 0)
	{
		i = -1;
		while (++i < preci - 1)
			ft_putchar('0');
	}
}

void		aff_d(double nbr, int preci)
{
	int		s;
	double	x;
	double	y;
	double	tmp;

	s = 0;
	y = (int)nbr;
	if (nbr < 0 && !y)
		ft_putchar('-');
	ft_putnbr(y);
	if (preci)
	{
		ft_putchar('.');
		x = fma(nbr, 1, -y);
		tmp = x;
		while (ft_fabs(tmp) > 0 && ft_fabs(tmp) < 0.99)
		{
			tmp *= 10;
			s++;
		}
		print_ratio(x, preci, s);
	}
}
