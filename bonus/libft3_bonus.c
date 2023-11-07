/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 01:58:22 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/05 10:39:18 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

/**
 * Converts a string representation of an integer to an integer value.
 *
 * The function parses the input string `nptr` and converts it to an integer.
 * If an error condition occurs, the first character of the input string is
 * modified to 'E' and 0 is returned.
 *
 * @param nptr The string to convert to an integer.
 * @return The converted integer value if successful, 0 if an error occurs.
 */
int	ft_atoi_mod(char *nptr)
{
	int			sign;
	long long	result;
	int			i;

	sign = 1;
	result = 0;
	i = 0;
	if (!nptr)
		return (0);
	if (nptr[0] == '-' || nptr[0] == '+')
	{
		if (nptr[0] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = (result * 10) + (nptr[i++] - '0');
	result *= sign;
	if (nptr[i] != '\0' || result > INT_MAX || result < INT_MIN)
	{
		nptr[0] = 'E';
		return (0);
	}
	return ((int)result);
}