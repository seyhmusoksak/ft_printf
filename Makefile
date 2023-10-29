NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_base.c ft_printf_ptr.c ft_itoa.c \
		ft_printf_hex.c


OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
