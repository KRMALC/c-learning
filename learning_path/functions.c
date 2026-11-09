#include <stdio.h>

void selamVer(void){
    printf("selam \n");
}

/*
selamVer();               // ✅ doğru
selamVer(5);              // ❌ hata: girdi almıyor ki
int x = selamVer();       // ❌ hata: geriye bir şey vermiyor ki
*/

void selamAl(int number){
    printf("%d \n",number);
}

/*
selamAl(4);          // ✅ ekrana 5 yazar
selamAl();           // ❌ hata: sayı vermedin
int x = selamAl(5);  // ❌ hata: geriye bir şey vermiyor
*/

int zarAt(void){
    return 6;
}

/*
int x = zarAt();        // ✅ x'in içine 4 konur
zarAt(3);               // ❌ hata: girdi almıyor
*/

int topla(int a, int b){

    return a + b;

}

/*
int x = topla(2, 3);    // ✅ x = 5
topla(2);               // ❌ hata: iki sayı istiyordu
*/
int main (void){

    selamVer();

    selamAl(5);

    int numara = zarAt();
    printf("%d \n",numara);

    int toplam = topla(5,6);
    printf("%d",toplam);

    return 0;
}