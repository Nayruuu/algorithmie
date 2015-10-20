/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_attr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 16:18:04 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/15 15:49:32 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				get_attr(const char *format, t_env *env)
{
	int			i;

	i = 0;
	while (ft_strchr("#0-+ ", format[i]) && format[i])
	{
		if (format[i] == '#')
			ATTR |= 0x10;
		else if (format[i] == '0' && (ATTR & 0x04) != 0x04)
			ATTR |= 0x08;
		else if (format[i] == '-')
		{
			ATTR &= 0x17;
			ATTR |= 0x04;
		}
		else if (format[i] == ' ' && (ATTR & 0x01) != 0x01)
			ATTR |= 0x02;
		else if (format[i] == '+')
		{
			ATTR &= 0x1D;
			ATTR |= 0x01;
		}
		i++;
	}
	return (i);
}
