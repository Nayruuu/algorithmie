/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 16:50:02 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/15 13:43:28 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			case_star(t_env *env, va_list ap)
{
	if ((PREC = va_arg(ap, int)) < 0)
	{
		IS_PREC--;
		PREC = 0;
	}
	return (1);
}

int					get_prec(const char *format, t_env *env, va_list ap)
{
	int				i;
	unsigned int	value;

	i = 0;
	value = 0;
	if (format[0] != '.')
		return (0);
	else
	{
		IS_PREC = 1;
		i++;
	}
	if (format[i] == '*')
		return (i + case_star(env, ap));
	while (format[i] >= '0' && format[i] <= '9')
	{
		value = (value * 10) + (format[i] - '0');
		i++;
	}
	PREC = value;
	return (i);
}
