# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohan <yohan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 13:58:50 by yohan             #+#    #+#              #
#    Updated: 2025/02/19 15:31:12 by yohan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat
FLAGS = -Wall -Wextra -Werror -std=c++98
CC = g++

SRC = main.cpp source/Bureaucrat.cpp source/AForm.cpp source/PresidentialPardonForm.cpp source/RobotomyRequestForm.cpp source/ShrubberyCreationForm.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(NAME)

fclean: clean
	@rm -f $(NAME)

re: clean all
