NAME = rush-02

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       parse.c \
       parse_utils.c \
       convert.c \
       utils.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I.

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c ft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
