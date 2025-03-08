# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohan <yohan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 13:58:50 by yohan             #+#    #+#              #
#    Updated: 2025/03/08 13:40:54 by yohan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe
FLAGS = -Wall -Wextra -Werror -std=c++98
CC = g++

SRC = main.cpp source/deque.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: clean all
