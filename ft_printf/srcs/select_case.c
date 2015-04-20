/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 20:49:30 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/17 17:10:45 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				print_width(t_env env, int c)
{
	if ((_ATTR & 0x04) == 0x04)
	{
		if ((env.attr & 0x08) == 0x08 && (int)(_WIDTH - 1) > 0)
			return (ft_printfchar(c, 0) + ft_printfnchar('0', env.width - 1));
		else if ((int)(_WIDTH - 1) > 0)
			return (ft_printfchar(c, 0) + ft_printfnchar(' ', env.width - 1));
		else
			return (ft_printfchar(c, 0));
	}
	else
	{
		if ((env.attr & 0x08) == 0x08 && (int)(_WIDTH - 1) > 0)
			return (ft_printfnchar('0', env.width - 1) + ft_printfchar(c, 0));
		else if ((int)(_WIDTH - 1) > 0)
			return (ft_printfnchar(' ', env.width - 1) + ft_printfchar(c, 0));
		else
			return (ft_printfchar(c, 0));
	}
}

static int				get_wlength(wchar_t c)
{
	int					length;

	if (c < 0x80)
		length = 1;
	else if (c < 0x0800)
		length = 2;
	else if (c < 0x010000)
		length = 3;
	else if (c < 0x110000)
		length = 4;
	else
		return (-1);
	return (length);
}

static int				print_wchar(wchar_t c, t_env env)
{
	_WIDTH = (int)(_WIDTH - get_wlength(c) + 1);
	if ((_ATTR & 0x04) == 0x04)
	{
		if ((env.attr & 0x08) == 0x08 && (int)(_WIDTH - 1) > 0)
			return (ft_printfwchar(c) + ft_printfnchar('0', env.width - 1));
		else if ((int)(_WIDTH - 1) > 0)
			return (ft_printfwchar(c) + ft_printfnchar(' ', env.width - 1));
		else
			return (ft_printfwchar(c));
	}
	else
	{
		if ((env.attr & 0x08) == 0x08 && (int)(_WIDTH - 1) > 0)
			return (ft_printfnchar('0', env.width - 1) + ft_printfwchar(c));
		else if ((int)(_WIDTH - 1) > 0)
			return (ft_printfnchar(' ', env.width - 1) + ft_printfwchar(c));
		else
			return (ft_printfwchar(c));
	}
	return (ft_printfwchar(c));
}

int						select_case2(char c, va_list ap, t_env env, int ret)
{
	int					*n;

	if (c == 'n')
	{
		n = va_arg(ap, int *);
		*n = ret;
		return (0);
	}
	else if (c == 'm')
		return (ft_printfstr(strerror(errno), env));
	else if (c == 'k')
		return (ft_printfdate(va_arg(ap, unsigned long int)));
	else
		return (print_width(env, c));
}

int						select_case(char c, va_list ap, t_env env, int ret)
{
	if (c == '%')
		return (print_width(env, c));
	else if (c == 's' && (env.modifier & 0x04) != 0x04)
		return (ft_printfstr(va_arg(ap, char *), env));
	else if (c == 'S' || (c == 's' && (env.modifier & 0x04) == 0x04))
		return (ft_printfwstr(va_arg(ap, unsigned int *), env));
	else if (c == 'c' && (env.modifier & 0x04) != 0x04)
		return (print_width(env, va_arg(ap, int)));
	else if (c == 'C' || (c == 'c' && (env.modifier & 0x04) == 0x04))
		return (print_wchar(va_arg(ap, wchar_t), env));
	else if (ft_strchr("diDuUoOxXb", c))
		return (select_convers(c, ap, env));
	else if (c == 'p')
		return (ft_printfptr(ap, env));
	else
		return (select_case2(c, ap, env, ret));
}
