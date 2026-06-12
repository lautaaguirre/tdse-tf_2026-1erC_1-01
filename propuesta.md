<p align="left">
  <img src="logo_fiuba.png" width= 35%>
</p>


# **Propuesta de Trabajo Final: Aspiradora Inteligente**

<div align="left">
  <table style="border-collapse: collapse; width: 35%;">
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
        <td style="border: 1px solid #888; padding: 8px;">Maleh Magalí</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">112001</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Medina Mateo</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">111253</td>
      </tr>
    </tbody>
  </table>
</div>

**Fecha:** 1er Cuatrimestre 2026

---

### **1. Selección del proyecto a implementar**

#### **1.1 Objetivo del proyecto y resultados esperados**
El objetivo de este proyecto es diseñar e implementar un sistema embebido que emule la lógica de control de un vehículo de limpieza inteligente para interiores. Se busca que la arquitectura de firmware maneje la evasión autónoma de obstáculos y el monitoreo constante de los componentes para prevenir y solucionar fallas, a la vez que reporta su estado a una aplicación móvil y permite configurar sus parámetros a través de un menú interactivo y almacenamiento no volátil. 

Como resultado, se espera un prototipo funcional (Producto Mínimo Viable) estructurado en una arquitectura de módulos, manejado estrictamente por eventos (sin código bloqueante), optimizado para bajo consumo y con capacidad de transicionar de forma segura entre cuatro modos de operación fundamentales: Normal, Espera, Configuración y Falla.

#### **1.2 Proyectos similares**
En base al objetivo planteado por la cátedra, se proponen tres alternativas de implementación cuyo núcleo operativo sea el mismo pero difieran en prestaciones adicionales. A continuación, se detallan las opciones que serán sometidas a ponderación para seleccionar la más adecuada:

1. **Base (Aspiradora autónoma):** Sistema de control que emula la evasión autónoma de obstáculos, la gestión de modos de operación (Normal, Espera, Configuración, Falla) y el reporte de su estado general al usuario.
2. **Base + Control Manual:** Al sistema base se le suma la capacidad de recibir comandos de dirección desde una aplicación móvil, interrumpiendo la evasión autónoma para pasar a un control direccional estricto comandado por el usuario.
3. **Base + Retorno a Carga:** Al sistema base se le incorpora la lectura de sensores direccionales de luz para implementar una navegación reactiva. Ante una alerta simulada de "batería baja", el sistema transiciona a un estado de búsqueda para guiarse hacia una base emisora de luz.

Para comparar las alternativas mencionadas, se tienen en cuenta los siguientes aspectos:
* **Disponibilidad de hardware:** Evalúa si contamos con los componentes necesarios en el kit provisto o si es posible conseguirlos en tiendas cercanas sin depender de tiempos de envío que retrasen el proyecto.
* **Costo:** Pondera la necesidad de invertir dinero extra en módulos o actuadores adicionales fuera del presupuesto inicial.
* **Dificultad técnica:** Considera la complejidad de implementar la solución respetando la arquitectura de capas, el ruteo de eventos en la máquina de estados, la programación no bloqueante y el manejo de periféricos.
* **Tiempo de desarrollo:** Estima la cantidad de horas requeridas para codificar, depurar y estabilizar el firmware, teniendo en cuenta los deadlines estrictos de las entregas.
* **Valor agregado:** Analiza cuánto aporta cada variante a la funcionalidad general del prototipo y a la demostración de habilidades técnicas.
* **Interés personal del equipo:** Refleja la motivación por investigar y resolver los desafíos específicos que plantea cada alternativa.

A cada aspecto se le asigna un peso del 1 al 10:

