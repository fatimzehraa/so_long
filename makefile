# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 17:55:29 by fael-bou          #+#    #+#              #
#    Updated: 2022/05/10 18:04:47 by fael-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -lmlx -framework OpenGL -framework AppKit
INCLUDE = -I./inc -I/usr/local/include/

BUILD_DIR = build

MANDATORY_FILES = main.o parse.o check_map.o draw.o moves.o utils.o manage_err.o\
		ft_printf/ft_printf.o ft_printf/ft_conversion.o ft_printf/ft_putchar.o\
		ft_printf/ft_putnbr.o ft_printf/ft_putstr.o\
		gnl/get_next_line.o gnl/get_next_line_utils.o \
		lists/ft_lstadd_back.o lists/ft_lstclear.o lists/ft_lstiter.o \
		lists/ft_lstmap.o lists/ft_lstsize.o lists/ft_lstadd_front.o \
		lists/ft_lstdelone.o lists/ft_lstlast.o lists/ft_lstnew.o

BONUS_FILES = bonus/main_bonus.o parse.o bonus/check_map_bonus.o bonus/draw_bonus.o bonus/moves_bonus.o bonus/utils_bonus.o manage_err.o bonus/moves_counter_bonus.o\
		ft_printf/ft_printf.o ft_printf/ft_conversion.o ft_printf/ft_putchar.o\
		ft_printf/ft_putnbr.o ft_printf/ft_putstr.o\
		gnl/get_next_line.o gnl/get_next_line_utils.o \
		lists/ft_lstadd_back.o lists/ft_lstclear.o lists/ft_lstiter.o \
		lists/ft_lstmap.o lists/ft_lstsize.o lists/ft_lstadd_front.o \
		lists/ft_lstdelone.o lists/ft_lstlast.o lists/ft_lstnew.o

OBJ = $(addprefix $(BUILD_DIR)/, $(MANDATORY_FILES))
BONUS_OBJ = $(addprefix $(BUILD_DIR)/, $(BONUS_FILES))

NAME = so_long
BONUS_NAME = so_long_bonus

all : $(NAME)

bonus : $(BONUS_NAME)

$(NAME) : $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

$(BONUS_NAME) : $(BONUS_OBJ) 
	$(CC) $(LDFLAGS) $^ -o $@

$(BUILD_DIR)/%.o : src/%.c inc/so_long.h inc/so_long_bonus.h inc/ft_printf.h inc/get_next_line.h inc/list.h
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	rm -rf $(OBJ) $(BONUS_OBJ)
	rm -rf $(BUILD_DIR)

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)

re : fclean all

.PHONY: all clean fclean
