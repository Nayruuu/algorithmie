# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_cat.s                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/17 12:13:24 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 15:15:01 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_cat(int fd);

global _ft_cat
extern _ft_bzero

section .data

buff times 1 db 0
.len equ $ - buff

section .text

_ft_cat:
		cmp rdi, 0
		je stand

normal:
		lea rsi, [rel buff]
		push rsi
		push rdi
		mov rdi, rsi
		mov rsi, buff.len
		call _ft_bzero
		pop rdi
		pop rsi
		mov rdx, buff.len
		mov rax, 0x2000003
		syscall
		jc end
		cmp rax, 0
		jle end
		push rdi
		mov rdi, 1
		lea rsi, [rel buff]
		mov rdx, buff.len
		mov rax, 0x2000004
		syscall
		pop rdi
		jmp normal

stand:
		lea rsi, [rel buff]
		push rsi
		mov rdi, rsi
		mov rsi, buff.len
		call _ft_bzero
		pop rsi
		mov rdi, 0
		mov rdx, buff.len
		mov rax, 0x2000003
		syscall
		mov rdi, 1
		lea rsi, [rel buff]
		mov rdx, buff.len
		mov rax, 0x2000004
		syscall
		mov rdi, 0
		jmp stand

end:
	ret
