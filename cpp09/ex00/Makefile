NAME = btc
CXX = c++
CXXFLAGS =  -Wall -Wextra -Werror -std=c++98
src = main.cpp BitcoinExchange.cpp

OBJ = $(src:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
