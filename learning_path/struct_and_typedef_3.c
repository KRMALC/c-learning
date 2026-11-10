#include <stdio.h>

typedef enum
{
   PEKIYI,
   IYI,
   ORTA,
   KOTU,
   COKKOTU,
   MAL,
}harfNotu_t;

typedef struct {
    char isim[30];
    char soyIsim[30];
    int numara;
    harfNotu_t karne;
}Student_t;

void ogrenciRaporu (Student_t s){
    printf("Ogrenci ismi:%s \n",s.isim);
    printf("Ogrenci soyismi:%s \n",s.soyIsim);
    printf ("Ogrenci numarasi: %d \n",s.numara);
};

void main (void){
    Student_t ogrenci = {.isim = "Burak", .soyIsim = "ozturk", .numara = 494, .karne=ORTA};
    ogrenciRaporu(ogrenci);
   
// struct dizisi    
    Student_t veli[3] = {
        {.isim = "Ali, . soyIsim = ozturk", .numara =494, .karne=ORTA},
        {.isim = "Veli, . soyIsim = ozturk", .numara =494, .karne=ORTA},
        {.isim = "Deli, . soyIsim = ozturk", .numara =494, .karne=ORTA},
    };
    printf("1.ogrenci notu %d", veli[0].numara);
}
