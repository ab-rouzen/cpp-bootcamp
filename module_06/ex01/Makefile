NAME = serializer
SRCS = main.cpp Serializer.cpp
INCLUDE = Serializer.hpp
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