/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftasm.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/15 14:51:04 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/18 14:04:18 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTASM_H
# define LIBFTASM_H

#include <stddef.h>

void		ft_bzero(void *b, size_t len);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dest, const void *src, size_t len);

char		*ft_strdup(const char *s);
char		*ft_strcat(char *s1, const char *s2);

int			ft_puts(const char *s);
void		ft_cat(int fd);

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_strlen(const char *s);

/*
**			BONUS
**
*/

int			ft_abs(int c);
void		ft_strclr(char *s);
char		*ft_strnew(size_t size);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strncpy(char *dst, const char *src, size_t n);
int			ft_min(int a, int b);
int			ft_max(int a, int b);

#endif
