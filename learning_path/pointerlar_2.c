#include <stdio.h>

void sifirla(int* x) {
    *x = 0;
}

int main(void) {
    int a = 42;
    int b = 17;
    sifirla(&b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}

/*

void arttir(int *x) {
    printf("  fonksiyona girdim, x'in gosterdigi deger: %d\n", *x);
    *x = *x + 1;
    printf("  1 ekledim, simdi: %d\n", *x);
}

int main(void) {
    int sayac = 0;

    printf("baslangic: sayac = %d\n", sayac);

    arttir(&sayac);
    printf("1. cagridan sonra: sayac = %d\n", sayac);

    arttir(&sayac);
    printf("2. cagridan sonra: sayac = %d\n", sayac);

    arttir(&sayac);
    printf("3. cagridan sonra: sayac = %d\n", sayac);

    return 0;
}

*/

/*
void arttir(int* x) {
    *x = *x + 1;
}

int main(void) {
    int sayac = 0;

    arttir(&sayac);
    arttir(&sayac);
    arttir(&sayac);

    printf("%d\n", sayac);

*/

    