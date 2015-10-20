/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 17:25:01 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/17 14:56:51 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			get_real_length(t_lli arg, t_env env)
{
	int				length;

	length = 0;
	if (_IS_PREC && _PREC > _LENGTH)
		length = _PREC;
	else
		length = _LENGTH;
	if (_IS_PREC && !_PREC && !arg)
		length--;
	length += 2;
	return (length);
}

static int			print_changes(t_lli arg, int length, t_env env)
{
	int				ret;

	ret = 0;
	ft_printfchar('0', 0);
	ft_printfchar('x', 0);
	if (_IS_PREC && _PREC > _LENGTH)
		ft_printfnchar('0', _PREC - _LENGTH);
	else if ((_ATTR & 0x08) == 0x08 && !_IS_PREC && _WIDTH > length)
		ret = ft_printfnchar('0', _WIDTH - length);
	if (!(_IS_PREC && !_PREC && !arg))
		ft_printfbase(arg, 16);
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

int					ft_printfptr(va_list ap, t_env env)
{
	int				ret;
	int				length;
	t_uli			t_arg;

	ret = 0;
	t_arg = (t_uli)va_arg(ap, void*);
	_LENGTH = G_UL(t_arg, 16);
	length = get_real_length(t_arg, env);
	if ((_ATTR & 0x04) != 0x04)
	{
		ret += print_width(length, env);
		ret += print_changes(t_arg, length, env);
	}
	else
	{
		ret += print_changes(t_arg, length, env);
		ret += print_width(length, env);
	}
	return (ret + length);
}
