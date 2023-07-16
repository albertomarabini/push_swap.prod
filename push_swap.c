/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 01:47:57 by amarabin          #+#    #+#             */
/*   Updated: 2023/07/16 07:49:13 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL)
	{
		if (s2 == NULL)
			return (0);
		else
			return (-1);
	}
	else if (s2 == NULL)
		return (1);
	while (n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

/**
 * Converts a string representation of an integer to an integer value.
 *
 * The function parses the input string `nptr` and converts it to an integer.
 * If an error condition occurs, the first character of the input string is
 * modified to 'E' and 0 is returned.
 *
 * @param nptr The string to convert to an integer.
 * @return The converted integer value if successful, 0 if an error occurs.
 */
int	ft_atoi_mod(char *nptr)
{
	int			sign;
	long long	result;
	int			i;

	sign = 1;
	result = 0;
	i = 0;
	if (!nptr)
		return (0);
	if (nptr[0] == '-' || nptr[0] == '+')
	{
		if (nptr[0] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = (result * 10) + (nptr[i++] - '0');
	result *= sign;
	if (nptr[i] != '\0' || result > INT_MAX || result < INT_MIN)
	{
		nptr[0] = 'E';
		return (0);
	}
	return ((int)result);
}

int	*print_error(int *result)
{
	ft_putstr_fd("Error\n", 2);
	if (result)
		free(result);
	return (NULL);
}

int	*parse_input(int size, char *argv[])
{
	int	*result;
	int	result_size;
	int	i;
	int	num;

	result_size = 0;
	result = (int *)malloc((size - 1) * sizeof(int));
	if (!result || size <= 1)
		return (print_error(result));
	while (result_size < size - 1)
	{
		num = ft_atoi_mod(argv[result_size + 1]);
		if (num == 0 && argv[result_size + 1][0] == 'E')
			return (print_error(result));
		i = 0;
		while (i < result_size)
			if (result[i++] == num)
				return (print_error(result));
		result[result_size] = num;
		result_size++;
	}
	return (result);
}

int	main(int size, char *argv[])
{
	int			*input;
	t_array		*map;
	t_stacks	*stks;
	t_n_base	*n_base;

	input = parse_input(size, argv);
	if (!input)
		return (0);
	size -= 1;
	map = normalize_input(input, size);
	stks = init_stacks(map, size);
	n_base = init_n_base_data(2, size - 1);
	if (size <= 3 && !ft_arrissorted(stks->a))
		sort_smallest_map(stks->a);
	else if (size <= 37 && !ft_arrissorted(stks->a))
		sort_small_map(stks->a, stks->b);
	else if (!ft_arrissorted(stks->a))
		n_binary_radix_sort(stks, n_base, size);
	free_stacks(stks);
	free_n_base_data(n_base);
	ft_arrfree(map);
	free(input);
	return (0);
}
