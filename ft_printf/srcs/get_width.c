/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 16:50:02 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/17 15:36:27 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int					get_width(const char *format, t_env *env, va_list ap)
{
	int				i;
	unsigned int	value;

	i = 0;
	value = 0;
	if (format[0] == '0')
		return (0);
	if (format[0] == '*')
	{
		if ((WIDTH = va_arg(ap, int)) < 0)
		{
			WIDTH = -WIDTH;
			get_attr("-", env);
		}
		return (1);
	}
	while (format[i] >= '0' && format[i] <= '9')
	{
		value = (value * 10) + (format[i] - '0');
		i++;
	}
	if (value)
		WIDTH = value;
	return (i);
}
