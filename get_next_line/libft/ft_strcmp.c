/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:35:52 by sde-toda          #+#    #+#             */
/*   Updated: 2014/11/10 10:57:38 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_strcmp(const char *s1, const char *s2)
{
	size_t					i;
	unsigned const char		*news1;
	unsigned const char		*news2;

	i = 0;
	news1 = (unsigned const char *)s1;
	news2 = (unsigned const char *)s2;
	while (news1[i] != '\0' && news2[i] != '\0' && news1[i] == news2[i])
	{
		i++;
	}
	return (news1[i] - news2[i]);
}
