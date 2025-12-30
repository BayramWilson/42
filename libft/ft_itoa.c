/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:13:30 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/27 16:17:17 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(long nb)
{
	size_t	i;

	i = 1;
	if (nb < 0)
		nb = -nb;
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	len;
	char	*result;

	nb = n;
	len = count_digits(nb) + (nb < 0);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nb == 0)
		result[0] = '0';
	if (nb < 0)
		result[0] = '-';
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		result[--len] = '0' + (nb % 10);
		nb /= 10;
	}
	return (result);
}
