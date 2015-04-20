/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:27:30 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/05 10:51:03 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack **stack)
{
	t_stack		*curs;
	t_stack		*temp;

	if (stack && *stack && (*stack)->prev)
	{
		curs = *stack;
		temp = *stack;
		while (curs->prev)
			curs = curs->prev;
		curs->prev = *stack;
		*stack = temp->prev;
		curs->prev->prev = NULL;
	}
}

static void	rev_rotate_stack(t_stack **stack)
{
	t_stack		*curs;
	t_stack		*temp;

	if (stack && *stack && (*stack)->prev)
	{
		curs = *stack;
		temp = *stack;
		while (curs->prev->prev)
			curs = curs->prev;
		*stack = curs->prev;
		(*stack)->prev = temp;
		curs->prev = NULL;
	}
}

void		rotate_stacks(t_stack **a, t_stack **b)
{
	if (a)
		rotate_stack(a);
	else
		rotate_stack(b);
}

void		rev_rotate_stacks(t_stack **a, t_stack **b)
{
	if (a)
		rev_rotate_stack(a);
	else
		rev_rotate_stack(b);
}
