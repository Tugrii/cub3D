/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:21:49 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/02 13:13:37 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	fill_new_stash(char *new_stash, char *src, int start, int length)
{
	int	i;

	i = 0;
	if (!new_stash)
		return ;
	while (i < length)
	{
		new_stash[i] = src[start + i];
		i++;
	}
	return ;
}

char	*build_new_malloc_for_stash(char **stash, char *buffer, int bytes_read)
{
	int		total_length;
	char	*new_stash;
	int		old_length;

	old_length = ft_strlen_gnl(*stash);
	total_length = old_length + bytes_read;
	new_stash = malloc(total_length + 1);
	if (!new_stash)
		return (NULL);
	fill_it(new_stash, *stash, 0, 0);
	fill_it(new_stash, buffer, old_length, -2);
	new_stash[total_length] = '\0';
	free (*stash);
	return (new_stash);
}

char	*add_to_stash(char **stash, char *buffer, int bytes_read)
{
	if (!*stash)
	{
		*stash = malloc(bytes_read + 1);
		if (!*stash)
			return (NULL);
		(*stash)[bytes_read] = '\0';
		fill_it(*stash, buffer, 0, 0);
		return (*stash);
	}
	else
		*stash = build_new_malloc_for_stash(stash, buffer, bytes_read);
	return (*stash);
}

char	*fill_buffer(char **stash, char **line, int fd)
{
	int			bytes_read;
	char		*buffer;

	bytes_read = 1;
	while (is_there_a_new_line(*stash, ft_strlen_gnl(*stash), 0, '1') == 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
			buffer[bytes_read] = '\0';
		if (bytes_read <= 0)
		{
			free (buffer);
			buffer = NULL;
			return (last_stash_controls(stash, line, &buffer, bytes_read));
		}
		*stash = add_to_stash(stash, buffer, bytes_read);
		free (buffer);
		buffer = NULL;
	}
	if (is_there_a_new_line(*stash, ft_strlen_gnl(*stash), 0, '1') != 0)
		*line = divide_the_stash(line, stash);
	return (*line);
}

char	*get_next_line(int fd)
{
	static char		*stash = NULL;
	char			*line;

	line = NULL;
	if (fd < 0)
		return (NULL);
	return (fill_buffer(&stash, &line, fd));
}
