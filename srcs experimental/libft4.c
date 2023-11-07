/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 01:58:22 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/02 14:05:09 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_array	*ft_iarrsort(t_array *array, int desc)
{
	int	temp;
	int	i;
	int	h;

	i = 0;
	while (i < array->l - 1)
	{
		h = 0;
		while (h < array->l - i - 1)
		{
			if ((desc && array->a[h] > array->a[h + 1]) || (!desc
					&& array->a[h] < array->a[h + 1]))
			{
				temp = array->a[h];
				array->a[h] = array->a[h + 1];
				array->a[h + 1] = temp;
			}
			h++;
		}
		i++;
	}
	return (array);
}

t_array	*ft_arrsort(t_array *arr)
{
	ft_iarrsort(arr, 1);
	return (arr);
}

t_array	*ft_arrisort(t_array *arr)
{
	ft_iarrsort(arr, 0);
	return (arr);
}

/**
 * Takes a pointer to a t_array structure and an integer flag
 * to specify the sorting order, then determines if the array is sorted
 *
 * @param stack t_array structure containing the integer array.
 * @param desc Specify the sorting order.
 *              - 1 for descending order.
 *              - 0 for ascending order.
 * @return Returns 1 stack is sorted according to the specified order
 */
int	ft_iarrissorted(t_array *stack, int desc)
{
	int	i;

	i = 0;
	while (i < stack->l - 1)
	{
		if ((desc && stack->a[i + 1] < stack->a[i]) || (!desc
				&& stack->a[i + 1] > stack->a[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_arriscsorted(t_array *stack)
{
	int	i;

	i = 0;
	while (i < stack->l - 1)
	{
		if (stack->a[i + 1] < stack->a[i] || stack->a[i + 1] - stack->a[i] > 1)
			return (0);
		i++;
	}
	return (1);
}
