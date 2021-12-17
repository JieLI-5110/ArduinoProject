
#ifndef _STRUCT_H
#define _STRUCT_H


#include <TimeLib.h>

typedef struct S_meteo{
    float temp;
    uint32_t pression;
    uint8_t humidity;
}Meteo;

typedef struct S_Geography{
  uint16_t altitude;
} Geography

typedef struct S_Data{
    Meteo meteo;
    Geography geography;
    tmElements_t time;
} Data;

typedef union U_S_Data{
    Data data;
    uint8_t au8Buffer[sizeof(Data)];
} UData;


Data global_data;

#endif //_STRUCT_H
