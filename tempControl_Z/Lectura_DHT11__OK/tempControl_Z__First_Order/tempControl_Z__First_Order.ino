// --------------------------------------------------------------------------------------------------
// ---------------- MÓDULO 2: Identificación y control de una planta de primer orden ----------------
// --------------------------------------------------------------------------------------------------

// **************************************************************************************************
/*
  Asignatura: Control
  Archivo: tempControl_Z__First_Order.ino
  Versión: 1.0
  Función: Define y ejecuta la función de lectura de temperatura y humedad del sensor DHT22. 
           Implementa verificación de error y muestra mensajes en OLED si falla la lectura, además
           de visualizar en el LED interno de la placa un parpadeo ON/OFF con delay de 400 ms que
           indica un error en la lectura del sensor.
  Autor: Diego Andrés García Díaz (@dagdmfc)
  Código: 2195533
  Fecha: 13/03/2025
*/
// **************************************************************************************************

#include "dht11.h"

float temp;
float hum;

void setup() {
  Serial.begin(115200);
  dht.begin(); // Inicializa la comunicación con el sensor DHT11
  Serial.println(">>> Iniciando proceso de lectura de la Temperatura <<<"); // Mensaje de diagnóstico en consola
  delay(1000); // Espera 1 segundo 
}

void loop() {
  // dataRead_DHT(&temp, &hum);
  dataRead_DHT(&temp);
  delay(2000);  // DHT11 solo da ~1 lectura cada 1-2 segundos
}
