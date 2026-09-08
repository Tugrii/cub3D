/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 15:27:59 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/08 11:03:54 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../../Library/Libft/libft.h"

void	save_it(int identifier_no, char *raw_file_name, t_map_conf_info *map_conf)
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
	/*C VE F NIN PARSE'I BURADA else if (identifier_no == 4 || identifier_no == 5)
		parse_c_and_f(identifier_no, file_name, map_conf); */
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

char	*skip_white_spaces_return_lead(char *content)
{
	int		i;

	i = 0;
	while (is_white_space(content[i]))
		i++;
	return (content + i);
}

char *if_valid_get_file_name(char *content, char **identifiers, int identifier_len, int *identifier_no)
{
	int		j;
	char	*file_name;

	j = 0;
	while (j < 6)
	{
		if (!ft_strncmp(identifiers[j], content, identifier_len))
		{
			*identifier_no = j;
			file_name = skip_white_spaces_return_lead(content + identifier_len);
			return (file_name);
		}
		j++;
	}
	return (NULL);
}

char *is_identifier_return_file_s_name(char *content, char **identifiers, int *identifier_no)
{
	int		char_count_till_other_whitespace;
	int		i;

	i = 0;
	char_count_till_other_whitespace = 0;
	while (!is_white_space(content[i]))
	{
		char_count_till_other_whitespace++;
		i++;
	}
	if (char_count_till_other_whitespace == 1)
		return (if_valid_get_file_name(content, identifiers, 1, identifier_no));
	else if (char_count_till_other_whitespace == 2)
		return (if_valid_get_file_name(content, identifiers, 2, identifier_no));
	return (NULL);
}

void	read_configs_and_save_it(char **content, t_map_conf_info *map_conf)
{
	char	*identifiers[6];
	char	*raw_file_name;
	int		identifier_no;

	identifiers[0] = "NO";
	identifiers[1] = "SO";
	identifiers[2] = "WE";
	identifiers[3] = "EA";
	identifiers[4] = "C";
	identifiers[5] = "F";

	raw_file_name = skip_white_spaces_return_lead(*content);
	raw_file_name = is_identifier_return_file_s_name(raw_file_name, identifiers, &identifier_no);
	if (raw_file_name)
		save_it(identifier_no, raw_file_name, map_conf);
	free(*content);
	*content = NULL;
}
