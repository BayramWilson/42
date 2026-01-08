/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:09:38 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/08 16:57:43 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (size > 1 && src[i])
	{
		dest[i] = src[i];
		i++;
		size--;
	}
	if (size > 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		len;
	int		i;

	len = ft_strlen(s1);
	copy = (char *)malloc(len + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*sub;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		sub_len = s_len - start;
	else
		sub_len = len;
	sub = malloc(sub_len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, sub_len + 1);
	return (sub);
}

size_t	ft_strlen(const char *x)
{
	size_t	i;

	if (!x)
		return (0);
	i = 0;
	while (x[i] != '\0')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || !(buffer = malloc((size_t)BUFFER_SIZE
				+ 1)))
		return (NULL);
	while (1)
	{
		if (contain_newline(stash))
			return (line = extract_line(stash), stash = trim_stash(stash),
				free(buffer), line);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
			stash = grow_stash(stash, buffer, bytes_read);
		if (bytes_read == 0)
		{
			free(buffer);
			if (!stash || !*stash)
				return (free(stash), stash = NULL, NULL);
			return (line = stash, stash = NULL, line);
		}
		if (bytes_read == -1 || !stash)
			return (free(buffer), free(stash), stash = NULL, NULL);
	}
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		line_count;

// 	line_count = 0;
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error: cannot open test.txt");
// 		return (1);
// 	}
// 	printf("=== Reading test.txt with get_next_line ===\n");
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		line_count++;
// 		printf("[%02d] %s", line_count, line);
// 		free(line); // Don't forget to free!
// 	}
// 	printf("\nTotal lines read: %d\n", line_count);
// 	close(fd);
// 	return (0);
// }
