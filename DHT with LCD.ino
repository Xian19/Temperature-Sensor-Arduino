/* DHT-22 sensor with 12c 16x2 LCD with Arduino uno
   Temperature   and humidity sensor displayed in LCD
   based on: http://www.ardumotive.com/how-to-use-dht-22-sensor-en.html   and
   https://www.ardumotive.com/i2clcden.html for the i2c LCD library by Michalis   Vasilakis
   Recompile by adhitadhitadhit
   Notes: use LCD i2c Library from   link above, i'm not sure why but new Liquidcristal library from Francisco Malpartida   isn't working for me
   other thing, check your */

//Libraries
#include   <dht.h> // sensor library using lib from https://www.ardumotive.com/how-to-use-dht-22-sensor-en.html
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT;

//Constants
#define   DHT22_PIN 7     // DHT 22  (AM2302) - pin used for DHT22 

//Variables
float hum;  //Stores   humidity value
float temp; //Stores temperature value

void setup()
{
     Serial.begin(9600);
    lcd.begin(16, 2);
}

void   loop()
{
    int chk = DHT.read22(DHT22_PIN);
    //Read data and store   it to variables hum and temp
    hum = DHT.humidity;
    temp= DHT.temperature;
     //Print temp and humidity values to LCD
    lcd.setCursor(0,0);
    lcd.print("Humidity: ");
    lcd.print(hum);
    lcd.print("%");
    lcd.setCursor(0,1);
     lcd.print("Temp: "); 
    lcd.print(temp);
    lcd.println(" C    ");
     delay(2000); //Delay 2 sec between temperature/humidity check.
}