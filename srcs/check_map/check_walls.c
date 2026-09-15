/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkoc <alkoc@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 15:24:52 by alkoc            #+#    #+#             */
/*   Updated: 2026/09/15 21:13:10 by alkoc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"

static int	is_floor(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int	check_cell(t_map_cont_list *map, int i)
{
	if (!map || !map->line_content)
		return (0);
	if (i < 0 || i >= map->line_len)
		return (0);
	if (map->line_content[i] == '1' || is_floor(map->line_content[i]))
		return (1);
	return (0);
}

static int	check_line(t_map_cont_list *prev, t_map_cont_list *map)
{
	int	i;

	if (!map->line_content || map->line_len <= 0)
		return (0);
	i = 0;
	while (i < map->line_len)
	{
		if (is_floor(map->line_content[i]))
		{
			if (!check_cell(prev, i) || !check_cell(map->next, i))
				return (0);
			if (!check_cell(map, i - 1) || !check_cell(map, i + 1))
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_walls(t_map_cont_list *map)
{
	t_map_cont_list	*prev;

	if (!map)
		return (0);
	prev = 0;
	while (map)
	{
		if (!check_line(prev, map))
			return (0);
		prev = map;
		map = map->next;
	}
	return (1);
}
