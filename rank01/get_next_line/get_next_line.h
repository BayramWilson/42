/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:10:05 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/08 13:38:20 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*trim_stash(char *stash);
char	*extract_line(char *stash);
char	*grow_stash(char *old_stash, char *buffer, int bytes_read);
int		contain_newline(char *stash);
size_t	ft_strlen(const char *x);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t len);

#endif