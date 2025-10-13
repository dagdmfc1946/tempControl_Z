🎯 Introducción

En este módulo nos sumergiremos en el fascinante mundo del control de procesos térmicos 🔥❄️. El reto será trabajar con un heater como actuador (fuente de calor) y un sensor DHT11 como detector de temperatura, todo controlado con nuestra confiable ESP32.

Pero ojo 👀, aquí no se trata solo de "prender y medir". La clave es comprender cómo responde un sistema real ante las señales de control:

- ¿Qué tan rápido cambia la temperatura cuando aplicamos más potencia?
- ¿Por qué no se comporta de forma instantánea?
- ¿Cómo podemos predecir su comportamiento con un modelo matemático?

La magia aparece cuando usamos MATLAB/Simulink 🖥️: allí podremos probar, analizar y ajustar estrategias de control antes de aplicarlas al hardware real, evitando errores costosos y ganando confianza en el diseño.

Al finalizar este módulo tendrás la experiencia de haber cerrado el ciclo completo: desde la experimentación con hardware hasta el análisis matemático y el diseño de controladores. 🚀

---

🧩 Competencias que se trabajan

👉 Este módulo no solo refuerza tu conocimiento técnico, también potencia habilidades esenciales para tu perfil como ingeniero/a:

⚙️ Competencias técnicas:

📊 Entender el comportamiento dinámico de un sistema térmico (planta de primer orden).

🔌 Usar microcontroladores (ESP32) para adquisición de datos y control en tiempo real.

⚡ Implementar estrategias de control como ON-OFF y PWM, comparando sus ventajas.

🖥️ Aplicar herramientas de MATLAB/Simulink:

System Identification para modelado.
rlocus para análisis de estabilidad.
Diseñar y probar controladores PI/PID.

💡 Competencias blandas:

🧠 Pensamiento crítico: contrastar lo teórico con lo real y cuestionar resultados.
🛠️ Resolución de problemas prácticos propios de la ingeniería de control.
👩‍💻 Trabajo autónomo y autogestión en el uso de hardware y software.
📢 Comunicación clara de resultados y reflexiones.

✨ Al terminar, habrás fortalecido tanto tu lado técnico como tus soft skills, que son muy valoradas en la industria y la academia.

⚙️ Materiales y Archivos

Para llevar a cabo la práctica necesitarás los siguientes elementos:

🔥 Heater (resistencia calefactora) – nuestra planta física.
🔌 Transistor 2N2222 – para controlar la potencia mediante PWM.
🧩 ESP32 – el cerebro del sistema.
🌡️ Sensor DHT11 – encargado de medir la temperatura.
🔋 Fuente de alimentación – para energizar el sistema.
📂 Archivos de la práctica
En esta sección encontrarás todos los recursos necesarios para replicar la práctica:

📘 DHT_Definitivo → prueba inicial del sensor.
📄 Temp_Control_Identificacion → práctica central de control e identificación.

👉 Haz clic aquí para acceder a la carpeta en Google Drive



💡 Dato curioso: Muchos fallos en controladores industriales no vienen de algoritmos complicados, sino de sensores mal calibrados o sin validar.

📝 Desarrollo de la práctica

🔹 Paso 1 – Reconociendo la planta (Heater + DHT11)
👉 Aquí comienza la acción con el montaje físico:

Conecta el heater, el transistor 2N2222 y la ESP32.
Conecta el DHT11 en el pin definido para lectura de temperatura.
Carga el archivo DHT_Definitivo.
Visualiza en el Scope los datos de temperatura.

🎯 Objetivo pedagógico: Comprobar que el sistema adquiere correctamente la variable de proceso. Un ingeniero siempre valida sensores antes de diseñar el control.

---

🔹 Paso 2 – Montaje y verificación de control en PWM

Ahora damos vida al heater:

- Carga el archivo Temp_Control_Identificacion.
- Observa cómo la señal PWM controla el transistor → esto regula la potencia entregada al heater.
- Nota que a mayor ciclo de trabajo, mayor calor y, por lo tanto, la temperatura medida sube.

⚡ Dato interesante: el PWM es tan eficiente que se usa en motores, iluminación, climatización y hasta en impresoras 3D.

🎯 Objetivo pedagógico: comprender que PWM no es solo "ON-OFF rápido", sino una forma de control equivalente a señales analógicas continuas.

---

🔹 Paso 3 – Obtención y tratamiento de datos

Ejecutamos el experimento:

1. Configura la simulación a 600 [s].
2. Al finalizar, los bloques out.Temp_Data y out.Heater_Data guardarán temperatura y PWM.

