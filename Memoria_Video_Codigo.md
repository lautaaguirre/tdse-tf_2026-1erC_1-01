<div align="left">

<p align="left">
  <img src="DIAGRAMAS/logo_fiuba.png" width="35%">
</p>

**UNIVERSIDAD DE BUENOS AIRES**  
**Facultad de Ingeniería**  
**TA134 – Taller de Sistemas Embebidos**  

# Memoria del Trabajo Final:
## Aspiradora Inteligente (Evasión autónoma de obstáculos, monitoreo de consumo, interfaz inalámbrica y alertas acústicas)

<div align="left">
  <table style="border-collapse: collapse; width: 45%;">
    <thead>
      <tr>
        <th align="left" style="border: 1px solid #888; padding: 8px;">Autor</th>
        <th align="center" style="border: 1px solid #888; padding: 8px;">Padrón</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Aguirre Lautaro</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">111870</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Medina Mateo</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">111253</td>
      </tr>
    </tbody>
  </table>
</div>

*Trabajo realizado en la Provincia de Buenos Aires, entre marzo y agosto de 2026.*  
**Fecha de entrega final:** Agosto de 2026.

</div>

---

## RESUMEN

Se desarrolló un sistema embebido para una aspiradora inteligente capaz de evadir obstáculos de forma autónoma y monitorear su consumo energético emulado, permitiendo además la configuración y control mediante un teclado matricial, un display interactivo, conectividad inalámbrica por Bluetooth y alertas acústicas mediante un buzzer piezoeléctrico. El proyecto surge de la necesidad de aplicar conceptos de sistemas que reaccionen ante estímulos en un entorno de electrónica autónoma, garantizando seguridad y eficiencia.

El hardware se implementó sobre un microcontrolador STM32F103RB, integrando entradas analógicas que emulan los sensores de distancia y consumo, un teclado matricial para que el usuario pueda interactuar con el dispositivo, un display LCD para mostrar los distintos menús, LEDs accionados por PWM que simulan la tracción de los motores, un módulo de comunicación Bluetooth asincrónico y un buzzer gobernado por temporizadores de hardware. El firmware fue diseñado bajo una arquitectura de software estrictamente no bloqueante, estructurada en tres capas de ejecución unidireccionales y máquinas de estados finitos coordinadas por una base de tiempo periódica de un milisegundo.

En este trabajo se busca demostrar la correcta aplicación de las metodologías de diseño de sistemas de tiempo real aprendidas en la carrera. La documentación incluye los ensayos de integración, el análisis de ocupación de memoria, el cálculo del factor de uso del procesador y la medición de los tiempos máximos de ejecución para validar el cumplimiento de los plazos del sistema.

---

## Registro de versiones

La tabla 0.1 resume el historial de revisiones y entregas de esta memoria técnica.

Tabla 0.1: Registro de versiones del documento.
| Revisión | Cambios realizados | Fecha |
| :---: | :--- | :---: |
| 1.0 | Entrega de la version inicial de la memoria del Trabajo Final | 10/07/2026 |
| 1.1 | Entrega de la versión final (sujeta a revisión y correcciones del docente) | 24/07/2026 |
| 2.0 | Corrección integral y entrega final definitiva del informe | 03/08/2026 |

---

# Índice General

