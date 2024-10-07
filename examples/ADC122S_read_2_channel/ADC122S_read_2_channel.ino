//
//    FILE: ADC122S_read_2_channel.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo triple read
//     URL: https://github.com/RobTillaart/ADC08XS


#include "ADC08XS.h"

ADC122S adc;  //  use HWSPI

uint16_t val;


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);

  SPI.begin();

  adc.begin(4);  //  select pin
}


void loop()
{
  val = adc.read(0);
  Serial.print("0\t");
  Serial.print(val);
  val = adc.read(0);
  Serial.print("\t");
  Serial.print(val);
  val = adc.read(0);
  Serial.print("\t");
  Serial.println(val);

  
  val = adc.read(1);
  Serial.print("1\t");
  Serial.print(val);
  val = adc.read(1);
  Serial.print("\t");
  Serial.print(val);
  val = adc.read(1);
  Serial.print("\t");
  Serial.println(val);
  
  delay(5000);
}
