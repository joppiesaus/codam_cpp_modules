# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jobvan-d <jobvan-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/05/19 16:33:41 by jobvan-d      #+#    #+#                  #
#    Updated: 2023/08/01 16:30:20 by jobvan-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++17
NAME = btc
DEPS = main.cpp BitcoinExchange.cpp
HEADERS = BitcoinExchange.hpp

OBJ_DIR = obj
OBJ = $(DEPS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.cpp $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir $@

clean:
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re: fclean
	$(MAKE)

run: all
	./$(NAME)

.PHONY: all clean fclean re run
