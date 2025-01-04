![ESPink-4.26 TOP](https://github.com/LaskaKit/ESPink-426/blob/main/img/ESPink-4-26_top.JPG)
</br>
# ESPink-4.26" - univerzální a velmi úsporná deska s ESP32-S3 pro velký 4.26" 800x480 ePaper

Do obliby nejen bastlířů se dostaly naše už kompletně hotové a osazené vývojové desky s ESP32 a přilepeným ePaper displejem. Rozšiřujeme tak náš sortiment o další hotový vývojový kit Laskakit ESPink o variantu 4.26". </br>
Doplňuje tak stávající rodinu hotových kitů s ePaper jako jsou [Laskakit ESPink-Shelf-2.9 ESP32 e-Paper](https://www.laskakit.cz/laskakit-espink-shelf-2-9-esp32-e-paper/?variantId=14193), [LaskaKit ESPink-4.2 ESP32 e-Paper](https://www.laskakit.cz/laskakit-espink-42-esp32-e-paper-pcb-antenna/?variantId=13538) a [LaskaKit ESPink-Shelf-2.13 ESP32 e-Paper](https://www.laskakit.cz/laskakit-espink-shelf-213-esp32-e-paper/).</br>
Pokud preferuješ samostatnou desku, pak máme v nabídce [velmi úsporný a univerzální ESPink](https://www.laskakit.cz/laskakit-espink-esp32-e-paper-pcb-antenna/?variantId=12419). Deska je menší a univerzálnější pro připojení jiných ePaper displejů. </br>
</br>
![ESPink-4.26 TOP](https://github.com/LaskaKit/ESPink-426/blob/main/img/ESPink-4-26_bottom.JPG)</br>
</br>
ESPink-4.26 s ESP32-S3 nabízí velmi nízkou spotřebu, rozumně velký ePaper s velkým 800x480px rozlišením, jednoduché programování díky vestavěnému programátoru připojeného na USB-C ze kterého se zároveň nabíjí akumulátor, konektor s vyvedenými nevyužitými piny z ESP32-S3 díky kterému mohou být do desky přivedeny další signály a v neposlední řadě i microSD slot pro paměťovou kartu. </br>
</br>
ESPink-4.26 má osazeny dva naše univerzální I2C uŠup konektory ke kterým můžeš připojit nejrůznější čidla - [SHT40 (teplota, vlhkost)](https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/), [BME280 (tlak, teplota, vlhkost)](https://www.laskakit.cz/arduino-senzor-tlaku--teploty-a-vlhkosti-bme280/), [SCD41 (CO2, teplota, vlhkost)](https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/), [BH1750 (osvětlení)](https://www.laskakit.cz/laskakit-bh1750-snimac-intenzity-osvetleni/), [APDS-9960 (senzor gest)](https://www.laskakit.cz/laskakit-apds-9960-senzor-priblizeni-a-gest/) a spoustu další senzorů. Náš I2C uŠup konektor je kompatibilní s Adafruit Stemma a Qwiik od Sparkfun.</br>
Kromě I2C uŠup konektoru máme osazený i SPI uŠup konektor.
</br>
Deska podporuje populární projekt Živý Obraz, který výrazně zjednodušuje použití ePaper displeje k zobrazení fotografií, (google, outlook, apple) kalendáře, kurzů, hodnot z meteostanic, předpovědi počasí a mnoho dalšího. Není nutné psát kód, stačí nahrát správný typ ePaper a desky skrze webové prostředí a dodržet postup popsaný v [dokumentaci](https://wiki.zivyobraz.eu/).</br>
Program nahraješ [přes webové prostředí na této stránce](https://zivyobraz.eu/?page=instalace) a stačí zvolit desku <b>LaskaKit ESPink 2.x</b> a typ ePaperu <b>GDEY029F51H, GDEY029T71H, GDEY029T94 nebo GDEY0213B74</b> - podle toho, co sis objednal. </br>
</br>
Pokud si chceš napsat vlastní program, tak do toho :-)</br>
Na našem github máš [schéma desky](https://github.com/LaskaKit/ESPink-426/tree/main/HW) a nezapomněli jsme ani na [vzorové kódy](https://github.com/LaskaKit/ESPink-426/tree/main/SW), které by ti značně měly usnadnit programování a práci s naším ESPink-4.26. </br>
</br>
Pár technických informací:</br>
ESPink-4.26 má přepínač kterým se deska i ePaper kompletně odpojí od napájení. Jak baterie, tak i USB. </br>
IO piny pro I2C sběrnici jsou použity - SDA IO42 a SCL IO2.</br>
Na desce může být osazen SHT40, který je připojen na stejnou I2C sběrnici jako externí čidla.</br>
Napájení pro externí I2C čidla (uŠup), SPI čidla (uŠup), osazené SHT40 čidlo, Fuel Gauge MAX17048 a ePaper je spínán přes GPIO pin 47. Aktivní v HIGH.</br>
Stav baterie je monitorován Fuel Gauge senzorem MAX17048 připojeným na stejnou I2C sběrnici.</br>
Kromě RESET tlačítka jsou na desce osazena další tři tlačítka označená jako UP (GPIO39), PUSH (GPIO40) a DOWN (GPIO41) - všechny aktivní v LOW.</br>
IO piny pro SPI sběrnici jsou použity - CS IO46, MOSI IO37, CLK IO14 a MISO IO21.</br> 

## ESPink-4.26 je k zakoupení na našem e-shopu [https://www.laskakit.cz/laskakit-espink-4-26-esp32-s3-e-paper/](https://www.laskakit.cz/laskakit-espink-4-26-esp32-s3-e-paper/)
