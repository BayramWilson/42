/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:18:15 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/11 22:32:31 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int	    i;
	char	*s;

	i = 0;
	s = ft_itoa(n);
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

