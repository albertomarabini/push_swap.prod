/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:00:56 by amarabin          #+#    #+#             */
/*   Updated: 2023/07/15 17:03:55 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_array
{
	int		*a;
	int		l;
}			t_array;

typedef struct s_n_base
{
	int		base;
	int		mask;
	int		largest_digit;
	int		dgt_count;
}			t_n_base;

typedef struct s_stacks
{
	t_array	*a;
	t_array	*b;
	t_array	*map;
}			t_stacks;

int			n_binary_radix_sort(t_stacks *stks, t_n_base *n_base, int size);
int			extract_digit(int number, int digit, int n_base);
int			contains_dgt_grp(t_array *stack, int digit_grp, int digit,
				int n_base);
int			fix_stack_shift(t_array *stack, t_array *map, char label);
int			sort_small_map(t_array *stack_a, t_array *stack_b);
int			sort_smallest_map(t_array *stack);
void		free_stacks(t_stacks *stacks);
t_stacks	*init_stacks(t_array *a_map, int size);
void		free_n_base_data(t_n_base *data);
t_n_base	*init_n_base_data(int n_base, int maxsize);
int			rr(t_array *stack, char label);
int			r(t_array *stack, char label);
int			s(t_array *stack, char label);
int			p(t_array *dest, t_array *src, char label);
t_array		*normalize_input(int *array, int size);
int			ipow(int n, int power);
void		ft_putchar_fd(char c, int fd);
int			ft_arrfinds(t_array *arr);
void		ft_arrshftr(t_array *stack);
t_array		*ft_arrsort(t_array *array);
int			ft_arrissorted(t_array *stack);
int			ft_arrindexof(t_array *arr, int n);
int			ft_arrfindl(t_array *arr);
void		ft_arrshftl(t_array *stack);
void		ft_arrrev(t_array *array);
t_array		*ft_arrclone(t_array *arr);
void		ft_arrfree(t_array *array);
t_array		*ft_arrnew(int max_size);

#endif
