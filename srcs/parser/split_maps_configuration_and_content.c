/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_maps_configuration_and_content.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 13:50:52 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/08 09:33:14 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../../Library/Libft/libft.h"
#include "../../Library/get_next_line/get_next_line.h"

int		run_if_not_wall(char	*line_content)
{
	int		i;
	int		wall_chars_count;
	int		line_len;

	i = 0;
	line_len = ft_strlen(line_content);
	make_line_format_suitable(line_content, &line_len);
	wall_chars_count = 0;
	while (i < line_len)
	{
		if (line_content[i] == '1' || line_content[i] == ' ')
			wall_chars_count++;
		else
			break ;
		i++;
	}
	if (wall_chars_count == line_len && (wall_chars_count != 0))
		return (0);
	return (1);
}

int	split_maps_configuration_and_content(int fd, t_map_all_infos *map_infos)
{
	char	*line_content;

	line_content = get_next_line(fd);
	if (line_content)
	{
		while (run_if_not_wall(line_content))
		{
			read_configs_and_save_it(&line_content, &(map_infos->map_conf));
			line_content = get_next_line(fd);
		}
		if (!create_maps_linked_list(line_content, fd, &(map_infos->map_cont)))
			malloc_error();
	}
	else
		return (err_msg_int('2'));
	return (1);
}
