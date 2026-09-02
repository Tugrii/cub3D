/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_error_mesages.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 12:20:11 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/02 13:44:31 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	err_msg_int(char msg_no)
{
	if (msg_no == '1')
		ft_putendl_fd("Map contain invalid char(s)", 2);
	return (0);
}
