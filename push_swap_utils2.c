/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 03:23:23 by amarabin          #+#    #+#             */
/*   Updated: 2023/07/15 15:13:02 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * The function takes an array we need to sort, sort it using a
 * whatever bubble sort, then take the index of each number and reassign it
 * inside another array, ordered in the same order as the original input.
 *
 * @param array The input array to be normalized.
 * @param size The size of the input array.
 * @return A dynamically allocated array of normalized indexes or NULL if
 * memory allocation fails.
 */
t_array	*normalize_input(int *array, int size)
{
	t_array	*sorted;
	int		curr;
	int		i;

	i = 0;
	sorted = ft_arrnew(size);
	if (sorted == NULL)
		return (NULL);
	while (i < size)
	{
		sorted->a[i] = array[i];
		sorted->l++;
		i++;
	}
	ft_arrsort(sorted);
	i = 0;
	while (i < size)
	{
		curr = 0;
		while (array[curr] != sorted->a[i])
			curr++;
		sorted->a[i] = curr;
		i++;
	}
	return (sorted);
}

/**
 * Implements the 's' instruction
 *
 * @param a pointer to the first integer (head of the first stack)
 * @param b pointer to the second integer (head of the second stack)
 * @param label The label of the stack.
 */
int	s(t_array *stack, char label)
{
	int	temp;

	temp = stack->a[stack->l - 1];
	stack->a[stack->l - 1] = stack->a[stack->l - 2];
	stack->a[stack->l - 2] = temp;
	ft_putchar_fd('s', 1);
	ft_putchar_fd(label, 1);
	ft_putchar_fd('\n', 1);
	return (1);
}

/**
 * Implements the 'r' instruction
 *
 * @param stack The stack to be rotated.
 * @param label The label of the stack.
 */
int	r(t_array *stack, char label)
{
	ft_arrshftl(stack);
	ft_putchar_fd('r', 1);
	ft_putchar_fd(label, 1);
	ft_putchar_fd('\n', 1);
	return (1);
}

/**
 * Implements the 'rr' instruction
 *
 * @param stack The stack to be rotated.
 * @param label The label of the stack.
 */
int	rr(t_array *stack, char label)
{
	ft_arrshftr(stack);
	ft_putchar_fd('r', 1);
	ft_putchar_fd('r', 1);
	ft_putchar_fd(label, 1);
	ft_putchar_fd('\n', 1);
	return (1);
}

/**
 * Implements the 'p' instruction
 *
 * @param dest Destination.
 * @param src Src.
 */
int	p(t_array *dest, t_array *src, char label)
{
	dest->a[dest->l] = src->a[src->l - 1];
	dest->l++;
	src->l--;
	ft_putchar_fd('p', 1);
	ft_putchar_fd(label, 1);
	ft_putchar_fd('\n', 1);
	return (1);
}
