/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:06:54 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/19 18:10:49 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_end(int count, int actions[8], int opt)
{
	if (count && (opt & 0x02))
	{
		ft_putstr(opt & 0x04 ? "" : "\n");
		ft_putstr("Number of actions : ");
		ft_putnbr(count);
		ft_putstr(opt & 0x01 ? "\033[1;31m\nSA : \033[37m" : "\nSA : ");
		ft_putnbr(actions[0]);
		ft_putstr(opt & 0x01 ? "\033[0;31m  SB : \033[37m" : "  SB : ");
		ft_putnbr(actions[1]);
		ft_putstr(opt & 0x01 ? "\033[1;32m  PA : \033[37m" : "  PA : ");
		ft_putnbr(actions[2]);
		ft_putstr(opt & 0x01 ? "\033[0;32m  PB : \033[37m" : "  PB : ");
		ft_putnbr(actions[3]);
		ft_putstr(opt & 0x01 ? "\033[1;33m  RA : \033[37m" : "  RA : ");
		ft_putnbr(actions[4]);
		ft_putstr(opt & 0x01 ? "\033[0;33m  RB : \033[37m" : "  RB : ");
		ft_putnbr(actions[5]);
		ft_putstr(opt & 0x01 ? "\033[1;34m  RRA : \033[37m" : "  RRA : ");
		ft_putnbr(actions[6]);
		ft_putstr(opt & 0x01 ? "\033[0;34m  RRB : \033[37m" : "  RRB : ");
		ft_putnbr(actions[7]);
	}
	else if (!count)
		ft_putstr("Stack already sorted");
	ft_putendl("");
}

static int	init(t_stack **a, t_stack **b, t_env *env)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if ((*a)->data != MIN_S && (*a)->prev && (*a)->prev->data != MIN_S)
	{
		while ((*a)->data != MAX_S)
		{
			choose_action(a, NULL, env, 5);
			count++;
		}
		choose_action(a, b, env, 4);
		while (count--)
			choose_action(a, NULL, env, 7);
		choose_action(a, b, env, 3);
	}
	while (*a)
		choose_action(a, b, env, 4);
	while (*b)
	{
		choose_action(NULL, b, env, 8);
		choose_action(a, b, env, 3);
	}
	return (i);
}

static void	algorithm2(t_stack **a, t_stack **b, t_env *env)
{
	if ((*a)->prev && (*a)->prev->data == MIN_S)
		choose_action(a, b, env, 1);
	if (check_last(*a))
		choose_action(a, b, env, 7);
	if (!check_a(*a))
	{
		if ((*a)->data == MIN_S)
			choose_action(a, b, env, 4);
		while ((*a)->data == MIN_S + 1)
		{
			MIN_S = (*a)->data;
			choose_action(a, b, env, 4);
		}
		MIN_S = get_min(*a);
	}
}

void		algorithm(t_stack *a, t_env *env)
{
	t_stack	*b;

	b = NULL;
	check_end(&a, env);
	check_rev_a(a, SIZE) ? init(&a, &b, env) : check_first(&a, env);
	while (!check_a(a))
	{
		while (!check_a(a))
		{
			algorithm2(&a, &b, env);
			if (!check_a(a) && a->prev && a->prev->data == MIN_S)
				choose_action(&a, &b, env, 1);
			if (!check_a(a) && check_position(a, MIN_S) < SIZE / 2)
				while (a->data != MIN_S && !check_a(a))
					choose_action(&a, &b, env, 5);
			else
				while (!check_a(a) && a->data != MIN_S)
					choose_action(&a, &b, env, 7);
		}
		while (b)
			choose_action(&a, &b, env, 3);
	}
	if (!(OPTS & 0x04) && (OPTS & 0x02))
		print_all(&a, &b);
	print_end(COUNT, ACTIONS, OPTS);
}
