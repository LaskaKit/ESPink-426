/* Display test for LaskaKit ESPink-4.26
 * 
 * Board:   LaskaKit ESPink-4.26   https://www.laskakit.cz/laskakit-espink-esp32-e-paper-pcb-antenna/
 *
 * Libraries:
 * MAX17048:  https://github.com/hideakitai/MAX17048
 * SHT40: https://github.com/adafruit/Adafruit_SHT4X
 * EPD library: https://github.com/ZinggJM/GxEPD2
 * 
 * Email:podpora@laskakit.cz
 * Web:laskakit.cz
 */
 
#include <WiFi.h>
#include <GxEPD2_BW.h>
#include "SPI.h"

#include "Adafruit_SHT4x.h"
#include "MAX17048.h"

// Fonts
#include "OpenSansSB_12px.h"
#include "OpenSansSB_50px.h"
 
//MOSI/SDI    11
//CLK/SCK     12
//SS/CS       10
#define DC    48 
#define RST   45  
#define BUSY  36 
#define POWER 47
#define SDA   42
#define SCL   2

GxEPD2_BW<GxEPD2_426_GDEQ0426T82, GxEPD2_426_GDEQ0426T82::HEIGHT> display(GxEPD2_426_GDEQ0426T82(SS, DC, RST, BUSY)); // GDEQ0426T82 480x800, SSD1677 (P426010-MF1-A)


// SHT40
Adafruit_SHT4x sht4 = Adafruit_SHT4x();

// ADC
MAX17048 pwr_mgmt;
float vBat = 0.0;
int pBat = 0;
float ppBat = 0.0;

void setup() {
  Serial.begin(115200);
  // turn on power to display
  pinMode(POWER, OUTPUT);
  digitalWrite(POWER, HIGH);   // turn the Display on (HIGH is the voltage level)
  Serial.println("Display power ON");
  delay(500);   

  Wire.begin (SDA, SCL);
  pwr_mgmt.attatch(Wire); //připojí čip MAX17048 k desce

  // read the voltage
  vBat = pwr_mgmt.voltage();
  pBat = pwr_mgmt.percent();
  ppBat = pwr_mgmt.accuratePercent();
  Serial.println((String)"VCELL V   : "+vBat+"V"); //Vypíše napětí na baterii
  Serial.println((String)"VCELL SOC : "+pBat+" \%"); //Vypíše přibližné nabití baterie
  Serial.println((String)"VCELL SOC : "+ppBat+" \%"); //Vypíše přesné nabití baterie 


  /*----------- SHT40 -----------*/
  if (! sht4.begin()) 
  {
    Serial.println("SHT4x not found");
    Serial.println("Check connection");
    while (1) delay(1);
  }

  sht4.setPrecision(SHT4X_HIGH_PRECISION); // the higest resolution
  sht4.setHeater(SHT4X_NO_HEATER); // no heater

  sensors_event_t humidity, temperature; // variable for humidity and temperature
  sht4.getEvent(&humidity, &temperature); // read value

  Serial.print("Temperature: "); Serial.print(temperature.temperature); Serial.println(" degrees C");
  Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");

  display.init();

  display.setRotation(3);
  display.fillScreen(GxEPD_WHITE);  // white background
  display.setTextColor(GxEPD_BLACK);  // black font

  display.setCursor(/*x*/5, /*y*/50); // set cursor
  display.setFont(&OpenSansSB_50px); // font
  display.print(String(temperature.temperature, 1)); 
  display.print("  ");
  display.print(String(humidity.relative_humidity, 0)); 

  display.setFont(&OpenSansSB_12px); // font
  display.setCursor(/*x*/30, /*y*/70); // set cursor
  display.println(" degC");
  display.setCursor(/*x*/150, /*y*/70); // set cursor
  display.println(" % Rh");

  display.setFont(&OpenSansSB_50px); // font
  display.setCursor(/*x*/5, /*y*/150); // set cursor
  display.print(String(vBat, 1) + "V"); 
  display.setCursor(/*x*/5, /*y*/250); // set cursor
  display.print(String(pBat) + "%"); 
  display.setCursor(/*x*/5, /*y*/350); // set cursor
  display.print(String(ppBat, 1) + "%"); 

  display.setFont(&OpenSansSB_12px); // font
  display.setCursor(/*x*/5, /*y*/170); // set cursor
  display.print("Battery voltage, V");
  display.setCursor(/*x*/5, /*y*/270); // set cursor
  display.print("Battery percentage, %");
  display.setCursor(/*x*/5, /*y*/370); // set cursor
  display.print("precise Battery percentage, %");

  display.display(false); // update 
  delay(100);
  digitalWrite(POWER, LOW); // disable power supply for ePaper

  // deep sleep mode
  esp_sleep_enable_timer_wakeup(300 * 1000000);
  delay(200);
  esp_deep_sleep_start();
}

void loop() {

}
