# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 13:50:01 by sde-toda          #+#    #+#              #
#    Updated: 2015/01/22 23:25:03 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

GCC = gcc

CFLAGS = -Wall -Werror -Wextra -O2 -I includes/

AR = ar rc

SRC = ft_printf.c ft_strlen.c ft_printfstr.c ft_printfnbr.c ft_printfchar.c
SRC += ft_printfbase.c ft_printfptr.c ft_printfwchar.c ft_printfwstr.c get_length.c 
SRC += ft_strchr.c init_env.c get_attr.c get_width.c get_prec.c get_modif.c 
SRC += ft_printfnchar.c select_case.c select_modif.c ft_putchar.c
SRC += select_convers.c select_base.c  get_ulength.c get_wchar_length.c
SRC += ft_printfdate.c ft_printfmemcpy.c select_color.c

OBJ = $(SRC:.c=.o)

SRCD = srcs/
OBJD = objs/
SRCS = $(addprefix $(SRCD), $(SRC))
OBJS = $(addprefix $(OBJD), $(OBJ))

.PHONY = all clean fclean re

$(NAME) : $(OBJS) 
	@echo "\\033[1;36mMaking Objects..."
	@$(AR) $(NAME) $(OBJS)
	@echo "\\033[6;32mLIBFTPRINTF.A = DONE"

$(LIBFT):
	@echo "\\033[1;36mMaking Lib..."

$(OBJD)%.o: $(SRCD)%.c
	@mkdir $(OBJD) 2> /dev/null || echo '' > /dev/null
	@$(GCC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

clean:
	 	@rm -f $(OBJS)
		@rm -rf $(OBJD)
		@echo "\\033[2;31mCleaning Objects..."

fclean: clean
	@echo "Cleaning Libftprintf.a.."
	@rm -f $(NAME)

re: fclean all

norme:
	@norminette "includes/"
	@norminette $(SRCS)
