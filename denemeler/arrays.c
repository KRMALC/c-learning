#include <stdio.h>

int not1 = 70;
int not2 = 85;
int not3 = 60;
int not4 = 90;
int not5 = 45;

int notlar[5] = {70, 85, 60, 90, 45};

/* arrays and functions*/

int notToplam (int dizi[], int boyut){
    int toplam=0;
    for (int eleman = 0; eleman<boyut; eleman++){
        toplam = toplam + dizi[eleman];
    }
    return toplam;      
}

int main (void){
    printf("%d\n",notlar[0]);
    printf("%d\n",notlar[2]);

    for (int indexNumber = 0; indexNumber < 5; indexNumber++)
    {
        printf("%d. %d\n ",indexNumber, notlar[indexNumber]);
    }
    
    /*avarage*/

    int toplam=0;

    for (int i =0; i<5; i++){
        toplam = toplam + notlar[i];
    }

    printf("ortalama deger: %d \n",toplam / 5);
    printf("toplam: %d",toplam);

    /*fonksiyon*/
    int notlar[5]={10,20,30,40,50};
    int sonuc = notToplam (notlar,5);
    printf("sonuc:%d",sonuc);
    return 0;
}

