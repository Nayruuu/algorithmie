/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:29:50 by sde-toda          #+#    #+#             */
/*   Updated: 2014/11/10 10:56:17 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*new;

	new = (void*)malloc(size * sizeof(void));
	if (new)
	{
		ft_memset(new, 0, size);
		return (new);
	}
	else
		return (NULL);
}
