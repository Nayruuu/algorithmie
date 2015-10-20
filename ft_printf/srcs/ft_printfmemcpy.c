/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfmemcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:45:15 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/21 21:46:37 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					*ft_printfmemcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*newd;
	unsigned const char	*news;

	newd = dst;
	news = src;
	while (n--)
		*newd++ = *news++;
	return (dst);
}
