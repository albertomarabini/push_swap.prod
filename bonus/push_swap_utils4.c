/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 05:01:10 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/05 05:38:16 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"


/**
 * Implements the 's' instruction
 *
 * @param a pointer to the first integer (head of the first stack)
 * @param b pointer to the second integer (head of the second stack)
 * @param label The label of the stack.
 */
int	s(t_array *stack)
{
	int	temp;

	temp = stack->a[stack->l - 1];
	stack->a[stack->l - 1] = stack->a[stack->l - 2];
	stack->a[stack->l - 2] = temp;
	return (1);
}

/**
 * Implements the 'ss' instruction
 *
 * @param a pointer to the first integer (head of the first stack)
 * @param b pointer to the second integer (head of the second stack)
 * @param label The label of the stack.
 */
int	ss(t_array *stack_a, t_array *stack_b)
{
	s(stack_a);
    s(stack_b);
	return (1);
}

/**
 * Implements the 'r' instruction
 *
 * @param stack The stack to be rotated.
 * @param label The label of the stack.
 */
int	r(t_array *stack)
{
	ft_arrshftr(stack);
	return (1);
}

/**
 * Implements the 'rr' instruction
 *
 * @param stack_a The stack to be rotated.
 * @param stack_b The stack to be rotated.
 * @param label The label of the stack.
 */
int	r_all(t_array *stack_a, t_array *stack_b)
{
	ft_arrshftr(stack_a);
	ft_arrshftr(stack_b);
	return (1);
}

/**
 * Implements the 'rr' instruction
 *
 * @param stack The stack to be rotated.
 * @param label The label of the stack.
 */
int	rr(t_array *stack)
{
	ft_arrshftl(stack);
	return (1);
}

