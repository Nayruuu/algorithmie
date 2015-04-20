/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:10:00 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/05 10:49:11 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (a && b && *a)
	{
		temp = (*a)->prev;
		(*a)->prev = *b;
		*b = *a;
		*a = temp;
	}
}

void		push_a(t_stack **b, t_stack **a)
{
	t_stack	*temp;

	if (a && b && *b)
	{
		temp = (*b)->prev;
		(*b)->prev = *a;
		*a = *b;
		*b = temp;
	}
}
