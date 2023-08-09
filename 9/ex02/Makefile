# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jobvan-d <jobvan-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/05/19 16:33:41 by jobvan-d      #+#    #+#                  #
#    Updated: 2023/08/08 13:45:48 by jobvan-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = c++
# uncomment final flags to make the program faster for larger numbers
CFLAGS = -Wall -Wextra -Werror -std=c++17 # -O2 -mtune=native -march=native
NAME = PmergeMe 
DEPS = main.cpp PmergeMe.cpp
HEADERS = PmergeMe.hpp

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
