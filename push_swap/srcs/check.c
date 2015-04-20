/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 21:26:02 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/19 17:53:03 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_a(t_stack *a)
{
	while (a)
	{
		if (a->prev && a->data > a->prev->data)
			return (0);
		a = a->prev;
	}
	return (1);
}

int			check_rev_a(t_stack *a, int size)
{
	int		count;

	count = 0;
	while (a)
	{
		if (a->prev && a->data > a->prev->data)
			count++;
		a = a->prev;
	}
	if (count > size / 2)
		return (1);
	return (0);
}

int			check_last(t_stack *a)
{
	while (a)
	{
		if (a->prev && a->data > a->prev->data)
			break ;
		a = a->prev;
	}
	if (a && !a->prev)
		return (1);
	return (0);
}

int			check_first(t_stack **a, t_env *env)
{
	int		count;

	count = 0;
	if ((*a)->data == MAX_S && (*a)->prev && (*a)->prev->data == MIN_S)
		choose_action(a, NULL, env, 5);
	return (count);
}

void		check_end(t_stack **a, t_env *env)
{
	t_stack	*temp;

	temp = *a;
	if (SIZE == 3 && temp->prev->data == MAX_S && temp->data == MIN_S)
	{
		choose_action(a, NULL, env, 7);
		choose_action(a, NULL, env, 1);
	}
	while (temp && temp->prev && temp->data < temp->prev->data)
		temp = temp->prev;
	if (SIZE > 2 && temp->prev && !temp->prev->prev)
	{
		if (temp->data > temp->prev->data)
		{
			!check_a(*a) ? choose_action(a, NULL, env, 7) : ft_putstr("");
			!check_a(*a) ? choose_action(a, NULL, env, 7) : ft_putstr("");
			!check_a(*a) ? choose_action(a, NULL, env, 1) : ft_putstr("");
			!check_a(*a) ? choose_action(a, NULL, env, 5) : ft_putstr("");
			!check_a(*a) ? choose_action(a, NULL, env, 5) : ft_putstr("");
		}
	}
}
