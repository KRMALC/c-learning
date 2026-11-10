#include <stdio.h>

struct Sensor
{
    float sicaklik;
    int pil;
};

typedef struct 
{
    float temparature;
    int battery;
}Sensor_t;

typedef enum {
    BEKLEME,
    CALISIYOR,
    UYARI
} Cihaz_Durumu_t; 



int main (void){
    struct Sensor oda;   // kaliptan oda adinda bir Sensor urettim.
    struct Sensor bahce; // kaliptan bahce adinda bir Sensor urettim.

    oda.sicaklik = 24.6;
    oda.pil = 85;

    bahce.sicaklik = 25;
    bahce.pil =90;

    printf("Oda sicakligi ve pili : %.2f %d ",oda.sicaklik,oda.pil);
    printf("Oda sicakligi ve pili : %.2f %d",bahce.sicaklik,bahce.pil);

    Sensor_t oda_t;   // kaliptan oda_t adinda bir Sensor urettim. artik struct Sensor yazmama gerek kalmadi.
    Cihaz_Durumu_t d = UYARI;  // "enum CihazDurumu d" yerine
    
    return 0;
}

