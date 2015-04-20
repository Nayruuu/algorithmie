# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strchr.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/17 15:29:17 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 21:49:20 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_strchr(const char *s, int c);

global _ft_strchr

section .text

_ft_strchr:
			mov al, sil	
_count: 
			mov bl, byte[rdi]
			cmp bl, al
			jz yes
			test bl, bl
			jz end
			inc rdi
			jmp _count

yes:
	mov rax, rdi
	ret

end:
	mov rax, 0
	ret
