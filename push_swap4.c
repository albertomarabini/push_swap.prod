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
 * @brief Count the number of bits in an integer.
 *
 * The function takes an integer `n` as input and counts the number of bits in
 * it by performing a right shift operation on it until it becomes zero,
 *
 * @param n The integer for which to count the number of bits.
 * @return The number of bits in the given integer.
 */
int	bit_counter(int n)
{
	int	bit_count;

	bit_count = 0;
	while (n != 0)
	{
		n = n >> 1;
		bit_count++;
	}
	return (bit_count);
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
void	p(int **dest, int *dest_l, int **src, int *src_l)
{
	(*dest)[*dest_l] = (*src)[*src_l-1];
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
// 	while (i < bit_counter(size - 1))
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


void printArray(int *array, int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

#define STACK_SIZE 500

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
	int *clone_b;
	int size = STACK_SIZE;
	int total_moves = 0;
	int	i;
	int	h;
	int k;
	int	size_b;
	int	size_a;
	i = 0;
	// printf("Normalized array:\n ");
	// printArray(stack_a, STACK_SIZE);
	int bit_count = bit_counter(size - 1);
	if(!is_sorted(stack_a, size)){
		while (i < bit_count)
		{
			h = 0;
			size_b = 0;
			size_a = size;
			printf("At i =%i\n ",i);
			printArray(stack_a, size_a);
			printArray(stack_b, size_b);
			clone = clone_array(stack_a, size_a);
			while (h < size)
			{
				if (((stack_a[size_a - 1] >> i) & 1) == 0)
				{
					p(&stack_b, &size_b, &stack_a, &size_a);
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
			printf("After Pass\n ");
			printArray(stack_a, size_a);
			printArray(stack_b, size_b);
			printArray(clone, size);
			clone_b = clone_array(stack_a, size_a);
			h=0;
			while (!check_filtered_order(clone, size, clone_b, size_a))
			{
				r(clone_b, size_a);
				h++;
			}
			free(clone_b);
			clone_b = clone_array(stack_a, size_a);
			k=0;
			while (!check_filtered_order(clone, size, clone_b, size_a))
			{
				rr(clone_b, size_a);
				k++;
			}
			free(clone_b);
			while (!check_filtered_order(clone, size, stack_a, size_a))
			{
				if(h<k)
					r(stack_a, size_a);
				else
					rr(stack_a, size_a);
				printf("ra ");
				total_moves++;
			}
			free(clone);
			while (size_b > 0)
			{
				p(&stack_a, &size_a, &stack_b, &size_b);
				printf("pa ");
				total_moves++;
			}
			// printf("Rebuilt\n ");
			// printArray(stack_a, size_a);
			// printArray(stack_b, size_b);
			i++;
			if (is_sorted(stack_a, size))
				break ;
		}
	}
	printf("\ntotal moves: %d\n", total_moves);
	printArray(denormalize(input, map, stack_a, STACK_SIZE), STACK_SIZE);
	return (0);
}
