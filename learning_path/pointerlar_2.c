#include <stdio.h>

// bu kisimda goruldugu uzere pil 100 olmuyor gene 80 yaziyor.struct’ı fonksiyona gönderince kopyası gidiyor. 
// Fonksiyonun içinde değiştirsen asıl değişmiyor. Ders 10'da çözümü öğrendik: adresini gönder.
/*
typedef struct
{
    int pil;
    float sicaklik;
}Sensor_t;

void pilDoldur(Sensor_t s){
    s.pil = 100;
};

int main(void){
    Sensor_t odaSensoru = {.pil = 80, .sicaklik = 25.4};
    pilDoldur(odaSensoru);
    printf("%d",odaSensoru.pil);
    return 0;
}

*/


// dogru sekilde degistirebildigin hali

typedef struct 
{
    int pil;
    float sicaklik;
}Sensor_t;

void sensorVerileri(Sensor_t *s){
    (*s).pil = 100; // s->pil=100 ayni seydir.
    // sarj oldu.
}

void raporYazdir(const Sensor_t *s){
    printf("pil: %.2f \n",s->sicaklik);
    printf("sicaklik: %d \n",s->pil);
    // const = “salt okunur”. Adres gidiyor (hızlı, kopya yok), ama fonksiyon yanlışlıkla bir şey değiştiremiyor (güvenli).
    // sadece okursun, yazma yapamazsin.
}


void hespiniSifirla(int*notlar, int boyut)
{

    for (int i = 0; i < boyut ; i++)
    {
        notlar[i] = 0;
    }
};

int main (void){
    Sensor_t odaSensoru = {.pil = 58, .sicaklik = 77.2};
    
    sensorVerileri(&odaSensoru);

    printf("%d \n",odaSensoru.pil);
    
    raporYazdir(&odaSensoru);

    int dizi[3] = {10,20,30};
    int *p = dizi;

    printf("%d",p[0]);
    printf("%d",p[1]);
    printf("%d",p[2]);

    // dizinin adi da ayni zamanda adrestir.


    int notlar[3] = {80,90,100};
    hespiniSifirla(notlar,3); // dizinin adi zaten bir adres & isareti koymana gerek yok.
    printf("%d,%d,%d,",notlar[0],notlar[1],notlar[2]);

    return 0;
}

// 1. Fonksiyon asıl şeyi değiştirecekse → adresini gönder
//void pilDoldur(Sensor_t* s)   // tanımda *
//pilDoldur(&oda);              // çağırırken &


// 2. Struct’ın adresi elindeyse → -> kullan
// oda.pil    // kendisi elimde → nokta
// s->pil     // adresi elimde  → ok

// 3. Sadece okuyacaksan → const ekle
// const cok hızlı okur gelır yanlıslıkla degıstırmez.

// Dizinin adı zaten bir adres → & koyma


/*
=====================================================================
 DERS 11 NOTLARI: Pointer'lar (Bölüm 2) - struct ve dizi ile
=====================================================================

 ----- 1) Struct'ın adresini göndermek -----

   void pilDoldur(Sensor_t* s) {
       (*s).pil = 100;     // uzun yol: adrese git, içindeki pil
       s->pil   = 100;     // kısa yol: AYNI ŞEY
   }
   pilDoldur(&oda);        // asıl struct değişir

   (*s).pil -> parantez ŞART, çünkü . işareti * işaretinden önce çalışır

 ----- 2) . mı -> mi? -----

   Struct'ın KENDİSİ elimdeyse   ->  .     oda.pil
   Struct'ın ADRESİ elimdeyse    ->  ->    s->pil

 ----- 3) const : salt okunur -----

   void raporYazdir(const Sensor_t* s)

   - Adres gider -> kopya yok, hızlı, bellek harcamaz
   - const       -> fonksiyon içeride değiştiremez (derleyici engeller)

   Değiştirecek fonksiyon   ->  Sensor_t* s
   Sadece okuyacak fonksiyon ->  const Sensor_t* s

 ----- 4) Dizinin adı = ilk kutunun adresi -----

   int dizi[3] = {10, 20, 30};
   dizi  ile  &dizi[0]  aynı adres
   int* p = dizi;      // & gerekmez, dizi zaten adres
   p[1]  -> 20         // pointer da [ ] ile kullanılabilir

 ----- 5) Fonksiyona dizi göndermek -----

   int f(int dizi[], int boyut)   ile   int f(int* dizi, int boyut)  AYNI

   - Kopya gitmez, sadece BAŞLANGIÇ ADRESİ gider.
   - Boyut gitmez -> boyutu ayrıca göndermek ZORUNLU.
   - Fonksiyon asıl diziyi DEĞİŞTİREBİLİR.
   - Çağırırken & yazılmaz:  f(notlar, 3);

 ----- Two Sum tekrar -----

   int* twoSum(int* nums, int numsSize, int target, int* returnSize)
     int* nums        -> dizinin başlangıç adresi
     int numsSize     -> dizi boyutunu bilmediği için
     int* returnSize  -> *returnSize = 2  ile Leetcode'un kutusuna yazarım
     baştaki int*     -> cevap dizisinin adresini döndürürüm

 ----- STM32 bağlantısı -----

   HAL_GPIO_Init(GPIOA, &ayar);
     -> ayar struct'ının ADRESİ gidiyor (kopya değil)
     -> fonksiyonun içinde ayar->Pin, ayar->Mode diye okunuyor
   HAL_UART_Transmit(&huart2, veri, uzunluk, 100);
     -> veri bir dizi (adres), uzunluk ayrıca gönderiliyor
     -> Ders 7'deki "dizi + boyut" kuralının aynısı!
=====================================================================
*/