/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 03:23:23 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/05 10:47:19 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * Implements the 'rr' instruction
 *
 * @param stack The stack to be rotated.
 * @param label The label of the stack.
 */
int	rrr(t_array *stack_a, t_array *stack_b)
{
	ft_arrshftl(stack_a);
	ft_arrshftl(stack_b);
	return (1);
}

/**
 * Implements the 'p' instruction
 *
 * @param dest Destination.
 * @param src Src.
 */
int	p(t_array *dest, t_array *src)
{
	dest->a[dest->l] = src->a[src->l - 1];
	dest->l++;
	src->l--;
	return (1);
}

void	ft_free_split(char **vals, int size)
{
	while (size >= 0)
		free(vals[size--]);
	free(vals);
}

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