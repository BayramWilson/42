/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:44:02 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/15 19:13:51 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	put_hex(unsigned int n);
int	put_hex_upper(unsigned int n);
int	put_hex_ull(unsigned long long n);
int	pf_putnbr(long n);
int	write_string(char *s);
int	write_char(char c);
int	write_integer(int i);
int	write_unsigned_integer(unsigned int i);
int	put_ptr(void *ptr);
int	ft_printf(const char *s, ...);

#endif