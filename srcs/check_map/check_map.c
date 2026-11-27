/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <tgeler@stundent.42.istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 21:33:21 by tgeler            #+#    #+#             */
/*   Updated: 2026/11/28 01:42:37 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"
#include <stdlib.h>

int check_map_utils(int validty_flag, t_map_all_infos *map_info)
{
	if (!validty_flag)
	{
		free_map_info(map_info);
		return (0);
	}
	return (1);
}

int	check_map(int argc, char **argv, int *fd, t_map_all_infos **map_info)
{
	int	validty_flag;

	validty_flag = 1;
	*map_info = malloc(sizeof(t_map_all_infos));
	if (!(*map_info))
		malloc_err_msg_ex();
	init_map_info(*map_info);
	if (argc != 2)
		return (err_msg_int_2('1'));
	if (!map_name_checking(argv[1]))
		return (err_msg_int_2('2'));
	if (!create_fd(fd, argv[1]))
		return (err_msg_int_2('3'));
	if (!split_maps_configuration_and_content(*fd, *map_info))
		return (free_map_info(*map_info), 0);
	if (!check_contain_valid_char((*map_info)->map_cont, "01NSEW "))
		validty_flag = err_msg_int('9', NULL);
	if(!check_map_has_only_one_raydir((*map_info)->map_cont, "NSEW"))
		validty_flag = err_msg_int('0', NULL);
	if (!check_walls((*map_info)->map_cont))
		validty_flag = err_msg_int_2('0');
	return (check_map_utils(validty_flag, *map_info));
}
