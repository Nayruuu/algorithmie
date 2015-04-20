# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_puts.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/16 19:54:55 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 15:17:00 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_puts(const char *s);

global _ft_puts
extern _ft_strlen

section .text

_ft_puts:
		cmp rdi, 0
		je end
		mov rcx, rdi
		call _ft_strlen
		mov rdx, rax
		mov rsi, rcx
		mov rdi, 1
		mov rax, 0x2000004
		syscall
		jmp _newline

_newline:
		lea rsi, [rel null + 6]
		mov rdx, 1
		mov rax, 0x2000004
		syscall
		mov rax, 10
		ret

end:
	mov rdi, 1
	lea rbx, [rel null]
	mov rsi, rbx
	mov rdx, 7
	mov rax, 0x2000004
	syscall
	mov rax, 10
	ret

section .data

null db "(null)", 10
