/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 01:12:43 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/27 15:56:31 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*cstr;

	i = 0;
	cstr = (unsigned char *)b;
	while (i < len)
	{
		cstr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