<div align="center">
  <table style="border-collapse: collapse; width: 90%;">
    <thead>
      <tr>
        <th align="left" style="border: 1px solid #888; padding: 8px; font-weight: normal;">Aspecto</th>
        <th align="center" style="border: 1px solid #888; padding: 8px; font-weight: normal; width: 12%;">Peso</th>
        <th align="left" style="border: 1px solid #888; padding: 8px; font-weight: normal;">Justificación</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Tiempo de desarrollo</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">10</td>
        <td style="border: 1px solid #888; padding: 8px;">Cronograma acotado, sumándole que pueden surgir complicaciones.</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Dificultad técnica</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">9</td>
        <td style="border: 1px solid #888; padding: 8px;">Trabajando por primera vez con código 100% no bloqueante e interrupciones.</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Disponibilidad de hardware</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">8</td>
        <td style="border: 1px solid #888; padding: 8px;">No podemos detener el desarrollo por no conseguir los materiales necesarios.</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Costo</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">6</td>
        <td style="border: 1px solid #888; padding: 8px;">Se busca maximizar el uso del kit actual sin gastos excesivos.</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Valor agregado</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">7</td>
        <td style="border: 1px solid #888; padding: 8px;">Es importante mostrar un buen sistema, pero priorizando siempre cumplir con los requisitos obligatorios primero.</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Interés personal</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">4</td>
        <td style="border: 1px solid #888; padding: 8px;">La motivación es clave, pero lo más importante es la disciplina y compromiso.</td>
      </tr>
    </tbody>
  </table>
</div>

<p align="center"><em>Tabla 1: Ponderación de aspectos de evaluación</em></p>

La siguiente tabla muestra los valores ponderados asignados a cada alternativa de proyecto:

<div align="center">
  <table style="border-collapse: collapse; width: 100%;">
    <thead>
      <tr>
        <th rowspan="2" align="left" style="border: 1px solid #888; padding: 8px; font-weight: normal;">Aspecto</th>
        <th colspan="2" align="center" style="border: 1px solid #888; padding: 8px; font-weight: normal;">Proyecto base</th>
        <th colspan="2" align="center" style="border: 1px solid #888; padding: 8px; font-weight: normal;">Base + control manual</th>
        <th colspan="2" align="center" style="border: 1px solid #888; padding: 8px; font-weight: normal;">Base + retorno a carga</th>
      </tr>
      <tr>
        <th align="center" style="border: 1px solid #888; padding: 8px; font-weight: normal;">Puntaje</th>
        <th align="center" style="border: 1px solid #888; padding: 8px; font-weight: normal;">Puntaje ponderado</th>
        <th align="center" style="border: 1px solid #888; padding: 8px; font-weight: normal;">Puntaje</th>
        <th align="center" style="border: 1px solid #888; padding: 8px; font-weight: normal;">Puntaje ponderado</th>
        <th align="center" style="border: 1px solid #888; padding: 8px; font-weight: normal;">Puntaje</th>
        <th align="center" style="border: 1px solid #888; padding: 8px; font-weight: normal;">Puntaje ponderado</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Tiempo de desarrollo</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">9</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">90</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">8</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">80</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">7</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">70</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Dificultad técnica</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">9</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">81</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">7</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">63</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">6</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">54</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Disponibilidad HW</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">10</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">80</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">10</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">80</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">8</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">64</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Costo</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">10</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">60</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">10</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">60</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">8</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">48</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Valor agregado</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">7</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">49</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">8</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">56</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">9</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">63</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Interés personal</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">7</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">28</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">7</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">28</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">8</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">32</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Puntaje total</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">-</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;"><b>388</b></td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">-</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;"><b>367</b></td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">-</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;"><b>331</b></td>
      </tr>
    </tbody>
  </table>
</div>

<p align="center"><em>Tabla 2: Matriz de decisión ponderada</em></p>

#### **1.3 Selección de proyecto**
Vistas las consideraciones tomadas en cuenta en la matriz de decisión, se resolvió avanzar con el desarrollo del Proyecto Base. Al momento de ponderar los aspectos, se hizo un fuerte hincapié en el tiempo de desarrollo y en la dificultad técnica. Si bien las alternativas que incluían control manual o retorno a la base de carga ofrecían un mayor valor agregado e interés personal, el Proyecto Base demostró ser la opción más sólida y segura para garantizar un Producto Mínimo Viable (MVP) funcional dentro de los plazos estrictos de la cursada. 

