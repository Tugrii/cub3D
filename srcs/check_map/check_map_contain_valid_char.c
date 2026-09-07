/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_contain_valid_char.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 11:24:56 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/07 15:37:38 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Library/Libft/libft.h"
#include "check_map.h"

int	check_contain_valid_char(t_map_cont_list *map, char *valid_chars)
{
	t_traversal_map	traversal_map;

	traversal_map.node = map;
	while (traversal_map.node)
	{
		traversal_map.i = 0;
		while (traversal_map.i < traversal_map.node->line_len)
		{
			traversal_map.j = 0;
			while (traversal_map.j < 7)
			{
				if (traversal_map.node->line_content[traversal_map.i]
					== valid_chars[traversal_map.j])
					break ;
				(traversal_map.j)++;
			}
			if (traversal_map.j == 8)
				return (0);
			(traversal_map.i)++;
		}
		traversal_map.node = traversal_map.node->next;
	}
	return (1);
}
