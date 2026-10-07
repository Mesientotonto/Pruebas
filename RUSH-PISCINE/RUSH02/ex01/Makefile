# Nombre del archivo final
NAME = rush-02

# Aqui se pone el compilador que se va a usar
CC = cc

# Aqui pongo los flags que va a usar
CFLAGS = -Wall -Werror -Wextra

# Aqui pongo los archivos que va a compilar
SRCS = prueba.c

# Lo traduces a lenguaje maquina
OBJS = $(SRCS:.c=.o)

# Busca los archivos .h
INCLUDES = -I.

# Regla principal
all: $(NAME)

# Para continuar necesita todos los objetos
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Regla para el patron para generar archivos
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Borra todos los archivos .o
clean:
	rm -f $(OBJS)

# Borra todos los archivos .o y el ejecutable rush-02
fclean: clean
	rm -f $(NAME)

# Recompila todo desde cero
re: fclean all

# Aqui se indica que estos son acciones
.PHONY: all clean fclean re
