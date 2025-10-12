## 📈 Versiones

---

🔬 Para la identificación de la planta se recomienda:
- [✔] Ejecutar el sistema en modo PWM
- [✔] Aplicar entrada escalón
- [✔] Registrar respuesta por ~600 segundos
- [✔] Usar MATLAB System Identification Toolbox
- [✔] Modelar como sistema de primer orden + retardo

---

### v1.0 - Lectura Básica ✅
- [x] Lectura de temperatura DHT11
- [x] Visualización en monitor serial
- [x] Manejo de errores del sensor

---

### v2.0 - Control Implementado ✅ 
- [x] Control ON-OFF con histéresis
- [x] Control PWM proporcional
- [x] Interfaz de cambio de modo (ON/OFF - PWM)
- [x] LEDs indicadores (ON/OFF - PWM)
- [x] Monitoreo más visual (Monitor Serial)

> [!NOTE]
> Informe 1 (identificación) realizado para **v1.0** y **v2.0**: [INFORME_1_TEMP_Control_Z_2195533](https://www.overleaf.com/read/ygfkqjzxgrjt#f2e4d4).

---

### v3.0 - Planificando... 🚧❌
- [x] Control P		(🛠 Ya se tiene una base)
- [ ] Control PD	(🛠)
- [ ] Control PI	(🛠)
- [ ] Control PID	(🛠)

> [!NOTE]
> Informe 2 (final) realizado para **v3.0**: [INFORME_2_TEMP_Control_Z_2195533](https://www.overleaf.com/read/npqnfcggdkfs#01d40b).

---

### Mejoras opcionales... 🔜
⚠ Opcional (Mejoras del proyecto):
- [ ] Interfaz web
- [ ] Logging de datos
- [ ] Comunicación MQTT

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