/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discr_inf_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 17:43:29 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/24 17:50:25 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static void	get_secondx(t_env poly, double sqrt)
{
	double	x2;

	ft_putstr("  x2 = ");
	x2 = (-poly.coeff[2]) / (2 * poly.coeff[3]);
	x2 = get_double(x2, PREC > 2 ? PREC : 2);
	aff_d(x2, PREC > 2 ? PREC : 2);
	ft_putstr(" - ");
	x2 = (sqrt / (2 * poly.coeff[3]));
	x2 = get_double(x2, PREC > 2 ? PREC : 2);
	aff_d(x2, PREC > 2 ? PREC : 2);
	ft_putendl("i");
}

void		discr_inf_0(t_env poly, double discr)
{
	double	x1;
	double	sqrt;

	sqrt = get_sqrt(-discr);
	ft_putendl("Solutions are :");
	ft_putstr("x1 = ");
	x1 = (-poly.coeff[2]) / (2 * poly.coeff[3]);
	x1 = get_double(x1, PREC > 2 ? PREC : 2);
	aff_d(x1, PREC > 2 ? PREC : 2);
	ft_putstr(" + ");
	x1 = (sqrt / (2 * poly.coeff[3]));
	x1 = get_double(x1, PREC > 2 ? PREC : 2);
	aff_d(x1, PREC > 2 ? PREC : 2);
	ft_putstr("i");
	get_secondx(poly, sqrt);
}
