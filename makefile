# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 01:29:22 by fael-bou          #+#    #+#              #
#    Updated: 2022/05/07 15:12:21 by fael-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -lmlx -framework OpenGL -framework AppKit
INCLUDE = -I./inc -I/usr/local/include/

BUILD_DIR = build

FILES = main.o parse.o check_map.o draw.o moves.o utils.o manage_err.o\
		ft_printf/ft_printf.o ft_printf/ft_conversion.o ft_printf/ft_putchar.o\
		ft_printf/ft_putnbr.o ft_printf/ft_putstr.o\
		gnl/get_next_line.o gnl/get_next_line_utils.o \
		lists/ft_lstadd_back.o lists/ft_lstclear.o lists/ft_lstiter.o \
		lists/ft_lstmap.o lists/ft_lstsize.o lists/ft_lstadd_front.o \
		lists/ft_lstdelone.o lists/ft_lstlast.o lists/ft_lstnew.o

OBJ = $(addprefix $(BUILD_DIR)/, $(FILES))

NAME = so_long

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

$(BUILD_DIR)/%.o : src/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean
