/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 12:44:15 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/04 16:17:01 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_min(t_stack *a)
{
	int		min;

	min = 214783647;
	while (a)
	{
		min = MIN(a->data, min);
		a = a->prev;
	}
	return (min);
}

int			check_position(t_stack *a, int min)
{
	int		pos;

	pos = 0;
	while (a->data != min)
	{
		a = a->prev;
		pos++;
	}
	return (pos);
}
