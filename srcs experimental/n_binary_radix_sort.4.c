/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_binary_radix_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 03:03:14 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/06 16:19:26 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_all(t_array *stack_a, t_array *stack_b)
{
	ft_arrshftr(stack_a);
	ft_arrshftr(stack_b);
	ft_putchar_fd('r', 1);
	ft_putchar_fd('r', 1);
	ft_putchar_fd('\n', 1);
	return (1);
}

/**
 * Transpose back the digit groups in stack_a, grouped into buckets.
 * This is an example of his effect in n_base = 2 for digit 0:
 * |  b0  | |  b1  | |   b2  | | b3 |
 * 0 12 8 4 9 5 1 13 14 2 10 6 11 7 3
 * This is the next passage at digit 1
 * |  b0 | |  b1 | |  b2  |  |  b3 |
 * 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
 *
 * @param pos The current digit position.
 * @param stks The stacks containing the numbers.
 * @param nb The n_base structure representing the number base.
 * @return The total number of moves performed.
 */
static int	transpose_back_dgt_grps(int pos, t_stacks *stks, t_n_base *nb)
{
	int i;
	int	total_moves;

	i = 0;
	total_moves = 0;

	
	// while(stks->b->l > 0 && extract_digit(stks->b->a[0], pos, nb->base) == 1) {
	// 	total_moves += rr(stks->b, 'b');
	// 	total_moves += p(stks->a, stks->b, 'a');
	// 	printArray("transp st a \n", stks->a->a, stks->a->l);
	// 	printArray("transp st b \n", stks->b->a, stks->b->l);
	// 	printArray("transp st m \n", stks->map->a, stks->map->l);
	// }

	//total_moves += fix_stack_shift(stks->a, stks->map, 'a');
	// ft_arrrev(stks->map);
	// total_moves += fix_stack_shift(stks->b, stks->map, 'b');
	
	while (stks->b->l > 0 && contains_dgt_grp(stks->b, 1, pos, nb->base))
	{
		if (extract_digit(head(stks->b,0), pos, nb->base) == 1)
			total_moves += p(stks->a, stks->b, 'a');
		else
			total_moves += r(stks->b, 'b');
	}
	printArray("push 1  a \n", stks->a->a, stks->a->l);
	printArray("push 1  b \n", stks->b->a, stks->b->l);
	printArray("push 1  m \n", stks->map->a, stks->map->l);
	
	// while (stks->b->l > 0 && extract_digit(stks->b->a[0], pos, nb->base) == 2)
	// 	total_moves += rr(stks->b, 'b');
	// printArray("2 to head a\n", stks->a->a, stks->a->l);
	// printArray("2 to head a\n", stks->b->a, stks->b->l);
	// printArray("2 to head a\n", stks->map->a, stks->map->l);

	while(extract_digit(stks->map->a[i], pos, nb->base) != 2 && i < stks->map->l)
		i++;
	
	while (stks->b->l > 0 && head(stks->b, 0) != stks->map->a[i])
		total_moves += rr(stks->b, 'b');
	printArray("2 to head a\n", stks->a->a, stks->a->l);
	printArray("2 to head a\n", stks->b->a, stks->b->l);
	printArray("2 to head a\n", stks->map->a, stks->map->l);
	
	while (stks->b->l > 0 && extract_digit(head(stks->b, 0), pos, nb->base) == 2)
		total_moves += p(stks->a, stks->b, 'a');
	printArray("2 to head b\n", stks->a->a, stks->a->l);
	printArray("2 to head b\n", stks->b->a, stks->b->l);
	printArray("2 to head b\n", stks->map->a, stks->map->l);

	while (stks->b->l > 0){
		total_moves += rr(stks->b, 'b');
		total_moves += p(stks->a, stks->b, 'a');
	}
	printArray("3 to head b\n", stks->a->a, stks->a->l);
	printArray("3 to head b\n", stks->b->a, stks->b->l);
	printArray("3 to head b\n", stks->map->a, stks->map->l);
	
	// while (stks->b->l > 0){
	// 	total_moves += rr(stks->b, 'b');
	// 	total_moves += p(stks->a, stks->b, 'a');
	// }
	// printArray("3 to head\n", stks->a->a, stks->a->l);
	// printArray("3 to head\n", stks->b->a, stks->b->l);
	// printArray("3 to head\n", stks->map->a, stks->map->l);
		
	// while (stks->b->l > 0 && contains_dgt_grp(stks->b, 1, pos, nb->base))
	// {
	// 	if (extract_digit(head(stks->b,0), pos, nb->base) == 1)
	// 		total_moves += p(stks->a, stks->b, 'a');
	// 	else
	// 		total_moves += r(stks->b, 'b');
	// }
	// printArray("transp a \n", stks->a->a, stks->a->l);
	// printArray("transp b \n", stks->b->a, stks->b->l);
	// printArray("transp m \n", stks->map->a, stks->map->l);
	
	// while (contains_dgt_grp(stks->b, 1, pos, nb->base))
	// {


			
	// 		total_moves += p(stks->a, stks->b, 'a');
	// 	else
	// 		total_moves += r(stks->b, 'b');
	// }	
	// while (h <= nb->largest_digit && contains_dgt_grp(stks->b, h, pos, nb->base))
	// {
	// 	while (contains_dgt_grp(stks->b, h, pos, nb->base))
	// 	{
	// 		if (extract_digit(stks->b->a[stks->b->l - 1], pos, nb->base) == h)
	// 			total_moves += p(stks->a, stks->b, 'a');
	// 		else
	// 			total_moves += r(stks->b, 'b');
	// 	}
	// 	h++;
	// 	total_moves += fix_stack_shift(stks->b, stks->map, 'b');
	// printArray("transp a \n", stks->a->a, stks->a->l);
	// printArray("transp b \n", stks->b->a, stks->b->l);
	// printArray("transp m \n", stks->map->a, stks->map->l);
	// }
	return (total_moves);
}

/**
 * Used by prune_dgt_bkts_at to check if pruning is complete for a given digit
 * position.
 * It iterates over each digit group 1 to 2^n -1 (nb->largest_digit) and checks
 * if any number belonging to them is still in the stack.
 *
 * @param stks The stacks containing the numbers.
 * @param nb The structure representing the number base.
 * @param digit The current digit group to check.
 * @return 1 if pruning is complete, 0 otherwise.
 */
static int	is_pruning_complete(t_stacks *stks, t_n_base *nb, int digit)
{
	int	digit_group;
	int	pruning_complete;

	digit_group = 1;
	pruning_complete = 1;
	while (digit_group <= nb->largest_digit && pruning_complete)
	{
		if (contains_dgt_grp(stks->a, digit_group, digit, nb->base))
			pruning_complete = 0;
		digit_group++;
	}
	return (pruning_complete);
}

/**
 * Prunes all the digit groups bigger than the bucket 0 into stack_b without
 * sorting.
 * The instruction
 * if (((stks->a->a[stks->a->l - 1] >> pos * nb->base) & nb->mask) > 0)
 * takes the value curently at the head of stack_a, shifts it to the right
 * at the position of the digit we are currently sorting the stack by
 * (pos * nb->base) and then filtering it by the mask attached to the
 * n_base bit's group length (1 for n_base=1, 3 for n_base=2, 7 for
 * n_base =3 and so on) to retrieve the value of the digit positio we
 * are examining.
 * The algorithm terminates when we have examinated all the numbers in the
 * stack or better when we have pruned all the number who's nth digit is
 * bigger than 0 (we keep group 0 in stack a).
 * Example with nb->base = 2 (base 4 rappresentation) after a complete
 * pruning on the first digit.
 * stack a: 12 0 4 8 (all the base 4 rapp. of these numbers end by 0)
 * stack b: 1 13 7 11 6 3 10 9 2 14 5 (all these end with digits 1 to 3)
 * We then procede with the second digit
 * stack a: 0 1 2 3 (in all these the second digit is 0)
 * stack b: 7 11 6 10 14 13 9 5 4 12 8 (in these the second digit is 1 to 3)
 *
 * @param pos The current digit position to gather the digit group.
 * @param stks The stacks containing the numbers.
 * @param nb The structure representing the number base.
 * @param size The size of the stacks.
 * @return The total number of moves performed.
 */
