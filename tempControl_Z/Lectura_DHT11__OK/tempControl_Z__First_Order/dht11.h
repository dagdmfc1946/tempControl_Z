// --------------------------------------------------------------------------------------------------
// ---------------- MÓDULO 2: Identificación y control de una planta de primer orden ----------------
// --------------------------------------------------------------------------------------------------

// **************************************************************************************************
/*
  Archivo: dht11.h
  Versión: 1.0
  Función: Define y ejecuta la función de lectura de temperatura y humedad del sensor DHT11. 
           
  Autor: Diego Andrés García Díaz (@dagdmfc)
  Código: 2195533
  Fecha: 13/03/2025
*/
// **************************************************************************************************

// #pragma once

#include "DHT.h"      // Librería para el sensor DHT11 o DHT22

#define DHTPIN 4      // Pin para los datos del sensor DHT11
#define DHTTYPE DHT11 // Se define el sensor a usar DHT11 o DHT22

DHT dht(DHTPIN, DHTTYPE); // Se inicializa el sensor creando un objeto con el pin de datos y el tipo de sensor

// --------------------------- FUNCIÓN PRINCIPAL PARA LECTURA DE SENSOR -----------------------------
// void dataRead_DHT(float* temp, float* hum) { // FUNCIÓN PRINCIPAL // 'float* __' --> Accede o modifica el valor almacenado en una dirección de memoria (puntero).
void dataRead_DHT(float* temp) {
  // Serial.println("Iniciando proceso de lectura de la Temperatura..."); // Mensaje de diagnóstico en consola

  float t = dht.readTemperature(); // Lee temperatura en grados Celsius
  // float h = dht.readHumidity(); // Lee humedad relativa en porcentaje

  // Verifica si la lectura es válida; si no, reporta error y muestra en pantalla
  // if (isnan(t) || isnan(h)) {
  if (isnan(t)) {
    Serial.println("❌ ¡¡ERROR en la lectura del sensor!!"); // Notifica error en consola
    *temp = 0; // Devuelve 0 como valor de temperatura inválida (ERROR lectura sensor)
    // *hum = 0; // Devuelve 0 como valor de humedad inválida (ERROR lectura sensor)
  } else {
    *temp = t; // Asigna la temperatura leída a la variable original
    // *hum = h; // Asigna la humedad leída a la variable original
    // Serial.printf("Temperatura: %.1f °C\tHumedad: %.1f %%\t   ", t, h); // Imprime resultados en consola
    Serial.printf("Temperatura: %.1f °C\n", t); // Imprime resultados en consola
  }
}
// *************************************************************************************************