NAME  = ./materia
SRCS = AMateria.cpp Character.cpp Cure.cpp Ice.cpp ICharacter.cpp \
		IMateriaSource.cpp MateriaSource.cpp main.cpp
CFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address -g
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