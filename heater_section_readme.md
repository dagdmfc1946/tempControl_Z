## 🔥 Especificaciones del Heater y Configuración de Potencia

### **Características Técnicas del Heater**
| Parámetro | Valor | Cálculo |
|-----------|-------|---------|
| **Resistencia** | 47Ω | Medido |
| **Potencia nominal** | 1W | Especificación del fabricante |
| **Corriente máxima @ 5V** | 106 mA | I = V/R = 5V/47Ω |
| **Potencia real @ 5V** | 0.53W | P = V²/R = 25/47 |
| **Margen de seguridad** | 47% | (1W - 0.53W)/1W |
| **Tiempo de respuesta** | ~50s | Para Δ10°C estimado |
| **Eficiencia térmica** | Alta | Resistencia cerámica |

### **Configuración del Transistor 2N2222**
```
Esquema de conexión:
Vin (5V) → Heater Pin 1 
           Heater Pin 2 → Colector (2N2222)  
D32 → 220Ω → Base (2N2222)
           Emisor (2N2222) → GND

Configuración: Emisor común como switch de potencia
Función: Control PWM de corriente del heater
```

### **Comparación 44Ω/2W vs 47Ω/1W**
| Parámetro | Heater 44Ω/2W | Heater 47Ω/1W | Ventaja |
|-----------|---------------|---------------|---------|
| **Corriente máxima** | 114 mA | 106 mA | 47Ω: Menor estrés |
| **Potencia real @ 5V** | 0.57 W | 0.53 W | 44Ω: Más calor |
| **Calor generado** | Mayor (+7%) | Menor | 44Ω: Más potencia |
| **Control de precisión** | Menos preciso | Más preciso | **47Ω: Mejor control** |
| **Eficiencia energética** | Menor | Mayor | **47Ω: Más eficiente** |
| **Seguridad del transistor** | Buena | Excelente | **47Ω: Menor corriente** |
| **Respuesta del sistema** | Más rápida | Más suave | **47Ω: Ideal para control** |

### **Funcionamiento del Control PWM**
#### **Ejemplos de Potencia según Temperatura:**
```cpp
// Control proporcional con ganancia = 200
temp = 30.0°C → error = 6.0°C → duty = 1200 (29.3% potencia) → 31mA
temp = 34.0°C → error = 2.0°C → duty = 400  (9.8% potencia)  → 10mA
temp = 36.0°C → error = 0.0°C → duty = 0    (0% potencia)    → 0mA
temp = 38.0°C → error = -2.0°C → duty = 0   (0% - límite)    → 0mA
```

#### **Ventajas del Heater 47Ω/1W para Control:**
- ✅ **Control más suave**: Menor potencia bruta permite ajustes finos
- ✅ **Mayor precisión**: Respuesta más controlable y predecible  
- ✅ **Eficiencia energética**: Menor consumo del sistema completo
- ✅ **Menor estrés térmico**: En transistor y componentes
- ✅ **Ideal para identificación**: Respuestas más limpias para MATLAB
- ✅ **Mayor vida útil**: Menos desgaste del hardware

#### **Consideraciones de Diseño:**
- **Tiempo de calentamiento**: ~15% más lento que 44Ω/2W
- **Capacidad térmica**: Suficiente para alcanzar 40-45°C
- **Margen de seguridad**: Excelente (47% de reserva de potencia)
- **Compatibilidad**: Perfecta con 2N2222 y ESP32

---

## 🤝 Contribuciones

Este proyecto es parte de un trabajo académico del curso **Control II**.

> [!NOTE]
> *Desarrollado como parte de colaboración del **Trabajo de Grado MIACON** para la asignatura Control II* 🎓

---

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
