NAME  = ./bsp
SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp
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