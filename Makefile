# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: tgeler <tgeler@stundent.42.istanbul.com.tr>  +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 2026/09/01 09:08:14 by tgeler              #+#    #+#             #
#   Updated: 2026/09/02 10:32:10 by tgeler             ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror

GNL_DIR = Library/get_next_line
GNL = $(GNL_DIR)/get_next_line.a

LIBFT_DIR = Library/Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c

OBJS = $(SRCS:.c=.o)

all: libft gnl $(NAME)

libft:
	make -C $(LIBFT_DIR)

gnl:
	make -C $(GNL_DIR)

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(GNL_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(GNL_DIR)

re: fclean all

.PHONY: all clean fclean re libft gnl