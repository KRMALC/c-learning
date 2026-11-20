#include <stdio.h>

#define MENU_SAYISI 3

typedef struct
{
    char isim[20];
    int fiyat;
}Kahveler_t;

int main (void)
{
    Kahveler_t menu[MENU_SAYISI]={
        {"Latte",20},
        {"Turk Kahvesi", 35},
        {"espresso",50}
    };

    int secim;

    while (1)
    {
        printf(" ========MENU=========");

        for (int i = 0; i < MENU_SAYISI ; i++)
        {
            printf("%d),%s,%d",i+1,menu[i].isim,menu[i].fiyat);
        }
        printf("0) cikis");
        printf("Lutfen secım yap:");
        
        scanf("%d",&secim);

        if ( 0 < secim < 4)
        {
            printf("Seciminiz: %s",menu[secim - 1].isim);
            printf("fiyati: %d",menu[secim-1].fiyat);
        }
        elif (secim = 0)
        {
            printf("gule gule");
        }
        
        else(secim<1 || secim > 3)
        {
            printf("hatali secim yaptiniz.");
            continue;
        }
        
        break;
    }
    
    return 0;
}

// basta bir daha yap.