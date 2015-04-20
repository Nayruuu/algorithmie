# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/17 10:59:28 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/17 15:17:36 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;ft_memcpy(void *dst, const void *src, size_t len);

global _ft_memcpy

section .text

_ft_memcpy:
			push rdi
			mov rax, rsi
			mov rcx, rdx
			cld
			rep movsb
			pop rax
			ret
