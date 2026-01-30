/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:44:14 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/15 19:05:45 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_spec(char spec, va_list *ap, int *count)
{
	if (spec == 'c')
		*count += write_char(va_arg(*ap, int));
	else if (spec == 's')
		*count += write_string(va_arg(*ap, char *));
	else if (spec == 'x')
		*count += put_hex(va_arg(*ap, unsigned int));
	else if (spec == 'X')
		*count += put_hex_upper(va_arg(*ap, unsigned int));
	else if (spec == 'p')
		*count += put_ptr(va_arg(*ap, void *));
	else if (spec == 'i' || spec == 'd')
		*count += write_integer(va_arg(*ap, int));
	else if (spec == 'u')
		*count += write_unsigned_integer(va_arg(*ap, unsigned int));
	else if (spec == '%')
		*count += write_char('%');
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
// #include <stdio.h>
// #include "ft_printf.h"

// int	main(void)
// {
// 	int		a;
// 	char	c;
// 	char	*s;
// 	void	*p;
// 	int		ret_ft;
// 	int		ret_pf;

// 	a = -42;
// 	c = 'Z';
// 	s = "hello";
// 	p = &a;

// 	/* c */
// 	ret_ft = ft_printf("[ft] c: '%c'\n", c);
// 	ret_pf = printf("[pf] c: '%c'\n", c);
// 	printf("ret ft=%d pf=%d\n\n", ret_ft, ret_pf);

// 	/* s */
// 	ret_ft = ft_printf("[ft] s: '%s'\n", s);
// 	ret_pf = printf("[pf] s: '%s'\n", s);
// 	printf("ret ft=%d pf=%d\n\n", ret_ft, ret_pf);

// 	/* p */
// 	ret_ft = ft_printf("[ft] p: '%p'\n", p);
// 	ret_pf = printf("[pf] p: '%p'\n", p);
// 	printf("ret ft=%d pf=%d\n\n", ret_ft, ret_pf);

// 	/* d i */
// 	ret_ft = ft_printf("[ft] d: '%d' i: '%i'\n", a, a);
// 	ret_pf = printf("[pf] d: '%d' i: '%i'\n", a, a);
// 	printf("ret ft=%d pf=%d\n\n", ret_ft, ret_pf);

// 	/* u */
// 	ret_ft = ft_printf("[ft] u: '%u'\n", (unsigned int)a);
// 	ret_pf = printf("[pf] u: '%u'\n", (unsigned int)a);
// 	printf("ret ft=%d pf=%d\n\n", ret_ft, ret_pf);

// 	/* x X */
// 	ret_ft = ft_printf("[ft] x: '%x' X: '%X'\n", (unsigned int)a,
//			(unsigned int)a);
// 	ret_pf = printf("[pf] x: '%x' X: '%X'\n", (unsigned int)a, (unsigned int)a);
// 	printf("ret ft=%d pf=%d\n\n", ret_ft, ret_pf);

// 	/* % */
// 	ret_ft = ft_printf("[ft] %%: '%%'\n");
// 	ret_pf = printf("[pf] %%: '%%'\n");
// 	printf("ret ft=%d pf=%d\n\n", ret_ft, ret_pf);

// 	/* mixed */
// 	ret_ft = ft_printf("[ft] mix: c=%c s=%s p=%p d=%d i=%i u=%u x=%x X=%X %%\n",
// 			c, s, p, a, a, (unsigned int)a, (unsigned int)a, (unsigned int)a);
// 	ret_pf = printf("[pf] mix: c=%c s=%s p=%p d=%d i=%i u=%u x=%x X=%X %%\n",
// 			c, s, p, a, a, (unsigned int)a, (unsigned int)a, (unsigned int)a);
// 	printf("ret ft=%d pf=%d\n\n", ret_ft, ret_pf);

// 	return (0);
// }
