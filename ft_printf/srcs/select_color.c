/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 22:59:42 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/22 23:40:40 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char g_color[12][8] = {"{eoc}", "{high}", "{under}", "{blink}", "{black}",
	"{red}", "{green}", "{yellow}", "{blue}", "{purple}", "{cyan}",
	"{white}"};

char g_mac[12][8] = {EOC, HIG, UND, BLI, BLA, RED, GRE, YEL, BLU, PUR, CYA,
	WHI};

int		cmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (1);
		if (s1[i] == '\0' || s2[i] == '\0')
			break;
		i++;
	}
	return (0);
}

int		select_color(const char *format, int *ret)
{
	int	j;
	int	i;
	int	verif;

	j = 0;
	i = 0;
	verif = 0;
	if (format[0] == '{')
	{
		while (cmp(format, g_color[j], ft_strlen(g_color[j])) && j < 12)
			j++;
		verif = 1;
	}
	if (j < 12 && verif)
	{
		while (g_mac[j][i])
			ft_printfchar(g_mac[j][i++], 0);
		*ret += ft_strlen(g_color[j]);
		return (ft_strlen(g_color[j]));
	}
	else 
		return (0);
}
