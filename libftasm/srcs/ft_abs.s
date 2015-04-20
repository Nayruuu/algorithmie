# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_abs.s                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/18 13:55:40 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/18 14:06:09 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_abs(int c);

global _ft_abs

section .text

_ft_abs:
		cmp rdi, 0
		jle _neg
		mov rax, rdi
		ret

_neg:
		push rdi
		mov rax, rdi
		pop rsi
		imul rsi, 2
		sub rax, rsi
		ret
