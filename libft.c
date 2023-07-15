/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 03:26:34 by amarabin          #+#    #+#             */
/*   Updated: 2023/07/15 15:15:08 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_array	*ft_arrnew(int max_size)
{
	t_array	*array;

	array = (t_array *)malloc(sizeof(t_array));
	if (array == NULL)
		return (NULL);
	array->a = (int *)malloc(max_size * sizeof(int));
	if (array->a == NULL)
	{
		free(array);
		return (NULL);
	}
	array->l = 0;
	return (array);
}

void	ft_arrfree(t_array *array)
{
	free(array->a);
	free(array);
}

t_array	*ft_arrclone(t_array *arr)
{
	t_array	*clone;

	clone = ft_arrnew(arr->l);
	if (clone == NULL)
		return (NULL);
	while (clone->l < arr->l)
	{
		clone->a[clone->l] = arr->a[clone->l];
		clone->l++;
	}
	return (clone);
}

void	ft_arrrev(t_array *array)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = array->l - 1;
	while (i < j)
	{
		temp = array->a[i];
		array->a[i] = array->a[j];
		array->a[j] = temp;
		i++;
		j--;
	}
}

/**
 * Shifts the elements of the array to the right by one position.
 *
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
