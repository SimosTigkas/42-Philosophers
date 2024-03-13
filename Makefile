NAME = philo

FUNC = test.c

INC = includes

PHILO = philo

OBJ = $(FUNC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -I $(INC) $(OBJ) -o $(PHILO)
	chmod +x $(PHILO)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(PHILO)

re: fclean all

.PHONY: all clean fclean re