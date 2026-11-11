#ifndef SENSOR_H   // "SENSOR_H daha önce tanımlanmadıysa..."
#define SENSOR_H   // "...şimdi tanımla"

typedef struct {
    float sicaklik;
    int   pil;
} Sensor_t;

void raporYazdir(const Sensor_t* s);
void pilDoldur(Sensor_t* s);

#endif // "...if bloğunun sonu"