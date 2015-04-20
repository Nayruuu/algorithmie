# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strncpy.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/17 21:47:30 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 22:01:02 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_strncpy(char *dst, const char *src, size_t n);

global _ft_strncpy

section .text

_ft_strncpy:
			cmp rdi, 0
			je _fail
			mov rcx, 0
			mov al, 0

_count:
		mov bl, byte[rsi + rcx]
		test bl, bl
		jz _yes
		cmp rcx, rdx
		je _yes
		mov [rdi + rcx], bl
		inc rcx
		jmp _count

_yes:
	 cmp rcx, rdx
	 je _end
	 mov[rdi + rcx], al
	 inc rcx
	 jmp _yes

_end:
	 mov rax, rdi
	 ret
		
_fail:
	  mov rax, 0
	  ret
