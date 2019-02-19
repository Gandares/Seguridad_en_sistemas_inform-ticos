CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -fsanitize=address

SRC = vigenere.cpp
OBJ = $(SRC:.cc=.o)
EXEC = vigenere

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)