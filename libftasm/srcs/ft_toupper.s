# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_toupper.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/16 18:17:24 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 15:02:57 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_toupper(int c);

global _ft_toupper

section .text

_ft_toupper:
			push rbp
			mov rbp, rsp
			pushf
			cmp rdi, 97
			jl no
			cmp rdi, 122
			jg no
			sub rdi, 32
			mov rax, rdi
			popf
			leave
			ret

no:
	mov rax, rdi
	popf
	leave
	ret
