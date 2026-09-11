# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: tgeler <tgeler@stundent.42.istanbul.com.tr>  +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 2026/09/01 09:08:14 by tgeler              #+#    #+#             #
#   Updated: 2026/09/08 08:41:23 by tgeler             ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

GNL_DIR = Library/get_next_line
GNL = $(GNL_DIR)/get_next_line.a

LIBFT_DIR = Library/Libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = Library/mlx
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

SRCS = main.c\
		srcs/parser/create_fd.c\
		srcs/parser/create_maps_linked_list.c\
		srcs/check_map/check_map_contain_valid_char.c\
		srcs/parser/save_conf.c\
		srcs/parser/split_maps_configuration_and_content.c\
		srcs/error_msgs/general_error_mesages.c\
		srcs/error_msgs/malloc_errors.c\
		srcs/parser/check_map_has_only_one_raydir.c\
		srcs/parser/make_line_format_suitable.c\
		srcs/parser/check_file_extension.c

OBJS = $(SRCS:.c=.o)

all: libft gnl mlx $(NAME)

libft:
	make -C $(LIBFT_DIR)

gnl:
	make -C $(GNL_DIR)

mlx:
	make -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(GNL) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) $(MLX_FLAGS) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(GNL_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(GNL_DIR)
	make fclean -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re libft gnl mlx