De esta forma, el proyecto a desarrollar consists en un prototipo embebido que emula la lógica de un vehículo de limpieza inteligente, centrándose en la evasión autónoma de obstáculos y el monitoreo de consumo de los motores, y actuando mediante señales PWM para la dirección diferencial, alarmas acústicas (buzzer) y visualización en un display LCD. Todo esto va a funcionar a la par de una configuración activa de modos (Normal, Espera, Configuración, Falla) llevada a cabo por el usuario a través de un menú interactivo y el reporte de estado mediante una aplicación Bluetooth. 

En la Figura 1 se observa el diagrama en bloques del mecanismo completo separado por los módulos más importantes (UART, I2C, ADC, GPIO y PWM).

<p align="center">
  <img src="diagrama_en_bloques.png" alt="Diagrama en Bloques de la Arquitectura">
</p>
<p align="center"><em>Figura 1: Diagrama en bloques del sistema</em></p>

---

### **2. Elicitación de requisitos y casos de uso**

En el mercado actual de electrodomésticos inteligentes, existen cada vez más opciones a la hora de elegir una aspiradora inteligente, como pueden ser los productos comerciales de marcas internacionales (SmartLife, Gadnic, Xiaomi, entre otros) o alternativas nacionales (Atma, Liliana). Sin embargo, todas estas variantes son sistemas cerrados pensados para un usuario final. Debido a esto, no permiten con facilidad a los desarrolladores (o estudiantes en nuestro caso) acceder al bajo nivel para revisar o configurar a propio gusto y decisión. Por otro lado, si el mismo desarrollador quisiera replicar o poner en marcha su propio producto, encontraría grandes dificultades en infraestructura y costos; cambiando el foco del verdadero propósito: la lógica de los sistemas embebidos.

En conclusión, si bien existen una amplia variedad de aspiradoras inteligentes en el mercado, no se dispone de una solución orientada al desarrollo y aprendizaje combinando: sistema disparado por eventos, gestión de fallas, elaboración de código no bloqueante y una arquitectura bare-metal abierta. Esto posiciona a nuestro proyecto como una propuesta ideal para un entorno académico, al implementar un prototipo sin contar con componentes mecánicos o electrónicos costosos, sino replicando su comportamiento con alternativas de bajo costo; disminuyendo a su vez tiempos de desarrollo.

A continuación, se presenta la matriz detallada de requisitos funcionales y operativos del sistema. En ella se clasifican y numeran las especificaciones técnicas que debe cumplir el firmware, abarcando desde la adquisición de datos en la capa de sensores hasta el manejo según corresponda en la capa de actuadores, garantizando así una operación secuencial y segura.

