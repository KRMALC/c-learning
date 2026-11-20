#if !defined(sensorler_h)
#define sensorler_h

typedef struct
{
    float sicaklik;
    int pil;
}Sensor_t;

void raporYazdir(const Sensor_t *s);
int tehlikedemi(const Sensor_t *s);

#endif // sensorler_h

//  .h  = İÇİNDEKİLER: struct'lar, fonksiyon isimleri (gövdesiz)
