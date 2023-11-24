CC := cc
CFLAGS := -Wall -Wextra -Werror #-O3 #-g -fsanitize=address -fno-omit-frame-pointer
#VALGRIND  = valgrind --track-fds=yes #--leak-check=full  -s #--show-leak-kinds=all --track-origins=yes
#LEAKS      = leaks --atExit --

NAME := libft.a
SRC := ft_isalpha.c \
 		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c  \
		ft_memset.c  \
		ft_bzero.c  \
		ft_memcpy.c  \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c  \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c  \
		ft_memcmp.c  \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c



OBJ = $(SRC:.c=.o)

RM = /bin/rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rcs $@ $^

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

test:
	make
	cc ../main.c libft.a
	./a.out

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

valgrind: $(VALGRIND) ./$(name)

leaks: $(LEAKS) ./$(name)

.PHONY:	all clean fclean re test