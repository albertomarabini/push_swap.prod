/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 03:26:34 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/01 06:46:48 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Find the smalles integer in the given array.
 *
 * @param arr The array from which to find the largest integer.
 * @param n The largest integer in the array.
 */
int	ft_arrfinds(t_array *arr)
{
	t_array	*clone;
	int		largest;

	if (arr->l == 0)
		return (-1);
	clone = ft_arrclone(arr);
	ft_arrsort(clone);
	largest = clone->a[0];
	ft_arrfree(clone);
	return (largest);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(const char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

/**
 * Calculate the power of an integer.
 *
 * @param n The base value.
 * @param power The exponent value.
 * @return The result of n raised to the power.
 */
int	ipow(int n, int power)
{
	int	result;
	int	i;

	result = 1;
	i = 0;
	while (i < power)
	{
		result *= n;
		i++;
	}
	return (result);
}
void reverse_array(int *arr, int len)
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
