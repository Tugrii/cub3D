/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <tgeler@stundent.42.istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 18:26:47 by alkoc             #+#    #+#             */
/*   Updated: 2026/11/26 21:10:24 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stddef.h>

void	init_map_info(t_map_all_infos *info)
{
	int	i;

	if (!info)
		return ;
	info->map_cont = NULL;
	info->map_cont_arr = NULL;
	info->map_conf.n_texture_name = NULL;
	info->map_conf.s_texture_name = NULL;
	info->map_conf.w_texture_name = NULL;
	info->map_conf.e_texture_name = NULL;
	info->map_conf.c_saved = 'n';
	info->map_conf.f_saved = 'n';
	i = 0;
	while (i < 3)
	{
		info->map_conf.c_rgb_colors[i] = -1;
		info->map_conf.f_rgb_colors[i] = -1;
		i++;
	}
}
