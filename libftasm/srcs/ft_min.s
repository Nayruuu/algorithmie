# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_min.s                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/17 15:21:49 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 15:23:53 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_min(int a, int b);

global _ft_min

section .text

_ft_min:
		cmp rdi, rsi
		jl yes
		mov rax, rsi
		ret

yes:
	mov rax, rdi
	ret
