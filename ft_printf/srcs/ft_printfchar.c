/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 16:40:34 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/21 21:54:15 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		do_other(int select, va_list ap, char *stock, int i)
{
	char		**str;

	if (select == 2)
	{
		str = va_arg(ap, char**);
		if (!(*str = (char*)malloc(sizeof(char) * i)))
			return (-1);
		stock[i] = '\0';
		while (i--)
			(*str)[i] = stock[i];
		va_end(ap);
	}
	else
	{
		stock[i] = '\0';
		if ((write(va_arg(ap, int), stock, i) == -1))
			return (-1);
		va_end(ap);
	}
	return (1);
}

int				ft_printfchar(int c, int select, ...)
{
	va_list		ap;
	static int	i = 0;
	static char stock[4000000];

	if (select == 2 || select == 3)
	{
		va_start(ap, select);
		return (do_other(select, ap, stock, i));
	}
	else if (select == 0)
	{
		stock[i] = c;
		i++;
	}
	else if (select == 1)
	{
		stock[i] = '\0';
		if ((write(1, stock, i) == -1))
		{
			write(2, "Writting Error", 14);
			return (-1);
		}
		i = 0;
	}
	return (1);
}
