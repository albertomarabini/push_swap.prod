/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:50:53 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/02 14:54:26 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * This is a pattern often used: it will take longer to rotate left(r) or
 * right(rr) to bring an element at index i to head?
 *
 * @param stack Array to rotate.
 * @param i Index to the element that we want to bring to head.
 * @param src Src.
 */
static int	rotate_which(t_array *stack, int i, char label)
{
	i = i + 1 >= stack->l - i;
	if (i)
		r(stack, label);
	else
		rr(stack, label);
	return (1);
}

/**
 * Sorts maps with 3 or lesser values.
 *                                                 <-rr  r->
 *                                       Input       Rappr.
 *                              Target->[0, 1, 2]-->[0, 1, 2]*
 * (stack->l == 2)           // Handles [0, 1]
 * (a[0] == 1 && a[1] == 0)  // Handles [0, 2, 1]-->[1, 0, 2]*
 * (a[0] == 2 && a[1] == 0)  // Handles [1, 2, 0]-->[2, 0, 1]*
 * (a[0] == 0 && a[1] == 2)  // Handles [1, 0, 2]-->[0, 2, 1]*
 * (a[0] == 1 && a[1] == 2)  // Handles [2, 0, 1]-->[1, 2, 0]*
 * (a[0] == 2 && a[1] == 1)  // Handles [2, 1, 0]-->[2, 1, 0]*
 * @param stack A pointer to the array to be sorted.
 * @return The total number of moves required to sort the array.
 */
int	sort_smallest_map(t_array *stack)
{
	int	*a;
	int	total_moves;

	a = stack->a;
	total_moves = 0;
	if (!ft_arrissorted(stack))
	{
		if (stack->l == 2)
			total_moves += s(stack, 'a');
		else if (a[0] == 1 && a[1] == 0)
			total_moves += r(stack, 'a') + s(stack, 'a') + rr(stack, 'a');
		else if (a[0] == 2 && a[1] == 0)
			total_moves += rr(stack, 'a');
		else if (a[0] == 0 && a[1] == 2)
			total_moves += s(stack, 'a');
		else if (a[0] == 1 && a[1] == 2)
			total_moves += r(stack, 'a');
		else if (a[0] == 2 && a[1] == 1)
			total_moves += s(stack, 'a') + rr(stack, 'a');
	}
	return (total_moves);
}

/**
 * Since the biggest problem to efficiency is to move up and down unused values
 * in the stack, this function will find the mapping value >3 closest to the
 * the stack's head and move it there for pushing.
 *
 * @param a Stack to rotate.
 * @param low Value of the element from wih on we'll bring the closest to edge.
 * @param label the label of the stack we are shifting.
 * @param cls must be initialized as INT_MAX by the caller (NORM)
 */
static int	push_to_head(t_array *a, int low, char label, int cls)
{
	t_array	*clone;
	int		i;
	int		direction;

	clone = ft_arrsort(ft_arrclone(a));
	while (clone->a[clone->l - 1] >= low)
	{
		i = ft_arrindexof(a, clone->a[clone->l - 1]);
		if (i + 1 >= a->l - i && i + 1 < cls)
		{
			cls = i + 1;
			direction = 1;
		}
		if (i + 1 < a->l - i && a->l - i < cls)
		{
			cls = a->l - i;
			direction = 0;
		}
		clone->l--;
	}
	ft_arrfree(clone);
	if (direction == 1)
		return (r(a, label));
	return (rr(a, label));
}

// int	sort_small_map(t_array *stack_a, t_array *stack_b)
// {
// 	int	tm;
// 	int	i;

