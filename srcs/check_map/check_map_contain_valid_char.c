/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_contain_valid_char.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 11:24:56 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/02 15:51:40 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Library/Libft/libft.h"
#include "check_map.h"

int	check_contain_valid_char(t_map_list *map)
{
	t_traversal_map	traversal_map;
	char			*valid_chars;
	int				j;

	valid_chars = "01NSEW";
	traversal_map.node = map;
	while (traversal_map.node)
	{
		traversal_map.i = 0;
		while (traversal_map.i < traversal_map.node->line_len)
		{
			j = 0;
			while (j < 6)
			{
				if (traversal_map.node->line_content[traversal_map.i] == valid_chars[j])
					break ;
				j++;
			}
			if (j == 7)
				return (0);
			(traversal_map.i)++;
		}
		traversal_map.node = traversal_map.node->next;
	}
	return (1);
}
