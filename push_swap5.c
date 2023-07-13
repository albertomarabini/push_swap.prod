#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	if (s == NULL)
		return (NULL);
	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
char	*ft_strnew(size_t size)
{
	char	*str;

	if (size == 0)
		size = 1;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memset(str, '\0', size + 1);
	return (str);
}

void bubble_sort(int *array, int size)
{
	int	temp;
	int	i;
	int	h;

	i = 0;
	while (i < size - 1)
	{
		h = 0;
		while (h < size - i - 1)
		{
			if (array[h] > array[h + 1])
			{
				temp = array[h];
				array[h] = array[h + 1];
				array[h + 1] = temp;
			}
			h++;
		}
		i++;
	}
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
int *normalize_input(int *array, int size)
{
	int *sorted;
    int curr;
    int i;

    i = 0;
	sorted =(int *)malloc(size * sizeof(int));
	if (sorted == NULL)
        return NULL;
    while (i < size)
	{
		sorted[i] = array[i];
		i++;
	}
	bubble_sort(sorted, size);
    i = 0;
    while (i < size)
    {
        curr = 0;
        while (array[curr] != sorted[i])
            curr++;
        sorted[i] = curr;
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
 * Compare two digits of numbers stored in the base rappresented by n_base
 * being 1>base 2, 2>base 4, 3>base 8, 4>base 16, etc.
 *
 * This function compares the specified digit (group of n bits)of two numbers.
 * @param n1 The first number to compare.
 * @param n2 The second number to compare.
 * @param digit The digit position to compare (1-indexed).
 * @param n_base The base used for storing the numbers.
 * @return 1 if n1 > n2, -1 if n2 > n1, 0 if equal.
 * @note The mask variable is a group of n_base 1's used to mask the bits we
 * want to compare. Can be calculated as either 2^n_base - 1 or
 * (1 << n_base) - 1
 * ex:with n_base=3 (1<<n_base) = 1000, (1<<n_base)-1 = 111 = 7 =2^n_base - 1
 * @note (n_base>>digit*n_base) shifts the bits of n_base to the right by
 * bringing the bitscorresponding at the  digit position at the beginning of
 * the number so to mask them with & mask
 * @note the position digit is 0 based
 */
int	compare_base_digit(int n1, int n2, int digit, int n_base)
{
	int	mask;
	int	digit_n1;
	int	digit_n2;

	mask = (1 << n_base) - 1;
	digit_n1 = (n1 >> digit * n_base) & mask;
	digit_n2 = (n2 >> digit * n_base) & mask;
	if (digit_n1 > digit_n2)
		return (1);
	else if (digit_n2 > digit_n1)
		return (-1);
	else
		return (0);
}
/**
 * Find the position for a number in a stack based on a specific digit
 * in base n_base being n_base1>base 2, 2>base 4, 3>base 8, 4>base 16, etc.
 *
 * @param stack The stack array.
 * @param size The size of the stack array.
 * @param number The number to be inserted.
 * @param digit The digit position to compare (1-indexed).
 * @param n_base The base used for storing the numbers.
 * @return The position for inserting the number in the stack.
 */
int	find_b_stack_pos(int *stack, int size, int number, int digit, int n_base)
{
	int	position;
	int comp;
	int	i;

	position = 0;
	i = size - 1;
	while (i >= 0)
	{
		comp = compare_base_digit(stack[i], number, digit, n_base);
		if (comp<1)
		{
			position = i + 1;
			break ;
		}
		i--;
	}
	return (position);
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
 * @param size The size of the stack array.
 * @param digit_grp The desired digit group.
 * @param digit The digit position to check (1-indexed).
 * @param n_base The base used for storing the numbers.
 * @return 1 if the stack contains numbers belonging to the specified digit group, 0 otherwise.
 */
int	check_dgt_grp_in_stack(int *stack, int size, int digit_grp, int digit, int n_base)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (extract_digit(stack[i], digit, n_base) == digit_grp)
			return (1);
		i++;
	}
	return (0);
}

/**
 * Implements the 'r' instruction
 *
 * @param stack The stack to be rotated.
 * @param length The length of the stack.
 */
void r(int *stack, int length)
{
	int	temp;
	int i;

	temp = stack[0];
	i = 0;
	while (i < length - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[length - 1] = temp;
}

/**
 * Implements the 'rr' instruction
 *
 * @param stack The stack to be rotated.
 * @param length The length of the stack.
 */
void rr(int *stack, int length)
{
	int		temp;
	int		i;

	temp = stack[length - 1];
	i = length-1;
	while(i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
}

/**
 * Implements the 'p' instruction
 *
 * @param dest Destination.
 * @param dest_l The length of destination.
 * @param src Src.
 * @param src_l The length of src.
 */
void	p(int *dest, int *dest_l, int *src, int *src_l)
{
	dest[*dest_l] = src[*src_l-1];
	(*dest_l)++;
	(*src_l)--;
}

/**
 * Checks if an array is sorted in ascending order.
 *
 * @param stack The array to be checked for sorting.
 * @param size The size of the array.
 * @return 1 if the array is sorted in ascending order, 0 otherwise.
 */
int	is_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i + 1] < stack[i])
			return (0);
		i++;
	}
	return (1);
}

/**
 * CLones an array.
 */
