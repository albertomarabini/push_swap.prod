#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include "push_swap.h"

void printArray(char *label, int *array, int size) {
    printf("%s: ",label);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
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








#define STACK_SIZE 15

/*

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
	t_stacks *stks = init_stacks(map, STACK_SIZE);
	int size = STACK_SIZE;
	int total_moves = 0;
	t_n_base *n_base = init_n_base_data(2, size-1);
	if(size <= 3 && !ft_arrissorted(stks->a))
		total_moves = sort_smallest_map(stks->a);
	else if(size <= 14 && !ft_arrissorted(stks->a)) //37
		total_moves = sort_small_map(stks->a, stks->b);
	else if(!ft_arrissorted(stks->a)){
		total_moves = n_binary_radix_sort(stks, n_base, size);
	}
	printf("\ntotal moves: %d\n", total_moves);
	printArray("result",denormalize(input, map->a, stks->a->a, STACK_SIZE), STACK_SIZE);
	free_stacks(stks);
	free(input);
	return (0);
}
