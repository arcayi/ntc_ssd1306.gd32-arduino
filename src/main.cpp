#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
// #include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 32    // OLED display height, in pixels
#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


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
  //default is 10-bit ADC (arduino-compatibility).
  //change to 12-bit ADC
  analogReadResolution(12);

  Serial.println(F("SSD1306 ..."));
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }
  display.setTextSize(1);              // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.clearDisplay();
  display.display();
}

void loop()
{
  display.clearDisplay();

  display.setCursor(0, 0);
  display.setTextSize(1);              // Normal 1:1 pixel scale
  display.println("Temperature(C)");
  display.setTextSize(2);              // Normal 1:1 pixel scale

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

    display.setCursor(i*128/N_THERM, 10);
    display.print(buf1);
  }
  Serial.println("");

  display.display();
  delay(500);
}
