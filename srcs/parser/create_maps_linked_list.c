/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_maps_linked_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 11:26:21 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/02 15:47:48 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Library/get_next_line/get_next_line.h"
#include "../../Library/Libft/libft.h"
#include "parser.h"

void	add_map_lists_back(t_map_list **head, t_map_list *will_add_node)
{
	t_map_list	*traversal;

	if (!head || !will_add_node)
		return ;
	else if (*head == NULL)
	{
		*head = will_add_node;
		return ;
	}
	else
	{
		traversal = *head;
		while (traversal->next)
			traversal = traversal->next;
		traversal->next = will_add_node;
	}		
}

t_map_list	*set_new_map_node(char *line_content)
{
	t_map_list	*new_node;
	
	new_node = malloc(sizeof(t_map_list));
	if (!new_node)
		return (NULL);
	new_node->line_content = ft_strdup(line_content);
	if (!(new_node->line_content))
		return (NULL);
	new_node->line_len = ft_strlen(new_node->line_content);
	new_node->next = NULL;
	return (new_node);
}

int	create_maps_linked_list(int fd, t_map_list **map)
{
	char		*line_content;
	t_map_list	*new_map_list_node;

	*map = NULL;
	line_content = get_next_line(fd);
	while (line_content)
	{
		new_map_list_node = set_new_map_node(line_content);
		if (!new_map_list_node)
			return (0);
		add_map_lists_back(map, new_map_list_node);
		line_content = get_next_line(fd);
	}
	return (1);
}
