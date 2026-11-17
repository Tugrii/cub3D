/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <tgeler@stundent.42.istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:20:08 by tgeler            #+#    #+#             */
/*   Updated: 2026/10/22 22:08:28 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Library/Libft/libft.h"
#include "../parser/parser.h"

void	malloc_err_msg_ex()
{
	ft_putendl_fd("Could'nt alloceted memory!", 2);
	exit(1);
}

void	malloc_error(t_map_all_infos *map_info)
{
	free_map_info(map_info);
	malloc_err_msg_ex();
}

void	malloc_error_at_start(t_map_conf_info *map_conf)
{
	free(map_conf->n_texture_name);
	free(map_conf->s_texture_name);
	free(map_conf->w_texture_name);
	free(map_conf->e_texture_name);
	malloc_err_msg_ex();
}
