/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 01:47:57 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/08 00:48:05 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int	free_main(int *input, t_array *map, t_stacks *stks, t_n_base *n_base)
{
	if (input)
		free(input);
	if (map)
		ft_arrfree(map);
	if (stks)
		free_stacks(stks);
	if (n_base)
		free(n_base);
	return (0);
}

int	main(int size, char *argv[])
{
	int			*input;
	t_array		*map;
	t_stacks	*stks;
	t_n_base	*n_base;

	if (size < 2)
		return (0);
	input = parse_input(&size, argv);
	if (!input)
		return (print_error());
	reverse_array(input, size);
	map = normalize_input(input, size);
	if (!map)
		return (free_main(input, NULL, NULL, NULL), print_error());
	stks = init_stacks(map, size);
	if (!stks)
		return (free_main(input, map, NULL, NULL), print_error());
	n_base = init_n_base_data(2, size - 1);
	if (!n_base)
		return (free_main(input, map, stks, NULL), print_error());
	if (size <= 3 && !ft_arrissorted(stks->a))
		sort_smallest_map(stks->a);
	else if (size <= 32 && !ft_arrissorted(stks->a))
		sort_small_map(stks->a, stks->b);
	else if (!ft_arrissorted(stks->a))
		n_binary_radix_sort(stks, n_base, size);
	return (free_main(input, map, stks, n_base));

	//compile
}
