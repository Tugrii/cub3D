/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_conf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <tgeler@stundent.42.istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 23:29:58 by tgeler            #+#    #+#             */
/*   Updated: 2026/11/24 23:44:22 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	free_content(char **content)
{
	free(*content);
	*content = NULL;
}

int	if_is_nl_return_null(char **content)
{
	

	if (*content[0] == '\n')
	{
		free_content(content);
		return (1);
	}
	free_content(content);
	return (err_msg_int('4'));
}
