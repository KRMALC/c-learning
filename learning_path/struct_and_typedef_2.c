#include <stdio.h>

// Struct içinde enum
typedef enum {
    BEKLIYOR,
    CALISIYOR,
    UYARI
} Cihaz_Durumu_t;

typedef struct {
    float temparature;
    int battery;
    Cihaz_Durumu_t durum;
}Sensor_t;

// Struct’ı fonksiyona göndermek

void raporYazdir (Sensor_t s){
    printf("sicaklik: %.2f \n",s.temparature);
    printf("pil durumu: %d \n",s.battery);
}   

int main (void){
    Sensor_t bahce = {.temparature = 25.2, .battery = 15, .durum = UYARI};

    if (bahce.battery < 20 || bahce.temparature > 45.0)
    {
        bahce.durum = UYARI;
    }
    if (bahce.durum == UYARI)
    {
        printf("Bahce sensoru tehlikede ! sicaklik: %f, pil: %d \n",bahce.temparature, bahce.battery);
    }

    Sensor_t oda = {.temparature = 28.2, .battery = 12, .durum=CALISIYOR};
    raporYazdir(oda);

    return 0;
}

/*
=====================================================================
 DERS 9 NOTLARI: struct ve typedef
 Amaç: Birbirine ait bilgileri tek bir pakette toplamak
=====================================================================

 ----- 1) struct : Kalıp tanımlamak -----

   struct Sensor {
       float sicaklik;
       int   pil;
   };                          // <- sondaki ; UNUTMA!

   - Bu sadece bir KALIP, henüz kutu açmaz (kek kalıbı gibi).
   - İçine istediğim türü koyabilirim: int, float, char, enum, dizi...

 ----- 2) Kalıptan kutu üretmek -----

   struct Sensor oda;
   oda.sicaklik = 23.5f;       // nokta (.) = "içindeki"
   oda.pil      = 85;

   Kısa yol (oluştururken doldurmak):
   struct Sensor oda = { .sicaklik = 23.5f, .pil = 85 };

 ----- 3) typedef : Türe takma ad vermek -----

   typedef struct {
       float sicaklik;
       int   pil;
   } Sensor_t;

   Sensor_t oda;               // artık "struct" yazmama gerek yok

   - Sondaki _t geleneksel: "bu bir tür adıdır" demek.
   - Enum için de aynı şekilde kullanılır:
       typedef enum { BEKLIYOR, CALISIYOR } Durum_t;

 ----- 4) Struct'ı fonksiyona göndermek -----

   void raporYazdir(Sensor_t s) { printf("%.1f", s.sicaklik); }
   raporYazdir(oda);

   - Fonksiyona struct'ın KOPYASI gider.
   - Fonksiyonun içinde değiştirirsem main'deki ASIL değişmez.
     (Asılını değiştirmenin yolu: pointer, ileride göreceğim.)

 ----- 5) Struct dizisi -----

   Sensor_t sensorler[10];     // 10 sensörlük raf
   sensorler[0].pil = 50;      // önce kutu numarası, sonra içindeki

 ----- Hatırlatmalar -----

   - printf'te % işareti yazdırmak için %% kullanılır.
     "%%%d" -> önce % işareti, sonra sayı -> ekranda: %85

 ----- STM32 bağlantısı -----

   STM32 kütüphanesinde ayarlar hep struct ile yapılır. Örnek:
       GPIO_InitTypeDef ayar;
       ayar.Pin  = GPIO_PIN_5;
       ayar.Mode = GPIO_MODE_OUTPUT_PP;
   Bir LED'i ayarlamak = bir struct'ı doldurup fonksiyona vermek.
=====================================================================
*/