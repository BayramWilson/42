/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:29:00 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/03 17:19:04 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_toupper(char x)
{
	if (x >= 'a' && x <= 'z')
		x = x - 32;
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	str;

	str = 'c';
	// char *cstr = (char *) str;
	printf("Die Ausgabe vorher: %c\n", str);
	// str = toupper(str);
	str = ft_toupper(str);
	printf("Die Ausgabe nachher: %c\n", str);
}
*/
