/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:10:02 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/08 22:05:33 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (s < d)
	{
		while (len--)
			d[len] = s[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

int	contain_newline(char *stash)
{
	size_t	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i])
		if (stash[i++] == '\n')
			return (1);
	return (0);
}

char	*grow_stash(char *old_stash, char *buffer, int bytes_read)
/**
 * concatenate_stash - Concatenates old stash with new buffer data
 * @old_stash: The previously stored string data
 * @buffer: The newly read buffer containing bytes_read bytes
 * @bytes_read: The number of bytes to append from buffer
 *
 * Description:
 * Allocates new memory to hold both old stash and new buffer data.
 * Copies the old stash into the new memory block, then appends exactly
 * bytes_read bytes from the buffer. Frees the old stash after copying.
 * This function performs pure concatenation without any newline handling
 * or line extraction logic.
 *
 * Return: Pointer to the newly allocated concatenated string,
	or NULL on failure
 */
{
	char	*growed_stash;
	size_t	old_stash_len;
	size_t	j;

	if (bytes_read < 1)
		return (NULL);
	old_stash_len = ft_strlen(old_stash);
	growed_stash = malloc(old_stash_len + bytes_read + 1);
	if (!growed_stash)
		return (free(old_stash), NULL);
	j = 0;
	while (old_stash != NULL && old_stash[j])
	{
		growed_stash[j] = old_stash[j];
		j++;
	}
	ft_memmove(growed_stash + old_stash_len, buffer, bytes_read);
	growed_stash[bytes_read + old_stash_len] = '\0';
	free(old_stash);
	return (growed_stash);
}

char	*extract_line(char *stash)
{
	size_t	i;
	char	*line;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			line = ft_substr(stash, 0, i + 1);
			return (line);
		}
		i++;
	}
	return (NULL);
}

char	*trim_stash(char *stash)
{
	size_t	i;
	size_t	stash_len;
	char	*new_stash;

	if (!stash)
		return (NULL);
	i = 0;
	stash_len = ft_strlen(stash);
	while (stash != NULL && stash[i])
	{
		if (stash[i] == '\n')
		{
			new_stash = ft_substr(stash, i + 1, stash_len);
			free(stash);
			if (new_stash && *new_stash == '\0')
			{
				free(new_stash);
				return (NULL);
			}
			return (new_stash);
		}
		i++;
	}
	return (stash);
}
