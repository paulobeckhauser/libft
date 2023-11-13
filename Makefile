CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRC = *.c

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
