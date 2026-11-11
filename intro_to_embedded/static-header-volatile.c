#include <stdio.h>

// Bolum A: static 2 farkli gorevi var.
//Gorev 1: Normalde bir fonksiyonun içindeki kutular, fonksiyon bitince silinir. Bir sonraki çağırmada sıfırdan açılır:

/*
void say(){
    int sayac = 0;
    sayac = sayac + 1;
    printf("%d",sayac);
}

int main(void){
    say();
    say();
    
    return 0;
}

*/

// Her çağırmada sayac yeniden 0 olarak açılıyor, 1'e çıkıyor, fonksiyon bitince siliniyor.


void say (void){
    static int sayac = 0;      // static kutu fonksiyon bitince silinmez. Değerini hatırlar. = 0 kısmı sadece ilk seferde çalışır, sonraki çağırmalarda atlanır.
    sayac = sayac + 1;    
    printf("%d\n", sayac);
}

int main (void){
    say();
    say();
    say();
    say();
    say();
    return 0;
}


