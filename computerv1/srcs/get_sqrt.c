/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sqrt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 16:01:12 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/24 16:30:17 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static int	get_first_x(double nbr)
{
	int		x;

	x = 1;
	while (x * x < nbr)
		x++;
	return (x - 1);
}

double		get_sqrt(double nbr)
{
	int		i;
	double	x;

	i = 0;
	x = get_first_x(nbr);
	if (x * x != nbr)
	{
		while (i < 20)
		{
			x = (x + nbr / x) / 2;
			i++;
		}
	}
	return (x);
}
