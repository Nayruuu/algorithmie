# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isascii.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/16 17:59:34 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 15:15:40 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_isascii(int c);

global		_ft_isascii

section .text

_ft_isascii:
			cmp rdi, 0
			jl no
			cmp rdi, 127
			jg no
			mov rax, 1
			ret

no:
	mov rax, 0
	ret
