#include <stdio.h>
#include "sensor.h"

void raporYazdir(const Sensor_t* s) {
    printf("Sicaklik: %.1f, Pil: %d\n", s->sicaklik, s->pil);
}

void pilDoldur(Sensor_t* s) {
    s->pil = 100;
}