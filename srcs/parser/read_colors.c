/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkoc <alkoc@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 12:00:00 by alkoc          #+#    #+#             */
/*   Updated: 2026/09/13 12:00:00 by alkoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	skip_spaces(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

static int	read_color(char *str, int *i, int *value)
{
	*i = skip_spaces(str, *i);
	if (str[*i] < '0' || str[*i] > '9')
		return (0);
	*value = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*value = *value * 10 + (str[*i] - '0');
		if (*value > 255)
			return (0);
		(*i)++;
	}
	*i = skip_spaces(str, *i);
	return (1);
}

static int	check_rgb_end(char *str, int i)
{
	if (str[i] == '\r')
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i])
		return (0);
	return (1);
}

static int	check_rgb(char *str, int *rgb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 3)
	{
		if (!read_color(str, &i, &rgb[j]))
			return (0);
		if (j < 2)
		{
			if (str[i] != ',')
				return (0);
			i++;
		}
		j++;
	}
	return (check_rgb_end(str, i));
}

int	read_colors(int id, char *str, t_map_conf_info *conf)
{
	int	rgb[3];
	int	i;

	if (!str || !conf)
		return (0);
	if (id != 4 && id != 5)
		return (0);
	if (!check_rgb(str, rgb))
		return (0);
	i = 0;
	while (i < 3)
	{
		if (id == 4)
			conf->c_rgb_colors[i] = rgb[i];
		else
			conf->f_rgb_colors[i] = rgb[i];
		i++;
	}
	return (1);
}
