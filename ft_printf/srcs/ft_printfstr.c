/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 16:32:50 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/15 16:59:25 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_str_length(char *str, t_env env)
{
	int		length;

	length = ft_strlen(str);
	if (env.is_prec && (int)env.precision < length)
		return (env.precision);
	else
		return (length);
}

static int	print_width(t_env env, int length)
{
	if ((env.attr & 0x08) == 0x08 && _WIDTH - length > 0)
		return (ft_printfnchar('0', env.width - length));
	else if (_WIDTH - length > 0)
		return (ft_printfnchar(' ', env.width - length));
	else
		return (0);
}

int			ft_printfstr(char *str, t_env env)
{
	int		i;
	int		ret;
	int		length;

	if (str)
	{
		i = -1;
		ret = 0;
		length = get_str_length(str, env);
		if ((_ATTR & 0x04) != 0x04)
		{
			ret += print_width(env, length);
			while (++i < length && str[i])
				ft_printfchar(str[i], 0);
		}
		else
		{
			while (++i < length && str[i])
				ft_printfchar(str[i], 0);
			ret += print_width(env, length);
		}
		return (ret + length);
	}
	else
		return (ft_printfstr("(null)", env));
}
