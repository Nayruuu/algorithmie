/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 15:26:02 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/24 20:12:16 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"
#include <stdio.h>

static int		get_max_div(t_env poly)
{
	int			temp1;
	int			temp2;
	int			temp3;

	if (poly.coeff[0] + poly.coeff[1] == (int)(poly.coeff[0] + poly.coeff[1]) &&
		poly.coeff[2] == (int)poly.coeff[2] && (poly.coeff[0] + poly.coeff[1]))
	{
		temp1 = MAX((int)ft_fabs(poly.coeff[0] + poly.coeff[1]),
				(int)ft_fabs(poly.coeff[2]));
		temp2 = MIN((int)ft_fabs(poly.coeff[0] + poly.coeff[1]),
				(int)ft_fabs(poly.coeff[2]));
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

static void		resolve_first_deg(t_env poly)
{
	int			pgcd;
	double		solution;

	pgcd = get_max_div(poly);
	ft_putendl("Solution is :");
	ft_putstr("x = ");
	if (pgcd == 0)
	{
		solution = -(poly.coeff[0] + poly.coeff[1]) / poly.coeff[2];
		solution = get_double(solution, poly.precision);
		aff_d(solution, solution ? poly.precision : 0);
	}
	else
	{
		aff_d(-(poly.coeff[0] + poly.coeff[1]) / pgcd, 0);
		if ((int)poly.coeff[2] / pgcd != 1 && (int)poly.coeff[2] / pgcd != -1)
		{
			ft_putstr(" / ");
			aff_d(poly.coeff[2] / pgcd, 0);
		}
	}
	ft_putendl("");
}

void			resolve(t_env poly)
{
	if (poly.deg == -1 && !poly.coeff[0])
		ft_putendl("0 equal 0.");
	else if (poly.deg == -1 && poly.coeff[0])
	{
		ft_putstr("Equation is impossible to resolve\n");
		aff_d(poly.coeff[0], poly.precision);
		ft_putendl(" can't equal 0.");
	}
	else if (poly.deg == 0 && poly.coeff[1] + poly.coeff[0] == 0)
	{
		ft_putstr("Solution is :\n");
		ft_putendl("x = |R");
	}
	else if (poly.deg == 0 && poly.coeff[1] + poly.coeff[0] != 0)
		ft_putendl("No solution.");
	else if (poly.deg == 1)
		resolve_first_deg(poly);
	else if (poly.deg == 2)
		resolve_second_deg(poly);
}
