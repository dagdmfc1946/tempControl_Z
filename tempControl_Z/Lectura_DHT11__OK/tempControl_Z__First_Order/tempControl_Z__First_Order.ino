// --------------------------------------------------------------------------------------------------
// ---------------- MÓDULO 2: Identificación y control de una planta de primer orden ----------------
// --------------------------------------------------------------------------------------------------

// **************************************************************************************************
/*
  Asignatura: Control
  Archivo: tempControl_Z__First_Order.ino
  Versión: 2.0
  Función: Define y ejecuta la función de lectura de temperatura del sensor DHT11. 
  Autor: Diego Andrés García Díaz (@dagdmfc)
  Código: 2195533
  Fecha: 14/03/2025
*/
// **************************************************************************************************

#include <Arduino.h>
#include "dht11.h"   // Librería del sensor DHT11

// ----------------- CONFIGURACIÓN HEATER -----------------
#define HEATER_PIN 32     
#define LED_INTERNAL 2    

// ----------------- INDICADORES Y PULSADOR -----------------
#define LED_ONOFF 25    
#define LED_PWM   26     
#define BUTTON_PIN 27     

// ----------------- PWM (ESP32) -----------------
const int PWM_CHANNEL = 0;
const int PWM_FREQ = 2000;           
const int PWM_RESOLUTION = 12;       
const int MAX_DUTY_CYCLE = ((int)(pow(2, PWM_RESOLUTION) - 1));

float temp;
float setpoint = 36.0;  // °C de referencia

// ----------------- VARIABLES DE CONTROL -----------------
bool modePWM = false;    
bool lastButtonState = HIGH;

// ----------------- INICIALIZACIÓN PWM -----------------
void initPWM() {
  ledcAttachChannel(HEATER_PIN, PWM_FREQ, PWM_RESOLUTION, PWM_CHANNEL);
  ledcAttachChannel(LED_INTERNAL, PWM_FREQ, PWM_RESOLUTION, PWM_CHANNEL + 1);  
}

// ----------------- CONTROL ON-OFF -----------------
void controlONOFF(float temp, float T_ref, float hysteresis = 0.5) {
  if (temp < T_ref - hysteresis) {
    digitalWrite(HEATER_PIN, HIGH);
    digitalWrite(LED_INTERNAL, HIGH);
  } else if (temp > T_ref + hysteresis) {
    digitalWrite(HEATER_PIN, LOW);
    digitalWrite(LED_INTERNAL, LOW);
  }

  // Error instantáneo
  float error = T_ref - temp;
  Serial.printf("🔥 ON-OFF | Temp: %.1f°C | Setpoint: %.1f°C | Error: %.2f°C\n", temp, T_ref, error);
}

// ----------------- CONTROL PWM -----------------
void controlPWM(float temp, float T_ref) {
  float error = T_ref - temp;

  int duty = constrain((int)(error * 200), 0, MAX_DUTY_CYCLE);
  ledcWriteChannel(PWM_CHANNEL, duty);       
  ledcWriteChannel(PWM_CHANNEL + 1, duty);   

  Serial.printf("⚡ PWM | Temp: %.1f°C | Setpoint: %.1f°C | Error: %.2f°C | Duty: %d/%d (%.1f %%)\n",
                temp, T_ref, error, duty, MAX_DUTY_CYCLE, (duty / (float)MAX_DUTY_CYCLE) * 100);
}

// ----------------- CAMBIO DE MODO -----------------
void checkButton() {
  bool buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW && lastButtonState == HIGH) {  
    delay(50); // antirrebote
    modePWM = !modePWM;
    Serial.printf("🔄 Modo cambiado → %s\n", modePWM ? "PWM" : "ON/OFF");
  }

  lastButtonState = buttonState;

  // LEDs indicadores de modo
  digitalWrite(LED_ONOFF, !modePWM);
  digitalWrite(LED_PWM, modePWM);
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(HEATER_PIN, OUTPUT);
  pinMode(LED_INTERNAL, OUTPUT);
  pinMode(LED_ONOFF, OUTPUT);
  pinMode(LED_PWM, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);   

  initPWM();

  Serial.println(">>> Sistema de control iniciado <<<");
}

void loop() {
  dataRead_DHT(&temp);
  checkButton();

  if (modePWM) {
    controlPWM(temp, setpoint);
  } else {
    controlONOFF(temp, setpoint);
  }

  delay(2000); // lectura cada 2 s
}





