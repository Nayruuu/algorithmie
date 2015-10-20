/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:12:22 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/10 19:15:24 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	select_base(char c)
{
	if (c == 'u' || c == 'U' || c == 'd' || c == 'D' || c == 'i')
		return (10);
	else if (c == 'o' || c == 'O')
		return (8);
	else if (c == 'x')
		return (16);
	else if (c == 'X')
		return (17);
	else
		return (2);
}
