NAME = philo

FUNC = \
	init_data.c \
	getting_input.c \
	utils.c \
	main_philo.c \
	auto_lock_unlock.c \
	lets_eat_spaghetti.c \
	synchronization_utils.c \
	display.c \
	handlers.c \
	death_checker.c

INC = ./includes

OBJ = $(FUNC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I $(INC) $(OBJ) -o $(NAME)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
