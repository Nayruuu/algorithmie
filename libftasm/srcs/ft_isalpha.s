# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalpha.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/16 13:02:43 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 15:15:29 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_isalpha(int c);

global _ft_isalpha

section .text

_ft_isalpha:
			cmp rdi, 97		;'a'
			jl maj
			cmp rdi, 122	;'z'
			jg no
			mov rax, 1
			ret
maj:
	cmp rdi, 65				;'A'
	jl no
	cmp rdi, 90				;'Z'
	jg no
	mov rax, 1
	ret

no:
	mov rax, 0
	ret
