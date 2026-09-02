# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: tgeler <tgeler@stundent.42.istanbul.com.tr>  +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 2026/09/01 09:08:14 by tgeler              #+#    #+#             #
<<<<<<< HEAD
#   Updated: 2026/09/02 15:37:38 by tgeler             ###   ########.fr       #
=======
#   Updated: 2026/09/02 10:32:10 by tgeler             ###   ########.fr       #
>>>>>>> 21d6faea6d18cc398b7d0cd93d0815e6281ca370
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror

GNL_DIR = Library/get_next_line
GNL = $(GNL_DIR)/get_next_line.a

LIBFT_DIR = Library/Libft
LIBFT = $(LIBFT_DIR)/libft.a

<<<<<<< HEAD
MLX_DIR = Library/mlx
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

SRCS = main.c\
		srcs/parser/create_fd.c\
		srcs/parser/create_maps_linked_list.c\
		srcs/check_map/check_map_contain_valid_char.c

OBJS = $(SRCS:.c=.o)

all: libft gnl mlx $(NAME)
=======
SRCS = main.c

OBJS = $(SRCS:.c=.o)

all: libft gnl $(NAME)
>>>>>>> 21d6faea6d18cc398b7d0cd93d0815e6281ca370

libft:
	make -C $(LIBFT_DIR)

gnl:
	make -C $(GNL_DIR)

<<<<<<< HEAD
mlx:
	make -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(GNL) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) $(MLX_FLAGS) -o $(NAME)
=======
$(NAME): $(OBJS) $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) -o $(NAME)
>>>>>>> 21d6faea6d18cc398b7d0cd93d0815e6281ca370

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(GNL_DIR)
<<<<<<< HEAD
	make clean -C $(MLX_DIR)
=======
>>>>>>> 21d6faea6d18cc398b7d0cd93d0815e6281ca370

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(GNL_DIR)
<<<<<<< HEAD
	make fclean -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re libft gnl mlx
=======

re: fclean all

.PHONY: all clean fclean re libft gnl
>>>>>>> 21d6faea6d18cc398b7d0cd93d0815e6281ca370
