/* Ahorita mismo no cuento con las cosas para hacer el jardin por lo cual este codigo solo es conceptual 
aunque creo que los materiales nesesarios serian 

1. placa de arduino (la que se usa mas es la arduino 1 y no veo porq no se pudiera utilizar)
2. Un modulo de manejo de tiempo chat me dijo que el RTC DS3231 :v 
3. Un control para una bomba de agua y la bomba de agua
4. cables y resistores */
 

#include <Wire.h>  // es la biblioteca para el cableado
#include <RTClib.h>  //libreria o biblioteca para el motor

RTC_DS3231 rtc; // se crea el objeto que intaractuara con el motor dentro del codigo

const int bombaAgua = 8; // Dice en que pin está conectada la bomba de agua o electroválvula por eso const

void setup() {
  Serial.begin(9600); // Iniciar la comunicacion dentro del arduino a 9600 BPS que es la estandard
  pinMode(bombaAgua, OUTPUT); // Configurar el pin 8 que planeo que sea el de la bomba como salida
  digitalWrite(bombaAgua, LOW); // basicamente apaga la bomba es para q no la cage tbh

  // Iniciar el módulo RTC
  if (!rtc.begin()) { //comienza el motor para ver si funciona osea si esta conectado
    Serial.println("Error: No se encontró el RTC.");
    while (1); /* esta linea me la agrego chat por lo que entendi funciona porque crea un loop infinito vacio
    y no necesita {} porq en arduino y creo q en c++ al usar un loop de sola una linea o bloque de codigo osea 
    si se puede cambiar a {} pero es lo mismo*/
  }

  // Si el RTC perdio energia, ajustar la fecha y hora actuales
  if (rtc.lostPower()) {
    Serial.println("RTC perdió energía. Ajustando fecha y hora...");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Namas para cambiar hora y fecha 
  }
}

void loop() {
  DateTime ahora = rtc.now(); // Obtener la fecha y hora actuales

  // Mostrar la hora actual en el monitor serial
  Serial.print("Hora actual: ");
  Serial.print(ahora.hour());
  Serial.print(":");
  Serial.print(ahora.minute());
  Serial.print(":");
  Serial.println(ahora.second());

  // Verificar si es hora de regar
  if ((ahora.hour() == 18 && ahora.minute() == 0) || // 6:00 PM
      (ahora.hour() == 7 && ahora.minute() == 0) ||  // 7:00 AM
      (ahora.hour() == 12 && ahora.minute() == 0)) { // 12:00 PM
    regar(); // Activar la bomba de agua
  }

  delay(1000); // Esperar 1 segundo antes de volver a verificar
}

void regar() {
  Serial.println("Regando el jardín...");
  digitalWrite(bombaAgua, HIGH); // Encender la bomba de agua
  delay(60000); // Regar durante 1 minuto no se mucho de jardineria pero pudiera ser demaciado
  digitalWrite(bombaAgua, LOW); // Apagar la bomba de agua
  Serial.println("Riego completado.");
}