/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <tgeler@stundent.42.istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:20:08 by tgeler            #+#    #+#             */
/*   Updated: 2026/10/21 23:55:52 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Library/Libft/libft.h"
#include "../parser/parser.h"

void	malloc_error(t_map_all_infos *map_info)
{
	free_map_info(map_info);
	ft_putendl_fd("Could'nt alloceted memory!", 2);
	exit(1);
}
