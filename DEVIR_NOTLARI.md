**alper:** Harita dizisi yarım kaldığında ayrılan belleği temizlemek için `free_partial_map_info(info, saved_rows)` fonksiyonunu ekledim. Fonksiyon `free_map_info.c` içinde.

Harita listesinde üçüncü satır için bellek ayırırken hata alınırsa eğer `saved_rows` değeri 2 olacaktır. Buna göre de fonksiyon dizideki ilk iki satırı, dizinin kendisini ve bağlı listeyi serbest bırakır. Ardından texture yollarını ve ana yapıyı temizlemek için mevcut `free_map_info()` fonksiyonunu çağırır. 
