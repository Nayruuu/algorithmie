/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 11:58:19 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/05 16:26:48 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_putnbr(stack->data);
		if (stack->prev)
			ft_putchar(' ');
		stack = stack->prev;
	}
	ft_putendl("");
}
