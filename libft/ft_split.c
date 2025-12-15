/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:49:19 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/15 19:34:00 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;
	int		is_word;

	is_word = 0;
	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && is_word == 0)
		{
			is_word = 1;
			words++;
		}
		else if (s[i] == c)
			is_word = 0;
		i++;
	}
	return (words);
}

int	size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		size;
	char	**result;

	i = 0;
	j = -1;
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (0);
	while (++j < count_words(s, c))
	{
		while (s[i] == c)
			i++;
		size = size_word(s, c, i);
		result[j] = ft_substr(s, i, size);
		i = i + size;
	}
	result[j] = 0;
	return (result);
}
