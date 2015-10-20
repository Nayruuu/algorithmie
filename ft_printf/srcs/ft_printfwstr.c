/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfwstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 13:03:33 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/17 15:33:04 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_wstr_length(unsigned int *s, t_env env)
{
	int			i;
	int			length;

	i = 0;
	length = 0;
	while (s[i])
	{
		length += get_wchar_length(s[i]);
		i++;
	}
	if (env.is_prec && (int)env.precision < length)
		return (env.precision);
	else
		return (length);
}

static int		get_real_length(unsigned int *s, int length)
{
	int			i;
	int			t_length;

	i = 0;
	t_length = 0;
	while (t_length < length && s[i])
	{
		if (t_length + get_wchar_length(s[i]) <= length)
			t_length += get_wchar_length(s[i]);
		else
			break ;
		i++;
	}
	return (t_length);
}

static int		print_wstr(unsigned int *s, int length)
{
	int			i;
	int			ret;
	int			t_length;

	i = 0;
	ret = 0;
	t_length = 0;
	while (t_length < length && s[i])
	{
		if (t_length + get_wchar_length(s[i]) <= length)
		{
			t_length += get_wchar_length(s[i]);
			ret += ft_printfwchar(s[i]);
		}
		else
			break ;
		i++;
	}
	return (ret);
}

static int		print_width(t_env env, int length)
{
	if ((env.attr & 0x08) == 0x08 && _WIDTH - length > 0)
		return (ft_printfnchar('0', _WIDTH - length));
	else if ((int)(_WIDTH - length) > 0)
		return (ft_printfnchar(' ', _WIDTH - length));
	else
		return (0);
}

int				ft_printfwstr(unsigned int *s, t_env env)
{
	int			ret;
	int			length;

	ret = 0;
	if (s)
	{
		length = get_real_length(s, get_wstr_length(s, env));
		if ((_ATTR & 0x04) != 0x04)
		{
			ret += print_width(env, length);
			ret += print_wstr(s, length);
		}
		else
		{
			ret += print_wstr(s, length);
			ret += print_width(env, length);
		}
		return (ret);
	}
	else
		return (ft_printfstr("(null)", env));
}
