/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_convers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 00:57:56 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/21 20:46:24 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			get_real_length(char c, t_lli arg, t_env env)
{
	int				length;

	length = 0;
	if (_IS_PREC && _PREC > _LENGTH)
		length = _PREC;
	else
		length = _LENGTH;
	if (_IS_PREC && !_PREC && !arg)
		length--;
	if ((_ATTR & 0x02) == 0x02 && arg >= 0 && ft_strchr("diD", c))
		length++;
	if ((_ATTR & 0x01) == 0x01 && arg >= 0 && ft_strchr("diD", c))
		length++;
	if (arg < 0 && ft_strchr("diD", c))
		length++;
	if ((_ATTR & 0x10) == 0x10 && ft_strchr("oO", c) &&
		((arg && _PREC < _LENGTH) || (_IS_PREC && !arg && !_PREC)))
		length++;
	else if ((_ATTR & 0x10) == 0x10 && (c == 'x' || c == 'X') && arg)
		length += 2;
	return (length);
}

static void			print_oxo(char c, t_lli arg, t_env env)
{
	if ((_ATTR & 0x10) == 0x10 && ft_strchr("oO", c) &&
		((arg && _PREC < _LENGTH) || (_IS_PREC && !arg && !_PREC)))
		ft_printfchar('0', 0);
	else if ((_ATTR & 0x10) == 0x10 && c == 'x' && arg)
	{
		ft_printfchar('0', 0);
		ft_printfchar('x', 0);
	}
	else if ((_ATTR & 0x10) == 0x10 && c == 'X' && arg)
	{
		ft_printfchar('0', 0);
		ft_printfchar('X', 0);
	}
}

static int			print_changes(char c, t_lli arg, int length, t_env env)
{
	int				ret;

	ret = 0;
	if ((_ATTR & 0x02) == 0x02 && arg >= 0 && ft_strchr("diD", c))
		ft_printfchar(' ', 0);
	else if ((_ATTR & 0x01) == 0x01 && arg >= 0 && ft_strchr("diD", c))
		ft_printfchar('+', 0);
	else if (arg < 0 && (c == 'd' || c == 'i' || c == 'D'))
		ft_printfchar('-', 0);
	print_oxo(c, arg, env);
	if (_IS_PREC && _PREC > _LENGTH)
		ft_printfnchar('0', _PREC - _LENGTH);
	else if ((_ATTR & 0x08) == 0x08 && !_IS_PREC && _WIDTH > length)
		ret = ft_printfnchar('0', _WIDTH - length);
	if (!(_IS_PREC && !_PREC && !arg))
	{
		if (ft_strchr("diD", c) && (t_ulli)arg != -9223372036854775808ULL)
			ft_printfnbr(arg);
		else
			ft_printfbase(arg, SB(c));
	}
	return (ret);
}

static int			print_width(int length, t_env env)
{
	if (_WIDTH > length)
	{
		if ((_ATTR & 0x08) != 0x08)
			return (ft_printfnchar(' ', _WIDTH - length));
		else if ((_ATTR & 0x08) == 0x08 && _IS_PREC)
			return (ft_printfnchar(' ', _WIDTH - length));
		return (0);
	}
	else
		return (0);
}

int					select_convers(char c, va_list ap, t_env env)
{
	int				ret;
	t_lli			arg;
	int				length;
	union u_type	t_arg;

	ret = 0;
	t_arg = va_arg(ap, union u_type);
	arg = select_modif(c, t_arg, env);
	_LENGTH = (c == 'd' || c == 'i' || c == 'D') ?
		G_L(arg, 10) : G_UL(arg, SB(c));
	length = get_real_length(c, arg, env);
	if ((_ATTR & 0x04) != 0x04)
	{
		ret += print_width(length, env);
		ret += print_changes(c, arg, length, env);
	}
	else
	{
		ret += print_changes(c, arg, length, env);
		ret += print_width(length, env);
	}
	return (ret + length);
}
