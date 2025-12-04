/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 01:12:43 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/04 14:28:49 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *str, int repl, int amt)
{
	int				i;
	unsigned char	*cstr;

	i = 0;
	cstr = (unsigned char *)str;
	while (amt > 0)
	{
		cstr[i] = repl;
		i++;
		amt--;
	}
	return (str);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[50] = "Welcome to Tutorialspoint";
	char	repl;
	int		amt;

	repl = '#';
	amt = 8;
	printf("Before memset: %s\n", str);
	ft_memset(str, repl, amt);
	printf("After memset: %s\n", str);
}
*/