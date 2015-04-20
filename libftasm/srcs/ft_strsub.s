# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strsub.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/17 21:44:04 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 22:39:14 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_strsub(char const *s, unsigned int start, size_t len);

global _ft_strsub
extern _ft_strnew
extern _ft_strncpy
extern _ft_strlen

section .text

_ft_strsub:
			cmp rdi, 0
			je _fail
			call _ft_strlen
			cmp rax, rsi
			jb _fail
			mov bl, byte[rdi]
			test bl, bl
			je _len
			jmp _doit

_fail:
		mov rax, 0
		ret

_len:
	cmp rdx, 0
	jg _fail

_doit:
		push rdi
		push rsi
		push rdx
		mov rdi, rdx
		call _ft_strnew
		cmp rax, 0
		je _fail
		mov rdi, rax
		mov rax, 0
		pop rdx
		pop r8
		pop rsi

_get_start:
			cmp rax, r8
			je _end
			inc rax
			inc rsi
			jmp _get_start

_end:
	call _ft_strncpy
	ret
