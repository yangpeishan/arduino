//include library
#include <Wire.h>
#include <SPI.h>
#include "SSD1306Wire.h" // legacy include: #include "SSD1306.h"
#include "animation.h"
#define Logo_width 64
#define Logo_height 64

const int buttonPin=27;
int walk_i=0;
int idle_i=0;
int buttonState=0;
//設定腳位
SSD1306Wire  display(0x3c, 21, 22);
int w=-30; 

void setup() {
  //設定包率
  pinMode(buttonPin,INPUT);
  digitalWrite(buttonPin,HIGH);
  display.init();//初始化(init)
  display.setContrast(255); //數值介於0~255，調整對比
  display.clear();
}

void loop() { 
  buttonState=digitalRead(buttonPin);
  if(buttonState==HIGH){
     display.clear();
     display.drawXbm(w,0, Logo_width, Logo_height, walk[walk_i]);
     display.display();//顯示畫面(display);
     delay(100);
     w=w+10;
     if(w>=127)w=-30;
     walk_i++;
    if(walk_i==8){walk_i=0;}
  }
  else{
    display.clear();
    display.drawXbm(w,0, Logo_width, Logo_height, idle[idle_i]);
     display.display();//顯示畫面(display);
     delay(200);
     idle_i++;
     if(idle_i==2)idle_i=0;
  }
