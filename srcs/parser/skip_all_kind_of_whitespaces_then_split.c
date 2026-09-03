/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_all_kind_of_whitespaces_then_split.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 15:27:59 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/03 16:55:15 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

char *is_identifier_return_file_s_name(char *content, char **identifiers, t_map_conf_info *map_conf)
{
	int		char_count_till_other_whitespace;
	int		j;
	int		i;

	i = 0;
	char_count_till_other_white_space = 0;
	while (!is_white_space(content[i]))
	{
		char_count_till_other_white_space++;
		i++;
	}
	if (char_count_till_other_white_space != 2)//bu 1 ve 2 icin ozellestirilecek F VE C DE cunku sikinti cikarir.
		return (NULL);
	i++;
	j = 0;
	while (j < 6)
	{
		if (!ft_strncmp(identifiers[j], content + i, 2))
			return (content + i + 2);
		j++;
	}
	return (NULL);
}

void	skip_all_kind_of_whitespaces_then_split(char *content, int content_len, t_map_conf_info *map_conf)
{
	int		i;
	char	*identifiers[6];
	char	*file_name;

	identifiers[0] = "NO";
	identifiers[1] = "SO";
	identifiers[2] = "WO";
	identifiers[3] = "EA";
	identifiers[4] = 'C';
	identifiers[5] = 'F';
	i = 0;
	while (i < content_len)
	{
		while (is_white_space(content[i]))
			i++;
		file_name = is_identifier_return_file_name(content + i, identifiers, map_conf);
		if (file_name)
			is_valid_name_save_it_if_not_free_content(file_name, map_conf);
	}
}
