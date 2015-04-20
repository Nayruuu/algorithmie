/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 10:33:34 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/05 16:34:10 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			print_actions(int act, int count, int opt)
{
	if (count && !(opt & 0x04))
		ft_putchar(' ');
	if (act == 1)
		ft_putstr(opt & 0x01 ? "\033[1;31mSA" : "SA");
	else if (act == 2)
		ft_putstr(opt & 0x01 ? "\033[0;31mSB" : "SB");
	else if (act == 3)
		ft_putstr(opt & 0x01 ? "\033[1;32mPA" : "PA");
	else if (act == 4)
		ft_putstr(opt & 0x01 ? "\033[0;32mPB" : "PB");
	else if (act == 5)
		ft_putstr(opt & 0x01 ? "\033[1;33mRA" : "RA");
	else if (act == 6)
		ft_putstr(opt & 0x01 ? "\033[0;33mRB" : "RB");
	else if (act == 7)
		ft_putstr(opt & 0x01 ? "\033[1;34mRRA" : "RRA");
	else if (act == 8)
		ft_putstr(opt & 0x01 ? "\033[0;34mRRB" : "RRB");
}

void			print_all(t_stack **a, t_stack **b)
{
	ft_putendl("\na :");
	if (a)
		print_stack(*a);
	else
		ft_putendl("");
	ft_putendl("b :");
	if (b)
		print_stack(*b);
	else
		ft_putendl("");
	ft_putendl("");
}

void			choose_action(t_stack **a, t_stack **b, t_env *env, int act)
{
	if (act == 1)
		SA;
	else if (act == 2)
		SB;
	else if (act == 3)
		PA;
	else if (act == 4)
		PB;
	else if (act == 5)
		RA;
	else if (act == 6)
		RB;
	else if (act == 7)
		RRA;
	else if (act == 8)
		RRB;
	print_actions(act, COUNT, OPTS);
	ft_putstr("\033[0;37m");
	if (OPTS & 0x04)
		print_all(a, b);
	ACTIONS[act - 1]++;
	COUNT++;
}
