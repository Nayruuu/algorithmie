# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/17 02:44:13 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 20:15:03 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_strdup(const char *s);

global _ft_strdup
extern _malloc
extern _ft_strlen
extern _ft_strcat

section .text

_ft_strdup:
			push rdi
			call _ft_strlen
			mov rdi, rax
			add rdi, 1
			call _malloc
			cmp rax, 0
			je _fail
			mov rdi, rax
			pop rsi
			call _ft_strcat
			ret

_fail: 
		mov rax, 0
		ret