static int	prune_dgt_bkts_at(int pos, t_stacks *stks, t_n_base *nb, int size)
{
	int	h;
	int	total_moves;
	int	frr;

	h = 0;
	total_moves = 0;
	frr = 0;


	// while (contains_dgt_grp(stks->a, 1, pos, nb->base) || contains_dgt_grp(stks->a, 2, pos, nb->base) || extract_digit(head(stks->a,0), pos, nb->base) != 0 || extract_digit(stks->b->a[0], pos, nb->base) != 3)

	
	while (h < size)
	{
		// if (extract_digit(stks->a->a[stks->a->l - 1], pos, nb->base) > 0)
		// 	total_moves += p(stks->b, stks->a, 'b');
		// else
		if (extract_digit(head(stks->a, 0), pos, nb->base) > 0)
		{
			// if (frr == 1)
			// {
			// 	total_moves += r(stks->b, 'b');
			// 	frr = 0;
			// }
			total_moves += p(stks->b, stks->a, 'b');
			if (extract_digit(head(stks->b, 0), pos, nb->base) == 3)
				total_moves += r(stks->b, 'b');
				//frr = 1;
		}
		else
		{
			if (is_pruning_complete(stks, nb, pos))
				h = size;
			else
				total_moves += r(stks->a, 'a');
			h++;
			// else
			// {
			// 	if (frr == 1)
			// 	{
			// 		total_moves += r_all(stks->b, stks->a);
			// 		frr = 0;
			// 	}
			// 	else
			// 		total_moves += r(stks->a, 'a');
			// }
			// h++;
		}
		printArray("prn a \n", stks->a->a, stks->a->l);
		printArray("prn b \n", stks->b->a, stks->b->l);
		printArray("prn m \n", stks->map->a, stks->map->l);
	}
	return (total_moves);
}

/**
 * Perform n-binary radix sort on the stacks.
 *
 * Radix sort is a well known algorithm to sort a stack of positive integers by
 * progressively examining the digidts at their nth(n>=0) position and placing
 * them into buckets 0-9 corresponding to the value of that digit  (see this
 * video for the basic concept https://www.youtube.com/watch?v=nu4gDuFabIM )
 * In order to sort negative numbers the actual sorting is performed on
 * a map that holds the position of each number in the original stack.
 * The binary version of radix sorting is performed on the number's
 * binary rappresentation, using only 2 buckets instead.
 * Since none of them is the most efficient for stacks <= 500, here we use an
 * n-binary approach where we examine groups of n bits at a time. If required
 * we might see what n would work better at larger sizes (the parameter is
 * adjustable trough the n_base parameter)
 * Values of n_base corresponds to:
 * 1 for 1 bit (base 2), 2 for 2 bits (base 4), 3 for 3 bist (base 8) and on.
 *
 * @param stks The stacks containing the numbers.
 * @param n_base The structure representing the number base.
 * @param size The size of the stacks.
 * @return The total number of moves performed.
 */
int	n_binary_radix_sort(t_stacks *stks, t_n_base *n_base, int size)
{
	int	total_moves;
	int	i;

	total_moves = 0;
	i = 0;
	while (i < n_base->dgt_count)
	{
		stks->map = ft_arrclone(stks->a);
		if (!stks->map)
			return (-1);
		total_moves += prune_dgt_bkts_at(i, stks, n_base, size);
		total_moves += fix_stack_shift(stks->a, stks->map, 'a');
		total_moves += transpose_back_dgt_grps(i, stks, n_base);
		ft_arrfree(stks->map);
		i++;
	}
	return (total_moves);
}
