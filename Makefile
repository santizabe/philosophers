NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = main.c utils.c init.c monitor.c time.c ph_routine.c checker.c
OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) 

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus