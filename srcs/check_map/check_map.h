/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <tgeler@stundent.42.istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 13:52:54 by tgeler            #+#    #+#             */
/*   Updated: 2026/11/27 00:09:26 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H
 #include "../parser/parser.h"
 void	malloc_err_msg_ex();
 int	err_msg_int(char msg_no, char *msg_content);
 int	err_msg_int_2(char msg_no);

	typedef struct	s_traversal_map
	{
		int i;
		int	j;
		t_map_cont_list	*node;
	}t_traversal_map;

	int		check_contain_valid_char(t_map_cont_list *map, char *valid_chars);
	int		check_walls(t_map_cont_list *map);
	int		check_config(t_map_conf_info *conf);
	int		map_name_checking(char *map_name);
	int		create_fd(int *fd, char *map_name);
	int		create_maps_linked_list(char *line_content, int fd, t_map_all_infos *map_infos);
	int		check_map_has_only_one_raydir(t_map_cont_list *map, char *raydirs);
	int		split_maps_configuration_and_content(int fd, t_map_all_infos *map_infos);
	void	init_map_info(t_map_all_infos *info);

#endif
