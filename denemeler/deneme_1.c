#include <stdio.h>
#include <stdint.h>

int main (void){
    uint8_t bayt = 10;
    int8_t sayi = 20;
    uint16_t sayi2 = 30;
    int16_t sayi3 = 40;
    float sayi4 = 50.5;

    printf("bayt=%u sayi=%d sayi2=%u sayi3=%d sayi4=%.1f\n",
           bayt, sayi, sayi2, sayi3, sayi4);


    /// Tasma Deneyi       
    uint8_t x = 255;
    x= x + 1;
    printf("x=%u\n", x);
    return 0;

}