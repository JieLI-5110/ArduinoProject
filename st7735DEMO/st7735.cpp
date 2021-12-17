#include "st7735.h"
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
void showTime(char*);
void initFrame();
void showAltitude(char* );
void showPressure (char *);
void showMessage (char* msg, int x, int y, int length, int height, int backCorlor, int color); 

void initST() {
  tft.initR(INITR_BLACKTAB);      // Init ST7735S chip, black tab
  tft.fillScreen(ST77XX_BLACK);
  initFrame();
}

void loopST(S_Datas datas) {
  char buff[15]="";
  int i;
  sprintf(buff,"%02d:%02d",datas.tm.Hour,datas.tm.Minute);
  showTime(buff);
  sprintf(buff,"%d",datas.geo.alt);
  showAltitude(buff);
  
  for (i=0; i<sizeof(buff); i++)
  {
    buff[i] = '\0';
  }
  sprintf(buff,"%d",datas.meteo.pressure);
  showPressure(buff);
}
void initFrame(){

}
void showTime(char* str)
{
  showMessage(str,POS_TIME_X,POS_TIME_Y,44,12, ST77XX_BLUE, ST77XX_WHITE);
}

void showAltitude(char* str)
{
  showMessage(str,POS_ALT_X,POS_ALT_Y,44,12, ST77XX_YELLOW, ST77XX_BLACK);
}

void showPressure (char* str){
  showMessage(str,POS_PRESS_X,POS_PRESS_Y,100,12, ST77XX_GREEN, ST77XX_BLACK);
  tft.print(101000);
}


void showMessage (char* msg, int x, int y, int length, int height, int backCorlor, int color)
{
  tft.fillRect(x-2,y-2,length,height, backCorlor);
  tft.setCursor(x,y);
  tft.setTextColor(color);
  tft.print(msg);

}
