/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_modif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 20:49:30 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/12 19:38:27 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_lli			select_lddi(char c, union u_type arg, t_env env)
{
	if (!env.modifier && c != 'D')
		return (arg.i);
	else if ((!env.modifier || env.modifier <= 4) && c == 'D')
		return (arg.li);
	else if ((env.modifier & 0x01) == 0x01 && c != 'D')
		return (arg.c);
	else if ((env.modifier & 0x02) == 0x02 && c != 'D')
		return (arg.si);
	else if ((env.modifier & 0x04) == 0x04 && c != 'D')
		return (arg.li);
	else if ((env.modifier & 0x08) == 0x08)
		return (arg.lli);
	else if ((env.modifier & 0x10) == 0x10)
		return (arg.imt);
	else if ((env.modifier & 0x20) == 0x20)
		return (arg.ss);
	else
		return (0);
}

static t_lli			select_lulo(union u_type arg, t_env env)
{
	if (!env.modifier || env.modifier <= 4)
		return (arg.uli);
	else if ((env.modifier & 0x08) == 0x08)
		return (arg.ulli);
	else if ((env.modifier & 0x10) == 0x10)
		return (arg.uimt);
	else if ((env.modifier & 0x20) == 0x20)
		return (arg.s);
	else
		return (0);
}

static t_lli			select_oxgxub(union u_type arg, t_env env)
{
	if (!env.modifier)
		return (arg.ui);
	else if ((env.modifier & 0x01) == 0x01)
		return (arg.uc);
	else if ((env.modifier & 0x02) == 0x02)
		return (arg.usi);
	else if ((env.modifier & 0x04) == 0x04)
		return (arg.uli);
	else if ((env.modifier & 0x08) == 0x08)
		return (arg.ulli);
	else if ((env.modifier & 0x10) == 0x10)
		return (arg.uimt);
	else if ((env.modifier & 0x20) == 0x20)
		return (arg.s);
	else
		return (0);
}

t_lli					select_modif(char c, union u_type arg, t_env env)
{
	if (ft_strchr("Ddi", c))
		return (select_lddi(c, arg, env));
	else if (ft_strchr("OU", c))
		return (select_lulo(arg, env));
	else if (ft_strchr("oxXub", c))
		return (select_oxgxub(arg, env));
	else
		return (0);
}
