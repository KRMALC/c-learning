#include <stdio.h>

#define KIRMIZI_SURE  3
#define YESIL_SURE    3
#define SARI_SURE     1

typedef enum
{
    DURUM_KIRMIZI,
    DURUM_YESIL,
    DURUM_SARI
} lambadurumu_t;

int main(void)
{
    lambadurumu_t lambadurumu = DURUM_KIRMIZI;
    int sayac = 0;

    for (int saniye = 0; saniye < 15; saniye++)
    {
        switch (lambadurumu)
        {
            case DURUM_KIRMIZI:
                sayac = sayac + 1;
                printf("%d sn: KIRMIZI\n", saniye);
                if (sayac >= KIRMIZI_SURE)
                {
                    lambadurumu = DURUM_YESIL;
                    sayac = 0;
                }
                break;

            case DURUM_YESIL:
                sayac = sayac + 1;
                printf("%d sn: YESIL\n", saniye);
                if (sayac >= YESIL_SURE)
                {
                    lambadurumu = DURUM_SARI;
                    sayac = 0;
                }
                break;

            case DURUM_SARI:
                sayac = sayac + 1;
                printf("%d sn: SARI\n", saniye);
                if (sayac >= SARI_SURE)
                {
                    lambadurumu = DURUM_KIRMIZI;
                    sayac = 0;
                }
                break;
        }
    }

    return 0;
}