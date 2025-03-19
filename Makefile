
CC = cc
CFLAGS = 
NAME = fractol

SRC = src/test.c

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
