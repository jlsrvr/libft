/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:25:31 by jrivoire          #+#    #+#             */
/*   Updated: 2021/01/04 21:33:38 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *s, char c)
{
	size_t counter;
	size_t index;

	counter = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] && s[index] == c)
			index++;
		if (s[index])
			counter++;
		while (s[index] && s[index] != c)
			index++;
	}
	return (counter);
}

static	char	*copy_word(char const *s, size_t *begin, char c)
{
	size_t start;
	size_t end;

	start = *begin;
	end = start;
	while (s[end] != c && s[end])
		++end;
	*begin = end;
	return (ft_substr(s, start, (end - start)));
}

static	char	**free_words(char **dest)
{
	unsigned int	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
	return (NULL);
}

static	char	**protection(char **dest)
{
	if (!(dest = malloc(sizeof(**dest) * 1)))
		return (NULL);
	*dest = NULL;
	return (dest);
}

char			**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	index;
	size_t	di;

	if (!s || !*s)
	{
		return (protection(dest = NULL));
	}
	if (!(dest = malloc(sizeof(*dest) * (count_words(s, c) + 1))))
		return (NULL);
	index = 0;
	di = 0;
	while (s[index])
	{
		if (s[index] != c)
		{
			if (!(dest[di++] = copy_word(s, &index, c)))
				return (free_words(dest));
		}
		else
			index++;
	}
	dest[count_words(s, c)] = 0;
	return (dest);
}
