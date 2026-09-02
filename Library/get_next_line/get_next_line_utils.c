/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:08:19 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/02 16:16:52 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*last_stash_controls(char **stash, char **line,
				char **buffer, int bytes_read)
{
	int	length;

	if (!*stash)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	if (bytes_read == -1)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	length = ft_strlen_gnl(*stash);
	*line = malloc(length + 1);
	if (!*line)
		return (NULL);
	(*line)[length] = '\0';
	fill_it(*line, *stash, 0, 0);
	free (*stash);
	*stash = NULL;
	return (*line);
}

int	ft_strlen_gnl(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	fill_it(char *dst, char *src, int j, int i)
{
	int	length;

	length = ft_strlen_gnl(src);
	if (i == -1)
		length = is_there_a_new_line(src, length, 0, '2');
	if (i == -2)
	{
		i = 0;
		while (i < length)
		{
			dst[j + i] = src[i];
			i++;
		}
		return ;
	}
	i = 0;
	while (i < length)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	return ;
}

char	*divide_the_stash(char **line, char **stash)
{
	int		length_line;
	char	*new_stash;
	int		length_new_stash;

	length_line = is_there_a_new_line(*stash, ft_strlen_gnl(*stash), 0, '2');
	*line = malloc(length_line + 1);
	if (!*line)
		return (NULL);
	(*line)[length_line] = '\0';
	fill_it(*line, *stash, 0, -1);
	length_new_stash = ft_strlen_gnl(*stash) - length_line;
	if (length_new_stash == 0)
	{
		free (*stash);
		*stash = NULL;
		return (*line);
	}
	new_stash = malloc(length_new_stash + 1);
	if (!new_stash)
		return (NULL);
	new_stash[length_new_stash] = '\0';
	fill_new_stash(new_stash, *stash, length_line, length_new_stash);
	free(*stash);
	*stash = new_stash;
	return (*line);
}

int	is_there_a_new_line(char *string, int bytes_read, int i, char mode)
{
	int	return_value;

	return_value = 0;
	if (!string)
		return (0);
	if (string[0] == '\n')
		return (1);
	while (i < bytes_read)
	{
		if (string[i] == '\n')
		{
			return_value = i + 1;
			if (mode == '2')
				return (return_value);
		}
		i++;
	}
	return (return_value);
}
