# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/26 15:40:22 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/05 10:36:24 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

GCC = gcc

FLAGS = -Wall -Werror -Wextra -O3 -I includes/ -g
LFLAGS = -O3 -L libft/ -lft
LIBFT = ./libft/libft.a
DO_LIBFT = make -C libft/
CL_LIBFT = make -C libft/ clean
FCL_LIBFT = make -C libft/ fclean

SRC = push_swap.c check_param.c stack_push.c check_stack.c 
SRC += swap_stacks.c print_stack.c push_stacks.c rotate_stack.c
SRC += algo.c get_min.c check.c choose_action.c

OBJ = $(SRC:.c=.o)

SRCD = srcs/
OBJD = objs/
SRCS = $(addprefix $(SRCD), $(SRC))
OBJS = $(addprefix $(OBJD), $(OBJ))

.PHONY = all clean fclean re norme

$(NAME): $(LIBFT) $(OBJS)
	@$(GCC) -o $(NAME) $(OBJS) $(LFLAGS)
	@echo "\\033[0;32mPUSH_SWAP STATUS = DONE"
	@sleep 2
	@clear

$(LIBFT):
	@clear
	@echo "\\033[0;32mMaking Lib..."
	@sleep 1
	@$(DO_LIBFT)
	@printf "\\033[0;32mLIBFT STATUS = DONE\n"
	@sleep 1
	@clear
	@echo "\\033[0;32mMaking Objects..."
	@sleep 1

$(OBJD)%.o: $(SRCD)%.c
	@mkdir $(OBJD) 2> /dev/null || echo '' > /dev/null
	@$(GCC) $(FLAGS) -o $@ -c $<
	@printf "\\033[1;37m%-23s -\\033[0;32m->     \\033[1;34m%s\n" "$<" "$@"

all: $(NAME)

clean:	
		@clear
		@rm -f $(OBJS)
		@rm -rf $(OBJD)
		@$(FCL_LIBFT)	
		@echo "\\033[2;31mCleaning Objects..."
		@sleep 2
		@clear


fclean: clean
	@echo "Cleaning Libft.a and push_swap.."
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@$(FCL_LBFT)
	@sleep 2
	@clear

re: fclean
	@echo ""
	@make all

norme:
	@make -C libft/ norme
	@norminette $(SRCS) 
	@norminette "includes/"
