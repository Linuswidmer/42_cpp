NAME  = ./animal
SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
CFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address -g
OBJS = $(SRCS:.cpp=.o) 

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(OBJS)-o $(NAME)

%.o: %.cpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all