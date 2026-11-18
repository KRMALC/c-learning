#include <stdio.h>
#include <time.h>

int main (void){
    clock_t baslangic, bitis;

    // 1- Normal dongu

    baslangic = clock();

    for (int i = 0; i < 1000000000; i++){
        // 1.5 saniye surer yaklasik.
    }
    bitis = clock();

    printf("%.2f", (double)(bitis - baslangic)/CLOCKS_PER_SEC);

    // 2- volatile
    baslangic = clock();

    for (volatile int i = 0; i < 1000000000; i++) {
        // bos
    }
    bitis = clock();   // EKLENDİ

    printf("Volatile: %.2f saniye\n", (double)(bitis - baslangic) / CLOCKS_PER_SEC);

    return 0;
}


/*
=====================================================================
 DERS 13 NOTLARI: volatile
=====================================================================

 volatile = "Derleyici, bu değişkene kısaltma yapma.
             Her seferinde gerçekten bellekten oku/yaz."

 Neden lazım?
   Derleyici (-O2 gibi optimizasyonlarla) değişmediğini düşündüğü
   değişkeni tekrar okumaz, işe yaramaz sandığı kodu siler.

 Bilgisayarda deney:
   for (int i = 0; ...)           -> -O2 ile döngü silinir (0 sn)
   for (volatile int i = 0; ...)  -> döngü gerçekten çalışır

 Ne zaman kullanılır? (STM32)
   1) Interrupt'ta değişen değişkenler
        volatile uint8_t butonBasildi = 0;
   2) Donanım register'ları
        volatile uint32_t *reg = (uint32_t *)0x40020014;
        (HAL'deki GPIOA->ODR zaten volatile tanımlı)

 Kural: Değişkeni main'in bilmediği bir şey (interrupt, donanım)
        değiştiriyorsa -> volatile yaz.
=====================================================================
*/