#include <stdio.h>
#include "sensorler.h"

void raporYazdir(const Sensor_t *s)
{
    printf ("sicaklik: %2.f, pil: %d",s->sicaklik, s->pil);
}

int tehlikedemi(const Sensor_t *s)
{
    return (s ->pil < 20 || s->sicaklik > 50.2);
}

// fonksiyonlarin asil kodu burdadir.