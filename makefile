NAME = push_swap
NAME_BONUS = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs/
BONUS_DIR = bonus/
OBJ_DIR = objs/

SRCS = $(SRC_DIR)libft.c $(SRC_DIR)libft2.c $(SRC_DIR)libft3.c $(SRC_DIR)libft4.c $(SRC_DIR)n_binary_radix_sort.c $(SRC_DIR)n_binary_radix_sort_utils.c $(SRC_DIR)push_swap.c $(SRC_DIR)push_swap_utils.c $(SRC_DIR)push_swap_utils2.c $(SRC_DIR)push_swap_utils3.c $(SRC_DIR)push_swap_utils4.c $(SRC_DIR)push_swap_utils5.c $(SRC_DIR)sort_small_map.c
SRCS_TEST = $(filter-out $(SRC_DIR)push_swap.c, $(SRCS)) push_swap_test.c
SRCS_BONUS = $(BONUS_DIR)get_next_line.c $(BONUS_DIR)get_next_line_utils.c $(BONUS_DIR)checker_bonus.c $(BONUS_DIR)checker_utils_bonus.c $(BONUS_DIR)libft2_bonus.c $(BONUS_DIR)libft3_bonus.c $(BONUS_DIR)libft_bonus.c $(BONUS_DIR)push_swap_utils.c $(BONUS_DIR)push_swap_utils2.c $(BONUS_DIR)push_swap_utils3.c $(BONUS_DIR)push_swap_utils4.c $(BONUS_DIR)get_next_line.c $(BONUS_DIR)get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
OBJS_TEST = $(SRCS_TEST:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	$(MAKE) clean

debug: $(SRCS)
	$(CC) $(CFLAGS) $^ -g -o ../../debugger/a.out
	$(MAKE) clean

test: $(SRCS_TEST)
	$(CC) $(CFLAGS) $^ -g -o ../../debugger/a.out
	$(MAKE) clean

bonus: $(SRCS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(SRCS_BONUS)
	$(MAKE) clean

clean:
	rm -f $(OBJS) $(OBJS_TEST)

fclean: clean
	rm -f $(NAME) ../../debugger/a.out

re: fclean all

norm:
	@norminette $(SRCS)

renorm:  fclean all norm

.PHONY: all test clean fclean re debug norm renorm bonus
