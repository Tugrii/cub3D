/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_maps_configuration_and_content.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 13:50:52 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/03 15:59:06 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		run_if_not_wall(char	*line_content, int *line_len)
{
	int	i;
	int	wall_chars_count;

	i = 0;
	*line_len = ft_strlen(line_content);
	wall_chars_count = 0;
	while (i < len)
	{
		if (line_content[i] == '1' || line_content[i] == ' ')
			wall_chars_count++;
		else
			break ;
		i++;
	}
	if (wall_chars_count == *line_len)
		return (0);
	return (1);
}

int	split_maps_configuration_and_content(int fd, t_map_all_infos *map_infos)
{
	char	*line_content;
	int		line_len;

	line_content = get_next_line(fd);
	if (line_content)
	{
		while (run_if_not_wall(line_content, &line_len))
		{
			skip_all_kind_of_whitespaces_then_split(line_content, line_len, map_infos->map_conf);
			line_content = get_next_line(fd);
		}
	}
	else
		return (err_msg_int('2'));
}
