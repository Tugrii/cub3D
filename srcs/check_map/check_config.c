/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkoc <alkoc@student.42istanbul.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 15:51:36 by alkoc             #+#    #+#             */
/*   Updated: 2026/11/19 15:51:36 by alkoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

static int	check_texture(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (!str[i])
		return (0);
	return (1);
}

int	check_config(t_map_conf_info *conf)
{
	int	i;

	if (!conf)
		return (0);
	if (!check_texture(conf->n_texture_name)
		|| !check_texture(conf->s_texture_name))
		return (0);
	if (!check_texture(conf->w_texture_name)
		|| !check_texture(conf->e_texture_name))
		return (0);
	i = 0;
	while (i < 3)
	{
		if (conf->c_rgb_colors[i] < 0 || conf->c_rgb_colors[i] > 255)
			return (0);
		if (conf->f_rgb_colors[i] < 0 || conf->f_rgb_colors[i] > 255)
			return (0);
		i++;
	}
	return (1);
}
