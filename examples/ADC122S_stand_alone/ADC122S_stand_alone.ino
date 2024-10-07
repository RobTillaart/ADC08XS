//    FILE: ADC122S_stand_alone.ino
//  AUTHOR: Rob Tillaart
//    DATE: 2024-09-25
// PURPOSE: test
//     URL: https://github.com/RobTillaart/ADC08XS

#include "Arduino.h"
#include "SPI.h"


uint16_t val;

uint8_t  select = 10;


int readADC(uint8_t channel)
{
  uint8_t chan = 0x08;
  if (channel != 0) chan = 0x00;

  SPI.beginTransaction(SPISettings(100000, MSBFIRST, SPI_MODE3));
  digitalWrite(select, LOW);
  uint16_t data = SPI.transfer(chan) << 8;
  data += SPI.transfer(0);
  digitalWrite(select, HIGH);
  SPI.endTransaction();

  return data;
}


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);

  SPI.begin();

  pinMode(select, OUTPUT);
  digitalWrite(select, HIGH);
}


void loop()
{
  val = readADC(0);
  Serial.print("0\t");
  Serial.print(val);
  delay(1000);

  val = readADC(0);
  Serial.print("\t");
  Serial.print(val);
  delay(1000);

  val = readADC(0);
  Serial.print("\t");
  Serial.println(val);
  delay(1000);

  val = readADC(1);
  Serial.print("1\t");
  Serial.print(val);
  delay(1000);

  val = readADC(1);
  Serial.print("\t");
  Serial.print(val);
  delay(1000);

  val = readADC(1);
  Serial.print("\t");
  Serial.println(val);
  delay(1000);

  delay(2000);
}


//  -- END OF FILE --
