/*
=====================================================================
 DERS 16 NOTLARI: Kapsam, global değişkenler, extern
=====================================================================

 ----- 1) Kapsam (scope) -----

   Kutu, açıldığı { } içinde yaşar. } gelince silinir.
   İçerideki dışarıyı GÖRÜR, dışarıdaki içeriyi GÖREMEZ.

   for (int i = 0; ...) { }   -> i sadece döngünün içinde yaşar
   Farklı fonksiyonlardaki aynı isimli yerel kutular FARKLI kutulardır.

 ----- 2) Global değişken -----

   int sayac = 0;          // bütün fonksiyonların DIŞINDA

   - Dosyadaki bütün fonksiyonlar görür ve değiştirir.
   - Program boyunca yaşar.
   - Değer verilmezse otomatik 0 (yerel ise ÇÖP olur!).

   TEHLİKE: Herkes dokunabildiği için "kim bozdu?" bulmak zor.
   Kural: Varsayılan YEREL. Global sadece gerçekten paylaşılacaksa.

 ----- 3) extern : başka dosyadaki globali kullanmak -----

   sensor.c :  int okumaSayisi = 0;        // TANIM (kutu burada açılır) 1 kere
   sensor.h :  extern int okumaSayisi;     // DUYURU ("başka yerde var")
   main.c   :  #include "sensor.h"  -> okumaSayisi'ni kullanabilir

   - extern satırında DEĞER VERİLMEZ.
   - Fonksiyon prototipinin değişken versiyonu gibi.

 ----- 4) Dört tür -----

   fonksiyon İÇİNDE   int x;         -> sadece o blok, blok bitince ölür
   fonksiyon İÇİNDE   static int x;  -> sadece o fonksiyon, değerini korur
   fonksiyon DIŞINDA  int x;         -> bütün dosyalar (extern ile)
   fonksiyon DIŞINDA  static int x;  -> sadece bu dosya

 ----- STM32 bağlantısı -----

   Interrupt ile main'in haberleşmesi = global + volatile BAYRAK:

   volatile uint8_t butonBasildi = 0;
   void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) { butonBasildi = 1; }
   while (1) { if (butonBasildi) { butonBasildi = 0; ... } }

   CubeIDE: usart.c'de  UART_HandleTypeDef huart2;
            usart.h'de  extern UART_HandleTypeDef huart2;
=====================================================================
*/