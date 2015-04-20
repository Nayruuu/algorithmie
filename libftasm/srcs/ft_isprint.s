# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isprint.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/16 18:08:36 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 15:16:05 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_isprint(int c);

global _ft_isprint

section .text

_ft_isprint:
			cmp rdi, 32		;space
			jl no
			cmp rdi, 126	;~
			jg no
			mov rax, 1
			ret

no:
	mov rax, 0
	ret
