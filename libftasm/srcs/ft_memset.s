# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memset.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/16 11:04:20 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 15:17:45 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_memset(void *b, int c, size_t len);

global _ft_memset

section .text

_ft_memset:
			push rdi		;void	*b
			mov rax, rsi	;int	c
			mov rcx, rdx	;size_t len
			cld				;incrementing
			rep stosb		;len--, b++;
			pop rax			;return b
			ret
