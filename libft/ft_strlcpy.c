/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:21:22 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/08 12:55:13 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (size > 1 && src[i])
	{
		dest[i] = src[i];
		i++;
		size--;
	}
	if (size > 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[12] = "Hello World";
	char	src1[12] = "Hello World";
	char	dest[50];
	char	dest1[50];

	strlcpy(dest, src, 4);
	ft_strlcpy(src1, dest1, 4);
	printf("Library Function: %s\nMy Function: %s\n", dest, dest1);
}*/
