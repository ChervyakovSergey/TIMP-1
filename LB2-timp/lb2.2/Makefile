# Компилятор
CXX = g++

# Флаги компиляции
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

# Исходные файлы
SRC = modPermutation.cpp main.cpp

# Объектные файлы
OBJ = $(SRC:.cpp=.o)

# Исполняемый файл
EXEC = modPermutationCipher

# RULES

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

%.o: %.cpp modPermutation.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

run:
	./$(EXEC)

# Правило для удаления объектных и исполняемых файлов
.PHONY: clean run

