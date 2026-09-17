/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler@stundent.42.istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 09:55:20 by tgeler            #+#    #+#             */
/*   Updated: 2026/09/08 12:06:56 by tgeler           ###   ########.fr       */
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
TODO

Tugra:
1. .cub uzanti kontrolunu dosya acilmadan once cagirmak.
2. C/F renk okumasini configuration akisina baglamak.
3. Duvar kontrolunu map kontrollerine baglamak.
4. Oyuncunun baslangic konumunu ve bakis yonunu kaydetmek.

Alper:
1. Map ve configuration icin init_map_info() fonksiyonunu hazirlamak.
2. Map listesi ve texture isimleri icin free_map_info() hazirlamak.
3. Gecerli/gecersiz RGB, acik duvar ve farkli satir uzunluklari icin
   kucuk bir .cub test seti hazirlamak.

Yardimci fonksiyonlarin program akisina baglanmasi Tugra'da.
*/
