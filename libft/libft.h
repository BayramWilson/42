/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42Berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:00:00 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/08 15:25:52 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/* Character checks */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

/* Character conversion */
int		ft_toupper(int c);
int		ft_tolower(int c);

/* String functions */
size_t	ft_strlen(const char *x);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(char *str, char sym);
char	*ft_strnstr(const char *haystack, const char *needle, int len);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
char    *ft_strdup(const char *s1);


/* Memory functions */
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void    *ft_calloc(size_t count, size_t size);

/* Number conversion */
int		ft_atoi(const char *str);

#endif
