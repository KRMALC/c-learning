#include <stdio.h>


int main (void){

    int a = 10;
    int *p = &a;

    printf("a   = %d\n", a);
    printf("&a  = %p\n", (void *)&a);
    printf("p   = %p\n", (void *)p);
    printf("*p  = %d\n", *p);
    printf("&p  = %p\n", (void *)&p);

    *p = 20;
    printf("a artik = %d \n", a);

    printf("==========Alistirmalar=========== \n");

    // ornek_1 --> adrese gidip oku

    int k = 7;
    int* m = &k;        // k 

    printf("%d \n",a); // anin icindeki deger.
    printf("%d \n",m); // m nin icindeki deger.
    printf("%d \n",*m); // m nin gosterdigi adres.

  // & → “bu değişken nerede?” sorusunun cevabıdır, değişkenden adrese gider.
  // * → “bu adreste ne var?” sorusunun cevabıdır, adresten değere gider.

    // ornek_2 --> adrese gidip yazmak

    *m = 50;
    printf("%d \n",k);

    printf("ornek_3 --> adrese gidip hesap yapmak. \n");
    // ornek_3 --> adrese gidip hesap yapmak.

    *m = *m + 5 ;
    printf ("%d \n",m);
    printf ("%d",k);

    /*
    
    Örnek 5: Pointer’ın gösterdiği yeri değiştirmek
c
int a = 1;
int b = 2;
int* p = &a;

*p = 10;
p = &b;
*p = 20;

printf("a = %d, b = %d\n", a, b);

Çıktı:

a = 10, b = 20

Adım adım:

Satır	Ne oldu?	a	b	p kimi gösteriyor?
başlangıç		1	2	a
*p = 10;	a’nın adresine git, 10 yaz	10	2	a
p = &b;	kağıttaki adresi sil, b’nin adresini yaz	10	2	b
*p = 20;	b’nin adresine git, 20 yaz	10	20	b

    
    
    */


    return 0;
}

// İfade	Anlamı	Sonuç

// a	a’nın içindeki değer	10
// &a	a’nın adresi	1000
// p	p’nin içindeki değer, yani a’nın adresi	1000
// *p	p’nin gösterdiği adrese git, içindekini al	10
// &p	p’nin kendi adresi	2000

/*
=====================================================================
 DERS 10 NOTLARI: Pointer'lar (Bölüm 1)
 Amaç: Kutunun ADRESİ ile çalışmak
=====================================================================

 ----- Neden gerekli? -----

   Fonksiyona bir değişken gönderince KOPYASI gider.
   Fonksiyon kopyayı değiştirir, asıl kutu DEĞİŞMEZ.
   Asıl kutuyu değiştirmek için fonksiyona ADRESİNİ göndermeliyim.

 ----- İki işaret -----

   &  -> "adresini ver"       &a   = a'nın adresi
   *  -> "adrese git"         *p   = p'nin gösterdiği yerdeki değer

 ----- Pointer = adres tutan kutu -----

   int  a = 5;       // sayı tutar
   int* p = &a;      // a'nın adresini tutar  ->  "p, a'yı gösteriyor"

       p                    a
   [0x7ffc...] ───────►  [ 5 ]

   p    -> adres        (0x7ffc...)
   *p   -> o adresteki değer (5)

   *p = 20;          // p'nin gösterdiği yere git, 20 yaz -> a artık 20

 ----- * işaretinin iki görevi -----

   int* p     -> TANIM:   "p bir adres tutar"     (başında tür var)
   *p = 20    -> KULLANIM: "p'nin gösterdiği yere git"

 ----- Fonksiyona adres göndermek -----

   void pilDoldur(int* pil) {   // adres alır
       *pil = 100;              // o adrese gidip yazar
   }

   int pil = 15;
   pilDoldur(&pil);             // adresini gönder -> pil artık 100

   Değer gönder:  f(x)   / void f(int x)   -> asıl DEĞİŞMEZ
   Adres gönder:  f(&x)  / void f(int* x)  -> asıl DEĞİŞİR

   Benzetme: Evin FOTOĞRAFINI vermek vs. evin ADRESİNİ vermek.

 ----- Ekrana adres yazdırmak -----

   printf("%p\n", (void*)&a);
   (void* = türü belirtilmemiş adres; printf'in %p kuralı böyle ister)

 ----- STM32 bağlantısı -----

   HAL kütüphanesindeki çoğu fonksiyon adres alır:
       HAL_GPIO_Init(GPIOA, &ayar);    // ayar struct'ının ADRESİ
   Fonksiyon ayarı kopyalamak yerine doğrudan asılından okur.
   Ayrıca STM32'deki donanım register'ları da birer ADRESTİR.
   LED yakmak = belirli bir adrese gidip bir değer yazmak.
=====================================================================
*/