/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 19:34:43 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/14 18:00:42 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	select_p_base(t_ulli n, t_ui base)
{
	if (base == 17 && n > 9)
		ft_printfchar(n - 10 + 'A', 0);
	else if (base == 16 && n > 9)
		ft_printfchar(n - 10 + 'a', 0);
	else if (n < base)
		ft_printfchar(n + '0', 0);
}

int			ft_printfbase(t_ulli n, t_ui base)
{
	if ((n < base && base != 17) || (n < base - 1))
		select_p_base(n, base);
	else
	{
		if (base == 17)
		{
			ft_printfbase(n / 16, base);
			ft_printfbase(n % 16, base);
		}
		else
		{
			ft_printfbase(n / base, base);
			ft_printfbase(n % base, base);
		}
	}
	return (1);
}
