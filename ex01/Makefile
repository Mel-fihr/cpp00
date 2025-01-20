# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 11:51:31 by mel-fihr          #+#    #+#              #
#    Updated: 2025/01/11 14:35:54 by mel-fihr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook

SOURCE = main.cpp PhoneBook.cpp Contact.cpp

OBJECT = main.o PhoneBook.o Contact.o

CPP = c++ -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJECT)
	$(CPP) $^ -o $(NAME)

%.o : %.cpp Makefile PhoneBook.hpp Contact.hpp
	$(CPP) -c $< -o $@

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean