CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
NAME = brian
DEPS = main.cpp
OBJ = $(DEPS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(NAME)

fclean: clean

re: clean $(NAME)

.PHONY: all clean fclean re
