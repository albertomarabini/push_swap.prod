/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:09:59 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/04 07:49:33 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"


t_array	*normalize_input(int *array, int size)
{
	t_array	original;
	t_array	*sorted;
	t_array	*normalized;
	int		i;

	original.a = array;
	original.l = size;
	sorted = ft_arrclone(&original);
	if (sorted == NULL)
		return (NULL);
	ft_arrisort(sorted);
	normalized = ft_arrclone(sorted);
	if (normalized == NULL)
		return (free(sorted->a), free (sorted), NULL);
	i = 0;
	while (i < size)
	{
		normalized->a[i] = ft_arrindexof(sorted, original.a[i]);
		i++;
	}
	ft_arrfree(sorted);
	return (normalized);
}

/**
 * ft_strcmp - Compare two strings.
 *
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 *
 * Return: An int less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL)
	{
		if (s2 == NULL)
			return (0);
		else
			return (-1);
	}
	if (s2 == NULL)
		return (1);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

t_moves	*ft_lstnew(char *content)
{
	t_moves	*new;

	new = (t_moves *)malloc(sizeof(t_moves));
	if (new == NULL)
		return (NULL);
	new->move = content;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_moves *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	ft_lstadd_back(t_moves **lst, t_moves *new)
{
	t_moves	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

t_moves	*ft_lstlast(t_moves *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
void	ft_lstclear(t_moves **lst, void (*del)(void *))
{
	t_moves	*current;
	t_moves	*next;

	if (lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}
void	ft_lstdelone(t_moves *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->move);
	free(lst);
}

t_stacks	*init_stacks(t_array *a_map, int size)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (stacks == NULL)
		return (NULL);
	stacks->a = ft_arrclone(a_map);
	if (stacks->a == NULL)
		return (free_stacks(stacks), NULL);
	stacks->b = ft_arrnew(size);
	if (stacks->b == NULL)
		return (free_stacks(stacks), NULL);
	stacks->map = NULL;
	return (stacks);
}

void	free_stacks(t_stacks *stacks)
{
	if (stacks->a)
		ft_arrfree(stacks->a);
	if (stacks->b)
		ft_arrfree(stacks->b);
	free(stacks);
}

/**
 * Checks if an array is sorted in ascending order.
 *
 * @param stack The array to be checked for sorting.
 * @return 1 if the array is sorted in ascending order, 0 otherwise.
 */
int	ft_arrissorted(t_array *stack)
{
	int	i;

	i = 0;
	while (i < stack->l - 1)
	{
		if (stack->a[i + 1] < stack->a[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(const char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

void	reverse_array(int *arr, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	}
}

/**
 * Finds the index of an integer in the given array.
 *
 * @param arr The array in which to search for the integer.
 * @param n The integer to find in the array.
 * @return The index of the integer in the array, or -1 if not found.
 */
int	ft_arrindexof(t_array *arr, int n)
{
	int	i;

	i = 0;
	while (i < arr->l)
	{
		if (arr->a[i] == n)
		{
			return (i);
		}
		i++;
	}
	return (-1);
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
