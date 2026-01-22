/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:18:15 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/27 14:59:25 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	nbl;
	char	s[12];
	short	i;

	nbl = n;
	i = 0;
	if (0 == nbl)
	{
		write(fd, "0", 1);
		return ;
	}
	if (nbl < 0)
	{
		nbl = -nbl;
		write(fd, "-", 1);
	}
	while (nbl > 0)
	{
		s[i++] = (nbl % 10) + '0';
		nbl = nbl / 10;
	}
	while (i > 0)
		write(fd, &s[--i], 1);
}
