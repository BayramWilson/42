/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:50:17 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/03 13:05:55 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strrchr(char *str, char sym)
{
	int	i;
	int	temp;

	i = 0;
	while (str[i])
	{
		if (str[i] == sym)
		{
			temp = i;
		}
		i++;
	}
	return (temp);
}
/*
#include <stdio.h>

int	main(void)
{
	char	x[11] = "hallo welt";

	printf("%d", ft_strrchr(x, 'l'));
}*/