int* clone_array(int *arr, int size)
{
	int	*clone;
	int	i;

	clone = (int *)malloc(size * sizeof(int));
	if (clone == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		clone[i] = arr[i];
		i++;
	}
	return (clone);
}
/**
 * To correctly sort the numbers using radix sort, we need to make sure that
 * every time we extract numbers by the nth radix, the remainin numbers are
 * in the same order as in origin.
 *
 * @param orig The original array of integers.
 * @param l_orig The length of the original array.
 * @param dist The distinct array of integers.
 * @param l_dist The length of the distinct array.
 */
int check_filtered_order(int *orig, int l_orig, int *dist, int l_dist) {
    int i;
	int h;

	i = 0;
	h = 0;
    while (i < l_orig && h < l_dist) {
        if (orig[i] == dist[h]) {
            h++;
        }
        i++;
    }
    if (h == l_dist)
        return (1);
    return (0);
}
void reverse_array(int* array, int size) {
    int i = 0;
    int j = size - 1;

    while (i < j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
}
/**
 * The function takes a normalized version of stack_a, stack_b (empty)
 * and the size of stack_a as input.
 * Calculate the max possible number of bits (in a normalized array the max
 * number is size-1. It performs radix sort on the array by
 * iterating over each bit position from the least significant to the most
 * significant. It uses stack_b as an auxiliary stack for temporary storage
 * during the sorting process.
 *
 * @param stack_a The normalized array to be sorted.
 * @param stack_b The empty stack B for temporary storage.
 * @param size The size of the array.
 */
// void	radix_sort(int *stack_a, int *stack_b, int size)
// {
// 	int	i;
// 	int	h;
// 	int	size_b;

// 	i = 0;
// 	while (i < digit_counter(size - 1))
// 	{
// 		h = size - 1;
// 		size_b = 0;
// 		while (h >= 0)
// 		{
// 			if (((stack_a[h] >> i) & 1) == 0)
// 			{
// 				p(stack_b, size_b, stack_a, h);
// 				size_b++;
// 			}
// 			else
// 				rr(stack_a, size - size_b);
// 			h--;
// 		}
// 		while (size_b >= 0)
// 		{
// 			p(stack_a, bla bla something, 'a');
// 			size_b--;
// 		}
// 		i++;
// 		if (is_sorted(stack_a, size))
// 			break ;
// 	}
// }

int check_filtered_order_b(int *clone, int size, int *stack_a, int size_a){
	int h=0;
	int k =0;
	int *temp = clone_array(stack_a, size_a);
	while (!check_filtered_order(clone, size, temp, size_a))
	{
		r(temp, size_a);
		h++;
	}
	free(temp);
	temp = clone_array(stack_a, size_a);
	while (!check_filtered_order(clone, size, temp, size_a))
	{
		rr(temp, size_a);
		k++;
	}
	free(temp);
	return (h<k);
}


void printArray(int *array, int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

#define STACK_SIZE 100
// typedef struct s_radix_group
// {
// 	int	first;
// 	int	last;
// 	int	count;
// 	int digit;
// }	t_radix_group;

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
	int *map = normalize_input(input, STACK_SIZE);
	int *stack_a = clone_array(map, STACK_SIZE);
	printf("Input\n ");
	printArray(input, STACK_SIZE);
	int	*stack_b =(int *)malloc(STACK_SIZE * sizeof(int));
	int *clone;
	int *temp;
	int size = STACK_SIZE;
	int total_moves = 0;
	int	i;
	int	h;
	int k;
	int	size_b;
	int	size_a;
	int n_base = 2;
	int n_base_mask = ipow(2, n_base) - 1;
	int bit_count = digit_counter(size - 1, n_base);
	if(!is_sorted(stack_a, size)){
		i = 0;
		while (i < bit_count)
		{
			h = 0;
			size_b = 0;
			size_a = size;
			clone = clone_array(stack_a, size_a);
			while (h < size)
			{
				if (((stack_a[size_a - 1] >> i * n_base) & n_base_mask) > 0) // i'll keep largest digits (if any) in stack_a
				{
					p(stack_b, &size_b, stack_a, &size_a);
					printf("pb ");
					total_moves++;
				}
				else {
					rr(stack_a, size_a);
					printf("rra ");
					total_moves++;
					h++;
				}
			}
			while (!check_filtered_order(clone, size, stack_a, size_a))
			{
				if(check_filtered_order_b(clone, size, stack_a, size_a))
					r(stack_a, size_a);
				else
					rr(stack_a, size_a);
				printf("ra ");
				total_moves++;
			}
			h = 1;
			reverse_array(clone, size);
			while(h <= n_base_mask){
				while(check_dgt_grp_in_stack(stack_b, size_b, h, i, n_base)){
					if(extract_digit(stack_b[size_b - 1],i,n_base) == h){
						p(stack_a, &size_a, stack_b, &size_b);
						printf("pa ");
					} else {
						rr(stack_b, size_b);
						printf("rb ");
					}
					total_moves++;
				}
				h++;
				while (!check_filtered_order(clone, size, stack_b, size_b))
				{
					if(check_filtered_order_b(clone, size, stack_b, size_b))
						r(stack_b, size_b);
					else
						rr(stack_b, size_b);
					printf("ra ");
					total_moves++;
				}
			}
			free(clone);
			i++;
			if (is_sorted(stack_a, size))
				break ;
		}
	}
	printf("\ntotal moves: %d\n", total_moves);
	printArray(denormalize(input, map, stack_a, STACK_SIZE), STACK_SIZE);
	return (0);
}