<div align="center">
  <table style="border-collapse: collapse; width: 100%;">
    <thead>
      <tr>
        <th align="left" style="width: 20%; border: 1px solid #888; padding: 8px; font-weight: normal;">Grupo</th>
        <th align="center" style="width: 8%; border: 1px solid #888; padding: 8px; font-weight: normal;">ID</th>
        <th align="left" style="border: 1px solid #888; padding: 8px; font-weight: normal;">Descripción</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td rowspan="4" valign="top" style="border: 1px solid #888; padding: 8px;">Entradas / Sensores</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">1.1</td>
        <td style="border: 1px solid #888; padding: 8px;">El sistema leerá periódicamente un sensor de aproximación vía ADC para detectar obstáculos físicos.</td>
      </tr>
      <tr>
        <td align="center" style="border: 1px solid #888; padding: 8px;">1.2</td>
        <td style="border: 1px solid #888; padding: 8px;">El sistema monitoreará continuamente el consumo eléctrico de los motores emulado a través de potenciómetros conectados al ADC.</td>
      </tr>
      <tr>
        <td align="center" style="border: 1px solid #888; padding: 8px;">1.3</td>
        <td style="border: 1px solid #888; padding: 8px;">El sistema leerá un Dip Switch durante el arranque para determinar la configuración inicial de hardware.</td>
      </tr>
      <tr>
        <td align="center" style="border: 1px solid #888; padding: 8px;">1.4</td>
        <td style="border: 1px solid #888; padding: 8px;">El sistema detectará las pulsaciones de un teclado 1x4 (vía interrupciones EXTI) para permitir la navegación local a través de los menús.</td>
      </tr>
      <tr>
        <td rowspan="3" valign="top" style="border: 1px solid #888; padding: 8px;">Salidas / Actuadores</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">2.1</td>
        <td style="border: 1px solid #888; padding: 8px;">El sistema controlará la velocidad y sentido de giro emulado modificando el ciclo de trabajo PWM sobre un juego de LEDs.</td>
      </tr>
      <tr>
        <td align="center" style="border: 1px solid #888; padding: 8px;">2.2</td>
        <td style="border: 1px solid #888; padding: 8px;">El sistema activará una alarma acústica (Buzzer) si detecta un consumo indebido en los motores emulados.</td>
      </tr>
      <tr>
        <td align="center" style="border: 1px solid #888; padding: 8px;">2.3</td>
        <td style="border: 1px solid #888; padding: 8px;">El sistema actualizará periódicamente un Display LCD 16x2 (vía I2C) para reflejar estado, alarmas y opciones del menú.</td>
      </tr>
      <tr>
        <td rowspan="2" valign="top" style="border: 1px solid #888; padding: 8px;">Almacenamiento</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">3.1</td>
        <td style="border: 1px solid #888; padding: 8px;">La configuración del sistema (umbrales y modos) se persistirá de forma no volátil en una Memoria EEPROM externa vía I2C.</td>
      </tr>
      <tr>
        <td align="center" style="border: 1px solid #888; padding: 8px;">3.2</td>
        <td style="border: 1px solid #888; padding: 8px;">El sistema recuperará y validará la configuración guardada al iniciar; de lo contrario, cargará valores seguros por defecto.</td>
      </tr>
      <tr>
        <td rowspan="3" valign="top" style="border: 1px solid #888; padding: 8px;">Interfaz y App</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">4.1</td>
        <td style="border: 1px solid #888; padding: 8px;">Toda comunicación remota se realizará mediante tramas asincrónicas (UART) a través del módulo Bluetooth HM-10.</td>
      </tr>
      <tr>
        <td align="center" style="border: 1px solid #888; padding: 8px;">4.2</td>
        <td style="border: 1px solid #888; padding: 8px;">La aplicación móvil permitiría al usuario visualizar el estado del vehículo en tiempo real.</td>
      </tr>
      <tr>
        <td align="center" style="border: 1px solid #888; padding: 8px;">4.3</td>
        <td style="border: 1px solid #888; padding: 8px;">El sistema permitirá detener temporalmente la marcha remota al recibir un comando de pausa vía Bluetooth, modificando el estado lógico del microcontrolador.</td>
      </tr>
      <tr>
        <td valign="top" style="border: 1px solid #888; padding: 8px;">Operación Segura</td>
        <td align="center" style="border: 1px solid #888; padding: 8px;">5.1</td>
        <td style="border: 1px solid #888; padding: 8px;">Si el consumo supera el umbral de seguridad, el sistema interrumpirá el PWM (frenado total), pasando al estado de FALLA.</td>
      </tr>
    </tbody>
  </table>
</div>

<p align="center"><em>Tabla 3: Requisitos funcionales del sistema</em></p>

---

### **2.1 Casos de Uso**

