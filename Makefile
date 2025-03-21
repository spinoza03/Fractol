
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fractol

SRC = src/init.c src/main.c src/parsing.c src/mandelbrot.c \
		src/julia.c funct/ft_atoi.c funct/ft_strcmp.c funct/putstr_fd.c \
		src/controls.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	cc ${CFLAGS} $^ -Lmlx/ -lm -lmlx -lX11 -lXext -o $@

$(OBJ) : %.o: %.c include/fractol.h
	cc ${CFLAGS} -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all
