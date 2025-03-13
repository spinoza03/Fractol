
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fractol

SRC = src/main.c src/parsing.c funct/ft_atoi.c funct/ft_strcmp.c

OBJ = ${SRC:.c=.o}
HEADER = includes/fractol.h

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -I includes -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean