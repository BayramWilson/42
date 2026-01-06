/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:10:02 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/06 14:38:39 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	all_size;
	char	*result;

	if (!s1 || !s2)
	{
		if (s1)
			return (ft_strdup(s1));
		else if (s2)
			return (ft_strdup(s2));
		else
			return (ft_strdup(""));
	}
	all_size = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(all_size + 1);
	if (!result)
		return (result);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}