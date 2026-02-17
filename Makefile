NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror -pthread -g
SRC_DIR = src
SRC = main.c utils.c init.c monitor.c time.c ph_routine.c checker.c
OBJ_DIR = obj
INC = -Iinclude
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:c=o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(INC) -o $(NAME) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	@rm -fr $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus