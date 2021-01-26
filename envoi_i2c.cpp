
#include <Arduino.h>
#include <Wire.h>     // librairie pour I2C
#include <SparkFun_Si7021_Breakout_Library.h>  // librairie pour le capteur SI7021

float humidity = 0;
float temp = 0;

//creer une instance du SI7021
Weather sensor;

// declaratrion des fonctions 
void Envoi();
void getWeather();
void printInfo();

void setup()
{
  Serial.begin(9600); // debute une liaison serie
  Wire.begin();       // debute la communication I2C
  sensor.begin();     // initialise le capteur

}
void loop()
{
  // appel des differentes fonctions 
    getWeather(); // recolte les infos du capteurs
    Envoi();      // envoi les données par I2C
    printInfo();  // ecris les données dans le port série
    delay(1000);  // prise de mesure toutes les secondes

}
//---------------------------------------------------------------
void getWeather()
{
  // Prise de mesure de l'humidité et stockage
  humidity = sensor.getRH();

  // Prise de mesure de la temperature et stockage
  temp = sensor.getTemp();
}
//---------------------------------------------------------------
void printInfo()
{
  Serial.print("Temp:");
  Serial.print(temp);
  Serial.print("C, ");

  Serial.print("Humidity:");
  Serial.print(humidity);
  Serial.println("%");
}

void Envoi()
{
  /* notre variable etant un float sur sur 4 octets et etant donné que l'I2C envoi 1 octet
     a la fois, il faut envoyer octet apres octet de nos variables.
  */

  Wire.beginTransmission(1);   // debute une liaison avec l'esclave
  for (int i = 0; i<4 ; i++)
  {
    Wire.write( ((char*)&temp)[i] );    // envoi de 4 octets composants le float temperature
  }
  for (int i = 0; i<4 ; i++)
  {
    Wire.write( ((char*)&humidity)[i] );    // envoi de 4 octets composants le float humidité
  }
 
  Wire.endTransmission();   // libere le canal I2C
}
