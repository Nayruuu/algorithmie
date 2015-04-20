/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 11:14:53 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/24 18:28:20 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H

# include <math.h>
# include <stdio.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"

# define ERROR (-1)
# define ERROR_1 "Polynome's degree is > 2, I'm too poor to solve it."
# define ERROR_2 "Degrees must be anly integers, I can't solve it."
# define ERROR_3 "Polynome's degree is < 0, I'm too poor to solve it."
# define ERROR_4 "Something's wrong in your formula."
# define ERROR_5 "usage: computor = \"a * x ^ 2 + b * x ^ 1 + c * x ^ 0 + d\""

# define PREC poly.precision
# define COEFF poly->coeff
# define CST poly->coeff[0]
# define COEFF_0 poly->coeff[1]
# define COEFF_1 poly->coeff[2]
# define COEFF_2 poly->coeff[3]
# define MAX(a, b) (a) > (b) ? (a) : (b)
# define MIN(a, b) (a) < (b) ? (a) : (b)

typedef struct	s_env
{
	int			precision;
	double		deg;
	double		coeff[4];
}				t_env;

typedef struct	s_calc
{
	int			check;
	int			coeff;
	int			sign;
	double		nbr;
}				t_calc;

void			do_mlx(t_env poly);
double			ft_fabs(double a);
int				get_deg(char *str);
void			resolve(t_env poly);
char			*clear_str(char *str);
void			print_poly(t_env poly);
double			get_sqrt(double nbr);
void			aff_d(double nbr, int preci);
void			resolve_second_deg(t_env poly);
double			get_double(double nbr, int preci);
void			get_coeffs(t_env *poly, char *str);
void			discr_sup_0(t_env poly, double discr);
void			discr_inf_0(t_env poly, double discr);

#endif
