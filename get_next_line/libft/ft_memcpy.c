/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:45:15 by sde-toda          #+#    #+#             */
/*   Updated: 2014/11/21 21:46:54 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	int					i;
	unsigned char		*newd;
	unsigned const char	*news;

	newd = (unsigned char *)dst;
	news = (unsigned char *)src;
	while (n--)
	{
		newd[i] = news[i];
		i++;
	}
	return (dst);
}
