#include <stdio.h>
#include <stdint.h>

#define BIT_SET(x, n)     ((x) |=  (1 << (n)))  // ca
#define BIT_CLEAR(x, n)   ((x) &= ~(1 << (n)))  // kapat
#define BIT_TOGGLE(x, n)  ((x) ^=  (1 << (n)))  // cevir
#define BIT_READ(x, n)    (((x) >> (n)) & 1)    // oku
 
void bitYazdir(uint8_t x) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", BIT_READ(x, i));
    }
    printf("\n");
}

int main(void) {
    uint8_t port = 0;

    printf("Baslangic:   "); bitYazdir(port);

    BIT_SET(port, 3);
    printf("3 SET:       "); bitYazdir(port);

    BIT_SET(port, 5);
    printf("5 SET:       "); bitYazdir(port);

    BIT_CLEAR(port, 3);
    printf("3 CLEAR:     "); bitYazdir(port);

    BIT_TOGGLE(port, 0);
    printf("0 TOGGLE:    "); bitYazdir(port);

    printf("Bit 5: %d\n", BIT_READ(port, 5));
    printf("Bit 3: %d\n", BIT_READ(port, 3));

    return 0;
}


/*

stm32f4xx_hal.h nedir?

HAL (Hardware Abstraction Layer, yani donanım soyutlama katmanı), ST firmasının STM32 için hazırladığı hazır bir kütüphanedir. 
stm32f4xx kısmı ise bu kütüphanenin STM32F4 serisi çipler için olduğunu gösterir.



*/




/*

HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);

// içeride kabaca şunu yapar:

GPIOC->ODR ^= (1 << 13);


*/


/*

            HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13); 
            Yazdığın o kodların durumu?
Makrolar (BIT_SET vb.) → Bunları sen yazmayacaksın. STM32'nin kendi dosyalarında zaten var: SET_BIT, CLEAR_BIT, READ_BIT adıyla hazır geliyor. Ben sadece nasıl yapıldığını görmen için yazdım.
bitYazdir → Sadece bilgisayarda öğrenirken bitleri gözünle görmen için. STM32'de buna ihtiyacın olmayacak.

GPIO_PIN_13 nedir? STM32 kütüphanesinde şöyle tanımlı:

#define GPIO_PIN_13   ((uint16_t)0x2000)
0x2000 sayısını ikiliğe çevirirsen:
0010 0000 0000 0000
  ↑
  bit 13

Yani GPIO_PIN_13 aslında 1 << 13, bu derste öğrendiğin maskenin ta kendisi.

HAL_GPIO_TogglePin’in içi de kabaca şöyle bir şey yapıyor:
// GPIOC'nin register'ındaki 13 numaralı biti tersine çevir
GPIOC->ODR ^= GPIO_PIN_13;

Yani HAL bu dersteki bit işlemlerini senin için yapıyor ve üstüne güzel bir isim koyuyor.

O zaman neden öğreniyoruz?

Çünkü günlük işte HAL kullansan da şu durumlarda mutlaka bit işlemlerine döneceksin:

Hata ayıklarken: Debugger’da register’a bakınca 0x00002020 gibi bir sayı göreceksin. “Hangi pinler açık?” sorusunu cevaplayabilmen lazım.
HAL’in yetmediği yerde: Bazı özel ayarlar için HAL fonksiyonu yok. Datasheet’e bakıp register’a doğrudan bit yazman gerekecek.
Hız gerektiğinde: HAL fonksiyonları birkaç ekstra kontrol yapar. Çok hızlı işlerde (motor kontrolü, sinyal üretimi) doğrudan register’a yazılır.
Kendi verilerinde: Bir sensör sana tek bir byte içinde 8 farklı durum bilgisi gönderebilir. Hangisinin açık olduğunu & ile okuyacaksın.
İş görüşmelerinde: Gömülü sistem mülakatlarında “bir biti nasıl set edersin?” sorusu neredeyse her zaman sorulur.

*/
 
/*
=====================================================================
 DERS 12 NOTLARI: Bit işlemleri
 Amaç: Bir sayının içindeki tek tek bitleri açıp kapatmak
=====================================================================

 ----- 1) İkilik sistem -----

   1 bit  = 0 veya 1 (anahtar: kapalı/açık)
   1 byte = 8 bit

   bit no:   7    6    5    4    3    2    1    0    <- SAĞDAN başlar!
   değeri: 128   64   32   16    8    4    2    1

   0b00000101 = 4 + 1 = 5      (0b = ikilik sayı yazma öneki)

   #include <stdint.h>
   uint8_t  -> 8 bit,  0..255        (u = unsigned = işaretsiz)
   uint16_t -> 16 bit
   uint32_t -> 32 bit  (STM32 register'ları bu boyutta)

 ----- 2) Bit operatörleri -----

   &   VE      ikisi de 1 ise 1
   |   VEYA    en az biri 1 ise 1
   ^   XOR     farklıysa 1
   ~   DEĞİL   hepsini tersine çevir
   <<  sola kaydır     1 << 3  ->  00001000
   >>  sağa kaydır

   1 << n  = MASKE: sadece n. biti 1 olan sayı

   DİKKAT:  &  (bit işlemi)   ile   && (koşul birleştirme)  FARKLI
            &a (adres)        ile   a & b (bit işlemi)      FARKLI

   x |= y   demek   x = x | y   (&=, ^= de aynı mantık)

 ----- 3) 4 TEMEL HAREKET (EZBERLE!) -----

   SET     (1 yap)      x |=  (1 << n);       LED yak
   CLEAR   (0 yap)      x &= ~(1 << n);       LED söndür
   TOGGLE  (çevir)      x ^=  (1 << n);       LED yanıp söndür
   READ    (oku)        if (x & (1 << n))     buton basılı mı?

   Neden çalışıyor?
   |  -> maskedeki 1 o biti 1 yapar, 0'lar diğerlerine dokunmaz
   &~ -> ters maskede sadece hedef bit 0, o biti 0 yapar, gerisi aynı kalır
   ^  -> maskedeki 1 o biti tersine çevirir
   &  -> sadece hedef bit kalır; 0 değilse if "doğru" sayar

 ----- 4) Bitleri ekrana yazdırma -----

   void bitYazdir(uint8_t x) {
       for (int i = 7; i >= 0; i--)
           printf("%d", (x >> i) & 1);   // i. biti sağa al, sadece onu bırak
       printf("\n");
   }

 ----- STM32 bağlantısı -----

   Donanım REGISTER'larla kontrol edilir (32 bitlik kutular, her bit
   bir görev). Örnek: PA5 pinine bağlı LED

       GPIOA->ODR |=  (1 << 5);    // LED yak
       GPIOA->ODR &= ~(1 << 5);    // LED söndür
       GPIOA->ODR ^=  (1 << 5);    // LED yanıp söndür

   GPIOA = struct adresi (Ders 11), -> = adrese git (Ders 11),
   ODR = register, |= (1<<5) = bit SET (Ders 12)
=====================================================================
*/