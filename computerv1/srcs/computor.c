/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 11:15:29 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/24 18:22:29 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"
#include <stdio.h>

static t_env	init_poly(char *str, int precision)
{
	t_env		poly;

	poly = (t_env){precision, 0, {0, 0, 0, 0}};
	poly.deg = get_deg(str);
	get_coeffs(&poly, str);
	return (poly);
}

static int		check_str(char *str)
{
	int			i;
	int			equal;

	i = -1;
	equal = 0;
	while (str[++i])
	{
		if (!ft_strchr(" -+0123456789.,*^xX=", str[i]))
		{
			ft_putstr_fd("Computor: illegal character -- ", 2);
			ft_putchar_fd(str[i], 2);
			ft_putendl_fd("\nusage: computor [-+0123456789.,*^xX=]", 2);
			return (ERROR);
		}
		if (!equal && str[i] == '=')
			equal = 1;
		else if (equal && str[i] == '=')
		{
			ft_putendl_fd("Computor: two equalities", 2);
			ft_putendl_fd(ERROR_5, 2);
			return (ERROR);
		}
	}
	return (0);
}

static int		check_options(char **argv, int *precision)
{
	int			i;

	i = 1;
	while (!ft_strncmp("-precision=", argv[i], 11))
	{
		if (ft_strlen(argv[i]) == 12 && ft_isdigit(argv[i][11]))
			*precision = argv[i][11] - '0';
		else
			*precision = !*precision ? 0 : *precision;
		i++;
	}
	if (i == 1)
		*precision = 0;
	return (i);
}

static void		get_real_deg(t_env *poly)
{
	if (COEFF_2)
		poly->deg = 2;
	else if (COEFF_1)
		poly->deg = 1;
	else if (COEFF_0)
		poly->deg = 0;
	else
		poly->deg = -1;
}

int				main(int argc, char **argv)
{
	int			i;
	char		*str;
	t_env		poly;

	poly.precision = 0;
	if (argc >= 2)
	{
		i = check_options(argv, &poly.precision);
		if (check_str(argv[i]) == ERROR)
			return (ERROR);
		str = clear_str(argv[i]);
		poly = init_poly(str, poly.precision);
		free (str);
		poly.coeff[0] = get_double(poly.coeff[0], poly.precision);
		poly.coeff[1] = get_double(poly.coeff[1], poly.precision);
		poly.coeff[2] = get_double(poly.coeff[2], poly.precision);
		poly.coeff[3] = get_double(poly.coeff[3], poly.precision);
		print_poly(poly);
		get_real_deg(&poly);
		resolve(poly);
		do_mlx(poly);
	}
	return (0);
}
