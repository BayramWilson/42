/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:43:18 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/15 19:06:11 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_put_hex(unsigned int n)
{
	const char	*base = "0123456789abcdef";
	int			i;

	i = 0;
	if (n >= 16)
		i = i + pf_put_hex(n / 16);
	i = i + pf_write_char(base[n % 16]);
	return (i);
}

int	pf_put_hex_upper(unsigned int n)
{
	const char	*base = "0123456789ABCDEF";
	int			i;

	i = 0;
	if (n >= 16)
		i = i + pf_put_hex_upper(n / 16);
	i = i + pf_write_char(base[n % 16]);
	return (i);
}

int	pf_put_hex_ull(unsigned long long n)
{
	const char	*base = "0123456789abcdef";
	int			i;

	i = 0;
	if (n >= 16)
		i = i + pf_put_hex_ull(n / 16);
	i = i + pf_write_char(base[n % 16]);
	return (i);
}
