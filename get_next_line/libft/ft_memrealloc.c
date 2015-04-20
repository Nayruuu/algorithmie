/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 23:34:33 by sde-toda          #+#    #+#             */
/*   Updated: 2014/11/24 13:48:56 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_memrealloc(char *ptr, size_t new_size)
{
	char	*new_ptr;

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (ptr);
	}
	else if (ptr && new_size)
	{
		new_ptr = (char*)malloc((new_size + 1) * sizeof(char));
		if (new_ptr)
		{
			ft_strcpy(new_ptr, ptr);
			free(ptr);
			return (new_ptr);
		}
	}
	return (NULL);
}
