# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strclr.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/17 19:44:41 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 20:11:02 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_strclr(char *s);

global _ft_strclr

section .text

_ft_strclr:
			mov rax, 0
			mov al, 0
			
_count:
		mov bl, byte[rdi + rax]
		test bl, bl
		jz yes
		mov [rdi + rax], al
		inc rax
		jmp _count

yes:
	mov[rdi + rax], al
	ret
