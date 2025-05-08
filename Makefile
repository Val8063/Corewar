##
## EPITECH PROJECT, 2024
## MAkefile
## File description:
## Makefile
##

CFLAGS   = -g3 -Wall -Wextra -Iinclude
LDFLAGS  =

SRC      =	src/op.c \
			src/main.c \
			src/parser/args_parsing.c \
			src/init.c \
			src/free.c \
			src/worker/memory.c \
			$(wildcard src/op_functions/*.c)

LSRC     = $(wildcard lib/*.c)

OBJ      = $(SRC:.c=.o)
LOBJ     = $(LSRC:.c=.o)
NAME     = corewar

all: $(NAME)

$(NAME): $(OBJ) $(LOBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LOBJ) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: ${NAME}
	./${NAME}

val: ${NAME}
	valgrind ./${NAME}

clean:
	$(RM) $(OBJ) $(LOBJ)

fclean: clean
	$(RM) $(NAME) *.o *.gcda *.gcno

re: fclean all

.PHONY: all clean fclean re tests_run
