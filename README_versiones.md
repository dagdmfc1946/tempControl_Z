# 📈 Versiones

---

## 🔬 Para la identificación de la planta se recomienda:

1. Ejecutar el sistema en modo PWM
2. Aplicar entrada escalón
3. Registrar respuesta por ~600 segundos
4. Usar MATLAB System Identification Toolbox
5. Modelar como sistema de primer orden + retardo

---

### v1.0 - Lectura Básica ✅
- [✔] Lectura de temperatura DHT11
- [✔] Visualización en monitor serial
- [✔] Manejo de errores del sensor

---

### v2.0 - Control Básico Implementado (Arduino IDE y ESP32) ✅ 
- [✔] Control ON-OFF con histéresis
- [✔] Control PWM proporcional
- [✔] Interfaz de cambio de modo (ON/OFF - PWM)
- [✔] LEDs indicadores (ON/OFF - PWM)
- [✔] Monitoreo más visual (Monitor Serial)

> [!NOTE]
> Informe 1 (identificación) realizado para **v1.0** y **v2.0**: [INFORME_1_TEMP_Control_Z_2195533](https://www.overleaf.com/read/ygfkqjzxgrjt#f2e4d4).

---

### v3.0 - Controladores P, PI, PD y PID ✅ 
Se diseñaron los controladores usando el método analítico (ubicación de polos) con **aproximación de Padé**, el método de **Ziegler-Nichols**, y herramientas de MATLAB como **pid()**, **PID Tuner**, **sisotool**, entre otras.
- [✔] Control P	
- [✔] Control PD	
- [✔] Control PI	
- [✔] Control PID	

> [!NOTE]
> Informe 2 (final) realizado para **v3.0**: [INFORME_2_TEMP_Control_Z_2195533](https://www.overleaf.com/read/npqnfcggdkfs#01d40b).

---

### Mejoras opcionales... 🔜
⚠ Opcionalmente se pueden integrar más funcionalidades y mayor robustez:
- [🛠] Logging de datos
- [🛠] Comunicación MQTT
- [🛠] Almacenamiento y procesamiento de datos (**Internet of Things - IoT**)

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

## 📄 Licencia

Este proyecto está bajo la Licencia MIT - ver el archivo [LICENSE](LICENSE) para detalles.

---

> [!NOTE]
> *Desarrollado como parte de colaboración del proyecto de grado MIACON para la asignatura Control II* 🎓