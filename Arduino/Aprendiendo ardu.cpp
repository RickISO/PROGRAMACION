/*%el lenguaje de arduino lenguage es una variante de c++ contiene bibliotecas predeterminadas algunas de las bibliotecas
mas importantes son wire.h, RTClib.h y servo.h

*/
/*
Este es un programa básico para parpadear un LED. 
*/




 /* El LED está conectado al pin 14. */


void setup() {
  pinMode(14, OUTPUT); // Configurar el pin 14 como salida
}

void loop() {
  digitalWrite(14, HIGH); // Encender el LED en el pin 14
  delay(1000);            // Esperar 1 segundo
  digitalWrite(14, LOW);  // Apagar el LED
  delay(1000);            // Esperar 1 segundo
}

/* high y low son usados como encendido y apagado mientras que el tiempo es escrito en milisegundos dado la
naturaleza de computadoras */
