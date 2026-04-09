NAME = ex02

CXX = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++17

SRC_DIR = SRC/
OBJ_DIR = OBJ/
HEADER_DIR = HEADER/

SRC = $(SRC_DIR)Bureaucrat.cpp \
		$(SRC_DIR)AForm.cpp \
		$(SRC_DIR)PresidentialPardonForm.cpp\
		$(SRC_DIR)RobotomyRequestForm.cpp\
		$(SRC_DIR)ShrubberyCreationForm.cpp\
		$(SRC_DIR)Intern.cpp \
		main.cpp\

OBJ = $(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRC))

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re