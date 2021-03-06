/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 23:08:53 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/15 17:17:24 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_length(t_lli n, unsigned int base)
{
	t_lli	mem;
	t_ui	nbr_chars;

	mem = n;
	nbr_chars = 0;
	if (base == 17)
		base--;
	if (n < 0)
		n = -n;
	if (n == 0)
		nbr_chars++;
	while (mem)
	{
		mem = mem - (mem % base);
		mem = mem / base;
		nbr_chars++;
	}
	return (nbr_chars);
}
