NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = libft.c libft2.c libft3.c n_binary_radix_sort.c n_binary_radix_sort_utils.c push_swap.c push_swap_utils.c push_swap_utils2.c sort_small_map.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
