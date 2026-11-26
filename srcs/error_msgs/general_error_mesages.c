/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_error_mesages.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <tgeler@stundent.42.istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:20:11 by tgeler            #+#    #+#             */
/*   Updated: 2026/11/26 01:02:06 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Library/Libft/libft.h"

int	err_msg_int(char msg_no)
{
	if (msg_no == '1')
		ft_putendl_fd("Error\nMap contain invalid char(s)", 2);
	if (msg_no == '2')
		ft_putendl_fd("Error\n.cub file is empty!", 2);
	if (msg_no == '3')
		ft_putendl_fd("Error\nC OR F info are invalid!", 2);
	if (msg_no == '4')
		ft_putendl_fd("Error\n.cub file is contain invalid line!", 2);
	if (msg_no == '5')
		ft_putendl_fd("Error\n.cub file has extra configuration info!", 2);
	if (msg_no == '6')
		ft_putendl_fd("Error\n Map content has extra invalid line(s)!", 2);
	return (0);
}
