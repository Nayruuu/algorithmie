# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 13:50:01 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/18 14:15:09 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a

NASM = ~/.brew/bin/nasm -f macho64

AR = ar rc

SRC = ft_memset.s ft_bzero.s ft_isalpha.s ft_isdigit.s ft_isalnum.s 
SRC += ft_isascii.s ft_isprint.s ft_toupper.s ft_tolower.s ft_strlen.s
SRC += ft_puts.s ft_strcat.s ft_strdup.s ft_memcpy.s ft_cat.s
SRC += ft_min.s ft_max.s ft_strclr.s ft_strnew.s ft_strjoin.s
SRC += ft_strchr.s ft_strncpy.s ft_strsub.s ft_abs.s

OBJ = $(SRC:.s=.o)

SRCD = srcs/
OBJD = objs/
SRCS = $(addprefix $(SRCD), $(SRC))
OBJS = $(addprefix $(OBJD), $(OBJ))

.PHONY = all clean fclean re main

all : $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\\033[0;32mLIBFTS STATUS = DONE"
	@sleep 2
	@clear

$(OBJD)%.o: $(SRCD)%.s
	@mkdir $(OBJD) 2> /dev/null || echo "" > /dev/null
	@$(NASM) -g3 -o $@ $<
	@printf "\\033[1;37m%-23s -\\033[0;32m->     \\033[1;34m%s\n" "$<" "$@"

clean:
		@clear
	 	@rm -f $(OBJS)
		@echo "\\033[2;31mCleaning Objects..."
		@sleep 2
		@clear

fclean: clean
		@rm -f $(NAME)
		@echo "\\033[2;31mCleaning Libfts.a"
		@sleep 2
		@clear


re: fclean all

norme: 
	@norminette $(SRCS)
	@norminette "includes/"

main:
	gcc main.c libfts.a
