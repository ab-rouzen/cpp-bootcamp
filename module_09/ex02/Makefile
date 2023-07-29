NAME = PmergeMe

SRCS = 	main.cpp \
		GroupIterator.cpp \
		mergeInsertSort.cpp

INCLUDE = 	GroupIterator.hpp \
			mergeInsertSort.hpp \
			PmergeMe.hpp

BUILD_DIR = build/

STD = -std=c++98

FLAGS = -g -Wall -Wextra -Werror

OBJS = $(SRCS:%.cpp=$(BUILD_DIR)%.o)

CC = g++

all : $(NAME)
	@echo Done.

$(NAME) : $(OBJS) $(INCLUDE)
	$(CC) $(OBJS) -o $(NAME)

$(BUILD_DIR)%.o : %.cpp $(INCLUDE)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) $(STD) -c $< -o $@

clean :
	rm -rf $(BUILD_DIR)

fclean : clean
	rm -rf $(NAME)

re :	fclean all