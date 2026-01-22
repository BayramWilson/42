NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rcs

RM = rm -f

SRCS = ft_printf.c \
       put_hex.c \
       put_numbers.c \
       put_strings.c

OBJS = ft_printf.o \
       put_hex.o \
       put_numbers.o \
       put_strings.o

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

ft_printf.o: ft_printf.c ft_printf.h
	$(CC) $(CFLAGS) -c ft_printf.c -o ft_printf.o

put_hex.o: put_hex.c ft_printf.h
	$(CC) $(CFLAGS) -c put_hex.c -o put_hex.o

put_numbers.o: put_numbers.c ft_printf.h
	$(CC) $(CFLAGS) -c put_numbers.c -o put_numbers.o

put_strings.o: put_strings.c ft_printf.h
	$(CC) $(CFLAGS) -c put_strings.c -o put_strings.o

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

