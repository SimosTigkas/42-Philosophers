NAME = philo

FUNC = \
	init_data.c \
	getting_input.c \
	utils.c \
	main_philo.c \
	auto_lock_unlock.c \
	lets_eat_spaghetti.c \
	synchronization_utils.c

INC = includes

PHILO = philo

OBJ = $(FUNC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -I $(INC) $(OBJ) -o $(PHILO)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(PHILO)

re: fclean all

.PHONY: all clean fclean re