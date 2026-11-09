#include <stdio.h>
#include <stdint.h>

/* ---- 1) Sahte port tipi (gerçeği ST'nin dosyasında, burada taklit ediyoruz) ---- */
typedef struct
{
  char harf;              // portun harfi: 'D', 'E'...
} GPIO_TypeDef;

GPIO_TypeDef GPIOD = { 'D' };   // D portu
GPIO_TypeDef GPIOE = { 'E' };   // E portu

/* ---- 2) Projedeki Radio struct'ının sade hâli ---- */
typedef struct
{
  GPIO_TypeDef *nss_port;
  GPIO_TypeDef *led_port;  
  uint16_t nss_pin;
  uint16_t led_pin;
  uint8_t  dev_id;
  uint8_t  ok;              // 1: hazır
  int16_t  last_rssi;       // son sinyal gücü (dBm)
  uint32_t rx_count;        // gelen paket sayısı
} Radio;

/* ---- 3) Üç modülün kartı ---- */
Radio radios[3] =
{
  { .nss_port = &GPIOD, .nss_pin = 7,  .led_port = &GPIOD, .led_pin = 12, .dev_id = 0x01 },
  { .nss_port = &GPIOE, .nss_pin = 7,  .led_port = &GPIOD, .led_pin = 14, .dev_id = 0x02 },
  { .nss_port = &GPIOE, .nss_pin = 11, .led_port = &GPIOD, .led_pin = 15, .dev_id = 0x03 },
};

/* ---- 4) Tek fonksiyon, her modül için çalışır ---- */
void Radyo_Yazdir(Radio *r)
{
  printf("Modul 0x%02X | NSS: P%c%u | LED: P%c%u | ok=%u | rssi=%d dBm | rx=%u\n",
         r->dev_id,
         r->nss_port->harf, r->nss_pin,
         r->led_port->harf, r->led_pin,
         r->ok, r->last_rssi, (unsigned)r->rx_count);
}

void Paket_Geldi(Radio *r, int16_t rssi)
{
  r->rx_count++;            // sayacı 1 artır
  r->last_rssi = rssi;      // son sinyali kaydet
}

int main(void)
{
  radios[0].ok = 1;         // 1. modül hazır
  radios[2].ok = 1;         // 3. modül hazır (2. modül bozuk diyelim)

  printf("--- Baslangic ---\n");
  for (int i = 0; i < 3; i++) Radyo_Yazdir(&radios[i]);

  Paket_Geldi(&radios[0], -87);
  Paket_Geldi(&radios[0], -91);
  Paket_Geldi(&radios[2], -75);

  printf("\n--- Paketlerden sonra ---\n");
  for (int i = 0; i < 3; i++) Radyo_Yazdir(&radios[i]);

  return 0;
}