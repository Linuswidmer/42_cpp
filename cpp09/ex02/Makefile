NAME      	= ./PmergeMe

SRC_PATH	= src/
SRC			= main.cpp PmergeMe.cpp
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH	= obj/
OBJ			= $(SRC:.cpp=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

INC_PATH	= inc/
INCS		= -I $(INC_PATH)

CC        	= c++
OPTIMIZER 	= -O3
CFLAGS    	= -Wall -Werror -Wextra -std=c++98 -g

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

optimize: CFLAGS += $(OPTIMIZER)
optimize: re

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean