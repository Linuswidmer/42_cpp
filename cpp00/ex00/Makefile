# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 15:02:43 by lwidmer           #+#    #+#              #
#    Updated: 2023/06/07 11:12:01 by lwidmer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = megaphone
SRCS = Megaphone.cpp 
CFLAGS = -Wall -Werror -Wextra -std=c++98
OBJS = $(SRCS:.cpp=.o) 

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(OBJS)-o $(NAME)

%.o: %.cpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJS)

re: fclean all