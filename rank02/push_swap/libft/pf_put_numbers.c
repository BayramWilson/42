/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:50:23 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/15 19:06:37 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_write_integer(int i)
{
	int	fd;

	fd = 1;
	return (pf_putnbr_fd(i, fd));
}

int	pf_write_unsigned_integer(unsigned int i)
{
	int	fd;

	fd = 1;
	return (pf_putnbr_fd(i, fd));
}

int	pf_putnbr_fd(long n, int fd)
{
	long	nbl;
	char	s[12];
	short	i;
	int		len;

	nbl = n;
	i = 0;
	len = 0;
	if (0 == nbl)
		return ((int)write(fd, "0", 1));
	if (nbl < 0)
	{
		len = len + (int)write(fd, "-", 1);
		nbl = -nbl;
	}
	while (nbl > 0)
	{
		s[i++] = (nbl % 10) + '0';
		nbl = nbl / 10;
	}
	while (i > 0)
		len = len + (int)write(fd, &s[--i], 1);
	return (len);
}
