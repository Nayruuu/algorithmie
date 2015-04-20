# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isdigit.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/16 17:41:37 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 15:15:55 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_isdigit(int c);

global _ft_isdigit

section .text

_ft_isdigit:
			cmp rdi, 48  ;'0'
			jl no
			cmp rdi, 57  ;'9'
			jg no
			mov rax, 1
			ret

no:
	mov rax, 0
	ret
