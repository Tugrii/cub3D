/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_maps_linked_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <tgeler@stundent.42.istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 11:26:21 by tgeler            #+#    #+#             */
/*   Updated: 2026/11/26 20:52:42 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Library/get_next_line/get_next_line.h"
#include "../../Library/Libft/libft.h"
#include "parser.h"
#include "../error_msgs/error_msgs.h"

void	add_map_lists_back(t_map_cont_list **head, t_map_cont_list *will_add_node)
{
	t_map_cont_list	*traversal;

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

t_map_cont_list	*set_new_map_node(char *line_content)
{
	t_map_cont_list	*new_node;
	
	new_node = malloc(sizeof(t_map_cont_list));
	if (!new_node)
		return (NULL);
	new_node->line_content = ft_strdup(line_content);
	if (!(new_node->line_content))
		return (NULL);
	new_node->line_len = ft_strlen(new_node->line_content);
	make_line_format_suitable(new_node->line_content, &(new_node->line_len));
	new_node->next = NULL;
	return (new_node);
}

int	does_have_extra_line(int fd)
{
	char	*line_content;
	char	*temp;

	line_content = get_next_line(fd);
	while (line_content)
	{
		temp = skip_white_spaces_return_lead(line_content);
		if (temp[0] != '\0')
			return (1);
		free(line_content);
		line_content = get_next_line(fd);
	}
	return (0);
}

int	create_maps_linked_list(char *line_content, int fd, t_map_all_infos *map_infos)
{
	t_map_cont_list	*new_map_list_node;

	map_infos->map_cont = NULL;
	while (line_content)
	{
		new_map_list_node = set_new_map_node(line_content);
		if (!new_map_list_node)
			malloc_error(map_infos);
		add_map_lists_back(&(map_infos->map_cont), new_map_list_node);
		line_content = get_next_line(fd);
		if (!run_if_not_wall(line_content))
		{
			new_map_list_node = set_new_map_node(line_content);
			if (!new_map_list_node)
				malloc_error(map_infos);
			add_map_lists_back(&(map_infos->map_cont), new_map_list_node);
			break ;
		}
	}
	if (does_have_extra_line(fd))
		return (err_msg_int('6', NULL));
	return (1);
}
