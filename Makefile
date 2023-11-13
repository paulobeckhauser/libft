CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRC = main.c ft_isalnum.c ft_isalpha.c ft_isdigit.c

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

run: $(NAME)
	./$(NAME)

.PHONY: clean

clean:
	rm -f $(NAME) 
	clear

fclean:
	rm -f 
