#include <stdio.h>
#include "sensorler.h"

int main (void)
{
    Sensor_t sensor47 = {.sicaklik = 25.2f, .pil = 15};
    
    raporYazdir(&sensor47);

    if (tehlikedemi(&sensor47))
    {
        printf("bahce tehlike ! \n");
    }


    return 0;
}