/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:22:06 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/08 14:51:13 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;

	ps = (unsigned char *)s;
	while (n > 0)
	{
		if (*ps == (unsigned char)c)
			return ((void *)ps);
		ps++;
		n--;
	}
	return (NULL);
}
