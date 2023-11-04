/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:07:45 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/04 08:44:44 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	apply_operation(t_stacks *stack, char *operation)
{
	if (!ft_strcmp(operation, "sa"))
		return (s(stack->a, 'a'));
	else if (!ft_strcmp(operation, "sb"))
		return (s(stack->b, 'b')); // Changed to stack->b
	else if (!ft_strcmp(operation, "ra"))
		return (r(stack->a, 'a'));
	else if (!ft_strcmp(operation, "rb"))
		return (r(stack->b, 'b'));
	else if (!ft_strcmp(operation, "rra"))
		return (rr(stack->a, 'a'));
	else if (!ft_strcmp(operation, "rrb"))
		return (rr(stack->b, 'b'));
	else if (!ft_strcmp(operation, "pb"))
		return (p(stack->b, stack->a, 'b'));
	else if (!ft_strcmp(operation, "pa"))
		return (p(stack->a, stack->b, 'a'));
	else if (!ft_strcmp(operation, "pa"))
		return (p(stack->a, stack->b, 'a'));
	return (0); // Invalid operation
}

void	check_stacks(t_array *stack_a, t_array *stack_b)
{
	if (ft_arrissorted(stack_a) && stack_b->l == 0)
		ft_putstr_fd("OK\n", 2);
	else
		ft_putstr_fd("KO\n", 2);
}

static int	read_fd(int fd, t_moves **buffer)
{
	int		n_bytes;
	t_moves	*move;

	char tmp[5]; // Add space for '\0'
	tmp[4] = '\0'; // Null-terminate the buffer
	while ((n_bytes = read(fd, tmp, 4)) > 0)
	{
		tmp[n_bytes] = '\0'; // Null-terminate the actual read bytes
		if (n_bytes < 4 && tmp[n_bytes - 1] != '\n')
			return (0); // Error if last read isn't a newline
		move = ft_lstnew(tmp);
		if (!move)
			return (0);
		ft_lstadd_back(buffer, move);
	}
	return (n_bytes == -1 ? 0 : 1); // Return 0 if read returned -1, else 1
}

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int	free_main(int *input, t_array *map, t_stacks *stks)
{
	if (input)
		free(input);
	if (map)
		ft_arrfree(map);
	if (stks)
		free_stacks(stks);
	return (0);
}

int	main(int size, char *argv[])
{
	t_array *map;
	t_stacks *stks;
	t_moves *buffer;
	int *input;

	input = parse_input(&size, argv);
	if (!input)
		return (print_error());
	reverse_array(input, size);
	map = normalize_input(input, size);
	if (!map)
		return (free_main(input, NULL, NULL), print_error());
	stks = init_stacks(map, size);
	if (!stks)
		return (free_main(input, map, NULL), print_error());
	buffer = NULL; // Correct initialization
	if (read_fd(0, &buffer)) // Pass address of buffer
	{
		while (buffer)
		{
			if (!apply_operation(stks, buffer->move))
			{
				ft_putstr_fd("Error\n", 2);
				// Free operations and other dynamic memory here...
				return (0); // Error in operation
			}
			buffer = buffer->next;
		}
		check_stacks(stks->a, stks->b); // Moved out of the while loop
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
	}
	return(free_main(input, map, stks));
}