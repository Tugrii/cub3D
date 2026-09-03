/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 09:55:20 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/03 08:26:57 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/cub3d.h"
int main (int argc, char **argv)
{
	int			fd;
	t_map_list *map;

	if (argc != 2)
		return (1);
	if (!create_fd(&fd, argv[1]))
		return (1);
	if (!create_maps_linked_list(fd, &map))
		return (1);
	if (!check_contain_valid_char(map))
		return (1);
	return (0);
}

/*
Tugra:
1. dosyayi alip linked list icine yazmak +
2. NO, SO, WE, EA parselari. (kontrolleri)
3. map N, S,E ,W karakterlerinden sadece birini icerebilir
4. map sadece 0,1 N, S, E, W ve bosluk karakterlerini icermeli.



Alper:
1. C , F parse'i
2. ilk arguman olarak .cub uzantili dosyayi almali.
3. 1 ler duvar olacak sekilde mapin etrafi 1ler ile sarilmali.(harita surrounded olmali)(bosluklarin varligini da goz onune alarak)
*/