// 	tm = 0;
// 	while (stack_a->l > 3 && !ft_arriscsorted(stack_a))
// 	{
// 		if (head(stack_a,0) >2)
// 			tm += p(stack_b, stack_a, 'b');
// 		if(stack_b->l - 1 >= 2 && head(stack_b,0) > stack_b->a[0])
// 			tm += rr(stack_b, 'b');
// 		if(stack_b->l - 1 >= 2 && head(stack_b,0) > head(stack_b,1))
// 			tm += s(stack_b, 'b');
// 		if (head(stack_a,0) < head(stack_a,1) && head(stack_a,1) > 2)
// 			tm += s(stack_a, 'a');
// 		else if(head(stack_a,0) < stack_a->a[0] && stack_a->a[0] > 2)
// 			tm += rr(stack_a, 'a');
// 		else if(stack_a->l > 3)
// 			tm += push_to_head(stack_a, ft_arrfindl(stack_a), 'a', INT_MAX);
// 	}
// 	if (!ft_arriscsorted(stack_a) && stack_a->l == 3)
// 		tm += sort_smallest_map(stack_a);
// 	while (stack_b->l > 0 || !ft_arriscsorted(stack_a))
// 	{
// 		i = ft_arrindexof(stack_b, ft_arrfinds(stack_b));
// 		if (i == stack_b->l - 1)
// 			tm += p(stack_a, stack_b, 'a');
// 		else
// 			tm += rotate_which(stack_b, i, 'b');
// 		if (stack_b->l - 1 >= 2 && head(stack_b,0) > head(stack_b,1))
// 			tm += s(stack_b, 'b');
// 		if (head(stack_a,0) < head(stack_a,1))
// 			tm += s(stack_a, 'a');

int	push_back_b_elements(t_array *stack_a, t_array *stack_b)
{
	int	tm;
	int	i;

	tm = 0;
	while (stack_b->l > 0 || !ft_arriscsorted(stack_a))
	{
		i = ft_arrindexof(stack_b, ft_arrfinds(stack_b));
		if (i == stack_b->l - 1)
			tm += p(stack_a, stack_b, 'a');
		else
			tm += rotate_which(stack_b, i, 'b');
		if (stack_b->l - 1 >= 2 && head(stack_b,0) > head(stack_b,1))
			tm += s(stack_b, 'b');
		if (head(stack_a,0) < head(stack_a,1))
			tm += s(stack_a, 'a');
	}
	return (tm);
}

/**
 * Sorts maps up to 37 values.
 * First of all we remove from the stack in the quickest way possible all
 * the mapping numbers>3. Then we sort those 3 left using sort_smallest_map
 * Then we iterate trough the stack_b and push the values to stack_a in order.
 * This approach is more efficent than radix sorting up to 37 values.
 *
 * @param stack_a A pointer to the array to be sorted.
 * @param stack_b A pointer to the array to be used as a buffer.
 * @return The total number of moves required to sort the array.
 */
int	sort_small_map(t_array *stack_a, t_array *stack_b)
{
	int	tm;

	tm = 0;
	while (stack_a->l > 3 && !ft_arriscsorted(stack_a))
	{
		if (head(stack_a, 0) > 2)
			tm += p(stack_b, stack_a, 'b');
		if (stack_b->l - 1 >= 2 && head(stack_b, 0) > stack_b->a[0])
			tm += rr(stack_b, 'b');
		if (stack_b->l - 1 >= 2 && head(stack_b, 0) > head(stack_b, 1))
			tm += s(stack_b, 'b');
		if (head(stack_a, 0) < head(stack_a, 1) && head(stack_a, 1) > 2)
			tm += s(stack_a, 'a');
		else if (head(stack_a, 0) < stack_a->a[0] && stack_a->a[0] > 2)
			tm += rr(stack_a, 'a');
		else if (stack_a->l > 3)
			tm += push_to_head(stack_a, ft_arrfindl(stack_a), 'a', INT_MAX);
	}
	if (!ft_arriscsorted(stack_a) && stack_a->l == 3)
		tm += sort_smallest_map(stack_a);
	return (tm + push_back_b_elements(stack_a, stack_b));
}
