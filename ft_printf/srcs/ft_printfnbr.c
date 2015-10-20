/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:20:49 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/15 17:18:16 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printfnbr(t_lli n)
{
	if (n < 0)
		n = -n;
	if (n < 10)
	{
		ft_printfchar(n + '0', 0);
	}
	else
	{
		ft_printfnbr(n / 10);
		ft_printfnbr(n % 10);
	}
	return (1);
}
