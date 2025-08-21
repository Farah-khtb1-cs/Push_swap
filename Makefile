NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = push_swap.c \
		  operations.c \
		  rotate_operations.c \
		  reverse_rotate_operations.c \
		  stack_utils.c \
		  string_utils.c \
		  validation.c \
		  ft_split.c \
		  ft_free_split.c \
		  parsing.c \
		  small_sort.c \
		  normalize.c \
		  radix_sort.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re