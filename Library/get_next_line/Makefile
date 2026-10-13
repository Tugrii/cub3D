# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: <tgeler@stundent.42.istanbul.com.tr>         +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 2026/09/01 09:11:41 by tgeler              #+#    #+#             #
#   Updated: 2026/10/07 13:43:57 by tgeler             ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CXX = cc

CXXFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c\
		get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o:%.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
