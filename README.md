![ESPink-4.26 TOP](https://github.com/LaskaKit/ESPink-426/blob/main/img/ESPink-4-26_top.JPG)
</br>
# ESPink 4.26" - versatile and low power board with ESP32-S3 for big 4.26" 800x480 ePaper/eInk
Our completely finished and equipped development boards with ESP32 and glued ePaper display became popular not only among DIY makers. We are now expanding our product range with another finished Laskakit ESPink development kit with a 4.26" variant. </br>
It complements the existing family of ready to use ePaper kits such as Laskakit [ESPink-Shelf-2.9 ESP32 e-Paper](https://www.laskakit.cz/laskakit-espink-shelf-2-9-esp32-e-paper/?variantId=14193), [LaskaKit ESPink-4.2 ESP32 e-Paper](https://www.laskakit.cz/laskakit-espink-42-esp32-e-paper-pcb-antenna/?variantId=13538) and LaskaKit [ESPink-Shelf-2.13 ESP32 e-Paper](https://www.laskakit.cz/laskakit-espink-shelf-213-esp32-e-paper/).
If you prefer a standalone board, then we offer the [very low power and versatile ESPink](https://www.laskakit.cz/laskakit-espink-esp32-e-paper-pcb-antenna/?variantId=12419). The board is smaller and more versatile for connecting other ePaper displays.</br>
</br>
![ESPink-4.26 TOP](https://github.com/LaskaKit/ESPink-426/blob/main/img/ESPink-4-26_bottom.JPG)</br>
ESPink-4.26 with ESP32-S3 offers very low power consumption, reasonably sized ePaper with large 800x480px resolution, easy programming thanks to built-in programmer connected to USB-C from which the battery is also charged, connector with unused pins from ESP32-S3 thanks to which additional signals can be brought to the board and last but not least a microSD slot for memory card. </br>
ESPink-4.26 is equipped with two of our universal I2C uŠup connectors to which you can connect various sensors - [SHT40 (temperature, humidity)](https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/), [BME280 (tlak, teplota, vlhkost)](https://www.laskakit.cz/arduino-senzor-tlaku--teploty-a-vlhkosti-bme280/), [SCD41 (CO2, temperature, humidity)](https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/), [BH1750 (light sensor)](https://www.laskakit.cz/laskakit-bh1750-snimac-intenzity-osvetleni/), [APDS-9960 (gesture sensor)](https://www.laskakit.cz/laskakit-apds-9960-senzor-priblizeni-a-gest/) and lot of other sensors.</br>
Our I2C uŠup connector is compatible with Adafruit Stemma and Qwiik from Sparkfun.</br>
In addition to the I2C uŠup connector, we also have an SPI uŠup connector.</br>
</br>
The board supports the popular Živý Obraz project which greatly simplifies the use of the ePaper display to display photos, (google, outlook, apple) calendar, weather station readings, weather forecasts and much more. No need to write code, just upload the correct type of ePaper and board through the web environment and follow the procedure described in [wiki of project](https://wiki.zivyobraz.eu/).</br>
The firmware you may upload to board through [webpage available on this link](https://zivyobraz.eu/?page=instalace), just choose the board <b>LaskaKit ESPink 3.x</b> aand the type of ePaper <b>GDEQ0426T82</b>. </br>
</br>
If you want to write your own program, go ahead :-)</br>
The [schematic of board you may find on](https://github.com/LaskaKit/ESPink-426/tree/main/HW) and we also wrote several [example codes](https://github.com/LaskaKit/ESPink-426/tree/main/SW), which help a lot with writing of you own firmware for this ESPink-4.26 board.</br>
</br>
Some technical information:</br>
ESPink-4.26 has a switch that completely disconnects the board and ePaper from the power supply. Both battery and USB. </br>
IO pins for I2C bus are used - SDA IO42 and SCL IO2.</br>
The board can be assembled with a SHT40, which is connected to the same I2C bus as the external sensors.</br>
The power supply for the external I2C sensors (uSup), SPI sensors (uSup), mounted SHT40 sensor, Fuel Gauge MAX17048 and ePaper is switched via GPIO pin 47. Active in HIGH.</br>
Battery status is monitored by the Fuel Gauge MAX17048 sensor connected to the same I2C bus.</br>
In addition to the RESET button, there are three other buttons on the board labeled UP (GPIO39), PUSH (GPIO40) and DOWN (GPIO41) - all active in LOW.</br>
IO pins for the SPI bus are used - CS IO46, MOSI IO37, CLK IO14 and MISO IO21.</br>
## The ESPink-4.26 is available on [https://www.laskakit.cz/laskakit-espink-4-26-esp32-s3-e-paper/](https://www.laskakit.cz/laskakit-espink-4-26-esp32-s3-e-paper/)
