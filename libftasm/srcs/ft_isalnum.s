# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalnum.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/16 17:49:16 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 15:15:14 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_isalnum(int c);

global		_ft_isalnum
extern		_ft_isdigit
extern		_ft_isalpha

section .text

_ft_isalnum:
			call _ft_isdigit
			cmp rax, 0
			jne yes
			call _ft_isalpha
			cmp rax, 0
			jne yes
			mov rax, 0
			ret

yes:
	mov rax, 1
	ret
