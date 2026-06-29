<p align="left">
  <img src="logo_fiuba.png" alt="Logo FIUBA" width="35%">
</p>

# **Trabajo Final: Aspiradora Inteligente**
## **Informe de Avances**

**Autores:**
* Aguirre Lautaro - Padrón 111870
* Maleh Magalí - Padrón 112001
* Medina Mateo - Padrón 111253

**Fecha:** 12/06/2026
**Cuatrimestre:** 1er Cuatrimestre 2026

---

### **Estado General de Requisitos**

A continuación se detalla el estado actual de la implementación del firmware y la integración de hardware de acuerdo con los requisitos funcionales pautados en la propuesta. 

| Estado | Descripción |
| :---: | :--- |
| 🟢 | **Implementado y validado:** Código funcional, respetando la arquitectura y los requisitos mencionados anteriormente |
| 🟡 | **Pendiente:** Está garantizado el inicio del desarrollo del código, la depuración en STM32CubeIDE, y la integración del hardware. |
| 🔴 | **Bajo evaluación:** Aún se está evaluando la practicidad de su implementación y su ejecución. |

---

#### **1. Entradas / Sensores (`task_sensor`)**

| ID | Descripción | Estado |
| :---: | :--- | :---: |
| **1.1** | El sistema leerá periódicamente un sensor de aproximación vía ADC para detectar obstáculos físicos. | 🟡 |
| **1.2** | El sistema monitoreará continuamente el consumo eléctrico de los motores emulado a través de potenciómetros conectados al ADC. | 🟡 |
| **1.3** | El sistema leerá un Dip Switch durante el arranque para determinar la configuración inicial de hardware. | 🟡 |
| **1.4** | El sistema detectará las pulsaciones de un teclado 1x4 (vía interrupciones EXTI) para la navegación por menús. | 🔴 |

#### **2. Salidas / Actuadores (`task_actuator`)**

| ID | Descripción | Estado |
| :---: | :--- | :---: |
| **2.1** | El sistema controlará la velocidad y sentido de giro emulado modificando el ciclo de trabajo PWM sobre un juego de LEDs. | 🟡 |
| **2.2** | El sistema activará una alarma acústica (Buzzer) si detecta un consumo indebido en los motores emulados. | 🟡 |
| **2.3** | El sistema actualizará periódicamente un Display LCD 16x2 (vía I2C) para reflejar estado, alarmas y opciones del menú. | 🔴 |

#### **3. Almacenamiento (`task_system` / I2C)**

| ID | Descripción | Estado |
| :---: | :--- | :---: |
| **3.1** | La configuración del sistema (umbrales y modos) se persistirá de forma no volátil en una Memoria EEPROM externa vía I2C. | 🔴 |
| **3.2** | El sistema recuperará y validará la configuración guardada al iniciar; de lo contrario, cargará valores seguros. | 🔴 |

#### **4. Interfaz y App (`task_sensor` / UART)**

| ID | Descripción | Estado |
| :---: | :--- | :---: |
| **4.1** | Toda comunicación remota se realizará mediante tramas asincrónicas (UART) a través del módulo Bluetooth HM-10. | 🟡 |
| **4.2** | La aplicación móvil permitirá al usuario visualizar el estado del vehículo en tiempo real. | 🟡 |


#### **5. Operación Segura (`task_system`)**

| ID | Descripción | Estado |
| :---: | :--- | :---: |
| **5.1** | Si el consumo supera el umbral de seguridad, el sistema interrumpirá el PWM, pasando al estado de FALLA. | 🟡 |

---

### **Comentarios Adicionales**

Actualmente, el equipo registra un desvío respecto al cronograma inicial. No obstante, hemos pactado como meta estricta iniciar el desarrollo del trabajo en el transcurso de esta misma semana, asegurando así que el proyecto final sea presentado en tiempo y forma según lo previsto.


