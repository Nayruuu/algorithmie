# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_bzero.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/16 11:37:06 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 15:14:46 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_bzero(void *b, size_t len);

global		_ft_bzero
extern		_ft_memset

section .text

_ft_bzero:
			mov rax, rsi		;stock len in register
			mov rsi, 0			;init var in 2nd arg
			mov rdx, rax		;stock len_reg in third arg
			call _ft_memset
			ret
