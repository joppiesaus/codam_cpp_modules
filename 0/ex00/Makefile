CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
NAME = megaphone
DEPS = megaphone.cpp
OBJ = $(DEPS:%.c=%.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(NAME)

fclean: clean

re: clean $(NAME)

.PHONY: clean fclean re
