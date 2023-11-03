/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 01:47:57 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/03 07:30:10 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * 
 * NUMERIC RAPPRESENTATION OF THE STACKS
 * 
 * the command ./checker_Mac "1 2 3 4 5" considers 1 to be the head of the
 * stack.
 * <-- rra  ra -->
 *    1 2 3 4 5
 *    ^ head
 * but using arrays the head of the stack has to be the last element of
 * our stack
 * 
 * <-- ra  rra -->
 *    5 4 3 2 1
 *       head ^
 */


/** DELETE!!!! */
#include <stdio.h>
int	indexof(int n, int *arr, int size)
{
	int	i;
//Delete this
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
	//also delete this
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
	//delete this
}

int	main(int size, char *argv[])
{
	int			*input;
	int			tm;
	t_array		*map;
	t_stacks	*stks;
	t_n_base	*n_base;

	tm = 0;
	input = parse_input(&size, argv);
	if (!input)
		return (0);
	reverse_array(input, size);
	map = normalize_input(input, size);
	stks = init_stacks(map, size);
	n_base = init_n_base_data(4, size - 1);
	if (size <= 3 && !ft_arrissorted(stks->a))
		tm = sort_smallest_map(stks->a);
	else if (size <= 200 && !ft_arrissorted(stks->a))
		tm = sort_small_map(stks->a, stks->b);
	else if (!ft_arrissorted(stks->a))
		tm = n_binary_radix_sort(stks, n_base, size);


	/** DEBUG */

	// printf("\ntotal moves: %d\n", tm);
	// printArray("\nmap\n", map->a, size);
	// printArray("\nnorm\n", stks->a->a, size);
	// printArray("result", dnrmlize(input, map->a, stks->a->a, size), size);

	
	/** DEBUG */

		
	free_stacks(stks);
	free(n_base);
	ft_arrfree(map);
	free(input);
	return (0);
	//What about trying in base 5 by simply using the % operator?!!
}
