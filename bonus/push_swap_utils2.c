/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 09:41:02 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/05 10:15:32 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	free_matrix(char **res)
{
	size_t	i;

	if (!res)
		return ;
	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
}

/**
 * Allocates a new string and fills it with characters between
 * pointers s and p.
 */
static char	*get_between(char const *p, const char *s)
{
	char	*word;
	size_t	i;

	word = (char *)malloc((s - p + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (p < s)
	{
		word[i] = *p;
		p++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

/**
 * Generate a matrix to hold split words.
 */
static char	**generate_matrix(char const *s, char c)
{
	char	**res;
	size_t	word_count;

	word_count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			word_count++;
			while (*s && *s != c)
				s++;
		}
	}
	res = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res[word_count] = NULL;
	return (res);
}

/**
 * Iterates through the string s, extracts words separated by
 * the character c, and fills the array res with these words.
 */
static char	**fill_matrix(char const *s, char **res, char c)
{
	const char	*p;
	size_t		i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			p = s;
			while (*s && *s != c)
				s++;
			res[i] = get_between(p, s);
			if (!res[i])
			{
				free_matrix(res);
				return (NULL);
			}
			i++;
		}
		else
			s++;
	}
	return (res);
}

/**
 * Takes an input string s and a character c, and returns
 * a newly-allocated array of strings representing the words in s
 * separated by c.
 */
char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = generate_matrix(s, c);
	if (!res)
		return (NULL);
	return (fill_matrix(s, res, c));
}
