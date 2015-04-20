/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_modif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 19:48:08 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/12 16:31:59 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_modif2(const char *format, t_env *env)
{
	if (ft_strchr("hlzj", format[0]))
	{
		if (format[0] == 'h' && format[1] == 'h' && MODIF <= 0x01)
			MODIF = (MODIF | 0x01) & 0x01;
		else if (format[0] == 'h' && format[1] != 'h' && MODIF <= 0x02)
			MODIF = (MODIF | 0x02) & 0x02;
		else if (format[0] == 'l' && format[1] != 'l' && MODIF <= 0x04)
			MODIF = (MODIF | 0x04) & 0x04;
		else if (format[0] == 'l' && format[1] == 'l' && MODIF <= 0x08)
			MODIF = (MODIF | 0x08) & 0x08;
		else if (format[0] == 'j' && MODIF <= 0x10)
			MODIF = (MODIF | 0x10) & 0x10;
		else if (format[0] == 'z')
			MODIF = (MODIF | 0x20) & 0x20;
	}
	if ((format[0] == 'l' && format[1] == 'l')
		|| (format[0] == 'h' && format[1] == 'h'))
		return (2);
	else if (ft_strchr("hljz", format[0]))
		return (1);
	return (0);
}

int				get_modif(const char *format, t_env *env)
{
	int			i;

	i = 0;
	if (ft_strchr("hljz", format[i]) && format[i])
		i += get_modif2(format, env);
	return (i);
}
