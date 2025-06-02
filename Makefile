CXX = g++
CXXFLAGS = -Wall -std=c++17
SRC = src/main.cpp src/jogo.cpp src/perguntas.cpp src/utils.cpp
INC = -Iinclude
OUT = corrida

all:
	$(CXX) $(SRC) $(CXXFLAGS) $(INC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
