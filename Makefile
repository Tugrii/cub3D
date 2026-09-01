# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: tgeler <tgeler@stundent.42.istanbul.com.tr>  +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 2026/09/01 09:08:14 by tgeler              #+#    #+#             #
#   Updated: 2026/09/01 09:57:58 by tgeler             ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CXX = cc

CXXFLAGS = -Wall -Wextra -Werror

GNL_DIR = Library/get_next_line/
GNL = $(GNL_DIR)/get_next_line.a

LIBFT_DIR = Library/Libft
LIBFT = $(LIBFT_DIR)/libft.a

$(GNL):
	make -C $(GNL_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

SRCS = main.c\





OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LIBFT) $(GNL) -o $(NAME)

%.o:%.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $()