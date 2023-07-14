#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

void printArray(char *label, int *array, int size) {
    printf("%s: ",label);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}


typedef struct s_array
{
	int	*a;
	int	l;
}	t_array;

t_array	*ft_arrnew(int max_size)
{
	t_array	*array;

	array = (t_array *)malloc(sizeof(t_array));
	if (array == NULL)
		return (NULL);
	array->a = (int *)malloc(max_size * sizeof(int));
	if (array->a == NULL)
	{
		free(array);
		return (NULL);
	}
	array->l = 0;
	return (array);
}

void	ft_arrfree(t_array *array)
{
	free(array->a);
	free(array);
}

t_array	*ft_arrclone(t_array *arr)
{
	t_array	*clone;

	clone = ft_arrnew(arr->l);
	if (clone == NULL)
		return (NULL);
	while (clone->l < arr->l)
	{
		clone->a[clone->l] = arr->a[clone->l];
		clone->l++;
	}
	return (clone);
}

void	ft_arrrev(t_array *array)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = array->l - 1;
	while (i < j)
	{
		temp = array->a[i];
		array->a[i] = array->a[j];
		array->a[j] = temp;
		i++;
		j--;
	}
}
/**
 * Shifts the elements of the array to the right by one position.
 *
 * @param stack A pointer to the array to be shifted.
 */
void ft_arrshftl(t_array *stack)
{
	int	temp;
	int i;

	temp = stack->a[0];
	i = 0;
	while (i < stack->l - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->l - 1] = temp;
}
/**
 * Shifts the elements of the array to the left by one position.
 *
 * @param stack A pointer to the array to be shifted.
 */
void ft_arrshftr(t_array *stack)
{
	int	temp;
	int i;

	temp = stack->a[stack->l - 1];
	i = stack->l - 1;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = temp;
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void	ft_putstr_fd(const char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

t_array *ft_arrsort(t_array *array)
{
	int	temp;
	int	i;
	int	h;

	i = 0;
	while (i < array->l - 1)
	{
		h = 0;
		while (h < array->l - i - 1)
		{
			if (array->a[h] > array->a[h + 1])
			{
				temp = array->a[h];
				array->a[h] = array->a[h + 1];
				array->a[h + 1] = temp;
			}
			h++;
		}
		i++;
	}
	return (array);
}
/**
 * Checks if an array is sorted in ascending order.
 *
 * @param stack The array to be checked for sorting.
 * @return 1 if the array is sorted in ascending order, 0 otherwise.
 */
int	ft_arrissorted(t_array *stack)
{
	int	i;

	i = 0;
	while (i < stack->l - 1)
	{
		if (stack->a[i + 1] < stack->a[i])
			return (0);
		i++;
	}
	return (1);
}

/**
 * Finds the index of an integer in the given array.
 *
 * @param arr The array in which to search for the integer.
 * @param n The integer to find in the array.
 * @return The index of the integer in the array, or -1 if not found.
 */
int ft_arrindexof(t_array *arr, int n) {
    int i = 0;

    while (i < arr->l) {
        if (arr->a[i] == n) {
            return (i);
        }
        i++;
    }
    return (-1);
}

/**
 * Find the largest integer in the given array.
 *
 * @param arr The array from which to find the largest integer.
 * @param n The largest integer in the array.
 */
int ft_arrfindl(t_array *arr) {
	t_array *clone;
	int largest;

	if(arr->l == 0)
		return (-1);
	clone = ft_arrclone(arr);
	ft_arrsort(clone);
	largest = clone->a[clone->l -1];
	ft_arrfree(clone);
	return (largest);
}

/**
 * Find the smalles integer in the given array.
 *
 * @param arr The array from which to find the largest integer.
 * @param n The largest integer in the array.
 */
int ft_arrfinds(t_array *arr) {
	t_array *clone;
	int largest;

	if(arr->l == 0)
		return (-1);
	clone = ft_arrclone(arr);
	ft_arrsort(clone);
	largest = clone->a[0];
	ft_arrfree(clone);
	return (largest);
}

/**
 * @brief The function takes an array we need to sort, sort it using a
 * whatever bubble sort, then take the index of each number and reassign it
 * inside another array, ordered in the same order as the original input.
 *
 * @param array The input array to be normalized.
 * @param size The size of the input array.
 * @return A dynamically allocated array of normalized indexes or NULL if
 * memory allocation fails.
 */
t_array *normalize_input(int *array, int size)
{
	t_array *sorted;
    int curr;
    int i;

    i = 0;
	sorted = ft_arrnew(size);
	if (sorted == NULL)
        return NULL;
    while (i < size)
	{
		sorted->a[i] = array[i];
		sorted->l++;
		i++;
	}
	ft_arrsort(sorted);
    i = 0;
    while (i < size)
    {
        curr = 0;
        while (array[curr] != sorted->a[i])
            curr++;
        sorted->a[i] = curr;
		i++;
    }
    return sorted;
}

int *denormalize(int *original, int *map, int *normalized, int size)
{
    int *ret;
    int i;

    ret = malloc(sizeof(int) * size);
    if (!ret)
        return (NULL);
	i = 0;
    while(i < size)
	{
        ret[i] = original[map[normalized[i]]];
		i++;
	}
    return (ret);
}


/**
 * Calculate the power of an integer.
 *
 * @param n The base value.
 * @param power The exponent value.
 * @return The result of n raised to the power.
 */
int	ipow(int n, int power)
{
	int	result;
	int	i;

	result = 1;
	i = 0;
	while (i < power)
	{
		result *= n;
		i++;
	}
	return (result);
}

/**
 * @brief Count the number of bits in an integer.
 *
 * The function takes an integer `n` as input and counts the number of digits
 * in base n_base (1 for base2, 2 for base 4, 3 for base 8, 4 for base 16)
 * contained by performing a right shift operation on it until it becomes zero
 *
 * @param value The integer for which to count the number of bits.
 * @param n_base The base used for storing the number.
 * @return The number of bits in the given integer.
 */
int	digit_counter(int value, int n_base)
{
	int	bit_count;

	bit_count = 0;
	while (value != 0)
	{
		value = value >> n_base;
		bit_count++;
	}
	return (bit_count);
}

/**
 * Extract a digit from a number in a specified base n_base
 * being n_base1>base 2, 2>base 4, 3>base 8, 4>base 16, etc.
 *
 * @param number The number from which to extract the digit.
 * @param digit The digit position to extract (1-indexed).
 * @param n_base The base used for storing the numbers.
 * @return The extracted digit.
 */
int	extract_digit(int number, int digit, int n_base)
{
	int	mask;

	mask = (1 << n_base) - 1;
	return ((number >> (digit * n_base)) & mask);
}

/**
 * Check if the stack contains numbers belonging to a certain digit group.
 *
 * @param stack The stack array to check.
 * @param digit_grp The desired digit group.
 * @param digit The digit position to check (1-indexed).
 * @param n_base The base used for storing the numbers.
 * @return 1 if the stack contains numbers belonging to the specified digit
 * group, 0 otherwise.
 */
int	contains_dgt_grp(t_array *stack, int digit_grp, int digit, int n_base)
{
	int	i;

	i = 0;
	while (i < stack->l)
	{
		if (extract_digit(stack->a[i], digit, n_base) == digit_grp)
			return (1);
		i++;
	}
	return (0);
}

/**
 * Implements the 's' instruction
 *
 * @param a pointer to the first integer (head of the first stack)
 * @param b pointer to the second integer (head of the second stack)
 * @param label The label of the stack.
 */
int s(t_array *stack, char label)
{
	int	temp;

	temp = stack->a[stack->l - 1];
	stack->a[stack->l - 1] = stack->a[stack->l - 2];
	stack->a[stack->l - 2] = temp;
	ft_putchar_fd('s', 1);
	ft_putchar_fd(label, 1);
	ft_putchar_fd('\n', 1);
	return (1);
}
/**
 * Implements the 'r' instruction
 *
 * @param stack The stack to be rotated.
 * @param label The label of the stack.
 */
int r(t_array *stack, char label)
{
    ft_arrshftl(stack);
    ft_putchar_fd('r', 1);
    ft_putchar_fd(label, 1);
    ft_putchar_fd('\n', 1);
    return 1;
}

/**
 * Implements the 'rr' instruction
 *
 * @param stack The stack to be rotated.
 * @param label The label of the stack.
 */
int rr(t_array *stack, char label)
{
	ft_arrshftr(stack);
	ft_putchar_fd('r', 1);
	ft_putchar_fd('r', 1);
	ft_putchar_fd(label, 1);
	ft_putchar_fd('\n', 1);
	return (1);
}
/**
 * This is a pattern often used: it will take longer to rotate left(r) or
 * right(rr) to bring an element at index i to head?
 *
 * @param stack Array to rotate.
 * @param i Index to the element that we want to bring to head.
 * @param src Src.
 */
int rotate_which(t_array *stack, int i, char label){
	i = i + 1 >= stack->l - i;
	if (i)
		rr(stack, label);
	else
		r(stack, label);
	return (1);
}

/**
 * Implements the 'p' instruction
 *
 * @param dest Destination.
 * @param src Src.
 */
int	p(t_array *dest, t_array *src, char label)
{
	dest->a[dest->l] = src->a[src->l - 1];
	dest->l++;
	src->l--;
	ft_putchar_fd('p', 1);
	ft_putchar_fd(label, 1);
	ft_putchar_fd('\n', 1);
	return (1);
}


/**
 * Sorts maps with 3 or lesser values.
 *
 * @param stack A pointer to the array to be sorted.
 * @return The total number of moves required to sort the array.
 */
int	sort_smallest_map(t_array *stack)
{
	int *a;
	int l;
	int total_moves;

	a=stack->a;
	l=stack->l;
	total_moves = 0;
	if(stack->l > 3)
		return (0);
	while (!ft_arrissorted(stack))
	{
		if (stack->l == 2 || a[0] == 0)
			total_moves += s(stack,'a');
		else if (a[0] == 1 && a[1] == 2)
			total_moves +=rr(stack, 'a');
		else if (a[0] == 1 && a[1] == 0)
			total_moves +=r(stack, 'a') + s(stack,'a');
		else if (a[0] == 2 && a[1] == 1)
			total_moves +=rr(stack, 'a') + s(stack,'a');
		else if (a[0] == 2 && a[1] == 0)
			total_moves +=r(stack, 'a');
	}
	return (total_moves);
}

/**
 * Since the biggest problem to efficiency is to move as many unused values
 * outside the starting array, this function uses the same pattern as
 * the fn 'rotate_which' on multiple values >=low (3), moving
 * close to the head of the array the first number available bigger than 2
 *
 * @param a Stack to rotate.
 * @param low Value of the element from wih on we'll bring the closest to edge.
 * @param label the label of the stack we are shifting.
 * @param cls must be initialized as INT_MAX by the caller (NORM)
 */
int	push_larges_to_head(t_array *a, int low, char label, int cls)
{
	t_array	*clone;
	int		i;
	int		direction;

	clone = ft_arrsort(ft_arrclone(a));
	while (clone->a[clone->l - 1] >= low)
	{
		i = ft_arrindexof(a, clone->a[clone->l - 1]);
		if (i + 1 >= a->l - i && i + 1 < cls)
		{
			cls = i + 1;
			direction = 1;
		}
		if (i + 1 < a->l - i && a->l - i < cls)
		{
			cls = a->l - i;
			direction = 0;
		}
		clone->l--;
	}
	ft_arrfree(clone);
	if (direction == 1)
		return (rr(a, label));
	return (r(a, label));
}

int sort_small_map(t_array *stack_a, t_array *stack_b)
{
	int total_moves;
	int i;

	while (stack_a->l > 3 && !ft_arrissorted(stack_a))
	{
		if(stack_a->a[stack_a->l - 1] > 2)
			total_moves+=p(stack_b, stack_a,'b');
		else
			total_moves+=push_larges_to_head(stack_a, ft_arrfindl(stack_a), 'a', INT_MAX);
	}
	if(!ft_arrissorted(stack_a) && stack_a->l == 3)
		total_moves+=sort_smallest_map(stack_a);
	while (stack_b->l > 0)
	{
		i = ft_arrindexof(stack_b, ft_arrfinds(stack_b));
		if(i == stack_b->l - 1)
			total_moves+=p(stack_a, stack_b,'a');
		else if(stack_b->l == 2)
			total_moves+=s(stack_b,'b');
		else
			total_moves+=rotate_which(stack_b, i, 'b');
	}
	return (total_moves);
}

/**
 * To correctly sort the numbers using radix sort, we need to make sure that
 * every time we extract numbers by the nth radix, the remainin numbers are
 * in the same order as in origin. Sometimes the algorithm produces a
 * shift more than is supposed to. This helps correct it
 *
 * @param orig The original array of integers.
 * @param dist The distinct array of integers.
 */
int check_filtered_order(t_array *orig, t_array *dist) {
    int i;
	int h;

	i = 0;
	h = 0;
    while (i < orig->l && h < dist->l) {
        if (orig->a[i] == dist->a[h]) {
            h++;
        }
        i++;
    }
    if (h == dist->l)
        return (1);
    return (0);
}

/**
 * Sometimes the algorithm produces a shift more than is supposed to.
 * This finds the best direction to shift the array to fix it
 *
 * @param original The array that holds the original sorting.
 * @param stack_a  The array wrongly shifted.
 * @return         1 if the order fix is by using left shift(r),
 * 0 for right shift (rr)
 */
int find_direction_fix(t_array *ordered, t_array *stack){
	int h=0;
	int k =0;
	t_array *temp = ft_arrclone(stack);
	while (!check_filtered_order(ordered, temp))
	{
		ft_arrshftl(temp);
		h++;
	}
	ft_arrfree(temp);
	temp = ft_arrclone(stack);
	while (!check_filtered_order(ordered, temp))
	{
		ft_arrshftr(temp);
		k++;
	}
	ft_arrfree(temp);
	return (h<k);
}

#define STACK_SIZE 500
/*

size: size is not only the size of the input, maap and stacks arrays, but also
size-1 is the maximum number that will appear in the map array.
n_base_mask: is not only used as a mask to retrieve the value of a n_base digit
within it's int rappresentation, but also the max value of a n_base digit.
*/
int	main(void)
{
	int	*input =(int *)malloc(STACK_SIZE * sizeof(int));
	for (int i = 0; i < STACK_SIZE; i++) {
        input[i] = i - 50;
    }
	srand(time(NULL));
    for (int i = 0; i < STACK_SIZE; i++) {
        int randomIndex = rand() % STACK_SIZE;
        int temp = input[i];
        input[i] = input[randomIndex];
        input[randomIndex] = temp;
    }
	t_array *map = normalize_input(input, STACK_SIZE);
	t_array *stack_a = ft_arrclone(map);
	t_array	*stack_b = ft_arrnew(STACK_SIZE);
	t_array *clone;
	t_array *temp;
	int size = STACK_SIZE;
	int total_moves = 0;
	int	i;
	int	h;
	int k;
	int pruning_complete;
	int n_base = 2;
	int n_base_mask = ipow(2, n_base) - 1;
	int bit_count = digit_counter(size - 1, n_base);
	if(size <= 3 && !ft_arrissorted(stack_a))
		total_moves = sort_smallest_map(stack_a);
	else if(size <= 37 && !ft_arrissorted(stack_a))
		total_moves = sort_small_map(stack_a, stack_b);
	else if(!ft_arrissorted(stack_a)){
		i = 0;
		while (i < bit_count)
		{
			h = 0;
			stack_b->l = 0;
			stack_a->l = size;
			clone = ft_arrclone(stack_a);
			while (h < size)
			{
				if (((stack_a->a[stack_a->l - 1] >> i * n_base) & n_base_mask) > 0) // i'll keep largest digits (if any) in stack_a
					total_moves+=p(stack_b, stack_a,'b');
				else {
					k = 1;
					pruning_complete =1;
					while(k <= n_base_mask){
						if(contains_dgt_grp(stack_a, k, i, n_base)){
							pruning_complete = 0;
							break;
						}
						k++;
					}
					if(pruning_complete)
						h = size;
					else
					{
						total_moves+=rr(stack_a, 'a');
						h++;
					}
				}
			}
			while (!check_filtered_order(clone, stack_a))
				if(find_direction_fix(clone, stack_a))
					total_moves+=r(stack_a,'a');
				else
					total_moves+=rr(stack_a,'a');
			h = 1;
			ft_arrrev(clone);
			while(h <= n_base_mask){
				while(contains_dgt_grp(stack_b, h, i, n_base)){
					if(extract_digit(stack_b->a[stack_b->l - 1],i,n_base) == h)
						total_moves+=p(stack_a, stack_b, 'a');
					else
						total_moves+=rr(stack_b, 'b');
				}
				h++;
				while (!check_filtered_order(clone, stack_b))
					if(find_direction_fix(clone, stack_b))
						total_moves+=r(stack_b, 'b');
					else
						total_moves+=rr(stack_b, 'b');
			}
			ft_arrfree(clone);
			i++;
			if (ft_arrissorted(stack_a))
				break ;
		}
	}
	printf("\ntotal moves: %d\n", total_moves);
	printArray("result",denormalize(input, map->a, stack_a->a, STACK_SIZE), STACK_SIZE);
	ft_arrfree(stack_a);
	ft_arrfree(stack_b);
	ft_arrfree(map);
	free(input);
	return (0);
}
