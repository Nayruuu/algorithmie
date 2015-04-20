# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcat.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/16 23:45:44 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 22:39:17 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_strcat(char *s1, const char *s2)

global _ft_strcat
extern _ft_strlen

section .text

_ft_strcat:
			call _ft_strlen
			mov rcx, 0

_count:
		mov bl, byte[rsi + rcx]
		test bl, bl
		jz yes
		mov [rdi + rax], bl
		inc rcx
		inc rax
		jmp _count

yes:
	mov [rdi + rax], bl
	mov rax, rdi
	ret
