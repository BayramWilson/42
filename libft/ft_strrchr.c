/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:50:17 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/08 14:23:09 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(char *str, char sym)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (str[i])
	{
		if (str[i] == sym)
		{
			temp = &str[i];
		}
		i++;
	}
	if (sym == '\0')
		return (&str[i]);
	return (temp);
}
