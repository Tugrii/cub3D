/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: <tgeler@stundent.42.istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 09:55:20 by tgeler            #+#    #+#             */
/*   Updated: 2026/11/27 01:31:32 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/cub3d.h"
#include "Library/Libft/libft.h"

int main (int argc, char **argv)
{
	int				fd;
	t_map_all_infos	*map_info;

	if (!check_map(argc, argv, &fd, &map_info))
		return (1);
	return (0);
}

/*
TODO

Tugra:
1. Configuration okumasinda bos satir ve dosya sonunu ele almak +
2. RGB hatasini ust akis tarafina iletmek. +
3. Haritayi double array'e donusturmeyi tamamlayip akisa baglamak.
4. Oyuncunun baslangic konumunu ve bakis yonunu kaydetmek.
5. Basarili ve hatali cikislarda hata mesajlarini, close(fd) ve
   temizleme cagrilarini duzenlemek.

Alper:
1. Dort texture yolu ve C/F renklerinin atanmis oldugunu kontrol
   eden configuration tamamlik yardimcisini hazirlamak. +
2. free_map_info() fonksiyonunu map_cont_arr olusmamis veya yarim
   olusturulmusken de guvenli temizleme yapacak sekilde duzenlemek. +
3. Bos dosya, eksik ayar, yalnizca ayar iceren dosya ve gecersiz
   harita karakteri icin test dosyalari eklemek. +

Yardimci fonksiyonlarin program akisina baglanmasi Tugra'da.
*/
