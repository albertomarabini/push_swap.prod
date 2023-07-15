/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 01:30:35 by amarabin          #+#    #+#             */
/*   Updated: 2023/07/15 12:11:33 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>
#include <libft/ft_str.h>
#include <libft/ft_fd.h>
#include <stdlib.h>
#include <unistd.h>


static void	eval_line(t_global *tab, char *line)
{
	if (!ft_strncmp(line, "sa\n", 4))
		sa(tab, 0);
	else if (!ft_strncmp(line, "sb\n", 4))
		sb(tab, 0);
	else if (!ft_strncmp(line, "ss\n", 4))
		ss(tab, 0);
	else if (!ft_strncmp(line, "pa\n", 4))
		pa(tab, 0);
	else if (!ft_strncmp(line, "pb\n", 4))
		pb(tab, 0);
	else if (!ft_strncmp(line, "ra\n", 4))
		ra(tab, 0);
	else if (!ft_strncmp(line, "rb\n", 4))
		rb(tab, 0);
	else if (!ft_strncmp(line, "rr\n", 4))
		rr(tab, 0);
	else if (!ft_strncmp(line, "rra\n", 5))
		rra(tab, 0);
	else if (!ft_strncmp(line, "rrb\n", 5))
		rrb(tab, 0);
	else if (!ft_strncmp(line, "rrr\n", 5))
		rrr(tab, 0);
	else
		err_exit(tab);
}


