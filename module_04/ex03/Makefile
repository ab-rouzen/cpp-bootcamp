NAME = prog
SRCS = main.cpp AMateria.cpp Character.cpp \
		Ice.cpp Cure.cpp MateriaSource.cpp
INCLUDE = AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp \
			MateriaSource.hpp
CC = c++
BUILD_DIR = build/
STD = -std=c++98
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)%.o)

all : $(NAME)
	@echo Done.

$(NAME) : $(OBJS) $(INCLUDE)
	$(CC) $(OBJS) -o $(NAME)

$(BUILD_DIR)%.o : %.cpp $(INCLUDE)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) $(STD) -c $< -o $@

clean : 
	rm -rf $(BUILD_DIR)
	rm -rf $(NAME)