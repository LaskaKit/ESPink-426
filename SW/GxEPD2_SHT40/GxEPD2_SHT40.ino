/* Display test for LaskaKit ESPink-4.26
 * 
 * Board:   LaskaKit ESPink-4.26   https://www.laskakit.cz/laskakit-espink-esp32-e-paper-pcb-antenna/
 *
 * Libraries:
 * SHT40: https://github.com/Sensirion/arduino-i2c-sht4x
 * EPD library: https://github.com/ZinggJM/GxEPD2_4G
 * 
 * Email:podpora@laskakit.cz
 * Web:laskakit.cz
 */
 
#define ENABLE_GxEPD2_GFX 1

#include <GxEPD2_4G_4G.h>
#include <GxEPD2_4G_BW.h>
#include <SensirionI2cSht4x.h>
#include <Wire.h>

// macro definitions
#ifdef NO_ERROR
#undef NO_ERROR
#endif
#define NO_ERROR 0

// Fonts
#include "OpenSansSB_12px.h"
#include "OpenSansSB_50px.h"
 
//MOSI/SDI    11
//CLK/SCK     12
//SS/CS       10
#define DC    48 
#define RST   45  
#define BUSY  38
#define POWER 47
#define SDA   42
#define SCL   2
#define BAT   9

GxEPD2_4G_4G < GxEPD2_426_GDEQ0426T82, GxEPD2_426_GDEQ0426T82::HEIGHT / 2 > display(GxEPD2_426_GDEQ0426T82(SS, DC, RST, BUSY)); // GDEQ0426T82 480x800, SSD1677 (P426010-MF1-A)

// SHT40
SensirionI2cSht4x sensor;
static char errorMessage[64];
static int16_t error;

uint8_t sht4x_addr_found = 0x00;

// ADC
float vBat = 0.0;

static bool initSHT4xAutoAddr(float& aTemperature, float& aHumidity) {
  const uint8_t addrs[] = { 0x44, 0x45, 0x46 };

  for (uint8_t i = 0; i < sizeof(addrs); i++) {
    uint8_t addr = addrs[i];

    Serial.printf("Trying SHT4x at I2C address 0x%02X ...\n", addr);

    sensor.begin(Wire, addr);

    sensor.softReset();
    delay(10);

    uint32_t serialNumber = 0;
    error = sensor.serialNumber(serialNumber);
    if (error != NO_ERROR) {
      Serial.print("  serialNumber() failed: ");
      errorToString(error, errorMessage, sizeof errorMessage);
      Serial.println(errorMessage);
      continue;
    }

    delay(20);
    error = sensor.measureLowestPrecision(aTemperature, aHumidity);
    if (error != NO_ERROR) {
      Serial.print("  measureLowestPrecision() failed: ");
      errorToString(error, errorMessage, sizeof errorMessage);
      Serial.println(errorMessage);
      continue;
    }

    // success
    sht4x_addr_found = addr;
    Serial.printf("SHT4x found at 0x%02X, serialNumber: %lu\n", addr, (unsigned long)serialNumber);
    Serial.print("aTemperature: "); Serial.print(aTemperature);
    Serial.print("\t aHumidity: ");  Serial.println(aHumidity);
    return true;
  }

  Serial.println("SHT4x not found on 0x44/0x45/0x46.");
  return false;
}

void setup() {
  Serial.begin(115200);

  // turn on power to display
  pinMode(POWER, OUTPUT);
  digitalWrite(POWER, HIGH);   // turn the Display on (HIGH is the voltage level)
  Serial.println("Display power ON");
  delay(500);   

  Wire.begin(SDA, SCL);

  // read the voltage
  vBat = analogReadMilliVolts(BAT) * 1.769 / 1000; // the ratio of divider, R2=1.3M; R1=1M
  Serial.println((String)"VCELL V   : "+ vBat + "V");

  /*----------- SHT40 / SHT4x -----------*/
  float aTemperature = NAN;
  float aHumidity = NAN;

  bool sht_ok = initSHT4xAutoAddr(aTemperature, aHumidity);
  if (!sht_ok) {
    // fallback values to show something on display
    aTemperature = NAN;
    aHumidity = NAN;
  }

  display.init(115200);

  display.setRotation(3);
  display.fillScreen(GxEPD_WHITE);  // white background
  display.setTextColor(GxEPD_BLACK);  // black font

  display.setFullWindow();
  display.firstPage();
  do {
    display.setCursor(5, 50);
    display.setFont(&OpenSansSB_50px);

    if (sht_ok) {
      display.print(String(aTemperature, 1)); 
      display.print("  ");
      display.print(String(aHumidity, 0)); 
    } else {
      display.print("--.-  --");
    }

    display.setFont(&OpenSansSB_12px);
    display.setCursor(30, 70);
    display.println(" degC");
    display.setCursor(150, 70);
    display.println(" % Rh");

    display.setFont(&OpenSansSB_12px);
    display.setCursor(5, 90);
    if (sht_ok) {
      display.print("SHT4x I2C: 0x");
      display.print(String(sht4x_addr_found, HEX));
    } else {
      display.print("SHT4x I2C: not found");
    }

    display.setFont(&OpenSansSB_50px);
    display.setCursor(5, 150);
    display.print(String(vBat, 1)); 

    display.setFont(&OpenSansSB_12px);
    display.setCursor(5, 170);
    display.print("Battery voltage, V");
  }
  while (display.nextPage());

  delay(100);
  digitalWrite(POWER, LOW); // disable power supply for ePaper

  // deep sleep mode
  esp_sleep_enable_timer_wakeup(300 * 1000000);
  delay(200);
  esp_deep_sleep_start();
}

void loop() {
}