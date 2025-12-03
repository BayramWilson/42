/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:29:00 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/03 13:27:55 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_toupper(char x)
{
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
