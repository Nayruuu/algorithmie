/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 14:18:11 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/22 23:25:25 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <wchar.h>

# define ERROR -1

# define ATTR env->attr
# define WIDTH env->width
# define MODIF env->modifier
# define PREC env->precision
# define IS_PREC env->is_prec
# define LENGTH env->length

# define _ATTR env.attr
# define _WIDTH env.width
# define _MODIF env.modifier
# define _PREC env.precision
# define _IS_PREC env.is_prec
# define _LENGTH env.length

# define EOC "\033[0m"
# define HIG "\033[1m"
# define UND "\033[4m"
# define BLI "\033[5m"
# define BLA "\033[30m"
# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define PUR "\033[35m"
# define CYA "\033[36m"
# define WHI "\033[37m"

# define SB(c) select_base(c)
# define G_UL(n, base) get_ulength(n, base)
# define G_L(n, base) get_length(n, base)

/*
**			Renaming/
**						Renaiming Int Types
*/

typedef short int				t_si;
typedef intmax_t				t_imt;
typedef long int				t_li;
typedef uintmax_t				t_uimt;
typedef unsigned int			t_ui;
typedef long long int			t_lli;
typedef unsigned short int		t_usi;
typedef unsigned long int		t_uli;
typedef unsigned long long int	t_ulli;

/*
**			Renaiming/
**						Renaiming Char Types
*/

typedef signed char				t_sc;
typedef unsigned char			t_uc;

/*
**			Informations/
**						Struct & Functions
*/

union			u_type
{
	int			i;
	t_ui		ui;
	char		c;
	t_uc		uc;
	long int	li;
	t_uli		uli;
	short int	si;
	t_usi		usi;
	t_lli		lli;
	t_ulli		ulli;
	t_imt		imt;
	t_uimt		uimt;
	size_t		s;
	ssize_t		ss;
};

typedef struct	s_env
{
	t_usi		attr;
	int			width;
	t_ui		modifier;
	t_usi		is_prec;
	int			precision;
	int			length;
}				t_env;

void			init_env(t_env *env);
int				get_prec(const char *format, t_env *env, va_list ap);
int				get_attr(const char *format, t_env *env);
int				get_width(const char *format, t_env *env, va_list ap);
int				get_modif(const char *format, t_env *env);

/*
**			Misc/
**						Miscalleaneous
*/

int				select_base(char c);
t_lli			select_modif(char c, union u_type arg, t_env env);
int				select_color(const char *format, int *ret);
int				get_wchar_length(wchar_t c);
int				get_length(t_lli n, unsigned int base);
int				get_ulength(t_ulli n, unsigned int base);
char			*ft_strchr(const char *s, int c);
int				select_convers(char c, va_list ap, t_env env);
int				select_case(char c, va_list ap, t_env env, int ret);
int				ft_printf(const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);
int				ft_fprintf(int fd, const char *format, ...);
void			*ft_printfmemcpy(void *s1, const void *s2, size_t size);

/*
**			Printing/
**						Printing Functions
*/

void			ft_putchar(char c);
int				ft_printfchar(int c, int select, ...);
int				ft_printfnchar(int c, int n);
int				ft_printfwchar(wchar_t c);
int				ft_printfstr(char *str, t_env env);
int				ft_printfwstr(unsigned int *s, t_env env);
int				ft_printfnbr(long long int n);
int				ft_printfdate(unsigned long int date);
int				ft_printfbase(t_ulli n, t_ui base);
int				ft_printfptr(va_list ap, t_env env);
size_t			ft_strlen(char *str);

#endif
