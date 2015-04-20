# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strnew.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/17 20:15:19 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 20:23:33 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_strnew(size_t size);

global _ft_strnew
extern _malloc
extern _ft_bzero

section .text

_ft_strnew:
			push rdi
			add rdi, 1
			call _malloc
			cmp rax, 0
			je _fail
			mov rdi, rax
			pop rsi
			call _ft_bzero
			ret

_fail:
		mov rax, 0
		ret
