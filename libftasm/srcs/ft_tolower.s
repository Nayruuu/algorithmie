# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_tolower.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/16 18:22:59 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 15:02:29 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_tolower(int c);

global _ft_tolower

section .text

_ft_tolower:
			push rbp
			mov rbp, rsp
			pushf
			cmp rdi, 65
			jl no
			cmp rdi, 90
			jg no
			add rdi, 32
			mov rax, rdi
			popf
			leave
			ret

no:
	mov rax, rdi
	popf
	leave
	ret
