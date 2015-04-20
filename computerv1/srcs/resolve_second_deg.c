/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_second_deg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 14:51:04 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/24 20:13:51 by sde-toda         ###   ########.fr       */
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

static void	discr_equal_0(t_env poly)
{
	int		pgcd;
	double	solution;

	pgcd = get_max_div(poly.coeff[2], 2 * poly.coeff[3]);
	ft_putendl("Solution is :");
	ft_putstr("x1 = x2 = ");
	if (pgcd == 0)
	{
		solution = -(poly.coeff[2]) / (2 * poly.coeff[3]);
		solution = get_double(solution, PREC > 2 ? PREC : 2);
		aff_d(solution, PREC > 2 ? PREC : 2);
	}
	else if (poly.coeff[0] + poly.coeff[1] && poly.coeff[2])
	{
		aff_d(-poly.coeff[2] / pgcd, 0);
		if ((int)2 * poly.coeff[3] / pgcd != 1 &&
			(int)2 * poly.coeff[3] / pgcd != -1)
		{
			ft_putstr(" / ");
			aff_d(2 * poly.coeff[3] / pgcd, 0);
		}
	}
	else
		ft_putstr("0");
	ft_putendl("");
}

void		resolve_second_deg(t_env poly)
{
	double	discr;

	discr = (poly.coeff[2] * poly.coeff[2]);
	discr = discr - (4 * (poly.coeff[0] + poly.coeff[1]) * poly.coeff[3]);
	if (discr == 0)
		discr_equal_0(poly);
	else if (discr > 0)
		discr_sup_0(poly, discr);
	else if (discr < 0)
		discr_inf_0(poly, discr);
}
