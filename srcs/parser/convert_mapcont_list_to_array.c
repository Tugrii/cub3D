/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_mapcont_list_to_array.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <tgeler@stundent.42.istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 22:00:46 by tgeler            #+#    #+#             */
/*   Updated: 2026/10/21 23:59:32 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	convert_mapcont_list_to_array(t_map_all_infos	*map_info)
{
	int				line_num;
	t_map_cont_list	*traversal;

	traversal = map_info->map_cont;
	line_num = 0;
	while (traversal)
	{
		line_num++;
		traversal = traversal->next;
	}
	map_info->map_cont_arr = malloc(sizeof(char *) * line_num);
	if (!(map_info->map_cont_arr))
		malloc_error(map_info);
	traversal = map_info->map_cont;
	line_num = 0;
	while (traversal)
	{
		map_info->map_cont_arr[line_num] = malloc(sizeof(char) * (traversal->line_len + 1))
		if (!(map_info->map_cont_arr[line_num]))
			malloc_error(map_info);
		map_info->map_cont_arr[line_num][traversal->line_line] = '\0';
		line_num++;
		traversal = traversal->next;
	}
}