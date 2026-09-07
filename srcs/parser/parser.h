/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:06:59 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/07 15:54:30 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PARSER_H
# define PARSER_H

 #include "../error_msgs/error_msgs.h"

typedef struct s_map_cont_list
{
	char	*line_content;
	int		line_len;
	struct	s_map_cont_list *next;
}t_map_cont_list;

typedef struct s_map_conf_info
{
	char	*w_texture_name;
	char	*e_texture_name;
	char	*n_texture_name;
	char	*s_texture_name;
	int		c_rgb_colors[3];
	int		f_rgb_colors[3];
}t_map_conf_info;

typedef struct	s_map_all_infos
{
	t_map_conf_info		map_conf;
	t_map_cont_list		*map_cont;
}t_map_all_infos;

void	read_configs_and_save_it(char **content, t_map_conf_info *map_conf);
int	create_maps_linked_list(char *line_content, int fd, t_map_cont_list **map);
#endif