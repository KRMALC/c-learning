#include <stdio.h>

int main (void){

    int sicaklik = 20;

    if (sicaklik < 30){
        printf("hava sicak degil.");
    }
    else{
        printf("hava sicak.");
    }
    

    int pil = 50;

    if (pil > 60)
    {
        printf("pil durumu iyi");
    }
    else if (pil < 20)
    {
        printf("pil azaliyor");
    }
    else
    {
        printf("pilin durumu: %d",pil);
    }

    return 0;
}