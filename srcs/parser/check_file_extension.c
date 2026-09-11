/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_extension.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 00:00:00 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/11 00:00:00 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Library/Libft/libft.h"

int	map_name_checking(char *map_name)
{
	char	*file_name;
	int		file_len;

	if (!map_name)
		return (0);
	file_name = ft_strrchr(map_name, '/');
	if (file_name)
		file_name++;
	else
		file_name = map_name;
	file_len = ft_strlen(file_name);
	if (file_len <= 4)
		return (0);
	if (ft_strncmp(file_name + file_len - 4, ".cub", 4) != 0)
		return (0);
	return (1);
}
