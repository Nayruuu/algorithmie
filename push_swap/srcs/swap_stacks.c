/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 22:36:26 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/05 10:49:32 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		swap_stacks(t_stack **stack)
{
	t_stack		*temp;

	if (stack && *stack && (*stack)->prev)
	{
		temp = (*stack)->prev;
		(*stack)->prev = temp->prev;
		temp->prev = *stack;
		*stack = temp;
	}
}

void			swap_a(t_stack **a)
{
	swap_stacks(a);
}

void			swap_b(t_stack **b)
{
	swap_stacks(b);
}