Con el objetivo de modelar de forma dinámica y estructurada el comportamiento de la máquina de estados ante las entradas del entorno, se definen a continuación los casos de uso principales del prototipo. Estas descripciones permiten visualizar cómo interactúan las capas de software frente a distintas situaciones, especificando los disparadores, las precondiciones requeridas, el flujo secuencial de tareas no bloqueantes y las acciones correctivas ante flujos alternativos o fallas.

<div align="center">
  <table style="border-collapse: collapse; width: 100%;">
    <tbody>
      <tr>
        <th align="left" style="width: 20%; border: 1px solid #888; padding: 8px; font-weight: normal;">Elemento</th>
        <td style="border: 1px solid #888; padding: 8px;">Definición</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Disparador</td>
        <td style="border: 1px solid #888; padding: 8px;">El sensor de proximidad (LDR) detecta un cambio e indicando la presencia inminente de un obstáculo físico.</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Precondiciones</td>
        <td style="border: 1px solid #888; padding: 8px;">El sistema se encuentra en <code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">MODO_NORMAL</code> y los actuadores de tracción operan en sentido de avance (PWM constante).</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Flujo principal</td>
        <td style="border: 1px solid #888; padding: 8px;">
          1. La capa <code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">task_sensor</code> procesa la lectura del ADC y, al superar el umbral de detección, levanta un evento de obstáculo.<br>
          2. La máquina de estados en <code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">task_system</code> consume el evento y ejecuta la rutina de evasión.<br>
          3. Se emite la orden a <code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">task_actuator</code> para modificar la velocidad de un motor (modificando el PWM) y simular un giro.<br>
          4. Un temporizador no bloqueante indica el fin del giro y el sistema retorna al avance rectilíneo.
        </td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Flujos alternativos</td>
        <td style="border: 1px solid #888; padding: 8px;">a. Obstáculo persistente (Atrapamiento): Si tras ejecutar el giro el sensor sigue detectando el obstáculo continuamente, el sistema repite la maniobra de evasión con un ángulo mayor o transiciona a estado de error.</td>
      </tr>
    </tbody>
  </table>
</div>

<p align="center"><em>Tabla 4: Caso de Uso 1 - Operación normal y evasión autónoma</em></p>

<br>

<div align="center">
  <table style="border-collapse: collapse; width: 100%;">
    <tbody>
      <tr>
        <th align="left" style="width: 20%; border: 1px solid #888; padding: 8px; font-weight: normal;">Elemento</th>
        <td style="border: 1px solid #888; padding: 8px;">Definición</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Disparador</td>
        <td style="border: 1px solid #888; padding: 8px;">El nivel de tensión medido por el ADC (simulando consumo del motor) supera el umbral máximo de seguridad.</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Precondiciones</td>
        <td style="border: 1px solid #888; padding: 8px;">El sistema se encuentra operativo, ya sea en marcha (<code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">MODO_NORMAL</code>) o detenido temporalmente (<code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">MODO_ESPERA</code>).</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Flujo principal</td>
        <td style="border: 1px solid #888; padding: 8px;">
          1. La capa <code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">task_sensor</code> detecta la medición con valores indebidos y levanta un evento de sobrecorriente.<br>
          2. La máquina de estados en <code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">task_system</code> consume el evento y transiciona a <code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">MODO_FALLA</code>.<br>
          3. Se emite la orden a <code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">task_actuator</code> de llevar el PWM a 0% (frenado total) y encender el Buzzer.<br>
          4. Se envía una notificación de error vía Bluetooth a la App.
        </td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Flujos alternativos</td>
        <td style="border: 1px solid #888; padding: 8px;">a. Falla en el ADC (lectura errática inestable): Por redundancia de seguridad, tras X lecturas fallidas, el sistema asume estado de falla preventivo.</td>
      </tr>
    </tbody>
  </table>
</div>

<p align="center"><em>Tabla 5: Caso de Uso 2 - Detección de fallas</em></p>

<br>

