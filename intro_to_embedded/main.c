#include "sensor.h"

int main(void) {
    Sensor_t oda = { .sicaklik = 23.5f, .pil = 15 };

    raporYazdir(&oda);
    pilDoldur(&oda);
    raporYazdir(&oda);

    return 0;
}


/*
=====================================================================
 DERS 13 NOTLARI: static, header dosyaları, volatile
=====================================================================

 ----- 1) static : iki görevi var -----

   a) Fonksiyonun İÇİNDE -> "değerini unutma"

      void say(void) {
          static int sayac = 0;   // = 0 sadece İLK seferde çalışır
          sayac++;                // her çağırmada 1, 2, 3...
      }
      - Fonksiyon bitince SİLİNMEZ, değerini korur.
      - Ama yine sadece o fonksiyon kullanabilir.

   b) Fonksiyonun DIŞINDA -> "sadece bu dosyaya ait"

      static int yardimci(void) { ... }
      - Başka .c dosyalarından görünmez, çağrılamaz.
      - .h dosyasına yazılmaz (mutfağın iç işi).

 ----- 2) Header dosyaları -----

   modul.h  -> MENÜ:   struct, #define, fonksiyon PROTOTİPLERİ
   modul.c  -> MUTFAK: fonksiyonların GÖVDELERİ
   main.c   -> #include "modul.h" ile menüye bakar, kullanır

   #include <stdio.h>    -> sistem kütüphanesi
   #include "sensor.h"   -> benim dosyam (aynı klasörde)
   #include = o dosyayı buraya KOPYALA-YAPIŞTIR

   Derleme (tüm .c dosyaları, .h YAZILMAZ):
       gcc main.c sensor.c -o program

   Include guard (HER .h dosyası böyle başlar/biter):
       #ifndef SENSOR_H
       #define SENSOR_H
           ... içerik ...
       #endif
   -> Aynı .h iki kere eklenirse ikincisini atlar, "zaten var" hatası olmaz.

 ----- 3) volatile -----

   volatile int butonBasildi = 0;

   - Derleyici kodu hızlandırmak için "bu değişken değişmiyor" deyip
     bellekten tekrar okumayı ATLAYABİLİR (optimizasyon).
   - Donanım/interrupt değişkeni koddan habersiz değiştirirse
     program eski değeri görmeye devam eder -> sonsuz bekleme!
   - volatile = "akıllılık yapma, her seferinde bellekten TEKRAR OKU"

   Ne zaman?
   - Donanım register'ları (STM32 dosyalarında zaten volatile)
   - Interrupt içinde değişen değişkenler  <- BUNLARI BEN YAZACAĞIM
   Kural: Normal kod akışı dışında değişebiliyorsa -> volatile

 ----- STM32 bağlantısı -----

   CubeIDE projesi: main.c/.h, gpio.c/.h, usart.c/.h ... hepsi bu düzende
   static -> buton sayacı, "ilk çalışma mı?" kontrolü
   volatile -> interrupt ile değişen her bayrak (flag) değişkeni
=====================================================================
*/