- [Capítulo 1: Introducción general](#capítulo-1-introducción-general)
  - [1.1 Análisis de necesidad y objetivo](#11-análisis-de-necesidad-y-objetivo)
  - [1.2 Productos comparables](#12-productos-comparables)
  - [1.3 Justificación del enfoque técnico](#13-justificación-del-enfoque-técnico)
  - [1.4 Alcance y limitaciones](#14-alcance-y-limitaciones)
- [Capítulo 2: Introducción específica](#capítulo-2-introducción-específica)
  - [2.1 Evolución y estado final de los requisitos](#21-evolución-y-estado-final-de-los-requisitos)
  - [2.2 Casos de uso](#22-casos-de-uso)
    - [2.2.1 Limpieza autónoma y evasión de obstáculos](#221-limpieza-autónoma-y-evasión-de-obstáculos)
    - [2.2.2 Monitoreo de consumo y protección por sobrecorriente](#222-monitoreo-de-consumo-y-protección-por-sobrecorriente)
    - [2.2.3 Configuración y control local vía Menú SET UP](#223-configuración-y-control-local-vía-menú-set-up)
    - [2.2.4 Telemetría inalámbrica Bluetooth](#224-telemetría-inalámbrica-bluetooth)
  - [2.3 Descripción de módulos principales](#23-descripción-de-módulos-principales)
    - [2.3.1 Módulo de Control Central (NUCLEO-F103RB)](#231-módulo-de-control-central-nucleo-f103rb)
    - [2.3.2 Módulo de Sensores Analógicos Emulados](#232-módulo-de-sensores-analógicos-emulados)
    - [2.3.3 Módulo de Interfaz de Usuario Local (Teclado y Display LCD)](#233-módulo-de-interfaz-de-usuario-local-teclado-y-display-lcd)
    - [2.3.4 Módulo de Actuadores de Tracción (LEDs PWM) y Alertas Acústicas](#234-módulo-de-actuadores-de-tracción-leds-pwm-y-alertas-acústicas)
    - [2.3.5 Módulo de Comunicación Inalámbrica (Bluetooth)](#235-módulo-de-comunicación-inalámbrica-bluetooth)
- [Capítulo 3: Diseño e implementación](#capítulo-3-diseño-e-implementación)
  - [3.1 Arquitectura general](#31-arquitectura-general)
  - [3.2 Diseño de hardware](#32-diseño-de-hardware)
  - [3.3 Diseño de firmware](#33-diseño-de-firmware)
    - [3.3.1 Arquitectura en 3 capas](#331-arquitectura-en-3-capas)
    - [3.3.2 Máquinas de Estados Finitos (Statecharts)](#332-máquinas-de-estados-finitos-statecharts)
- [Capítulo 4: Ensayos y resultados](#capítulo-4-ensayos-y-resultados)
  - [4.1 Pruebas funcionales de hardware](#41-pruebas-funcionales-de-hardware)
  - [4.2 Pruebas funcionales de firmware](#42-pruebas-funcionales-de-firmware)
  - [4.3 Pruebas de integración](#43-pruebas-de-integración)
  - [4.4 Medición y análisis de consumo](#44-medición-y-análisis-de-consumo)
  - [4.5 Console and Build Analyzer](#45-console-and-build-analyzer)
  - [4.6 Medición y análisis de WCET por tarea](#46-medición-y-análisis-de-wcet-por-tarea)
  - [4.7 Cálculo del factor de uso de CPU (U)](#47-cálculo-del-factor-de-uso-de-cpu-u)
  - [4.8 Gestión de bajo consumo y justificación](#48-gestión-de-bajo-consumo-y-justificación)
  - [4.9 Cumplimiento de requisitos](#49-cumplimiento-de-requisitos)
  - [4.10 Comparación con sistemas similares](#410-comparación-con-sistemas-similares)
  - [4.11 Documentación del desarrollo realizado](#411-documentación-del-desarrollo-realizado)
- [Capítulo 5: Conclusiones](#capítulo-5-conclusiones)
  - [5.1 Resultados obtenidos](#51-resultados-obtenidos)
  - [5.2 Lecciones aprendidas](#52-lecciones-aprendidas)
  - [5.3 Próximos pasos](#53-próximos-pasos)
- [Capítulo 6: Uso de herramientas de IA](#capítulo-6-uso-de-herramientas-de-ia)
- [Capítulo 7: Bibliografía y referencias](#capítulo-7-bibliografía-y-referencias)

---

# Capítulo 1: Introducción general

## 1.1 Análisis de necesidad y objetivo

La automatización de tareas domésticas mediante robótica móvil exige sistemas electrónicos capaces de operar de manera reactiva y autónoma en entornos dinámicos. En particular, una aspiradora inteligente debe resolver dos problemas críticos en tiempo real:
1. **La evasión constante de obstáculos:** Detectar objetos en su trayectoria y ejecutar maniobras de evasión (detención, marcha atrás y giro) sin intervención humana.
2. **La seguridad electromecánica:** Monitorear continuamente la corriente de tracción de sus motores para detectar bloqueos mecánicos o sobreesfuerzos, deteniendo el sistema antes de que se produzcan daños físicos o térmicos.

El objetivo principal es construir una plataforma embebida funcional, robusta y escalable. A partir del análisis de alternativas y ajustes de alcance propuestos durante el proyecto, se establecieron los siguientes objetivos específicos:
* **Navegación reactiva:** Implementar un algoritmo de evasión autónoma de obstáculos basando las decisiones en niveles de tensión emulados.
* **Gestión energética y seguridad:** Desarrollar un sistema de monitoreo de consumo que permita a la aspiradora tomar decisiones según niveles de corriente emulados, generando seguridad para el entorno y alargando la vida útil del dispositivo.
* **Interacción con el usuario:** Incluir una interfaz local compuesta por un teclado matricial y un display LCD para acceder a las distintas configuraciones del sistema (modo SET UP).
* **Conectividad y alertas:** Integrar un canal Bluetooth para telemetría no bloqueante y un buzzer controlado por PWM para la reproducción de avisos acústicos.
* **Eficiencia computacional:** Asegurar un sistema 100% no bloqueante empleando una arquitectura basada en un *systick* de 1 ms y máquinas de estados finitos (FSM).
Desde el punto de vista pedagógico y de ingeniería de firmware, el objetivo primordial es validar una arquitectura *bare-metal* orientada a eventos, basada en un **ejecutor cíclico (*Super-Loop*) con base de tiempo de 1 ms y máquinas de estados finitos (*FSM*)**, garantizando cero tiempos de bloqueo computacional y alta predictibilidad temporal.

---

## 1.2 Productos comparables

En el mercado local e internacional existen diversas soluciones de robótica móvil de limpieza. El análisis de productos comparables permite contextualizar el valor de la arquitectura propuesta:

1. **Aspiradoras robóticas comerciales de entrada (ej. kits basados en microcontroladores de 8 bits o arquitecturas de recursos limitados):**
   * **Limitaciones:** Suelen implementar flujos secuenciales bloqueantes (uso de retardos por software para maniobras de giro o retroceso), lo que impide que el sistema responda a nuevos eventos críticos o comandos de usuario mientras ejecuta una maniobra. Carecen de telemetría en tiempo real accesible por el usuario o de modos de configuración local avanzados sin depender de redes externas. Un ejemplo de este esquema clásico se ilustra en la figura 1.1.

![Figura 1.1: Aspiradora robótica de entrada](/DIAGRAMAS/gama_entrada.png)

Figura 1.1: Representación de una plataforma de limpieza de entrada con arquitectura de recursos limitados y navegación reactiva.

2. **Aspiradoras robóticas comerciales de gama media/alta:**
   * **Características:** Integran conectividad Wi-Fi, mapeo por LIDAR (detección y medición por luz) o cámaras y control vía servicios en la nube.
   * **Diferenciación de nuestro proyecto:** Si bien estas soluciones comerciales poseen mayor complejidad de sensores de posicionamiento, presentan una alta dependencia de la infraestructura de red Wi-Fi y protocolos propietarios. Nuestro proyecto prioriza la robustez de un control local combinando una interfaz de usuario integrada (teclado matricial y display LCD) con un canal de comunicación Bluetooth directo, eliminando vulnerabilidades de red y garantizando operación autónoma aun en ausencia de conectividad exterior. La figura 1.2 muestra un ejemplo de este tipo de plataformas.

![Figura 1.2: Aspiradora robótica de gama media/alta](/DIAGRAMAS/gama_media_alta.png)

Figura 1.2: Plataforma comercial de gama alta equipada con torre LIDAR para mapeo y conectividad en la nube.

---

## 1.3 Justificación del enfoque técnico

La selección de las tecnologías de hardware y software para el desarrollo del prototipo se fundamenta en criterios de determinismo temporal, seguridad y modularidad:

* **Emulación de sensores mediante potenciómetros:** Para garantizar y facilitar la repetición de ensayos en un entorno seguro (sin introducir variables mecánicas incontrolables), se emuló el sensor de proximidad (Sharp IR) y el consumo en los motores de tracción (caída de tensión sobre una resistencia *shunt*) utilizando valores de potenciómetros entre 0 V y 3,3 V. Esto permite someter al firmware a condiciones extremas y saltos de umbral de manera controlada y medible.
* **Emulación de tracción mediante LEDs con modulación PWM:** El uso de canales PWM configurados en los temporizadores del STM32 sobre diodos LED permite verificar visualmente e instrumentalmente la variación proporcional de velocidad y sentido de avance de los motores izquierdo y derecho, preservando la integridad eléctrica del microcontrolador.
* **Conectividad Bluetooth clásico:** Se seleccionó un enlace UART asincrónico por Bluetooth por su facilidad de acoplamiento punto a punto y la ausencia de sobrecarga computacional de pilas de protocolo de red (como TCP/IP en Wi-Fi), permitiendo transmitir tramas de estado sin bloquear el lazo principal de control.


---

## 1.4 Alcance y limitaciones

### Alcance implementado
* **Control de marcha y evasión autónoma:** Algoritmo reactivo que controla la velocidad y dirección (adelante, retroceso y giro) de dos canales de motores independientes emulados por PWM.
* **Sistema de seguridad por sobrecorriente:** Monitoreo analógico por hardware (`ADC1`) con transición inmediata a un estado de falla segura.
* **Interfaz interactiva local:** Gestión completa de un menú *SET UP* mediante teclado matricial con filtrado antirrebote (*debounce*) de 50 ms y visualización en display LCD 16x2.
* **Telemetría inalámbrica:** Transmisión periódica asincrónica no bloqueante del estado operativo hacia una interfaz móvil vía módulo Bluetooth.
* **Avisos acústicos:** Reproducción de alarmas sonoras no bloqueantes mediante modulación de frecuencia y ciclo de trabajo en el periférico de hardware `TIM2` (buzzer piezoeléctrico).
* **Integración física robusta:** Montaje general consolidado en una placa de circuito impreso soldada, eliminando conexiones inestables de protoboard en la integración final.

### Limitaciones del prototipo
* **Sensores de entorno y motores físicos:** La navegación se evalúa sobre señales analógicas emuladas; la integración con motores de corriente continua reales y sensores infrarrojos ópticos queda definida para una fase de prototipado mecánica posterior.
* **Persistencia no volátil:** El almacenamiento de parámetros del menú *SET UP* se gestiona en memoria RAM durante el ciclo de operación, estando planificada la escritura en la memoria Flash interna o EEPROM externa como trabajo futuro.

---

# Capítulo 2: Introducción específica

## 2.1 Evolución y estado final de los requisitos

Durante la etapa inicial del proyecto (Informe de Avances, junio de 2026), se establecieron los requisitos funcionales organizados en cinco grupos principales. Algunos de estos requerimientos se encontraban bajo evaluación por su viabilidad de implementación en una arquitectura estrictamente no bloqueante. 

La tabla 2.1 detalla el enunciado original de cada requisito y su resolución final en el prototipo funcional.

Tabla 2.1: Trazabilidad desde el Informe de Avance hacia la implementación final. (Leyenda: 🟢 Implementado | ✅ Cumplido)
| ID | Descripción Original (Informe de Avance) | Estado Final | Resolución y Justificación en el Prototipo |
| :---: | :--- | :---: | :--- |
| **1.1** | El sistema leerá un sensor de aproximación vía ADC para detectar obstáculos físicos. | ✅ | **Implementado:** Emulado mediante potenciómetro en `ADC2` por interrupción. |
| **1.2** | El sistema monitoreará el consumo de motores emulado vía potenciómetros y ADC. | ✅ | **Implementado:** Adquisición continua mediante el canal `ADC1`. |
| **1.3** | El sistema leerá un Dip Switch al arrancar para determinar la configuración inicial. | ❌ | **Descartado:** Se reemplazó por un menú interactivo visual (SET UP) mucho más versátil operado desde el display LCD, eliminando la necesidad de hardware extra. |
| **1.4** | El sistema detectará las pulsaciones de un teclado 1x4 (vía interrupciones EXTI). | 🔄 | **Modificado:** Las interrupciones EXTI sufrían de rebotes mecánicos (*bouncing*). Se reemplazó por un escaneo GPIO coordinado por una Máquina de Estados con *debounce* de 50 ms. |
| **2.1** | Control de velocidad y sentido emulado modificando PWM sobre un juego de LEDs. | ✅ | **Implementado:** Operativo en los canales de los temporizadores `TIM3` y `TIM4`. |
| **2.2** | Activación de alarma acústica (Buzzer) ante consumo indebido en los motores. | ✅ | **Implementado:** Generación de señal PWM en `TIM2` sin bloquear el bucle principal. |
| **2.3** | Actualización periódica de un Display LCD 16x2 para reflejar estado y alarmas. | ✅ | **Implementado:** Se programó la actualización asincrónica carácter por carácter mediante una FSM dedicada en la capa de actuadores. |
| **3.1** | Persistencia no volátil en Memoria EEPROM externa vía I2C. | ❌ | **Postergado:** Se almacena en RAM temporalmente; EEPROM queda para trabajo futuro. |
| **3.2** | Recuperación y validación de configuración guardada al iniciar. | ❌ | **Postergado:** Queda a implementación futura del requisito 3.1. |
| **4.1** | Comunicación remota asincrónica vía Bluetooth HM-10. | 🔄 | **Modificado:** Se reemplazó el módulo HM-10 por un HC-06 debido a la disponibilidad de componentes, manteniendo la comunicación UART no bloqueante por interrupciones. |
| **4.2** | App móvil para visualizar el estado del vehículo en tiempo real. | ✅ | **Implementado:** La telemetría se transmite correctamente y es visualizable desde cualquier terminal Bluetooth serial en un dispositivo móvil. |
| **5.1** | Si el consumo supera el umbral, se interrumpe el PWM pasando al estado de FALLA. | ✅ | **Implementado:** Evasión instantánea en la capa de sistema al recibir el evento `EV_OVERCURRENT_DETECTED`. |

---

## 2.2 Casos de uso

A continuación se formalizan los cuatro casos de uso principales que definen la interacción entre el entorno físico, el usuario y el controlador embebido de la aspiradora.

### 2.2.1 Limpieza autónoma y evasión de obstáculos

La tabla 2.2 describe el ciclo normal de trabajo de la aspiradora y su respuesta reactiva ante la detección de un obstáculo en su trayectoria.

Tabla 2.2: Caso de uso 1 - Limpieza autónoma y evasión de obstáculos.
| Elemento | Definición |
| :--- | :--- |
| **Disparador** | El potenciómetro emulador del sensor frontal (`ADC2`) supera el umbral de proximidad calibrado. |
| **Precondiciones** | El sistema se encuentra en modo operativo `ST_SYS_NORMAL_CLEANING`, motores activos hacia adelante. |
| **Flujo básico** | 1. La tarea del sensor ADC detecta el umbral y publica el evento `EV_SYS_SENSOR_OBSTACLE`.<br>2. La FSM `task_system_normal_statechart` pasa al estado de evasión (`ST_SYS_NORMAL_AVOIDING`) iniciando la fase `PHASE_STOP` y enviando `EV_ACT_MOTORS_STOP`.<br>3. Por temporización de *tick*, avanza a `PHASE_REVERSE` emitiendo la orden `EV_ACT_MOTORS_REVERSE` durante 500 ms.<br>4. Expirado el tiempo, la FSM transiciona a la fase de giro (`PHASE_SPIN`) ordenando `EV_ACT_MOTORS_SPIN` durante 800 ms.<br>5. Finalizada la maniobra, el sistema retorna automáticamente a `ST_SYS_NORMAL_CLEANING`, ordenando `EV_ACT_MOTORS_FORWARD`. |
| **Alternativas** | Si durante cualquier fase de la evasión se detecta el evento `EV_SYS_FAULT_STALL` (sobrecorriente motriz), se cancela la maniobra, se salta a `ST_SYS_IDLE` y se transfiere el control al modo `FALLA`. |

---

### 2.2.2 Monitoreo de consumo y protección por sobrecorriente

La tabla 2.3 detalla el comportamiento del sistema ante un atasco mecánico de las ruedas que provoque un incremento excesivo en la corriente emulada de los motores.

Tabla 2.3: Caso de uso 2 - Monitoreo de consumo y protección por sobrecorriente.
| Elemento | Definición |
| :--- | :--- |
| **Disparador** | La señal analógica de consumo del *shunt* emulado (`ADC1`) excede el límite crítico configurado (2048). |
| **Precondiciones** | Sistema operando en `ST_SYS_NORMAL_CLEANING` o en medio de una evasión (`ST_SYS_NORMAL_AVOIDING`). |
| **Flujo básico** | 1. La tarea de adquisición lee `ADC1` y genera el evento de alarma hardware `EV_SYS_FAULT_STALL`.<br>2. El control se transfiere a la FSM `task_system_falla_statechart`, entrando en el estado enclavado `ST_SYS_FALLA_MAIN`.<br>3. Se emite `EV_ACT_MOTORS_STOP`, cortando instantáneamente las salidas PWM de todos los motores (`TIM3` y `TIM4`).<br>4. Se activa la alerta sonora mediante `buzzer_play_finish_melody()` y se reporta "ERR: SOBRECARGA" en el display LCD y la trama `BT_MSG_CARGA` vía Bluetooth. |
| **Alternativas** | El sistema permanece enclavado en la falla hasta que el operador elimina la obstrucción física y presiona el botón ENTER (`EV_SYS_ENTER`), lo que reconoce el error, limpia las variables y devuelve el sistema al modo `NORMAL`. |

---

### 2.2.3 Configuración y control local vía Menú SET UP

La tabla 2.4 formaliza la navegación del usuario por el menú interactivo para ajustar parámetros operativos y arrancar/pausar la aspiradora.

Tabla 2.4: Caso de uso 3 - Configuración y control local vía Menú SET UP.
| Elemento | Definición |
| :--- | :--- |
| **Disparador** | Pulsación física de las teclas de hardware (ENT, NEX, ESC, SET). |
| **Precondiciones** | El sistema arranca o es forzado al modo de configuración, iniciando la FSM `task_system_setup_statechart` en el estado `ST_SYS_IDLE`. |
| **Flujo básico** | 1. El usuario ingresa con ENTER (`EV_SYS_ENTER`) al estado `ST_SYS_MENU_1`.<br>2. Presionando NEXT (`EV_SYS_NEXT`), cicla entre las opciones de parámetros a modificar (MODO, POTENCIA, TIEMPO).<br>3. Al presionar ENTER de nuevo, desciende a `ST_SYS_MENU_2` para editar el valor de la variable seleccionada (ej. `val_modo`).<br>4. Confirma con ENTER para guardar (indicador "SAVED") o cancela con ESCAPE (`EV_SYS_ESCAPE`) para volver a `ST_SYS_MENU_1` sin aplicar cambios. |
| **Alternativas** | En cualquier estado del menú, al presionar el botón SET (`EV_SYS_SETUP_BTN`), la FSM aborta la configuración y retorna inmediatamente el control al modo `NORMAL`. Ruido en contactos es filtrado por la temporización máxima de *debounce* (`DEL_BTN_MAX`). |

---

### 2.2.4 Telemetría inalámbrica Bluetooth

La tabla 2.5 describe el reporte continuo y no bloqueante del estado operativo de la aspiradora hacia un terminal externo.

Tabla 2.5: Caso de uso 4 - Telemetría inalámbrica Bluetooth.
| Elemento | Definición |
| :--- | :--- |
| **Disparador** | Detección de un evento crítico o cambio de estado en la FSM del sistema (ej. `EV_SYS_SENSOR_OBSTACLE` o `EV_SYS_FAULT_STALL`) cuando la transmisión anterior ya finalizó (`g_bt_tx_complete == true`). |
| **Precondiciones** | Módulo Bluetooth HC-06 vinculado correctamente al puerto serial `USART3`. |
| **Flujo básico** | 1. La lógica principal emite comandos de publicación al detectar cambios (ej: `put_event_task_bluetooth(NULL, BT_MSG_CHOQUE)` o `BT_MSG_CARGA`).<br>2. Si el canal está libre (`g_bt_tx_complete == true`), `task_bluetooth_statechart` transiciona a `ST_BT_SEND_DATA`, bloquea el canal (`g_bt_tx_complete = false`) y dispara la interrupción de hardware con `HAL_UART_Transmit_IT`.<br>3. El *callback* `HAL_UART_TxCpltCallback`, ejecutado al finalizar el envío del último byte por hardware, vuelve a setear `g_bt_tx_complete = true`, permitiendo que la FSM retorne a `ST_BT_IDLE` y actualice el LED indicador (`GPIO_PIN_6`). |
| **Alternativas** | Si un evento intenta enviarse pero `g_bt_tx_complete` es `false` (UART ocupada), el evento se descarta o permanece encolado sin bloquear el temporizador *SysTick* de 1 ms, garantizando que los motores y sensores no sufran retardos. |

---
## 2.3 Descripción de módulos principales

La arquitectura de hardware del sistema se organiza alrededor del microcontrolador central en interconexión directa con cuatro subsistemas periféricos especializados. La forma en que se interconectan estos módulos se ilustra en la figura 2.1. A continuación se describen sus características principales:

![Diagrama de bloques](DIAGRAMAS/diagrama_en_bloques.png)  
Figura 2.1: Diagrama en bloques general del sistema y la interconexión de sus módulos principales.

### 2.3.1 Módulo de Control Central (NUCLEO-F103RB)
* **Función:** Es el núcleo de procesamiento computacional del prototipo. Ejecuta el planificador cíclico no bloqueante basado en la interrupción de *SysTick* (1 ms) y alberga la lógica de las máquinas de estado finitas (*FSM*).
* **Gestión:** Coordina las capas funcionales de firmware (ej. `task_sensor`, `task_system`, `task_actuator`, `task_bluetooth`) y administra la asignación de memoria RAM y Flash interna.

### 2.3.2 Módulo de Sensores Analógicos Emulados
* **Función:** Adquiere las magnitudes de variables físicas del entorno y mecánicas de la aspiradora.
* **Proximidad frontal:** Emulado por un potenciómetro conectado al canal analógico `ADC2`, representando la señal continua de un sensor Sharp IR para detección de obstáculos.
* **Consumo de corriente:** Emulado por un potenciómetro en `ADC1`, simulando la caída de tensión en una resistencia *shunt* de sensado de corriente de tracción de los motores.
* **Gestión:** Ambos canales analógicos se muestrean de forma asincrónica mediante interrupciones de hardware (`HAL_ADC_Start_IT`).

### 2.3.3 Módulo de Interfaz de Usuario Local (Teclado y Display LCD)
* **Función:** Provee la interfaz hombre-máquina (*HMI*) en el dispositivo para configuración, control y visualización de diagnósticos.
* **Teclado:** Arreglo de botones discretos leídos por GPIO digital para el ingreso de comandos interactivos (ENT, NEX, ESC, SET).
* **Display LCD 16x2:** Pantalla de cristal líquido compatible con controlador HD44780, conectada mediante interfaz de bus digital y gestionada por la máquina de estados `task_display`, la cual transmite de a un carácter por milisegundo para no bloquear la CPU.

### 2.3.4 Módulo de Actuadores de Tracción (LEDs PWM) y Alertas Acústicas
* **Función:** Simula físicamente el movimiento diferencial del robot y emite señales sonoras de notificación.
* **Tracción motriz:** Los canales `TIM3_CH1`/`TIM3_CH2` y `TIM4_CH1`/`TIM4_CH2` generan señales PWM cuya variación de ciclo de trabajo (*Duty Cycle*) se aplica sobre LEDs indicadores, representando avance frontal, retroceso y giro diferencial de las ruedas izquierda y derecha.
* **Avisos acústicos:** El temporizador `TIM2_CH1` genera señales de modulación PWM aplicadas sobre un buzzer piezoeléctrico para generar frecuencias audibles dinámicas (melodías de confirmación mediante `buzzer_play_finish_melody()` y alarmas de sobrecorriente).

### 2.3.5 Módulo de Comunicación Inalámbrica (Bluetooth)
* **Función:** Establece el canal de telemetría remota asincrónica hacia dispositivos externos (celular o terminal de monitoreo).
* **Implementación:** Módulo Bluetooth clásico HC-06 acoplado a las líneas de transmisión y recepción del puerto serie `USART3` del microcontrolador STM32. Opera de forma no bloqueante mediante interrupciones de hardware (`HAL_UART_Transmit_IT` y `HAL_UART_TxCpltCallback`), coordinado integralmente por la máquina de estados `task_bluetooth_statechart`.

--- 

# Capítulo 3: Diseño e implementación

## 3.1 Arquitectura general

El sistema se estructura bajo una arquitectura acoplada a eventos y orientada a tiempo real, dividiendo el dominio físico (hardware) del dominio lógico (firmware). La base de este diseño es el patrón arquitectónico de software no bloqueante, donde el flujo de información es estrictamente unidireccional y se divide en tres etapas fundamentales, tal como se ilustra en la figura 3.1.

![Diagrama de arquitectura de software](/DIAGRAMAS/diagrama_3_capas_unidirec.png)  
Figura 3.1: Diagrama de la arquitectura de software basada en eventos (Patrón Sensor-Sistema-Actuador).

Como se observa en la figura 3.1, la capa **Sensor** escruta las variables físicas o periféricos y publica eventos lógicos. La capa **Sistema** consume dichos eventos, evalúa su máquina de estados global y emite acciones de alto nivel. Finalmente, la capa **Actuador** traduce estas acciones en señales físicas hacia el hardware. Este desacople garantiza que el lazo principal (*Super-Loop*) pueda ejecutarse sin tiempos de bloqueo.

## 3.2 Diseño de hardware

Dado el enfoque pedagógico orientado a la arquitectura de firmware, se optó por emular los actuadores de potencia y ciertos sensores físicos, priorizando la robustez del código de control y la seguridad eléctrica en el banco de pruebas. 

La integración final se consolidó en una placa de circuito impreso soldada, eliminando el uso de protoboards y cables Dupont móviles para garantizar la estabilidad eléctrica frente a vibraciones mecánicas, como se ilustra en la figura 3.2 y la figura 3.3.

![Placa Soldada - Vista de cerca](DIAGRAMAS/placa_soldada_1.jpeg)  
Figura 3.2: Vista de cerca del montaje físico en placa soldada integrando el NUCLEO-F103RB y los periféricos.

![Placa Soldada - Vista](DIAGRAMAS/placa_soldada_2.jpeg)  
Figura 3.3: Vista general del montaje físico en placa soldada integrando el NUCLEO-F103RB y los periféricos.

### Asignación de pines y periféricos del STM32F103RB

La tabla 3.1 detalla la asignación de hardware, garantizando la independencia de los módulos para evitar colisiones:

Tabla 3.1: Pinout y periféricos del sistema.
| Componente Lógico / Físico | Instancia STM32 | Función del Periférico |
| :--- | :--- | :--- |
| Potenciómetro (Consumo) | `ADC1` | Conversión analógica por interrupción (IT) |
| Sensor Sharp IR (Obstáculos)| `ADC2` | Conversión analógica por interrupción (IT) |
| Motor Izquierdo (FWD / REV) | `TIM3_CH1` / `TIM3_CH2` | Generación de señales PWM |
| Motor Derecho (FWD / REV) | `TIM4_CH1` / `TIM4_CH2` | Generación de señales PWM |
| Buzzer | `TIM2_CH1` | Generación de tonos y melodías por PWM |
| Módulo Bluetooth HC-06 | `USART3` | Comunicación asincrónica por interrupciones (IT) |
| Teclado Matricial | `GPIO` | Entradas digitales con filtro antirrebote |
| Display LCD 16x2 | `GPIO` / `I2C` | Salidas digitales asincrónicas |

## 3.3 Diseño de firmware

El firmware fue diseñado bajo el paradigma de sistemas reactivos *Bare-Metal*. Queda estrictamente prohibido el uso de funciones bloqueantes (como `HAL_Delay()`) o bucles de espera activa. Toda la temporización se rige mediante una interrupción periódica del *Systick* configurada a **1 ms**.

### 3.3.1 Arquitectura en 3 capas
El flujo de ejecución es unidireccional, garantizando el desacople:
1. **Capa Sensor (`task_sensor`):** Escruta el hardware (ej. escaneo de matriz de botones con *debounce* de 50 ms por máquina de estados, o lectura de `ADC` por interrupción) y publica eventos limpios (ej. `EV_OBSTACLE_DETECTED`).
2. **Capa Sistema (`task_system`):** Consume los eventos, evalúa su máquina de estados global (transiciona entre `NORMAL`, `FAULT` y `SET UP`) y deposita órdenes de alto nivel para los actuadores. Al consumir un evento, su bandera (*flag*) se limpia inmediatamente fuera de las estructuras condicionales.
3. **Capa Actuador (`task_actuator`):** Traduce las órdenes lógicas del sistema en acciones de hardware (ej. reconfigura los registros `CCR` de los Timers para ajustar el PWM de los motores, o transmite caracteres al LCD por milisegundo).

### 3.3.2 Máquinas de Estados Finitos (Statecharts)

Cada módulo se implementó utilizando diagramas de estado (*Statecharts*), traducidos a C mediante estructuras `switch(state)` con evaluación de eventos vía `if/else if` y sentencias `break;` estrictas. La implementación de estos modelos se ilustra desde la figura 3.4 hasta la figura 3.8.

![Statechart - Filtro Antirrebote de Botones](DIAGRAMAS/statechart_button.jpg)  
Figura 3.4: FSM de filtro antirrebote (Debounce de 50 ms) en la capa Sensor.

![Statechart - System Normal](DIAGRAMAS/statechart_normal.jpeg)  
Figura 3.5: FSM de la capa Sistema durante el modo de operación Normal (Evasión).

![Statechart - System Falla](DIAGRAMAS/statechart_falla.jpeg)  
Figura 3.6: FSM de la capa Sistema durante el enclavamiento por Falla Crítica (Sobrecorriente).

![Statechart - System Setup](DIAGRAMAS/statechart_setup.jpeg)  
Figura 3.7: FSM del menú interactivo local de configuración (Setup).

![Statechart - Escritura de Display LCD](DIAGRAMAS/statechart_display.jpeg)  
Figura 3.8: FSM de la capa Actuador para refresco asincrónico del Display.

---

# Capítulo 4: Ensayos y resultados

## 4.1 Pruebas funcionales de hardware

Alineado con la estructura de validación de proyectos comparables, la tabla 4.1 resume los ensayos realizados sobre los componentes físicos emulados y periféricos.

Tabla 4.1: Ensayos funcionales de hardware.
| Ensayo | Resultado | Estado |
| :--- | :--- | :---: |
| **Validación de ADC (Proximidad y Consumo)** | Lectura correcta de los niveles de tensión emulados mediante los potenciómetros en los canales analógicos correspondientes. | ✅ |
| **Validación de PWM (Tracción)** | Variación correcta y visible del ciclo de trabajo sobre los LEDs direccionales (`TIM3`/`TIM4`) simulando el avance y retroceso. | ✅ |
| **Alertas acústicas** | Reproducción fluida de melodías acústicas en el buzzer piezoeléctrico comandado por temporizador de hardware (`TIM2`). | ✅ |

## 4.2 Pruebas funcionales de firmware

Los casos de prueba ejecutados validaron el comportamiento lógico y temporal de las máquinas de estado. La tabla 4.2 detalla los resultados obtenidos.

Tabla 4.2: Ensayos funcionales de firmware.
| Ensayo | Resultado | Estado |
| :--- | :--- | :---: |
| **Filtro antirrebote (Debounce)** | Se simularon pulsaciones ruidosas en el teclado matricial; la FSM filtró exitosamente los transitorios y emitió un único evento lógico tras 50 ms. | ✅ |
| **Evasión autónoma (Caso de Uso 1)** | Ante la variación del potenciómetro de proximidad, el sistema detuvo la tracción, ejecutó la fase de marcha atrás (500 ms) y giro (800 ms), retomando el avance. | ✅ |
| **Falla crítica (Caso de Uso 2)** | Se elevó el nivel de tensión del potenciómetro de consumo; el sistema transicionó al estado de falla, enclavando la seguridad hasta recibir la confirmación (ENTER). | ✅ |
| **Telemetría asincrónica** | Se comprobó la correcta transmisión de tramas vía Bluetooth sin afectar ni demorar la temporización del *SysTick*. | ✅ |

## 4.3 Pruebas de integración

Se validó la interacción completa del sistema conjugando el hardware y el firmware (evasión autónoma, falla por consumo, interfaz de usuario y telemetría Bluetooth) sin bloqueos de CPU. El funcionamiento completo del prototipo físico puede visualizarse en los siguientes enlaces:

* **Video Demostrativo (Parte 1):** [Enlace al video 1](https://drive.google.com/file/d/1ImlYVewvaIgjWdDmzIZxH56cVZUzW7G1/view?usp=drivesdk)
* **Video Demostrativo (Parte 2):** [Enlace al video 2](https://drive.google.com/file/d/1SKERN2DJHNzB4ahbBTDXgnLIgb7DQTnA/view?usp=drivesdk)

## 4.4 Medición y análisis de consumo

Para el análisis de consumo, se dimensionaron los requerimientos energéticos asumiendo la división de dos rieles principales:
* **Dominio Lógico (3,3 V):** Alimentación del MCU STM32F103RB y módulo Bluetooth. El consumo pico estimado se mantiene por debajo de los 100 mA durante la transmisión UART.
* **Dominio Periférico (5 V):** Display LCD (especialmente el backlight) y alimentación de sensores emulados.
* **Justificación de diseño:** En modo `ST_SYSTEM_FAULT`, la activación continua del buzzer piezoeléctrico incrementa el consumo transitorio. Sin embargo, al tratarse de PWM y no de corriente continua pura, la disipación térmica es manejable.

## 4.5 Console and Build Analyzer

Tras compilar la versión definitiva del firmware, se evaluó el consumo de recursos estáticos del microcontrolador STM32F103RB analizando la consola de compilación:

**Asignación de Memoria por Secciones (en bytes):**
* `.text` (Código ejecutable y constantes): **~29.800 bytes**
* `.data` (Variables globales inicializadas): **140 bytes**
* `.bss` (Variables globales sin inicializar): **~2.900 bytes**

**Ocupación por Regiones Físicas:**
* **Memoria FLASH Total Utilizada:** ~29.940 bytes (**22,84%** de 128 KB disponibles). *(Suma de .text y .data)*.
* **Memoria RAM Total Utilizada:** ~3.040 bytes (**14,84%** de 20 KB disponibles). *(Suma de .data y .bss)*.

El bajo consumo de RAM garantiza que no habrá desbordamientos de pila (*Stack Overflow*) incluso con interrupciones asincrónicas (EXTI, UART, ADC).

## 4.6 Medición y análisis de WCET por tarea

La medición de tiempos se realizó íntegramente por software utilizando el contador de ciclos del hardware interno **DWT (Data Watchpoint and Trace)** del núcleo ARM Cortex-M3. Los valores máximos (WCET) relevados tras someter el sistema a un test de estrés son:
* **Tarea Sensor (`task_sensor`):** 491 µs
* **Tarea de Control (`task_system`):** 52 µs
* **Tarea Actuador (`task_actuator`):** 12 µs

*Nota: La tarea dedicada a la interfaz visual (`task_display`) exige un tiempo de ejecución de 970 µs debido a la latencia de hardware intrínseca del protocolo de comunicación. Por razones de diseño arquitectónico, esta temporización se excluye de la métrica principal del lazo de control.*

**WCET del Lazo de Control Crítico:** 555 µs *(Sumatoria de los peores casos de Sensor, Sistema y Actuador).*

## 4.7 Cálculo del factor de uso de CPU (U)

Tomando la base de tiempo del *Systick* configurada a 1 ms (1000 µs), se calcula el factor de uso del lazo de control reactivo:

$$U = \left( \frac{555 \ \mu s}{1000 \ \mu s} \right) \times 100 = 55,5\%$$


**Análisis del resultado:**
El valor de $U =$ 55,5% demuestra un diseño holgadamente planificable. Indica que el procesador permanece ocioso (en espera del siguiente *tick*) el 44,5% del tiempo en el peor de los casos, garantizando la asimilación de eventos sin pérdidas y otorgando un amplio margen de procesamiento para futuras ampliaciones.

## 4.8 Gestión de bajo consumo y justificación

En esta etapa de prototipado, no se implementaron modos de bajo consumo explícitos del núcleo ARM (como `Sleep` o `Stop` con instrucción `WFI`), ya que el producto emula un sistema conectado a la batería principal de tracción, donde el consumo del microcontrolador es despreciable (< 1 W) frente al consumo de los motores mecánicos. Implementar rutinas `WFI` queda propuesto para una futura versión de la placa base donde la eficiencia del riel lógico sea crítica para el *stand-by*.

## 4.9 Cumplimiento de requisitos

La tabla 4.3 resume el estado final de cumplimiento de los requisitos propuestos en el Capítulo 2, reflejando las decisiones arquitectónicas definitivas, las modificaciones implementadas y los requerimientos postergados.

Tabla 4.3: Verificación de requisitos finales (🟢 Implementado / 🔴 No implementado / ✅ Cumplido / ❌ Descartado o Postergado).
| ID | Requisito (Estado Final) | Hardware | Software | Estado |
| :---: | :--- | :---: | :---: | :---: |
| **1.1** | Sensor de aproximación (Emulado por potenciómetro en `ADC2`) | 🟢 | 🟢 | ✅ |
| **1.2** | Monitoreo de consumo motriz (Emulado por potenciómetro en `ADC1`) | 🟢 | 🟢 | ✅ |
| **1.3** | Configuración inicial por Dip Switch | 🔴 | 🔴 | ❌ |
| **1.4** | Teclado interactivo GPIO (NEX, ENT, ESC, SET) con filtro antirrebote FSM | 🟢 | 🟢 | ✅ |
| **2.1** | Control de velocidad y sentido emulado por LEDs (PWM en `TIM3`/`TIM4`) | 🟢 | 🟢 | ✅ |
| **2.2** | Alarma acústica gestionada por temporizador de hardware (`TIM2`) | 🟢 | 🟢 | ✅ |
| **2.3** | Actualización de Display LCD 16x2 de forma asincrónica | 🟢 | 🟢 | ✅ |
| **3.1** | Persistencia no volátil en Memoria EEPROM externa vía I2C | 🔴 | 🔴 | ❌ |
| **3.2** | Recuperación y validación de configuración guardada al iniciar | 🔴 | 🔴 | ❌ |
| **4.1** | Comunicación remota asincrónica (Módulo Bluetooth HC-06 en `USART3`) | 🟢 | 🟢 | ✅ |
| **4.2** | Telemetría visualizable en terminal remoto / App móvil | 🟢 | 🟢 | ✅ |
| **5.1** | Enclavamiento instantáneo por evento de falla de sobrecorriente | 🟢 | 🟢 | ✅ |
| **6.1** | Arquitectura orientada a eventos estrictamente no bloqueante (1 ms) | 🟢 | 🟢 | ✅ |

## 4.10 Comparación con sistemas similares

En la tabla 4.4 se presenta una comparativa de características del sistema desarrollado frente a otras soluciones.

Tabla 4.4: Comparativa de características contra otras soluciones.
| Característica | Kits Básicos | Robots Comerciales Wi-Fi | Este Prototipo |
| :--- | :---: | :---: | :---: |
| **Arquitectura de Software** | Bloqueante (`delay()`) | RTOS / Linux Embebido | Reactiva *Bare-Metal* |
| **Interfaz Local Fija** | Nula / Escasa | Mínima (Botones LED) | Completa (LCD + Matrix) |
| **Tiempos de Respuesta** | Impredecibles | Alta latencia (Red) | Determinísticos (< 1ms) |
| **Protección Electromecánica** | Ausente | Por software interno | Reactiva por ADC directo |

## 4.11 Documentación del desarrollo realizado
Todo el código fuente, la configuración del CubeMX (`.ioc`), los modelos generados mediante Itemis Create, esquemas eléctricos y esta memoria técnica se encuentran versionados y disponibles en el repositorio GitHub de la entrega.

---

# Capítulo 5: Conclusiones

## 5.1 Resultados obtenidos
Se logró desarrollar y validar un Producto Mínimo Viable (PMV) para el controlador de una aspiradora inteligente. La implementación de una arquitectura no bloqueante en 3 capas, gobernada por *Systick* de 1 ms, permitió que el sistema evada obstáculos, envíe reportes vía Bluetooth, emita alarmas por PWM y refresque un display LCD, todo simultáneamente sin pérdida de eventos ni bloqueos de procesamiento.

## 5.2 Lecciones aprendidas
Desde el punto de vista de la ingeniería de firmware, la principal lección fue comprender la necesidad absoluta de erradicar los bucles de espera. Por ejemplo, modular la escritura del Display LCD o el *debounce* de botones mediante Máquinas de Estados Finitos demostró cómo sistemas complejos pueden compartir un mismo núcleo de procesamiento (Factor de Uso del 55,5%) manteniendo un ciclo temporal estricto.

## 5.3 Próximos pasos
Para la evolución del proyecto hacia un producto final, se proponen las siguientes mejoras:
1. Reemplazar los potenciómetros emuladores por módulos de puente H con resistencias shunt reales y sensores infrarrojos ópticos.
2. Implementar la escritura de la configuración del menú *SET UP* en la memoria EEPROM/Flash para lograr persistencia no volátil ante cortes de energía.
3. Implementar un gestor de modos *Low-Power* (Sleep Mode) en la capa de sistema para optimizar el consumo cuando el robot se encuentre inactivo.

---

# Capítulo 6: Uso de herramientas de IA

Durante el desarrollo de este trabajo se emplearon modelos de Inteligencia Artificial como asistentes técnicos (Gemini de Google) siguiendo la metodología recomendada por la cátedra. 

Se utilizó la IA para:
* Evaluar y explicar registros específicos del hardware del STM32 y el funcionamiento interno de bibliotecas HAL.
* Aportar soporte teórico en la estructura de los *Statecharts* (diagramas de estado) antes de la codificación.
* Revisar el flujo de ejecución no bloqueante de las funciones críticas escritas por el equipo.
* Ayudar en la estructuración semántica y revisión de estilo de esta memoria técnica, garantizando el cumplimiento de los lineamientos del Trabajo Final.

Es vital recalcar que toda la arquitectura, las decisiones de diseño, la programación empírica, el soldado del hardware y la validación instrumental en banco de pruebas fueron realizados y definidos íntegramente por los autores del trabajo.

---

# Capítulo 7: Bibliografía y referencias

1. STMicroelectronics, *UM1724 - STM32 Nucleo-64 boards user manual*.
2. STMicroelectronics, *MB1136 - Electrical Schematic - STM32 Nucleo-64 boards*.
3. STMicroelectronics, *STM32F103RB Datasheet* y *Reference Manual*.
4. Facultad de Ingeniería UBA, Cátedra TA134, *Guías de Trabajos Prácticos (TP1 a TP4)*.
5. Repositorio del proyecto: [Enlace al Repositorio de la Entrega Final en GitHub](https://github.com/lautaaguirre/tdse-tf_2026-1erC_1-01).