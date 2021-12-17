#include <stdio.h>
#include <stdlib.h>


typedef struct S_meteo{
    float temp;
    unsigned long  pression;
    float humidity;
}Meteo;

typedef struct S_gyro{
    float g_x;
    float g_y;
    float g_z;
    float i_x,i_y,i_z;
} Gyro;

typedef struct S_Data{
    Meteo meteo;
    Gyro gyro;
} Data;

typedef union U_S_Data{
    Data data;
    uint8_t au8Buffer[sizeof(Data)];
} UData;

void showStruct ( Meteo* meteo);
void setGyro (Data* localData);
void viewUnionOfUData (Data localData);

int main () {

    Data data;
    
    data.gyro.g_x=1;
    data.gyro.g_y=2;
    data.gyro.g_z=3;
    data.gyro.i_x=4;
    data.gyro.i_y=5;
    data.gyro.i_z=6;
    
    data.meteo.temp = 23.4F;
    data.meteo.pression = 102000ul;
    data.meteo.humidity = 43.0F;
    
    showStruct (&(data.meteo));
    setGyro (&data);
    
    printf ("temperature: %f\n", data.meteo.temp);
    printf ("pression: %lu\n", data.meteo.pression);
    printf ("humidity: %f\n", data.meteo.humidity);
    printf ("gyro_x: %f\n", data.gyro.g_x);
    
    viewUnionOfUData (data);
    data.meteo.temp = 0;
    viewUnionOfUData (data);
}

void showStruct (Meteo* meteo){
    meteo->temp = 15;
    printf ("func temperature: %f\n", meteo->temp);
    printf ("func pression: %lu\n", meteo->pression);
    printf ("func humidity: %f\n", meteo->humidity);
    
}

void setGyro (Data* localData){
    localData->gyro.g_x = 100;
}


void viewUnionOfUData (Data localData){
    UData ulocalData;
    int i;
    ulocalData.data = localData;
    
    printf ("The union data buffer:\n");
    for (i=0; i< sizeof(Data); i++)
    {
        printf ("%d; ", ulocalData.au8Buffer[i]);
    }
    printf("\n");
}
