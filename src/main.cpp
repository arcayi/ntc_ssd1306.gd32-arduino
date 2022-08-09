#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

#include <U8g2lib.h>

// U8X8_SSD1306_128X32_UNIVISION_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ SCL, /* data=*/ SDA);

// ntc
// 
#include <SmoothThermistor.h>
#include <AverageThermistor.h>
#include <NTC_Thermistor.h>
#include <Thermistor.h>

#define REFERENCE_RESISTANCE   10000
#define NOMINAL_RESISTANCE     10000
#define NOMINAL_TEMPERATURE    25
#define B_VALUE                3950
// #define B_VALUE                3435
#define ADCRESOLUTION          4096

#define SMOOTHING_FACTOR 3

#define N_THERM 2
const static int sensor_pins[2]={PA0,PA1};
Thermistor* thermistor[N_THERM];

char buf1[16];

void setup()
{
  Serial.begin(115200);
  Serial.println(F("NTC ..."));
  for(int i=0; i<N_THERM; i++) {
    thermistor[i] = new SmoothThermistor(
      new NTC_Thermistor(
        sensor_pins[i],
        REFERENCE_RESISTANCE,
        NOMINAL_RESISTANCE,
        NOMINAL_TEMPERATURE,
        B_VALUE,
        ADCRESOLUTION
      ),
      SMOOTHING_FACTOR
    );
  }
  // pinMode(ANALOG_IN_PIN, INPUT);
  // change to 12-bit ADC. default is 10-bit ADC (arduino-compatibility).
  analogReadResolution(12);

  Serial.println(F("SSD1306 ..."));

  u8g2.begin();
}

void loop()
{
  u8g2.clearBuffer();					// clear the internal memory
  u8g2.setFont(u8g2_font_ncenB08_tr);	// choose a suitable font
  u8g2.drawStr(0,9,"Temperature(C)");	// write something to the internal memory

  // ntc
  // 
  for(int i=0; i<N_THERM; i++) {
    const double celsius = thermistor[i]->readCelsius();
    // Output of information
    Serial.print("Temperature");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(celsius);
    Serial.print(" C, \t");
    sprintf(buf1, "%3d.%01d", int(celsius), abs(int(celsius * 10) %10));
    Serial.print(buf1);
    Serial.println(" C");

    u8g2.setFont(u8g2_font_10x20_tn );	// choose a suitable font
    u8g2.drawStr(i*128/N_THERM,31, buf1);	// write something to the internal memory
  }
  Serial.println("");
  u8g2.sendBuffer();					// transfer internal memory to the display

  delay(500);
}
