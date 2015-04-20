/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 20:49:30 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/22 23:25:31 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_env(const char *format, va_list ap, int *ret)
{
	int		i;
	int		j;
	int		t_ret;
	t_env	env;

	i = 0;
	init_env(&env);
	while (!ft_strchr("%sSpdDioOuUxXcCbnmk", format[i]) && format[i])
	{
		j = i;
		i += get_attr(&format[i], &env);
		i += get_width(&format[i], &env, ap);
		i += get_prec(&format[i], &env, ap);
		i += get_modif(&format[i], &env);
		if (j == i)
			break ;
	}
	if (!format[i])
		return (i + 1);
	t_ret = select_case(format[i], ap, env, *ret);
	if (t_ret == ERROR)
		return (ERROR);
	*ret += t_ret;
	return (i + 2);
}

static int	do_loop(const char *format, va_list ap)
{
	int		i;
	int		t_i;
	int		ret;

	i = 0;
	ret = 0;
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			i += select_color(&format[i], &ret);
			ret += ft_printfchar(format[i], 0);
			i++;
		}
		if (format[i] == '%')
		{
			if ((t_i = get_env(&format[i + 1], ap, &ret)) == ERROR)
				return (ERROR);
			i += t_i;
		}
	}
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	int		ret;
	va_list	ap;

	ret = 0;
	if (!format)
		return (ERROR);
	va_start(ap, format);
	ret += do_loop(format, ap);
	va_end(ap);
	if (ft_printfchar('\0', 1) == ERROR)
		return (ERROR);
	return (ret);
}

int			ft_sprintf(char *str, const char *format, ...)
{
	int		ret;
	char	*new;
	va_list	ap;

	ret = 0;
	if (!format)
		return (ERROR);
	va_start(ap, format);
	ret += do_loop(format, ap);
	va_end(ap);
	if (ft_printfchar('\0', 2, &new) == ERROR)
		return (ERROR);
	ft_printfmemcpy(str, new, ft_strlen(new) + 1);
	return (ret);
}

int			ft_fprintf(int fd, const char *format, ...)
{
	int		ret;
	va_list	ap;

	ret = 0;
	if (!format)
		return (ERROR);
	va_start(ap, format);
	ret += do_loop(format, ap);
	va_end(ap);
	if (ft_printfchar('\0', 3, fd) == ERROR)
		return (ERROR);
	return (ret);
}
