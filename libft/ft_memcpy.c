/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 09:52:43 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/03 13:06:24 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, void *src, int n)
{
	int		i;
	char	*cdest;
	char	*csrc;

	i = 0;
	cdest = (char *)dest;
	csrc = (char *)src;
	while (n > 0)
	{
		cdest[i] = csrc[i];
		i++;
		n--;
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = 4;
	b = 5;
	printf("Value of b before calling memcpy: %d\n", b);
	ft_memcpy(&b, &a, 3);
	printf("Value of b after calling memcpy: %d\n", b);
}*/
