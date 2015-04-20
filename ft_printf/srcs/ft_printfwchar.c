/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 12:53:03 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/14 18:23:54 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

static int			write_wchar(wchar_t c, char *new_c)
{
	int				ret;

	ret = 0;
	if (c < 0x80)
		ret += ft_printfchar(new_c[0], 0);
	else if (c < 0x0800)
		ret += ft_printfchar(new_c[0], 0) + ft_printfchar(new_c[1], 0);
	else if (c < 0x010000)
	{
		ret += ft_printfchar(new_c[0], 0) + ft_printfchar(new_c[1], 0);
		ret += ft_printfchar(new_c[2], 0);
	}
	else if (c < 0x110000)
	{
		ret += ft_printfchar(new_c[0], 0) + ft_printfchar(new_c[1], 0);
		ret += ft_printfchar(new_c[2], 0) + ft_printfchar(new_c[3], 0);
	}
	else
		return (-1);
	return (ret);
}

void				init_tab(char *tab)
{
	tab[0] = '\0';
	tab[1] = '\0';
	tab[2] = '\0';
	tab[3] = '\0';
}

int					ft_printfwchar(wchar_t c)
{
	char			new_c[4];

	init_tab(new_c);
	if (c < 0x80)
		new_c[0] = (char)c;
	else if (c < 0x0800)
	{
		new_c[0] = ((c >> 6) & 0x1F) | 0xC0;
		new_c[1] = ((c >> 0) & 0x3F) | 0x80;
	}
	else if (c < 0x010000)
	{
		new_c[0] = ((c >> 12) & 0x0F) | 0xE0;
		new_c[1] = ((c >> 6) & 0x3F) | 0x80;
		new_c[2] = ((c >> 0) & 0x3F) | 0x80;
	}
	else if (c < 0x110000)
	{
		new_c[0] = ((c >> 18) & 0x07) | 0xF0;
		new_c[1] = ((c >> 12) & 0x3F) | 0x80;
		new_c[2] = ((c >> 6) & 0x3F) | 0x80;
		new_c[3] = ((c >> 0) & 0x3F) | 0x80;
	}
	return (write_wchar(c, new_c));
}
