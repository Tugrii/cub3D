# RGB ve duvar testleri

Komutlari proje kokunden calistir. Texture yollari repodaki
`Library/mlx/test/open.xpm` dosyasini kullanir. Bu set texture yonlerini veya
goruntuleme kalitesini degil, RGB ve harita kapaliligini test eder.

## Beklenen sonuclar

| Dosya | Beklenti | Kontrol |
| --- | --- | --- |
| valid/rgb_limits.cub | Kabul | F: 0,0,0; C: 255,255,255 |
| valid/rgb_spaces.cub | Kabul | RGB aralarindaki bosluklar, 0/128/255 |
| valid/ragged.cub | Kabul | Farkli satir uzunluklari, kapali harita |
| valid/inner_space.cub | Kabul | Duvarlarla ayrilmis ic bosluk |
| invalid/rgb_overflow.cub | Hata | F icinde 256 |
| invalid/rgb_negative.cub | Hata | C icinde -1 |
| invalid/rgb_missing.cub | Hata | F icinde iki bilesen |
| invalid/rgb_extra.cub | Hata | C icinde dort bilesen |
| invalid/rgb_letter.cub | Hata | F icinde harf |
| invalid/rgb_separator.cub | Hata | C icinde virgul yerine noktali virgul |
| invalid/rgb_empty.cub | Hata | F icinde bos bilesen |
| invalid/rgb_trailing.cub | Hata | C sonunda fazladan karakter |
| invalid/open_top.cub | Hata | Ust kenarda aciklik |
| invalid/open_bottom.cub | Hata | Alt kenarda aciklik |
| invalid/open_side.cub | Hata | Sag kenarda aciklik |
| invalid/open_spawn.cub | Hata | Oyuncu ust sinirda |
| invalid/ragged_open.cub | Hata | Kisa satirda disariya acilan zemin |
| invalid/inner_space.cub | Hata | Zeminle temas eden ic bosluk |

## Yapilan kontrol

18 dosya, gercek `read_colors()` ve `check_walls()` fonksiyonlariyla ayri bir
gecici test duzeneginde denendi: 18/18 beklenen sonuc.
Fonksiyonlar `-Wall -Wextra -Werror` ile derlendi.
Duzenek dosyalardan F/C degerlerini ve harita satirlarini alip fonksiyonlara
verdi; projenin configuration parserini kullanmadi.
Gecerli RGB degerlerinin dogru kaydedildigi, hatali RGB'nin configuration'i
degistirmedigi ve duvar kontrolunun haritayi degistirmedigi de kontrol edildi.
Gecici test duzenegi teslim kaynaklarina eklenmedi.

Bu sonuc tum programin testi degildir. Yerel `main.c` / parser akisinda
RGB ve duvar yardimcilari henuz cagrilmiyor. Hata mesaji, cikis kodu,
temizleme ve bellek sizintisi asagidaki program testleriyle entegrasyondan
sonra ayrica kontrol edilmeli. WSL / Ubuntu kurulumundan sonra tam proje
derlemesi basarili oldu. Ancak mevcut programda gecersiz RGB dosyasi da
0 ile cikabiliyor: yardimcilarin akis baglantisi henuz tamamlanmadi.

## Manuel kontrol (42 / Linux terminali)

Once Tuğra kontrolleri program akisina bagladiktan sonra:

```sh
make
./cub3D maps/tests/valid/rgb_limits.cub
echo $?
./cub3D maps/tests/invalid/rgb_overflow.cub
echo $?
./cub3D maps/tests/valid/ragged.cub
echo $?
./cub3D maps/tests/invalid/ragged_open.cub
echo $?
```

`echo $?` komutunu programdan hemen sonra calistir; son komutun cikis
kodunu gosterir. Gecerli dosyada parser hatasi olmamali, normal cikis 0
olmali. Pencere akisi eklendiginde once pencereyi normal sekilde kapat.
Gecersiz dosyada `Error` satiri ve aciklayici mesaj gorulmeli; program
sifirdan farkli kodla cikmali, cokmemeli veya takilmamali.
Tablodaki diger dosyalari da ayni sekilde tek tek dene.

Bellek kontrolu icin, Valgrind kurulu Linux ortaminda:

```sh
valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/tests/valid/rgb_limits.cub
valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/tests/invalid/rgb_overflow.cub
```

Kendi ayirdigimiz belleklerin hem basarili hem hatali yolda serbest
birakildigini ve gecersiz bellek erisimi olmadigini kontrol et.
Valgrind kontrolleri burada calistirilmadi.
