# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/25 18:20:11 by bwilson           #+#    #+#              #
#    Updated: 2026/01/26 14:52:18 by bwilson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source files with paths
SRCS = push_swap.c \
       src/utils/push.c \
       src/utils/swap.c \
       src/utils/rotate.c \
       src/utils/reverse_rotate.c \
       src/utils/list.c \
       src/handler/helpers.c \
       src/handler/helpers2.c \
       src/handler/handle_input.c \
       src/handler/handle_error.c \
       src/algo/algo.c \
       src/algo/algo_helpers.c \
       src/algo/algo_helpers2.c \
       src/algo/sort.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

# Build libft first, then link it with push_swap
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Compile libft by calling make in the libft directory
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re