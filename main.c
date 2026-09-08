/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 09:55:20 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/08 11:27:35 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/cub3d.h"
#include "Library/Libft/libft.h"

int main (int argc, char **argv)
{
	int				fd;
	t_map_all_infos	map_info;

	if (argc != 2)
		return (1);
	if (!create_fd(&fd, argv[1]))
		return (1);
	if (!split_maps_configuration_and_content(fd, &map_info))
		return (1);
	if (!check_contain_valid_char(map_info.map_cont, "01NSEW "))
		return (1);
	if(!check_map_has_only_one_raydir(map_info.map_cont, "NSEW"))
		return (1);
	
	return (0);
}

/*
Tugra:
1. dosyayi alip linked list icine yazmak +
2. NO, SO, WE, EA parselari. (kontrolleri) +
3. map N, S,E ,W karakterlerinden sadece birini icerebilir +
4. map sadece 0,1 N, S, E, W ve bosluk karakterlerini icermeli. +


08.09.2026 11.26 not : 
	map conf map cont ayirma kismina bir daha bakacagim.
	map contentinin altindaki yeni satirlarin kabul edilmemesini saglayacagim.
--------------------------

Alper:
1. C , F parse'i
2. ilk arguman olarak .cub uzantili dosyayi almali.
3. 1 ler duvar olacak sekilde mapin etrafi 1ler ile sarilmali.(harita surrounded olmali)(bosluklarin varligini da goz onune alarak)
*/
