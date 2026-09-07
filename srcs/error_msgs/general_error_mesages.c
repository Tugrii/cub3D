/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_error_mesages.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:20:11 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/07 15:57:25 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Library/Libft/libft.h"

int	err_msg_int(char msg_no)
{
	if (msg_no == '1')
		ft_putendl_fd("Error\nMap contain invalid char(s)", 2);
	if (msg_no == '2')
		ft_putendl_fd("Error\n.cub file is empty!", 2);
	return (0);
}