<div align="center">
  <table style="border-collapse: collapse; width: 100%;">
    <tbody>
      <tr>
        <th align="left" style="width: 20%; border: 1px solid #888; padding: 8px; font-weight: normal;">Elemento</th>
        <td style="border: 1px solid #888; padding: 8px;">Definición</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Disparador</td>
        <td style="border: 1px solid #888; padding: 8px;">El usuario presiona el botón "Menú" en el teclado matricial 1x4.</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Precondiciones</td>
        <td style="border: 1px solid #888; padding: 8px;">El sistema se encuentra operativo en <code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">MODO_NORMAL</code> o <code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">MODO_ESPERA</code>.</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Flujo principal</td>
        <td style="border: 1px solid #888; padding: 8px;">
          1. Se detecta la interrupción (EXTI) y se levanta el evento de botón.<br>
          2. La máquina de estados consume el evento, ordena detener los motores (PWM = 0% si venía en movimiento) y transiciona a <code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">MODO_SETUP</code>.<br>
          3. El LCD muestra las opciones; el usuario navega con los botones direccionales y confirma con "Enter".<br>
          4. El nuevo parámetro se escribe en la EEPROM vía I2C.<br>
          5. El sistema retorna al modo de operación previo.
        </td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Flujos alternativos</td>
        <td style="border: 1px solid #888; padding: 8px;">a. Timeout de inactividad: Si no se presiona ningún botón durante X segundos, el sistema cancela los cambios y sale del menú automáticamente, retomando el estado anterior.</td>
      </tr>
    </tbody>
  </table>
</div>

<p align="center"><em>Tabla 6: Caso de Uso 3 - Configuración por menú interactivo</em></p>

<br>

<div align="center">
  <table style="border-collapse: collapse; width: 100%;">
    <tbody>
      <tr>
        <th align="left" style="width: 20%; border: 1px solid #888; padding: 8px; font-weight: normal;">Elemento</th>
        <td style="border: 1px solid #888; padding: 8px;">Definición</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Disparador</td>
        <td style="border: 1px solid #888; padding: 8px;">Se recibe un comando de "Pausa / Reanudar" vía aplicación móvil (Bluetooth), o el usuario presiona el botón físico asignado en el teclado matricial.</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Precondiciones</td>
        <td style="border: 1px solid #888; padding: 8px;">El sistema debe estar en <code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">MODO_NORMAL</code> (para poder pausar) o en <code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">MODO_ESPERA</code> (para reanudar). Para el uso remoto, el módulo HM-10 debe tener un enlace activo.</td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Flujo principal</td>
        <td style="border: 1px solid #888; padding: 8px;">
          1. La capa correspondiente (<code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">task_sensor</code> vía UART, o interrupción EXTI vía botón) detecta la orden y levanta el evento de pausa/reanudación.<br>
          2. Si se recibe "Pausa" en <code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">MODO_NORMAL</code>, la máquina de estados ordena apagar la tracción (PWM = 0%) y cambia a <code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">MODO_ESPERA</code>.<br>
          3. El display LCD actualiza la interfaz local reflejando el mensaje estático "Pausado".<br>
          4. Al recibir "Reanudar" estando en <code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">MODO_ESPERA</code>, el sistema restablece la marcha cíclica y retorna de forma directa a <code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">MODO_NORMAL</code>.
        </td>
      </tr>
      <tr>
        <td style="border: 1px solid #888; padding: 8px;">Flujos alternativos</td>
        <td style="border: 1px solid #888; padding: 8px;">a. Pérdida crítica de enlace inalámbrico: Si el microcontrolador detecta una desconexión abrupta del Bluetooth mientras limpia en <code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">MODO_NORMAL</code>, fuerza de forma preventiva el PWM a 0% y transiciona automáticamente a <code style="background-color: rgba(128,128,128,0.15); padding: 2px 4px; border-radius: 3px;">MODO_ESPERA</code> por seguridad.</td>
      </tr>
    </tbody>
  </table>
</div>

<p align="center"><em>Tabla 7: Caso de Uso 4 - Pausa y reanudación de operación (Remota/Local)</em></p>