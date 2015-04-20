/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 22:02:13 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/04 14:04:42 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				stack_push(t_stack **stack, int data)
{
	t_stack	*new;
	t_stack	*curs;

	if (stack)
	{
		new = (t_stack*)ft_xmalloc(sizeof(t_stack));
		if (new)
		{
			new->data = data;
			new->prev = NULL;
			if (*stack)
			{
				curs = *stack;
				while (curs->prev)
					curs = curs->prev;
				curs->prev = new;
			}
			else
				*stack = new;
		}
	}
}
