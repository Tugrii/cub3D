/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_all_kind_of_whitespaces_then_split.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 15:27:59 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/07 14:01:01 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	save_it_and_free_it(char **line, int identifier_no, char *raw_file_name, t_map_conf_info *map_conf)
{
	char	*file_name;

	file_name = ft_strdup(raw_file_name);
	if (!file_name)
		malloc_error();
	if (identifier_no == 0)
		map_conf->n_texture_name = file_name;
	else if (identifier_no == 1)
		map_conf->s_texture_name = file_name;
	else if (identifier_no == 2)
		map_conf->w_texture_name = file_name;
	else if (identifier_no == 3)
		map_conf->e_texture_name = file_name;
	else if (identifier_no == 4 || identifier_no == 5)
		parse_c_and_f(identifier_no, file_name, map_conf);
	free (*line);
	*line = NULL;
}

int		is_white_space(char content_index_s_value)
{
	int		i;
	char	*white_spaces;

	white_spaces = " \t\v\r\f";
	i = 0;
	while (i < 5)
	{
		if (content_index_s_value == white_spaces[i])
			return (1);
		i++;
	}
	return (0);
}

char *if_valid_get_file_name(char *content, char **identifiers, int identfier_len, int *identifier_no)
{
	int		j;

	j = 0;
	while (j < 6)
	{
		if (!ft_strncmp(identifiers[j], content, identifier_len))
		{
			*identifier_no = j;
			return (content + identifier_len);
		}
		j++;
	}
	return (NULL);
}
char *is_identifier_return_file_s_name(char *content, char **identifiers, t_map_conf_info *map_conf, int *identifier_no)
{
	int		char_count_till_other_whitespace;
	int		i;

	i = 0;
	char_count_till_other_white_space = 0;
	while (!is_white_space(content[i]))
	{
		char_count_till_other_white_space++;
		i++;
	}
	if (char_count_till_other_white_space == 1)
		return (if_valid_get_file_name(content + i, identifiers, 1, identifier_no));
	else if (char_count_till_other_white_space == 2)
		return (if_valid_get_file_name(content + i, identifiers, 2, identifier_no));
	return (NULL);
}

void	skip_all_kind_of_whitespaces_then_split(char **content, int content_len, t_map_conf_info *map_conf)
{
	int		i;
	char	*identifiers[6];
	char	*raw_file_name;
	int		identifier_no;

	identifiers[0] = "NO";
	identifiers[1] = "SO";
	identifiers[2] = "WO";
	identifiers[3] = "EA";
	identifiers[4] = 'C';
	identifiers[5] = 'F';
	i = 0;
	while (is_white_space(*content[i]))
		i++;
	file_name = is_identifier_return_file_name(*content + i, identifiers, map_conf, &identifier_no);
	if (file_name)
		save_it_and_free_it(content, identifier_no, file_name, map_conf);
	else
	{
		free(*content);
		*content = NULL;
	}
}
