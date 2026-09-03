/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 13:52:54 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/03 09:15:30 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H
 #include "../parser/parser.h"
	typedef struct	s_traversal_map
	{
		int i;
		int	j;
		t_map_list	*node;
	}t_traversal_map;
#endif