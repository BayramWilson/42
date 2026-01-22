/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:02:07 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/27 15:41:55 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
