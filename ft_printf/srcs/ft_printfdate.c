/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfdate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:10:57 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/19 17:51:49 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <time.h>

const char		g_month[12][3] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
	"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

const char		g_day[7][3] = {"Thu", "Fri", "Sat", "Sun", "Mon", "Tue", "Wed"};

static int		get_day(t_uli real_s)
{
	if (real_s / 86400 >= 334)
		return (real_s / 86400 + 1 - 334);
	else if (real_s / 86400 >= 304)
		return (real_s / 86400 + 1 - 304);
	else if (real_s / 86400 >= 273)
		return (real_s / 86400 + 1 - 273);
	else if (real_s / 86400 >= 243)
		return (real_s / 86400 + 1 - 243);
	else if (real_s / 86400 >= 212)
		return (real_s / 86400 + 1 - 212);
	else if (real_s / 86400 >= 181)
		return (real_s / 86400 + 1 - 181);
	else if (real_s / 86400 >= 151)
		return (real_s / 86400 + 1 - 151);
	else if (real_s / 86400 >= 120)
		return (real_s / 86400 + 1 - 120);
	else if (real_s / 86400 >= 90)
		return (real_s / 86400 + 1 - 90);
	else if (real_s / 86400 >= 59)
		return (real_s / 86400 + 1 - 59);
	else if (real_s / 86400 >= 31)
		return (real_s / 86400 + 1 - 31);
	else
		return (real_s / 86400 + 1);
}

static int		get_month(t_uli real_s)
{
	if (real_s / 86400 >= 334)
		return (11);
	else if (real_s / 86400 >= 304)
		return (10);
	else if (real_s / 86400 >= 273)
		return (9);
	else if (real_s / 86400 >= 243)
		return (8);
	else if (real_s / 86400 >= 212)
		return (7);
	else if (real_s / 86400 >= 181)
		return (6);
	else if (real_s / 86400 >= 151)
		return (5);
	else if (real_s / 86400 >= 120)
		return (4);
	else if (real_s / 86400 >= 90)
		return (3);
	else if (real_s / 86400 >= 59)
		return (2);
	else if (real_s / 86400 >= 31)
		return (1);
	else
		return (0);
}

void			print_day_mon(t_ulli time1, t_ulli real_s)
{
	ft_printfchar(g_day[time1 / 86400 % 7][0], 0);
	ft_printfchar(g_day[time1 / 86400 % 7][1], 0);
	ft_printfchar(g_day[time1 / 86400 % 7][2], 0);
	ft_printfchar(' ', 0);
	ft_printfchar(g_month[get_month(real_s)][0], 0);
	ft_printfchar(g_month[get_month(real_s)][1], 0);
	ft_printfchar(g_month[get_month(real_s)][2], 0);
	ft_printfchar(' ', 0);
}

int				ft_printfdate(unsigned long int time1)
{
	t_uli		real_s;

	real_s = time1 % 31556926;
	print_day_mon(time1, real_s);
	if (get_day(real_s) < 10)
		ft_printfchar(' ', 0);
	ft_printfnbr(get_day(real_s));
	ft_printfchar(' ', 0);
	if (time1 / 3600 % 24 < 10)
		ft_printfchar('0', 0);
	ft_printfnbr(time1 / 3600 % 24);
	ft_printfchar(':', 0);
	if (time1 / 60 % 60 < 10)
		ft_printfchar('0', 0);
	ft_printfnbr(time1 / 60 % 60);
	ft_printfchar(':', 0);
	if (time1 % 60 < 10)
		ft_printfchar('0', 0);
	ft_printfnbr(time1 % 60);
	ft_printfchar(' ', 0);
	ft_printfnbr(time1 / 31556926 + 1970);
	return (24);
}
