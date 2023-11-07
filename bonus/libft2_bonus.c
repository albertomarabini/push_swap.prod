/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 04:29:43 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/05 10:26:18 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
 * ft_strcmp - Compare two strings.
 *
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 *
 * Return: An int less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL)
	{
		if (s2 == NULL)
			return (0);
		else
			return (-1);
	}
	if (s2 == NULL)
		return (1);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

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
