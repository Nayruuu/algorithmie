# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_max.s                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/17 15:23:56 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 15:29:14 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_max(int a, int b);

global _ft_max

section .text

_ft_max:
		cmp rdi, rsi
		jl yes
		mov rax, rdi
		ret

yes:
	mov rax, rsi
	ret
