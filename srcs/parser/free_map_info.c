/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <tgeler@stundent.42.istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 00:07:29 by alkoc             #+#    #+#             */
/*   Updated: 2026/10/22 22:15:11 by tgeler           ###   ########.fr       */
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

static void free_map_arr(t_map_all_infos *info)
{
	t_map_cont_list	*traversal;
	int				i;

	i = 0;
	traversal = info->map_cont;
	while (traversal)
	{
		free(info->map_cont_arr[i]);
		i++;
		traversal = traversal->next;
	}
	free(info->map_cont_arr);
}

void	free_map_info(t_map_all_infos *info)
{
	if (!info)
		return ;
	free_map_arr(info);
	free_map(info->map_cont);
	free(info->map_conf.n_texture_name);
	free(info->map_conf.s_texture_name);
	free(info->map_conf.w_texture_name);
	free(info->map_conf.e_texture_name);
	free(info);
	info = NULL;
	init_map_info(info);
}
