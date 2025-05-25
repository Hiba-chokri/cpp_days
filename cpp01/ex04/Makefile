NAME = replace
CXX = c++ 
CXXFLAGS =  -Wall -Wextra -Werror -std=c++98  #-fsanitize=address -g3
src = main.cpp

OBJ = $(src:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean: 
	rm -rf $(OBJ) *.replace

fclean: clean
	rm -rf $(NAME)

re: fclean all
