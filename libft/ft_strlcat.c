/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:35:12 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/08 12:42:27 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	ldest;
	size_t	lsrc;

	ldest = ft_strlen(dest);
	lsrc = ft_strlen(src);
	i = ldest;
	j = 0;
	if (n <= ldest)
		return (n + lsrc);
	while (i < n - 1 && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (ldest + lsrc);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest[20] = "hallo";
	char	src[6] = " Welt";
	int		result;

	result = ft_strlcat(dest, src, 3);
	printf("%s\n%d", dest, result);
}
*/
