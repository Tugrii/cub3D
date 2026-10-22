/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <tgeler@stundent.42.istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 21:33:21 by tgeler            #+#    #+#             */
/*   Updated: 2026/10/22 22:32:30 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"
#include <stdlib.h>

int	check_map(int argc, char **argv, int *fd, t_map_all_infos **map_info)
{
	*map_info = malloc(sizeof(t_map_all_infos));
	if (!(*map_info))
		malloc_err_msg_ex();
	init_map_info(*map_info);
	if (argc != 2)
		return (0);
	if (!map_name_checking(argv[1]))
		return (0);
	if (!create_fd(fd, argv[1]))
		return (0);
	if (!split_maps_configuration_and_content(*fd, *map_info))
		return (0);
	if (!check_contain_valid_char((*map_info)->map_cont, "01NSEW "))
		return (0);
	if(!check_map_has_only_one_raydir((*map_info)->map_cont, "NSEW"))
		return (0);
	if (!check_walls((*map_info)->map_cont))
		return (0);
	return (1);
}
