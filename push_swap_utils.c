/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 03:23:23 by amarabin          #+#    #+#             */
/*   Updated: 2023/07/15 15:10:12 by amarabin         ###   ########.fr       */
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
static int	digit_counter(int value, int n_base)
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

t_n_base	*init_n_base_data(int n_base, int maxsize)
{
	t_n_base	*data;

	data = (t_n_base *)malloc(sizeof(t_n_base));
	data->base = n_base;
	data->mask = ipow(2, n_base) - 1;
	data->largest_digit = ipow(2, n_base) - 1;
	data->dgt_count = digit_counter(maxsize, n_base);
	return (data);
}

void	free_n_base_data(t_n_base *data)
{
	free(data);
}

t_stacks	*init_stacks(t_array *a_map, int size)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	stacks->a = ft_arrclone(a_map);
	stacks->b = ft_arrnew(size);
	stacks->map = NULL;
	return (stacks);
}

void	free_stacks(t_stacks *stacks)
{
	ft_arrfree(stacks->a);
	ft_arrfree(stacks->b);
	free(stacks);
}
