/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkoc <alkoc@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 00:07:29 by alkoc             #+#    #+#             */
/*   Updated: 2026/10/12 00:07:29 by alkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

static void	free_map(t_map_cont_list *map)
{
	t_map_cont_list	*next;

	while (map)
	{
		next = map->next;
		free(map->line_content);
		free(map);
		map = next;
	}
}

void	free_map_info(t_map_all_infos *info)
{
	if (!info)
		return ;
	free_map(info->map_cont);
	free(info->map_conf.n_texture_name);
	free(info->map_conf.s_texture_name);
	free(info->map_conf.w_texture_name);
	free(info->map_conf.e_texture_name);
	init_map_info(info);
}
