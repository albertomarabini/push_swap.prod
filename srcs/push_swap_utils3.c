/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 01:58:41 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/07 11:07:55 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
static int	ft_atoi_mod(char *nptr)
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

void	ft_free_split(char **vals, int size)
{
	while (size >= 0)
	{
		if (vals[size])
			free(vals[size]);
		size --;
	}
	free(vals);
}

static int	*populate_input_array(char **vals, int size)
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
	char	*buffer;
	char	**vals;

	if (*argc < 2)
		return (NULL);
	buffer = concat_argc(argv, *argc);
	if (!buffer)
		return (NULL);
	vals = ft_split(buffer, ' ');
	if (!vals)
		return (free(buffer), NULL);
	free(buffer);
	*argc = 0;
	while (vals[*argc])
		(*argc)++;
	result = populate_input_array(vals, *argc);
	ft_free_split(vals, *argc);
	if (!result)
		return (NULL);
	return (result);
}
