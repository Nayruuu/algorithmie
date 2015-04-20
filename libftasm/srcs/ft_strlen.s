# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/16 19:02:43 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 15:05:00 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_strlen(const char *s);

global _ft_strlen

section .text

_ft_strlen:
			mov rax, 0
				
_count:
		mov bl, byte[rdi + rax]	;on place le premier octet
		test bl, bl			;on check si on est a la fin de la chaine
		jz yes
		add rax, 1
		jmp _count

yes:
	ret
