#include <stdio.h>

int main (void){

    int sayi = 1 ;
    
    typedef enum {
        MARKA,
        YIL,
        ULKE,
    }arabalar_t;


    switch (sayi)     
    {
    case 1:
        printf("sayi %d'dir.",sayi);
        break;

    case 2:
        printf("sayi baska bir sey.");
        break;
    
    default:
        printf("sayi hic bir case durumu ile uyusmuyor.");
        break;
    }

    return 0;
}

/*
Kural: Her case’in sonuna break; yaz.
default, if’teki son else gibidir: hiçbir case eşleşmezse çalışır.

*/
