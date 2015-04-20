/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 15:49:56 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/23 15:59:15 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static void		fill_str(char *str, char *new)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
		if (str[i] != ' ' && str[i] != '\t' && str[i])
			new[j++] = str[i++];
	}
	new[j] = '\0';
}

char			*clear_str(char *str)
{
	int			i;
	int			j;
	char		*new;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
		if (str[i] != ' ' && str[i] != '\t' && str[i])
		{
			j++;
			i++;
		}
	}
	new = (char*)ft_xmalloc(sizeof(char) * j);
	fill_str(str, new);
	return (new);
}
