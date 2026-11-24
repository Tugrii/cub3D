/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_conf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <tgeler@stundent.42.istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 23:29:58 by tgeler            #+#    #+#             */
/*   Updated: 2026/11/25 00:11:50 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>
#include "../error_msgs/error_msgs.h"

void	free_content(char **content)
{
	free(*content);
	*content = NULL;
}

int	if_is_null_return_true(char **content)
{
	if (*content[0] == '\0')
	{
		free_content(content);
		return (1);
	}
	free_content(content);
	return (err_msg_int('4'));
}
