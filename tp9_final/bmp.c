#include "struct.h"
#include "bmp.h"

Adafruit_BMP085 bmp;
uint32_t initialPressure = 0;

void loopBMP(){
 global_data.meteo.pression = bmp.readPressure();
 global_dagta.geography.altitude = bmp.readAltitude 
}


uint8_t setupBMP(){
  if (!bmp.begin()) {
    return -1;
  } else {
    initialPressure = bmp.readPressure();
    return 0;
  }
}
