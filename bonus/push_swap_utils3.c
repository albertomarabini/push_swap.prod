/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:16:53 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/05 04:58:09 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * concat_argc takes a 2D char array (argv) and returns a 
 * dynamically-allocated string that concatenates the elements of arr 
 * separated by spaces. The function specifically skips the first element 
 * of the array and starts concatenating from the second element (index 1). 
 */
static int	calculate_total_length(char **arr, int size)
{
	int	i;
	int	j;
	int	tot;

	tot = 0;
	i = 1;
	while (i < size)
	{
		j = 0;
		while (arr[i][j++] != '\0')
			tot++;
		tot++;
		i++;
	}
	return (tot - 1);
}

char	*concat_argc(char **arr, int size)
{
	int		i;
	int		j;
	int		k;
	int		tot;
	char	*result;

	tot = calculate_total_length(arr, size);
	result = (char *)malloc(tot + 1);
	if (!result)
		return (NULL);
	k = 0;
	i = 1;
	while (i < size)
	{
		j = 0;
		while (arr[i][j] != '\0')
			result[k++] = arr[i][j++];
		if (i < size - 1)
			result[k++] = ' ';
		i++;
	}
	result[k] = '\0';
	return (result);
}
