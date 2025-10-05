# 🌡️ tempControl_Z - Sistema de Control de Temperatura

[![ESP32](https://img.shields.io/badge/ESP32-Development%20Board-blue.svg)](https://www.espressif.com/en/products/socs/esp32)
[![DHT11](https://img.shields.io/badge/Sensor-DHT11-green.svg)](https://www.adafruit.com/product/386)
[![Arduino IDE](https://img.shields.io/badge/Arduino%20IDE-Compatible-orange.svg)](https://www.arduino.cc/en/software)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

> **Sistema de control de temperatura de primer orden desarrollado para el Módulo 2 del proyecto de grado MIACON - Control II**

> [!NOTE]
> - Se puede visualizar el informe realizado para la parte de identificación del modelo de la planta o sistema: [INFORME_1_TEMP_Control_Z_2195533](https://www.overleaf.com/read/ygfkqjzxgrjt#f2e4d4).
>
> - Se puede visualizar el informe realizado para el diseño de los controladores: **Coming soon...**

## 📖 Descripción

Este proyecto implementa un sistema completo de control de temperatura utilizando ESP32, sensor DHT11 y un heater como actuador. Forma parte del **Módulo 2: Identificación y control de una planta de primer orden** del curso de Control II.

El sistema permite:
- 📊 Lectura y monitoreo de temperatura en tiempo real
- 🔥 Control ON-OFF con histéresis configurable
- ⚡ Control PWM para regulación continua
- 🔄 Cambio dinámico entre modos de control
- 📱 Visualización de estados mediante LEDs indicadores

## ✨ Características principales

- **Control Dual**: Implementación de control ON-OFF y PWM
- **Interfaz Visual**: LEDs indicadores para cada modo de operación
- **Cambio de Modo**: Botón para alternar entre estrategias de control
- **Monitoreo Serial**: Visualización detallada de variables en tiempo real
- **Arquitectura Modular**: Código organizado y reutilizable

## 🛠️ Componentes de Hardware

| Componente | Función | Pin ESP32 |
|------------|---------|-----------|
| 🔥 **Heater** | Actuador térmico | Pin 32 |
| 🌡️ **DHT11** | Sensor de temperatura | Pin 4 |
| 🔴 **LED ON-OFF** | Indicador modo ON-OFF | Pin 25 |
| 🟡 **LED PWM** | Indicador modo PWM | Pin 26 |
| 🔘 **Botón** | Cambio de modo | Pin 27 |
| 💡 **LED Interno** | Estado del heater | Pin 2 |

## 📁 Estructura del Proyecto

```
tempControl_Z/
├── 📄 tempControl_Z__First_Order.ino    # Programa principal
├── 📄 dht11.h                           # Librería del sensor DHT11
├── 📖 README.md                         # Este archivo
└── 📋 circuit_diagram.png               # Diagrama del circuito (próximamente)
```

## 🚀 Instalación y Configuración

### Prerrequisitos
- **Arduino IDE** 1.8.x o superior
- **ESP32 Board Package** instalado
- **Librería DHT sensor library** by Adafruit

### Instalación de librerías
```bash
# En Arduino IDE > Manage Libraries, buscar e instalar:
- DHT sensor library by Adafruit
- Adafruit Unified Sensor
```

### Configuración
1. Conecta los componentes según la tabla de pines
2. Abre `tempControl_Z__First_Order.ino` en Arduino IDE
3. Selecciona la placa ESP32 y el puerto correspondiente
4. Compila y carga el código

## 💻 Uso del Sistema

### Modo ON-OFF (Por defecto)
- **Funcionamiento**: Control de histéresis con bandas de ±0.5°C
- **Indicador**: LED rojo encendido
- **Ventajas**: Simple, bajo consumo
- **Desventajas**: Mayor oscilación

### Modo PWM
- **Funcionamiento**: Control proporcional continuo
- **Indicador**: LED amarillo encendido
- **Ventajas**: Control suave, menor oscilación
- **Desventajas**: Mayor complejidad

### Cambio de Modo
Presiona el **botón** para alternar entre modos. El sistema mostrará en el monitor serial:
```
🔄 Modo cambiado → PWM
🔄 Modo cambiado → ON/OFF
```

## 📊 Monitoreo en Tiempo Real

El sistema proporciona información detallada vía Serial Monitor:

**Modo ON-OFF:**
```
🔥 ON-OFF | Temp: 25.1°C | Setpoint: 36.0°C | Error: 10.90°C
```

**Modo PWM:**
```
⚡ PWM | Temp: 34.2°C | Setpoint: 36.0°C | Error: 1.80°C | Duty: 360/4095 (8.8%)
```

## ⚙️ Parámetros Configurables

```cpp
float setpoint = 36.0;           // Temperatura objetivo (°C)
float hysteresis = 0.5;          // Banda de histéresis para ON-OFF (°C)
const int PWM_FREQ = 2000;       // Frecuencia PWM (Hz)
const int PWM_RESOLUTION = 12;   // Resolución PWM (bits)
```

## 🎯 Objetivos Pedagógicos

Este proyecto desarrolla competencias en:
- **Control de Procesos**: Implementación práctica de estrategias de control
- **Sistemas Embebidos**: Programación de microcontroladores ESP32
- **Instrumentación**: Uso de sensores y actuadores industriales
- **Análisis de Sistemas**: Comportamiento de plantas de primer orden

### 📊 Configuración PWM - Análisis Técnico

#### **Frecuencias PWM Recomendadas**
| Frecuencia | Ventajas | Desventajas | Uso recomendado |
|------------|----------|-------------|-----------------|
| **100-1000 Hz** | Simple, bajo ruido EMI | Visible parpadeo, ruido audible | LEDs básicos |
| **1-10 kHz** ⭐ | Buen balance, sin parpadeo | Algo de ruido audible | **Heaters, motores DC** |
| **10-50 kHz** | Sin ruido audible | Mayor EMI, más complejo | Audio, iluminación |
| **50+ kHz** | Muy limpio | Alto EMI, pérdidas switching | Fuentes conmutadas |

> **✅ Nuestra elección: 5 kHz** - Óptimo para heaters resistivos con inercia térmica

#### **Resolución PWM Disponible**
| Resolución | Niveles | Precisión | Memoria | Velocidad | Uso |
|------------|---------|-----------|---------|-----------|-----|
| **8 bits** | 256 (0-255) | ~0.4% | Menos | Más rápido | Básico |
| **12 bits** ⭐ | 4096 (0-4095) | ~0.024% | Más | Más lento | **Control precisión** |
| **16 bits** | 65536 | ~0.0015% | Mucha | Lento | Ultra-precisión |

> **✅ Nuestra elección: 12 bits** - Balance perfecto entre precisión y eficiencia para control térmico

## 🔬 Identificación del Sistema

Para la identificación de la planta se recomienda:
1. Ejecutar el sistema en modo PWM
2. Aplicar entrada escalón
3. Registrar respuesta por ~600 segundos
4. Usar MATLAB System Identification Toolbox
5. Modelar como sistema de primer orden + retardo

> [!NOTE]
> Informe 1 (identificación) realizado para **v1.0** y **v2.0**: [INFORME_1_TEMP_Control_Z_2195533](https://www.overleaf.com/read/ygfkqjzxgrjt#f2e4d4)

---

## 🤝 Contribuciones

Este proyecto es parte de un trabajo académico del curso **Control II**. Las contribuciones son bienvenidas para:
- Optimización de algoritmos
- Mejoras en la interfaz
- Documentación adicional
- Nuevas estrategias de control

## 👨‍💻 Autor

**Diego Andrés García Díaz** ([@dagdmfc](https://github.com/dagdmfc1946))
- 🎓 Código: 2195533
- 📧 [diego2195533@correo.uis.edu.co]
- 📧 [dagdmfc@gmail.com]
- 🏫 Asignatura: Control II
- 📅 Fecha: Septiembre 2025

## 📚 Referencias

- [Guía Módulo 2 - MIACON](https://sites.google.com/view/miacon-proyectodegrado/gu%C3%ADas-de-laboratorio/m%C3%B3dulo-2-identificaci%C3%B3n-y-control-de-una-planta-de-primer-orden)
- [ESP32 Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
- [DHT11 Datasheet](https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf)

---
*Desarrollado como parte de colaboración del proyecto de grado MIACON para la asignatura Control II* 🎓
