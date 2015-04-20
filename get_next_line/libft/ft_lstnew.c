/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 21:08:24 by sde-toda          #+#    #+#             */
/*   Updated: 2014/11/10 10:56:10 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	if (new)
	{
		new->next = NULL;
		if (content)
			new->content_size = content_size;
		else
			new->content_size = 0;
		new->content = (void*)malloc(sizeof(void) * content_size);
		if (new->content)
		{
			if (content)
				new->content = ft_memcpy(new->content, content, content_size);
			else
				new->content = NULL;
		}
		return (new);
	}
	return (NULL);
}
