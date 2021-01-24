# communication-entre-2-arduino-en-I2C-avec-un-SI7021
envoi de le temperature d'un Si7021(temp/hygro) via le port I2C sur un 2eme arduino. la temperature est defini en float (4o). L'nvoi se fait octet par octet, il faut donc envoyer 4 fois.

le maitre ne demande pas de lui envoyer des octets. 
c'est l'esclave qui decide d'envoyer.
