#include <Arduino.h>
#include <Wire.h>   // librairie pour I2C

float temprecu = 0;
float humidity = 0;

void receiveEvent();

void setup()
{
  Wire.begin(1);                // Initialise la liaison I2C avec une adresse arbitraire             
  Wire.onReceive(receiveEvent); // si il y a quelque chose a recevoir; on lance la fonction
  Serial.begin(115200);         // Initilaise une liaison série
}

void loop()
{
  delay(100);
}

void receiveEvent(int howMany)
{
  for (int i = 0; i<4; i++)
  {
    ((char*)&temprecu)[i] = Wire.read();  // boucle pour recevoir les 4 octets represantant la temperature
  }
  for (int i = 0; i<4; i++)
  {
    ((char*)&humidity)[i] = Wire.read(); // boucle pour recevoir les 4 octets represantant l'humidité
  }
  
  Serial.print("Temperature recue: ");Serial.println(temprecu);  // affiche la variable reçue
  Serial.print("Humidite recue: ");Serial.println(humidity);
}
