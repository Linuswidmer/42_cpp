NAME      = ./identify

SRCS_PATH = srcs/
SRC       = main.cpp Base.cpp
SRCS      = $(addprefix $(SRCS_PATH), $(SRC))

OBJ_PATH  = obj/
OBJ       = $(SRC:.cpp=.o)
OBJS      = $(addprefix $(OBJ_PATH), $(OBJ))

CC        = c++
CFLAGS    = -Wall -Werror -Wextra -std=c++98

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean