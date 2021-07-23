NAME = so_long

CC = gcc

FLAGS = -Wall -Wextra -Werror -I./mlx

LIBS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC = so_long.c ft_split.c ft_strlen.c ft_substr.c error.c analize_proverka.c initial_map.c counter.c step2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(FLAGS) $(LIBS) $(OBJ)

%.o:%.c so_long.h
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	make clean -C mlx
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx
