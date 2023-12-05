NAME      	= ./RPN

SRC_PATH	= src/
SRC			= main.cpp RPN.cpp
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH	= obj/
OBJ			= $(SRC:.cpp=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

INC_PATH	= inc/
INCS		= -I $(INC_PATH)

CC        	= c++
CFLAGS    	= -Wall -Werror -Wextra -std=c++98

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean