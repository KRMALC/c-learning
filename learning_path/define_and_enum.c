#include <stdio.h>

/*TRAFIK LAMBASI UYGULAMASI*/

#define KIRMIZI_SURE 30
#define SARI_SURE 3 
#define YESIL_SURE 25

enum Renk{
    KIRMIZI,
    SARI,
    YESIL,
};

int main (void){

    enum Renk lamba = YESIL;

    if (lamba == KIRMIZI)
    {
        printf("Kirmizi yaniyor. %d kadar bekle.",KIRMIZI_SURE);
    }else if (lamba == SARI)
    {
        printf("Sari yaniyor. %d kadar bekle.",SARI_SURE);
    }
    else
    {
        printf("yesil yandi. Gec");
    }
    
    return 0;
}

/*
=====================================================================
 DERS 8 NOTLARI: #define ve enum
 Amaç: Kodda çıplak sayılar yerine anlamlı isimler kullanmak
=====================================================================

 ----- 1) #define : Sabit değere isim vermek -----

   #define KRITIK_PIL  20

   - "Kodda KRITIK_PIL gördüğün her yere 20 yaz" demek.
   - Derlemeden HEMEN ÖNCE metin olarak yerine konur.
   - Kutu (değişken) DEĞİLDİR: bellekte yer kaplamaz, değiştirilemez.
   - Dosyanın en üstüne, #include'un altına yazılır.
   - Sonunda ; YOK, = işareti YOK.
   - İsimler BÜYÜK HARFLE yazılır (sabit olduğu hemen anlaşılsın).
   - Faydası: değeri değiştirmek için sadece tek satırı değiştiririm.

 ----- 2) enum : Seçenek listesi oluşturmak -----

   enum Renk {
       KIRMIZI,    // otomatik 0
       SARI,       // otomatik 1
       YESIL       // otomatik 2
   };

   enum Renk lamba = SARI;     // Renk türünde bir kutu aç, içine SARI koy

   if (lamba == SARI) { ... }  // 1 yerine SARI yazmak çok daha okunaklı

   - enum yeni bir TÜR oluşturur (int gibi).
   - C, listedeki isimlere sırayla 0, 1, 2... değerlerini verir.
   - Arka planda yine sayı var, ama kodda isimleri kullanırım.
   - İstersem sayıları kendim verebilirim:
         enum Hiz { YAVAS = 10, ORTA = 50, HIZLI = 100 };

 ----- 3) Hangisini ne zaman kullanırım? -----

   Tek bir sabit değer (eşik, limit, süre, pin no)  ->  #define
   Birbiriyle ilgili seçenekler (durum, mod, renk)  ->  enum

 ----- Hatırlatmalar -----

   - Karşılaştırma == ile yapılır (= atamadır!).
   - typedef enum { ... } Isim_t;  yazımını struct dersinde göreceğim.
     Şimdilik: enum'a kısa bir tür adı vermenin yolu.

 ----- STM32 bağlantısı -----

   #define LED_PIN 5               -> donanım pinlerine isim vermek
   enum { BEKLEME, CALISMA, HATA } -> cihazın durumlarını tutmak
   (Gömülü sistemlerde "durum makinesi" denen yapının temeli budur.)
=====================================================================
*/