/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_binary_radix_sort_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 03:05:55 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/04 01:54:51 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return ((number / (int)ipow(n_base, digit)) % n_base);
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
 * To correctly sort the numbers using radix sort, we need to make sure that
 * every time we extract numbers by the nth radix, the remainin numbers are
 * in the same order as in origin. Sometimes the algorithm produces a
 * shift more than is supposed to. This function finds if the current order
 * is out of line and returns the best direction to shift the array to fix.
 *
 * @param map  The array that holds the original sorting map.
 * @param dist The distinct array of integers.
 */
static int	check_filtered_order(t_array *map, t_array *dist)
{
	int	i;
	int	h;

	i = 0;
	h = 0;
	while (i < map->l && h < dist->l)
	{
		if (map->a[i] == dist->a[h])
			h++;
		i++;
	}
	if (h == dist->l)
		return (1);
	return (0);
}

/**
 * Sometimes the algorithm produces a shift more or less than
 * is supposed to.
 * In a similar way as fix_stack_shift, this finds the best direction
 * to shift the array to fix the problem.
 *
 * @param map      The array that holds the original sorting map.
 * @param stack_a  The array wrongly shifted.
 * @return         0 if the order fix is by using right shift(r),
 * 1 for left shift (rr)
 */
static int	find_direction_fix(t_array *map, t_array *stack)
{
	int		h;
	int		k;
	t_array	*temp;

	h = 0;
	k = 0;
	temp = ft_arrclone(stack);
	if (!temp)
		return (-1);
	while (!check_filtered_order(map, temp))
	{
		ft_arrshftl(temp);
		h++;
	}
	ft_arrfree(temp);
	temp = ft_arrclone(stack);
	if (!temp)
		return (-1);
	while (!check_filtered_order(map, temp))
	{
		ft_arrshftr(temp);
		k++;
	}
	ft_arrfree(temp);
	return (h < k);
}

/**
 * In Radix sorting all the numbers of each progressive sorting must be kept
 * in a specific order. Furthermore they must remain in the bucket they
 * belong to.
 * This function fixes the order of the given stack based on the provided map
 * that keeps the original order of the numbers by performing the necessary
 * shifts.
 *
 * @param stack The stack to fix the order for.
 * @param map The map representing the desired order of the stack.
 * @param label The label representing the stack ('a' or 'b').
 * @return The total number of moves performed.
 */
int	fix_stack_shift(t_array *stack, t_array *map, char label)
{
	int	total_moves;

	total_moves = 0;
	while (!check_filtered_order(map, stack))
	{
		if (find_direction_fix(map, stack))
			total_moves += rr(stack, label);
		else
			total_moves += r(stack, label);
	}
	return (total_moves);
}
