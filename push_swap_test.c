/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 01:40:27 by amarabin          #+#    #+#             */
/*   Updated: 2023/09/25 01:23:11 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int	indexof(int n, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == n)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
void	printArray(char *label, int *array, int size)
{
	printf("%s: ", label);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int	*dnrmlize(int *original, int *map, int *normalized, int size)
{
	int	*ret;
	int	i;

	ret = malloc(sizeof(int) * size);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ret[i] = original[indexof( normalized[i], map, size)];
		i++;
	}
	return (ret);
}

int	*generate_test(int size)
{
	int	rnd;
	int	temp;
	int	*test;

	test = (int *)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
		test[i] = i - 50;
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		rnd = rand() % size;
		temp = test[i];
		test[i] = test[rnd];
		test[rnd] = temp;
	}
	return (test);
}

int	main(void)
{
	int			*input;
	t_array		*map;
	t_stacks	*stks;
	int			total_moves;
	t_n_base	*n_base;
	int			size;

	size = 50;
	input = generate_test(size);
	printArray("test", input, size);
	map = normalize_input(input, size);
	stks = init_stacks(map, size);
	printArray("\nmap\n", map->a, size);
	printArray("\nnorm\n", stks->a->a, size);
	total_moves = 0;
	n_base = init_n_base_data(2, size - 1);
	if (size <= 3 && !ft_arrissorted(stks->a))
		total_moves = sort_smallest_map(stks->a);
	else if (size <= 37 && !ft_arrissorted(stks->a))
		total_moves = sort_small_map(stks->a, stks->b);
	else if (!ft_arrissorted(stks->a))
		total_moves = n_binary_radix_sort(stks, n_base, size);
	printf("\ntotal moves: %d\n", total_moves);
	printArray("\nmap\n", map->a, size);
	printArray("\nnorm\n", stks->a->a, size);
	printArray("result", dnrmlize(input, map->a, stks->a->a, size), size);
	free_stacks(stks);
	free_n_base_data(n_base);
	ft_arrfree(map);
	free(input);
	return (0);
}
