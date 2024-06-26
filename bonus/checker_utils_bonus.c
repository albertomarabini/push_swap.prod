/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:09:59 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/05 10:49:15 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	init_stacks(t_stacks *stacks, t_array a_map, int size)
{
	stacks->a = ft_arrclone(&a_map);
	if (stacks->a == NULL)
		return (free_stacks(*stacks), 0);
	stacks->b = ft_arrnew(size);
	if (stacks->b == NULL)
		return (free_stacks(*stacks), 0);
	stacks->map = NULL;
	return (1);
}

void	free_stacks(t_stacks stacks)
{
	if (stacks.a)
		ft_arrfree(stacks.a);
	if (stacks.b)
		ft_arrfree(stacks.b);
}

int	*populate_input_array(char **vals, int size)
{
	int	*result;
	int	result_size;
	int	i;
	int	num;

	result = (int *)malloc(size * sizeof(int));
	if (!result)
		return (NULL);
	result_size = 0;
	while (result_size < size)
	{
		num = ft_atoi_mod(vals[result_size]);
		if (num == 0 && vals[result_size][0] == 'E')
			return (free(result), NULL);
		i = 0;
		while (i < result_size)
			if (result[i++] == num)
				return (free(result), NULL);
		result[result_size++] = num;
	}
	return (result);
}

int	*parse_input(int *argc, char *argv[])
{
	int		*result;
	char	**vals;

	if (*argc < 2)
		return (NULL);
	vals = ft_split(concat_argc(argv, *argc), ' ');
	if (!vals)
		return (NULL);
	*argc = 0;
	while (vals[*argc])
		(*argc)++;
	result = populate_input_array(vals, *argc);
	if (!result)
		return (ft_free_split(vals, *argc), NULL);
	return (result);
}

int	apply_operation(t_stacks stack, char *operation)
{
	if (!ft_strcmp(operation, "sa"))
		return (s(stack.a));
	else if (!ft_strcmp(operation, "sb"))
		return (s(stack.b));
	else if (!ft_strcmp(operation, "ra"))
		return (r(stack.a));
	else if (!ft_strcmp(operation, "rb"))
		return (r(stack.b));
	else if (!ft_strcmp(operation, "rra"))
		return (rr(stack.a));
	else if (!ft_strcmp(operation, "rrb"))
		return (rr(stack.b));
	else if (!ft_strcmp(operation, "pb"))
		return (p(stack.b, stack.a));
	else if (!ft_strcmp(operation, "pa"))
		return (p(stack.a, stack.b));
	else if (!ft_strcmp(operation, "rrr"))
		return (rrr(stack.a, stack.b));
	else if (!ft_strcmp(operation, "rr"))
		return (r_all(stack.a, stack.b));
	return (0);
}