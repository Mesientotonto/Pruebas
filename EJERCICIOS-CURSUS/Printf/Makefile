NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

SRCS		= ft_printf_bonus.c \
			  parse_bonus.c \
			  print_num_bonus.c \
			  print_str_bonus.c \
			  conv_num_bonus.c \
			  utils_bonus.c
OBJS		= $(SRCS:.c=.o)
HEADER		= ft_printf_bonus.h

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
