/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:44:14 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/24 19:47:21 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_spec(char spec, va_list *ap, int *count)
{
	if (spec == 'c')
		*count += pf_write_char(va_arg(*ap, int));
	else if (spec == 's')
		*count += pf_write_string(va_arg(*ap, char *));
	else if (spec == 'x')
		*count += pf_put_hex(va_arg(*ap, unsigned int));
	else if (spec == 'X')
		*count += pf_put_hex_upper(va_arg(*ap, unsigned int));
	else if (spec == 'p')
		*count += pf_put_ptr(va_arg(*ap, void *));
	else if (spec == 'i' || spec == 'd')
		*count += pf_write_integer(va_arg(*ap, int));
	else if (spec == 'u')
		*count += pf_write_unsigned_integer(va_arg(*ap, unsigned int));
	else if (spec == '%')
		*count += pf_write_char('%');
	else
		return (0);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	list;

	i = 0;
	count = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] && handle_spec(s[i + 1], &list, &count))
			i += 2;
		else
			count += (int)write(1, &s[i++], 1);
	}
	va_end(list);
	return (count);
}
