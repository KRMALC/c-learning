/*
=====================================================================
 DERS 15: Yazilar (string / char dizileri)
 Derle:      gcc strings_charDizileri.c -o strings_charDizileri
 Calistir:   .\strings_charDizileri
=====================================================================
*/

#include <stdio.h>
#include <string.h>     // strlen, strcpy, strcmp icin

// Ciktida bolumleri ayirmak icin kucuk bir yardimci fonksiyon
void bolum(const char* baslik) {
    printf("\n===== %s =====\n", baslik);
}

int main(void) {

    // -----------------------------------------------------------------
    // ADIM 1: char = tek karakter (arka planda bir sayi)
    // -----------------------------------------------------------------
    bolum("1) char");

    char harf = 'A';                                  // tek tirnak
    printf("Karakter olarak: %c\n", harf);            // A
    printf("Sayi olarak (ASCII): %d\n", harf);        // 65


    // -----------------------------------------------------------------
    // ADIM 2: Yazi = char dizisi + sonunda '\0'
    // -----------------------------------------------------------------
    bolum("2) Yazi = char dizisi");

    char isim[] = "Kerim";          // ['K']['e']['r']['i']['m']['\0']

    printf("isim dizisi %zu kutu (5 harf + 1 bitis isareti)\n", sizeof(isim));
    printf("Son kutu bitis isareti mi? %s\n", (isim[5] == '\0') ? "evet" : "hayir");


    // -----------------------------------------------------------------
    // ADIM 3: Yazdirmak (%s) ve tek harfe ulasmak
    // -----------------------------------------------------------------
    bolum("3) Yazdirmak");

    printf("Merhaba %s!\n", isim);          // %s = string
    printf("Ilk harf: %c\n", isim[0]);      // K

    isim[0] = 'B';                          // dizi oldugu icin harf degistirilebilir
    printf("Ilk harf degisti: %s\n", isim); // Berim

    isim[0] = 'K';                          // geri alalim


    // -----------------------------------------------------------------
    // ADIM 4: '\0' gorene kadar harf harf dolasmak
    // -----------------------------------------------------------------
    bolum("4) Harf harf dolasmak");

    int i = 0;
    while (isim[i] != '\0') {
        printf("%d. harf: %c\n", i, isim[i]);
        i++;
    }
    printf("Toplam %d harf\n", i);


    // -----------------------------------------------------------------
    // ADIM 5: <string.h> fonksiyonlari
    // -----------------------------------------------------------------
    bolum("5) strlen, strcpy, strcmp");

    // Uzunluk
    printf("strlen(isim) = %zu\n", strlen(isim));   // 5 ('\0' sayilmaz)

    // Kopyalama: isim2 = "Ahmet"; YAZILAMAZ, strcpy kullanilir
    char isim2[10];
    strcpy(isim2, "Ahmet");
    printf("strcpy sonrasi isim2: %s\n", isim2);

    // Karsilastirma: == ile DEGIL, strcmp ile
    char a[] = "evet";
    char b[] = "evet";

    // (a == b) yazsaydik adresleri karsilastirirdi ve hep "farkli" derdi.
    // gcc bu yuzden == ile dizi karsilastirmaya uyari bile verir.

    if (strcmp(a, b) == 0) {                 // 0 donerse AYNI
        printf("strcmp: \"%s\" ile \"%s\" ayni\n", a, b);
    } else {
        printf("strcmp: farkli\n");
    }

    char c[] = "hayir";
    if (strcmp(a, c) == 0) {
        printf("strcmp: \"%s\" ile \"%s\" ayni\n", a, c);
    } else {
        printf("strcmp: \"%s\" ile \"%s\" farkli\n", a, c);
    }


    // -----------------------------------------------------------------
    // ADIM 6: snprintf -> yaziyi ekrana degil DIZIYE hazirlamak
    // -----------------------------------------------------------------
    bolum("6) snprintf");

    char mesaj[50];
    float sicaklik = 23.5f;
    int pil = 85;

    snprintf(mesaj, sizeof(mesaj), "Sicaklik: %.1f, Pil: %d", sicaklik, pil);

    printf("Hazirlanan mesaj: %s\n", mesaj);
    printf("Mesajin uzunlugu: %zu\n", strlen(mesaj));

    // STM32'de bu mesaj ekrana degil UART'a gonderilir:
    // HAL_UART_Transmit(&huart2, (uint8_t*)mesaj, strlen(mesaj), 100);


    // -----------------------------------------------------------------
    // ADIM 7: Tasma (buffer overflow) ve snprintf'in korumasi
    // -----------------------------------------------------------------
    bolum("7) Tasma");

    char kucuk[8];      // 7 harf + 1 bitis isaretine yer var

    // TEHLIKELI: strcpy boyutu kontrol etmez, dizinin disina yazar.
    // Denemek istersen asagidaki satirin basindaki // isaretini kaldir:
    // strcpy(kucuk, "Kerim Alici");

    // GUVENLI: snprintf sigmayan kismi keser, disari tasmaz
    snprintf(kucuk, sizeof(kucuk), "Kerim Alici");
    printf("8 kutuya sigan kismi: %s\n", kucuk);    // Kerim A

    return 0;
}


/*
=====================================================================
 DERS 15 NOTLARI: Yazilar (string)
=====================================================================

 ----- 1) Yazi = char dizisi + '\0' -----

   char isim[] = "Kerim";
       ['K']['e']['r']['i']['m']['\0']
   - C'de ayri bir "yazi" turu YOK, yazi bir char dizisidir.
   - Sonuna otomatik '\0' eklenir = "yazi burada bitti" isareti.
   - Gereken kutu sayisi = harf sayisi + 1
   - 'K' (tek tirnak) = 1 karakter
     "K" (cift tirnak) = yazi = 'K' + '\0' = 2 kutu

 ----- 2) Yazdirmak -----

   printf("%s\n", isim);      // %s = string
   isim[0]                    // tek harfe ulasmak (dizi gibi)

   Harf harf dolasmak:
   while (isim[i] != '\0') { ... i++; }

 ----- 3) <string.h> fonksiyonlari -----

   strlen(a)              -> uzunluk ('\0' sayilmaz)
   strcpy(hedef, kaynak)  -> kopyala        (a = "..." CALISMAZ!)
   strcmp(a, b) == 0      -> ayni mi?       (a == b CALISMAZ!)
                             0 donerse AYNI

   Neden = ve == calismaz? Dizinin adi ADRES. Adresler karsilastirilir,
   icerik degil.

 ----- 4) snprintf : yaziyi diziye hazirlamak -----

   char mesaj[50];
   snprintf(mesaj, sizeof(mesaj), "Sicaklik: %.1f", sicaklik);
   - printf gibi, ama ekrana degil DIZIYE yazar.
   - sizeof(mesaj) -> en fazla bu kadar yaz, TASMA.

 ----- 5) TEHLIKE: Tasma (buffer overflow) -----

   char a[5];
   strcpy(a, "Kerim Alici");  // dizinin disina yazar!
   -> Diziyi yeterince buyuk tanimla, mumkunse snprintf kullan.

 ----- STM32 baglantisi -----

   STM32'de printf yok (ekran yok). Mesaj UART ile gonderilir:
   snprintf(mesaj, sizeof(mesaj), "Sicaklik: %.1f\r\n", sicaklik);
   HAL_UART_Transmit(&huart2, (uint8_t*)mesaj, strlen(mesaj), 100);
=====================================================================
*/