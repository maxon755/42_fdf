#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 08:37:35 by mgayduk           #+#    #+#              #
#    Updated: 2018/01/11 11:41:27 by mgayduk          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

# Output settings
DEFAULT	:=\033[0m
BOLD	:=\033[1m
GREEN	:=\033[0;32m
RED		:=\033[0;31m

# Compiler
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
G_LIBS  = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Directories
SRC_DIR := ./srcs
OBJ_DIR := ./objs
INC_DIR := ./includes
LFT_DIR := ./libft
MLX_DIR := ./minilibx_macos

# Source files
SRC :=	main.c 		        \
		reader.c			\
		parser.c			\
        matrix.c            \
		matrix2.c			\
		matrix3.c			\
		vector.c			\
		camera.c			\
		clip.c				\
		transformations.c	\
		helpers.c			\
		drawer.c			\
		primitives.c		

# Object files
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

#includes
INC := $(addprefix -I, $(INC_DIR))

# Libs
LFT := libft.a
MLX := libmlx.a

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Compiling libft...$(DEFAULT)"
	@make -C $(LFT_DIR) all --silent
	@echo "$(GREEN)Compiling minilibX...$(DEFAULT)"
	@make -C $(MLX_DIR) all --silent
	@echo "$(GREEN)Compiling $(NAME)...$(DEFAULT)"
	@$(CC) $(FLAGS) $(OBJ) $(LFT_DIR)/$(LFT) $(G_LIBS) $(INC) -o $(NAME)
	@echo "$(GREEN)$(BOLD)DONE.\n$(DEFAULT)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	@echo "$(RED)Cleaning libft o-files...$(DEFAULT)" 
	@make -C $(LFT_DIR) clean --silent
	@echo "$(RED)Cleaning minilibX o-files...$(DEFAULT)" 
	@make -C $(MLX_DIR) clean --silent
	@echo "$(RED)Cleaning $(NAME) o-files...$(DEFAULT)"
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)$(BOLD)DONE.\n$(DEFAULT)"

fclean: clean
	@echo "$(RED)Deleting libft.a...$(DEFAULT)" 
	@rm -rf $(LFT_DIR)/$(LFT)
	@echo "$(RED)Deleting minilibX.a...$(DEFAULT)" 
	@rm -rf $(MLX_DIR)/$(MLX)
	@echo "$(RED)Deleting $(NAME)...$(DEFAULT)" 
	@rm -rf $(NAME)
	@echo "$(GREEN)$(BOLD)DONE.\n$(DEFAULT)"

re: fclean all



