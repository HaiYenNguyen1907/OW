#include "mylib.h"
#include <Arduino.h>

#define DS18B20_PIN 2
mylib::mylib(){
	pinMode(DS18B20_PIN, INPUT);
}
void mylib::OW_Set(unsigned char mode){
  if (mode){
    pinMode(DS18B20_PIN, OUTPUT);
    digitalWrite(DS18B20_PIN, LOW);
    }
  else
    pinMode(DS18B20_PIN, INPUT);
}

unsigned char mylib::DIRECT_MODE(void){  
  return digitalRead(DS18B20_PIN);
}

unsigned char mylib::OW_Reset(void){
  OW_Set(1);
  delayMicroseconds(480);
  OW_Set(0);
  delayMicroseconds(70);
  unsigned char result = DIRECT_MODE();
  delayMicroseconds(410);
 return result;
 
}

void mylib::OW_WriteBit(unsigned char bit){
  OW_Set(1);    
  delayMicroseconds(1); 
  if(bit){
   OW_Set(0);
  }
  delayMicroseconds(60);
  OW_Set(0);
}

void mylib::OW_WriteByte(unsigned char byte){
  for (unsigned char i=0; i<8; i++){ 
    OW_WriteBit(bitRead(byte, i));
  }
}

unsigned char mylib::OW_ReadBit(void){
  unsigned char bit=0;
  OW_Set(1);
  delayMicroseconds(1);
  OW_Set(0);
  delayMicroseconds(14);
  if(DIRECT_MODE()){
    bit=1;
  }
  delayMicroseconds(45);
  return bit;
}

unsigned char mylib::OW_ReadByte(void){
  unsigned char n=0;
  for (unsigned char i=0; i<8; i++) 
    if (OW_ReadBit()) bitSet(n, i);
  return n;
}

