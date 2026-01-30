/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:50:40 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/15 19:06:54 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_write_char(char c)
{
	return ((int)write(1, &c, 1));
}

int	pf_write_string(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ((int)write(1, "(null)", 6));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	pf_put_ptr(void *ptr)
{
	int	i;

	if (!ptr)
		return ((int)write(1, "(nil)", 5));
	i = 0;
	i = i + (int)write(1, "0x", 2);
	i = i + pf_put_hex_ull((unsigned long long)(uintptr_t)ptr);
	return (i);
}
