/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 03:23:23 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/04 06:50:59 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Count the number of n_base long bit groups in an integer.
 *
 * The function takes an integer `n` as input and counts the number of digits
 * in base n_base (1 for base2, 2 for base 4, 3 for base 8, 4 for base 16)
 * contained by performing a right shift operation on it until it becomes zero
 *
 * @param value The integer for which to count the number of bits.
 * @param n_base The base used for storing the number.
 * @return The number of bits in the given integer.
 */
// static int	digit_counter(int value, int n_base)
// {
// 	int	bit_count;

// 	bit_count = 0;
// 	while (value != 0)
// 	{
// 		value = value >> n_base;
// 		bit_count++;
// 	}
// 	return (bit_count);
// }

static int	digit_counter(int value, int n_base)
{
	int	digit_count;

	digit_count = 0;
	while (value != 0)
	{
		value = value / n_base;
		digit_count++;
	}
	return (digit_count);
}

t_n_base	*init_n_base_data(int n_base, int maxsize)
{
	t_n_base	*data;

	data = (t_n_base *)malloc(sizeof(t_n_base));
	data->base = n_base;
	data->mask = n_base - 1;
	data->largest_digit = n_base - 1;
	data->dgt_count = digit_counter(maxsize, n_base);
	return (data);
}

/**
 * Fetch the element from the head of the array - d(elta) positions.
 */
int	head(t_array *stack, int d)
{
	if (d >= stack->l || d < 0)
		return (-1);
	return (stack->a[stack->l - 1 - d]);
}


t_stacks	*init_stacks(t_array *a_map, int size)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (stacks == NULL)
		return (NULL);
	stacks->a = ft_arrclone(a_map);
	if (stacks->a == NULL)
		return (free_stacks(stacks), NULL);
	stacks->b = ft_arrnew(size);
	if (stacks->b == NULL)
		return (free_stacks(stacks), NULL);
	stacks->map = NULL;
	return (stacks);
}

void	free_stacks(t_stacks *stacks)
{
	if (stacks->a)
		ft_arrfree(stacks->a);
	if (stacks->b)
		ft_arrfree(stacks->b);
	free(stacks);
}
