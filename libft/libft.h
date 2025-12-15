/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:00:00 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/15 12:42:42 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/* STRUCT FOR LINKED LISTS */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* Character checks */
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/* Character conversion */
int					ft_toupper(int c);
int					ft_tolower(int c);

/* String functions */
size_t				ft_strlen(const char *x);
int					ft_strncmp(char *s1, char *s2, int n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(char *str, char sym);
char				*ft_strnstr(const char *haystack, const char *needle,
						int len);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strdup(const char *s1);

void				ft_putnbr_fd(int n, int fd);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(char const *s, char c);
void				ft_putstr_fd(char *s, int fd);

/* Memory functions */
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_calloc(size_t count, size_t size);

/* Number conversion */
int					ft_atoi(const char *str);
char				*ft_itoa(int n);

/* List Conversion */
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);

#endif
