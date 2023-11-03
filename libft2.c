/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 03:26:34 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/02 01:40:15 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Shifts the elements of the array to the right by one position.
 * The last element becomes the first one.
 * @param stack A pointer to the array to be shifted.
 */
void	ft_arrshftl(t_array *stack)
{
	int	temp;
	int	i;

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
 * The first element becomes the last one.
 * @param stack A pointer to the array to be shifted.
 */
void	ft_arrshftr(t_array *stack)
{
	int	temp;
	int	i;

	temp = stack->a[stack->l - 1];
	i = stack->l - 1;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = temp;
}

// t_array	*ft_arrsort(t_array *array)
// {
// 	int	temp;
// 	int	i;
// 	int	h;

// 	i = 0;
// 	while (i < array->l - 1)
// 	{
// 		h = 0;
// 		while (h < array->l - i - 1)
// 		{
// 			if (array->a[h] > array->a[h + 1])
// 			{
// 				temp = array->a[h];
// 				array->a[h] = array->a[h + 1];
// 				array->a[h + 1] = temp;
// 			}
// 			h++;
// 		}
// 		i++;
// 	}
// 	return (array);
// }

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
int	ft_arrindexof(t_array *arr, int n)
{
	int	i;

	i = 0;
	while (i < arr->l)
	{
		if (arr->a[i] == n)
		{
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
int	ft_arrfindl(t_array *arr)
{
	t_array	*clone;
	int		largest;

	if (arr->l == 0)
		return (-1);
	clone = ft_arrclone(arr);
	ft_arrsort(clone);
	largest = clone->a[clone->l - 1];
	ft_arrfree(clone);
	return (largest);
}
