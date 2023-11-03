/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   push_swap_utils3.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: amarabin <amarabin@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/30 10:14:54 by amarabin		  #+#	#+#			 */
/*   Updated: 2023/10/30 10:18:11 by amarabin		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

int	*print_error(int *result)
{
	ft_putstr_fd("Error\n", 2);
	if (result)
		free(result);
	return (NULL);
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

static void	ft_free_split(char **vals, int size)
{
	while (size >= 0)
		free(vals[size--]);
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
		return (ft_free_split(vals, size), print_error(result));
	result_size = 0;
	while (result_size < size)
	{
		num = ft_atoi_mod(vals[result_size]);
		if (num == 0 && vals[result_size][0] == 'E')
			return (ft_free_split(vals, size),
				print_error(result));
		i = 0;
		while (i < result_size)
			if (result[i++] == num)
				return (ft_free_split(vals, size),
					print_error(result));
		result[result_size++] = num;
	}
	return (result);
}

int	*parse_input(int *argc, char *argv[])
{
	int		*result;
	char	**vals;
	char 	*str_argc;

	if (*argc != 2)
		return (print_error(NULL));
	str_argc = concat_argc(argv, *argc);
	if (!str_argc)
		return (print_error(NULL));
	vals = ft_split(str_argc, ' ');
	if (!vals)
		return (print_error(NULL));
	*argc = 0;
	while (vals[*argc])
		(*argc)++;
	result = populate_input_array(vals, *argc);
	// if (!result)
	// 	ft_free_split(vals, *argc);
	return (result);
}
