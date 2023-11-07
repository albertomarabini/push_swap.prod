/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:07:45 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/08 00:45:40 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	check_stacks(t_array *stack_a, t_array *stack_b)
{
	if (ft_arrissorted(stack_a) && stack_b->l == 0)
		ft_putstr_fd("OK\n", 2);
	else
		ft_putstr_fd("KO\n", 2);
}

static int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

static int	free_main(int *input, t_stacks stks)
{
	if (input)
		free(input);
	free_stacks(stks);
	return (0);
}

static void	read_map(int fd, int index, char **buffer, int *moves)
{
	char	*line;

	line = get_next_line(fd);
	if (line != NULL)
	{
		read_map(fd, index + 1, buffer, moves);
		if (buffer != NULL)
			buffer[index] = line;
		return ;
	}
	buffer = (char **)malloc(sizeof(char *) * (index + 1));
	if (!buffer)
		return ;
	buffer[index] = NULL;
	*moves = index;
}

int	main(int size, char *argv[])
{
	t_array map;
	t_stacks stks;
	char **buffer;
	int moves;

	if (size < 2)
		return (0);
	map.a = parse_input(&size, argv);
	map.l = size;
	if (!map.a)
		return (print_error());
	reverse_array(map.a, map.l);
	if (!init_stacks(&stks, map, size))
		return (free_main(map.a, stks), print_error());
	buffer = NULL;
	moves = 0;
	read_map(0, 0, buffer, &moves);
	if (moves)
	{
		while (buffer)
			if (!apply_operation(stks, *buffer))
				return (free_main(map.a, stks), print_error());
		check_stacks(stks.a, stks.b);
		return (free_main(map.a, stks));
	}
	else
	{
		return (free_main(map.a, stks), print_error());
	}
	return (free_main(map.a, stks));
}
