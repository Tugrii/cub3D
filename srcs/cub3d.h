/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:24:52 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/03 09:12:08 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB3D_H
# define CUB3D_H
 #include "parser/parser.h"
 #include "check_map/check_map.h"
	int	check_contain_valid_char(t_map_list *map, char *valid_chars);
	int	create_fd(int *fd, char *map_name);
	int	create_maps_linked_list(int fd, t_map_list **map);
	int	check_map_has_only_one_raydir(t_map_list *map, char *raydirs);
#endif