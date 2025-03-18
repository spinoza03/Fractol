
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fractol

SRC =  src/parsing.c src/init.c funct/ft_atoi.c funct/ft_strcmp.c 

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): src/main.c $(OBJ)
	cc -Wall -Wextra -Werror $^ -Lmlx/ -lm -lmlx -lX11 -lXext -o $@

$(OBJ) : %.o: %.c include/fractol.h
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all
