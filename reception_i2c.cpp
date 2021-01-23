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
  ((char*)&temprecu)[0] = Wire.read();    // Réception du premier octet
  ((char*)&temprecu)[1] = Wire.read();    // Réception du second octet
  ((char*)&temprecu)[2] = Wire.read();    // Réception du troisieme octet
  ((char*)&temprecu)[3] = Wire.read();    // Réception du quaatrieme octet

  ((char*)&humidity)[0] = Wire.read();    // Réception du premier octet
  ((char*)&humidity)[1] = Wire.read();    // Réception du second octet
  ((char*)&humidity)[2] = Wire.read();    // Réception du troisieme octet
  ((char*)&humidity)[3] = Wire.read();    // Réception du quaatrieme octet

  Serial.print("Temperature recue: ");Serial.println(temprecu);  // affiche la variable reçue
  Serial.print("Humidite recue: ");Serial.println(humidity);
}