Pero… 🛑 antes de analizarlos en MATLAB necesitamos ajustarlos:

- La temperatura se guarda en formato single.
- El PWM en double.

Esto causa errores en el análisis ⚠️. Para solucionarlo ejecutaremos esta linea de código en Matlab:

y = double(Temp_Data);

Luego eliminamos el sesgo inicial con:

y = y - y(1);

Así removemos el “arranque en falso” de la señal 🔄.

🎯 Objetivo pedagógico: entender la importancia del preprocesamiento de datos en la ingeniería. ¡Un mal dato puede arruinar todo el análisis!

---

🔹 Paso 4 – Identificación de la planta en MATLAB

Ahora abrimos la poderosa System Identification Toolbox 🛠️. Si no lo tienes instalado,  revisa el apartado de "Instalación de herramientas"

- Escríbelo en la consola de Matlab:

systemIdentification

- O búscalo en la pestaña APPS.

Importamos datos dando clic en "import data" y luego en "Time domain data...":

- Input: Heater_Data.signals.values (Datos del PWM) 
- Output: y (Datos de la temperatura)
- Sample time: 1 (porque el DHT11 actualiza cada segundo ⏱️).

Y damos clic en "Import"
Nos aparecerá nuestros datos importados en el apartado de la izquierda.

Luego:

- Menú Estimate → Transfer Function Models.
- Seleccionamos 1 polo, 0 ceros, modelo en tiempo discreto.
- MATLAB calcula la función de transferencia y muestra el ajuste.

👉 Si el ajuste es mayor al 80%, ¡nuestro modelo es confiable! 🎉

---

🔹 Paso 5 – Sintonización y diseño de controladores

💡 ¿Qué es la sintonización?

Es el proceso de ajustar los parámetros de un modelo o un controlador para que el sistema se comporte como deseamos: estable, rápido y sin demasiado sobreimpulso. ⚖️

⚡ 5.1 Identificación mediante Process Models

- Dentro de la ventana de System Identification, selecciona Estimate → Process Models.
- Escoge la opción con un polo + delay (modelo típico de sistemas térmicos).
- Da clic en Estimate.
- Obtendrás un bloque con los parámetros del modelo.

Haz clic derecho → En "P1D" para visualizar algunos datos importantes:
 - - Kp (ganancia).
 - - Tp1 (constante de tiempo).
 - - Td (tiempo muerto o delay).

👉 Anota estos valores, porque son la base del siguiente paso.

⚡ 5.2 Validación en Simulink

Con los valores obtenidos, crea un archivo nuevo en Simulink con los siguientes bloques:

- Step (entrada).
- Transfer Function (usando Kp y Tp1).
- Transport Delay (con Td).
- Scope (salida).

Configura el Step:

- Step time = 0
- Initial value = 0
- Final value = 1
- Sample time = 0

- Configura el bloque Transfer Function con los parámetros del modelo.
- En Transport Delay, pon el valor de Td.

Ejecuta la simulación por 600 [s].

👉 Esta gráfica nos muestra el comportamiento del modelo, y nos da una idea de en cuánto tiempo se estabiliza.

⚡ 5.3 Método de Dos Puntos de Smith

Con la gráfica obtenida podemos calcular los parámetros necesarios para aplicar Ziegler–Nichols.

De ahí obtenemos los tiempos t1 y t2, y luego:

- t1 = 142.65 [s]
- t2 = 405.17 [s]
- T = (3/2) (t2 - t1) = 393.78 [s]
- L = t2 - T = 11.39 [s]

👉 Con K, T y L ya tenemos la forma de la planta identificada.

---

📌 Conclusiones esperadas

- La planta térmica se comporta como un sistema de primer orden con retardo.
- El PWM ofrece un control eficiente frente al ON-OFF.
-El método de Dos Puntos de Smith permite simplificar la planta y facilita el diseño de controladores.
-La comparación entre distintos métodos de ajuste (Ziegler–Nichols, ISE, ITSE, IT2SE) muestra la importancia de elegir el controlador según la aplicación.

---

🚀 Llamado a la acción

¡Lo lograste! 🎉
Ya tienes experiencia de punta a punta: desde medir con un sensor hasta diseñar un controlador robusto en MATLAB/Simulink y aplicarlo en hardware real.

💡 Pregúntate:
1. ¿Qué pasaría si tuvieras que controlar un sistema con más retardos o de orden superior?
2. ¿Qué mejoras podrías implementar para enfrentar perturbaciones externas?


✨ Prepárate para el Módulo 3, donde el desafío será aún mayor: una planta de segundo orden que pondrá a prueba tus habilidades de control y modelado.




