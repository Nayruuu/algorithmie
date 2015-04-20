/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 22:29:30 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/02 22:35:04 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_stack(t_stack *stack, int nbr)
{
	while (stack)
	{
		if (stack->data == nbr)
			return (0);
		stack = stack->prev;
	}
	return (1);
}
