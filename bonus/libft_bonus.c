/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 03:26:34 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/05 04:57:00 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	reverse_array(array->a, array->l);
}

void	reverse_array(int *arr, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	}
}