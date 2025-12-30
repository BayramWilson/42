/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:28:09 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/28 17:33:09 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static int	ft_ispartof(char x, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == x)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	char	*result;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	i = 0;
	while (s1[start] && ft_ispartof(s1[start], set))
		start++;
	while (s1[end] && ft_ispartof(s1[end], set) && end >= 0)
		end--;
	if (end < start)
		return (ft_strdup(""));
	result = malloc((end - start + 2));
	while (start <= end)
	{
		result[i] = s1[start];
		start++;
		i++;
	}
	result[i] = '\0';
	return (result);
}
