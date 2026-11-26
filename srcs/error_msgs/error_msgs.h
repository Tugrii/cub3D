/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <tgeler@stundent.42.istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 15:23:31 by tgeler            #+#    #+#             */
/*   Updated: 2026/11/26 20:52:34 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSGS_H
# define ERROR_MSGS_H
 #include "../parser/parser.h"
	int		err_msg_int(char msg_no, char *msg_content);
	void	malloc_err_msg_ex();
	void	malloc_error(t_map_all_infos *map_info);
	void	malloc_error_at_start(t_map_conf_info *map_conf);
#endif