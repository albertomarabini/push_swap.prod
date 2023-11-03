NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = libft.c libft2.c libft3.c libft4.c n_binary_radix_sort.c n_binary_radix_sort_utils.c push_swap.c push_swap_utils.c push_swap_utils2.c push_swap_utils3.c push_swap_utils4.c push_swap_utils5.c sort_small_map.c
SRCS_TEST = $(filter-out push_swap.c, $(SRCS)) push_swap_test.c
OBJS = $(SRCS:.c=.o)
OBJS_TEST = $(SRCS_TEST:.c=.o)

all: $(NAME)
	$(MAKE) clean

debug:
	$(CC) $(CFLAGS) $(SRCS) -g -o ../../debugger/a.out
	$(MAKE) clean

test:
	$(CC) $(CFLAGS) $(SRCS_TEST) -g -o ../../debugger/a.out
	$(MAKE) clean

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(OBJS_TEST)

fclean: clean
	rm -f $(NAME) push_swap_test

re: fclean all

norm:
	@norminette $(SRCS)

renorm:  fclean all norm

.PHONY: all test clean fclean re
