/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_has_only_one_raydir.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 09:00:20 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/07 16:08:39 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../check_map/check_map.h"


static	int	return_truth_of_raydircount(int	raydir_count)
{
	if (raydir_count != 1)
		return (0);
	return (1);
}

int	check_map_has_only_one_raydir(t_map_cont_list *map, char *raydirs)
{
	t_traversal_map	trv_node;
	int			raydir_count;

	trv_node.node = map;
	raydir_count = 0;
	while (trv_node.node)
	{
		trv_node.i = 0;
		while (trv_node.i < trv_node.node->line_len)
		{
			trv_node.j = 0;
			while (trv_node.j < 4)
			{
				if (trv_node.node->line_content[trv_node.i] == raydirs[trv_node.j])
				{
					raydir_count++;
					break ;
				}
				(trv_node.j)++;
			}
			(trv_node.i)++;
		}
		trv_node.node = trv_node.node->next;
	}
	return (return_truth_of_raydircount(raydir_count));
}
