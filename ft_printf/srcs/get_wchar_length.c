/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfwstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 13:03:33 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/17 15:30:55 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_wchar_length(wchar_t c)
{
	if (c < 0x80)
		return (1);
	else if (c < 0x0800)
		return (2);
	else if (c < 0x010000)
		return (3);
	else if (c < 0x110000)
		return (4);
	else
		return (0);
}
