/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_poly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 22:50:38 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/24 17:30:30 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static void	print_coeffs(t_env poly, int coeff)
{
	int		i;
	int		is_here;

	i = -1;
	is_here = 0;
	while (++i < coeff)
	{
		if (poly.coeff[i])
			is_here = 1;
	}
	if (poly.coeff[coeff] != 0)
	{
		if (is_here)
			ft_putstr("+ ");
		if (poly.coeff[coeff] < 0)
			ft_putchar('(');
		aff_d(poly.coeff[coeff], poly.precision);
		if (poly.coeff[coeff] < 0)
			ft_putchar(')');
		ft_putstr(" * X^");
		ft_putnbr(coeff - 1);
		ft_putchar(' ');
	}
}

void		print_poly(t_env poly)
{
	int		i;

	i = 0;
	ft_putstr("Reduced form : ");
	if (poly.coeff[0] != 0)
	{
		if (poly.coeff[0] == '-')
			ft_putchar('-');
		aff_d(poly.coeff[0], poly.precision);
		ft_putchar(' ');
	}
	while (++i < 4)
		print_coeffs(poly, i);
	if (!poly.coeff[0] && !poly.coeff[1] && !poly.coeff[2] && !poly.coeff[3])
		ft_putstr("0 ");
	ft_putstr(" =  ");
	ft_putchar('0');
	ft_putendl("");
}
