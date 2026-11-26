/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_conf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <tgeler@stundent.42.istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 23:29:58 by tgeler            #+#    #+#             */
/*   Updated: 2026/11/26 21:22:17 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>
#include "../error_msgs/error_msgs.h"

int	is_saved_before(t_map_conf_info *conf_info, int identifier_no)
{
	if (identifier_no == 0)
		if (conf_info->n_texture_name)
			return (1);
	if (identifier_no == 1)
		if (conf_info->s_texture_name)
			return (1);
	if (identifier_no == 2)
		if (conf_info->w_texture_name)
			return (1);
	if (identifier_no == 3)
		if (conf_info->e_texture_name)
			return (1);
	if (identifier_no == 4)
		if (conf_info->c_rgb_colors[0] != -1 &&
			conf_info->c_rgb_colors[1] != -1 &&
				conf_info->c_rgb_colors[2] != -1)
					return (1);
	if (identifier_no == 5)
		if (conf_info->f_rgb_colors[0] != -1 &&
			conf_info->f_rgb_colors[1] != -1 &&
				conf_info->f_rgb_colors[2] != -1)
					return (1);
	return (0);
}

void	free_content(char **content)
{
	free(*content);
	*content = NULL;
}

int	if_is_null_return_true(char **content)
{
	if (*content[0] == '\0')
	{
		free_content(content);
		return (1);
	}
	free_content(content);
	return (err_msg_int('4', NULL));
}

int	does_have_all_conf(t_map_conf_info *conf_info)
{
	int	validty_flag;

	validty_flag = 1;
	if (!conf_info->w_texture_name)
		validty_flag = err_msg_int('7', "WE configuration");
	if (!conf_info->n_texture_name)
		validty_flag = err_msg_int('7', "NO configuration");
	if (!conf_info->e_texture_name)
		validty_flag = err_msg_int('7', "EA configuration");
	if (!conf_info->s_texture_name)
		validty_flag = err_msg_int('7', "SO configuration");
	if (conf_info->c_saved == 'n')
		validty_flag = err_msg_int('7', "C configuration");
	if (conf_info->f_saved == 'n')
		validty_flag = err_msg_int('7', "F configuration");
	if (!validty_flag)
		return (0);
	return (1);
}
