/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discr_sup_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 17:16:06 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/24 20:34:49 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static int	get_max_div(double nbr1, double nbr2)
{
	int		temp1;
	int		temp2;
	int		temp3;

	if (nbr1 == (int)nbr1 && nbr2 == (int)nbr2)
	{
		nbr1 = (int)nbr1 < 0 ? -nbr1 : nbr1;
		nbr2 = (int)nbr2 < 0 ? -nbr2 : nbr2;
		temp1 = MAX((int)nbr1, (int)nbr2);
		temp2 = MIN((int)nbr1, (int)nbr2);
		while (temp2 > 0 && temp1 - temp2 > 0)
		{
			temp3 = temp1 - temp2;
			temp1 = MAX(temp2, temp3);
			temp2 = MIN(temp2, temp3);
		}
		if (temp2 - temp1 == 0)
			return (temp2);
		else
			return (1);
	}
	return (0);
}

static void	get_secondx(t_env poly, double sqrt)
{
	double	x2;
	int		pgcd2;

	pgcd2 = get_max_div(-poly.coeff[2] - sqrt, 2 * poly.coeff[3]);
	ft_putstr("  x2 = ");
	if (pgcd2 == 0)
	{
		x2 = (-poly.coeff[2] - sqrt) / (2 * poly.coeff[3]);
		x2 = get_double(x2, PREC >= 2 ? PREC : 2);
		aff_d(x2, PREC >= 2 ? PREC : 2);
	}
	else
	{
		aff_d(-(poly.coeff[2] - sqrt) / pgcd2, 0);
		if ((int)2 * poly.coeff[3] / pgcd2 != 1 &&
			(int)2 * poly.coeff[3] / pgcd2 != -1)
		{
			ft_putstr(" / ");
			aff_d(2 * poly.coeff[3] / pgcd2, 0);
		}
	}
	ft_putendl("");
}

void		discr_sup_0(t_env poly, double discr)
{
	double	x1;
	double	sqrt;
	int		pgcd1;

	sqrt = get_sqrt(discr);
	pgcd1 = get_max_div(-poly.coeff[2] + sqrt, 2 * poly.coeff[3]);
	ft_putendl("Solutions are :");
	ft_putstr("x1 = ");
	if (pgcd1 == 0)
	{
		x1 = (-poly.coeff[2] + sqrt) / (2 * poly.coeff[3]);
		x1 = get_double(x1, PREC >= 2 ? PREC : 2);
		aff_d(x1, PREC >= 2 ? PREC : 2);
	}
	else
	{
		aff_d(-(poly.coeff[2] + sqrt) / pgcd1, 0);
		if ((int)2 * poly.coeff[3] / pgcd1 != 1 &&
			(int)2 * poly.coeff[3] / pgcd1 != -1)
		{
			ft_putstr(" / ");
			aff_d(2 * poly.coeff[3] / pgcd1, 0);
		}
	}
	get_secondx(poly, sqrt);
}
