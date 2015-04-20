# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/26 15:40:22 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/24 18:56:12 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computor

GCC = gcc

FLAGS = -Wall -Werror -Wextra -O3 -I includes/ -g -I minilibx_macos/
LFLAGS = -O3 -L libft/ -lft
MLX_FLAGS = -framework OpenGL -framework AppKit -L minilibx_macos/ -lmlx
LIBFT = ./libft/libft.a
DO_LIBFT = make -C libft/
CL_LIBFT = make -C libft/ clean
FCL_LIBFT = make -C libft/ fclean

SRC = computor.c get_deg.c get_coeffs.c aff_d.c print_poly.c resolve.c
SRC += clear_str.c resolve_second_deg.c get_sqrt.c discr_sup_0.c
SRC += discr_inf_0.c ft_fabs.c do_mlx.c

OBJ = $(SRC:.c=.o)

SRCD = srcs/
OBJD = objs/
SRCS = $(addprefix $(SRCD), $(SRC))
OBJS = $(addprefix $(OBJD), $(OBJ))

.PHONY = all clean fclean re norme

$(NAME): $(LIBFT) $(OBJS)
	@$(GCC) -o $(NAME) $(OBJS) $(LFLAGS) $(MLX_FLAGS)
	@echo "\\033[0;32mCOMPUTOR STATUS = DONE"
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
	@echo "Cleaning Libft.a and computor.."
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

minilibx:
		@clear
		@echo "\\033[0;32mMaking MiniLibx..."
		@sleep 1
		@printf "\\033[1;37m"
		@make -C minilibx_macos/
		@printf "\\033[0;32mMiniLibx STATUS = DONE\n"
		@sleep 1
		@clear

clean_minilibx:
		@clear
		@make -C minilibx_macos/ clean
		@echo "\\033[2;31mCleaning minilibx.a ..."
		@sleep 2
		@clear
