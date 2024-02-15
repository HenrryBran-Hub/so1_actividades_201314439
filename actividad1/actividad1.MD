![Actividad 1](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad1/Imagenes/img1.png)

# 1 
## Tipos de Kernel y sus diferencias :desktop_computer:

| Tipo de Kernel       | Descripción     | Ventajas        | Desventajas     | Ejemplos        | Otros puntos    |
|----------------------|-----------------|-----------------|-----------------|-----------------|-----------------|
|Monolítico| Es un sistema operativo en que el núcleo y los servicios del sistema operativo se ejecutan en el mismo espacio e memoria, todas sus funcionalidades(gestión de memoria, controladores etc.) residen en el Kernel.| Rendimiento eficiente debido a que la comunicación es directa.| Menor modularidad.| Linux, Windows, MacOS, FreeBSD| Menor sobrecarga entre módulos|
|Microkernel| En este solo las funciones esenciales del núcleo (gestión de memoria, gestión de comunicación etc.) residen en el Kernel. los servicios adicionales se ejecutan en modo usuario. | Mayor modularidad, menor riesgo a fallos. | Menor rendimiento, implementación más compleja| QNX, MINIX, Hurd. |Los servicios en el espacio del usuario mejoran la estabilidad. |
|Hibrido| Combina características de Kernel monolíticos y Microkernel. |Combinación de rendimiento y Modularidad. |Puede heredar las desventajas| Windows Nt, MacOS X, Solaris. |Equilibra rendimiento y modularidad|
|Exokernel | Delega funciones del sistema operativo al espacio del usuario, permitiendo mayor control sobre los recursos del hardware. |Alta flexibilidad y control para las aplicaciones, Eficiencia y optimización de recursos. |Mayor complejidad, Riesgo a incompatibilidad. | ExoOS, Nemesis. | Mayor control a las aplicaciones por delegación de políticas. |
|NanoKernel | Solo proporciona funciones esenciales, dejando la mayoría de funciones del sistema operativo a servicios externos. | Mínimo consumo de recursos, Mayor seguridad. | Menos funcionalidades integradas. | Sistemas embebidos, como Amoeba, RaOS, RadiOS, L4| Simplicidad y seguridad.|


---

# 2 
## :baby_chick: User vs :rooster: Kernel Mode

| ""Tipo de Kernel""       | User            | Kernel Mode     |
|----------------------|-----------------|-----------------|
|Ubicación en el CPU Kernel |Accesible al usuario |Accesible solo al Kernel |
|Permisos | Restringidos| Acceso completo a todos los recursos|
|Ejecución de código | Ejecuta aplicaciones y programas de usuario |Ejecuta el núcleo del sistema operativo|
|Interrupciones y excepciones |No puede manejar interrupciones del hardware | puede manejar interrupciones del hardware y excepciones|
|Capacidad para acceder a hardware |No pude realizar operaciones directas en el hardware |Si puede realizar operaciones directas en el hardware|
|Protección de memoria | Limitada por el sistema operativo y el hardware | Mayor protección debido a privilegios elevados|
|Tiempo de ejecución interrumpible | Puede ser interrumpido por el sistema operativo o eventos externos | Generalmente se ejecuta sin interrupciones|
|Ventajas|-Aislamiento de aplicaciones -Mayor estabilidad del sistema - Mayor seguridad debido a las restricciones de privilegios|-Acceso completo a los recursos del sistema -Mayor control y gestión del sistema -Capacidad para mejorar interrupciones|
|Desventajas|-Limitaciones en el acceso a recursos del sistema -Menor capacidad para realizar operaciones de bajo nivel directamente en el hardware|-Mayor riesgo de errores y fallos críticos -Mayor complejidad en el desarrollo de código de Kernel -Menor estabilidad si ocurre un error|
|Modos| También se conoce como modo no privilegiado, modo restringido o modo esclavo | También conocido como modo privilegiado modo maestro o modo sistema|
|Bloqueo del sistema | Un bloque se recupera simplemente reanudando la sesión | Es grave y complica las cosas|
|Referencias de memoria | Solo accede a la memoria asignada para su modo | Puede hacer referencias tanto a las áreas de memoria del modo usuario como del modo Kernel|


---

# 3 
## Interruptions :red_circle: vs Traps :yellow_circle:

|                      | Interruptions   | Traps           |
|----------------------|-----------------|-----------------|
|Definición |Es una señal al procesador emitida por el hardware que indica un evento que necesita atención inmediata |Es una señal proveniente de un programa de usuario que indica que el sistema operativo debe realizar alguna funcionalidad inmediatamente|
|Origen | Generadas por eventos externos o hardware. | Generadas por el propio programa en ejecución|
|causas | Eventos externos como temporizadores, dispositivos de entrada/salida | Instrucciones especificas en el código del programa|
|Manejo |Requiere un controlador de interrupciones para determinar la acción a tomar. puden cambiar el contexto de ejecución |Manejadas directamente por el sistema operativo | Pueden generar una excepción en el programa|
|Privilegios | pueden ocurrir en cualquier nivel de privilegio | Suelen ocurrir en modo usuario y se utilizan para transacciones controladas al modo Kernel |
|Ejemplos|-Interrupción de temporizador -Interrupción de disco -Interrupción de red|-División por cero -llamada al sistema -excepción de punto flotante|
|Uso común| Manejo de eventos externos, multitareas, eficiencia de recursos |Manejo de errores específicos del programa, llamadas al sistema|
|Ventajas |Permite manejar eficientemente eventos externos sin bloquear la ejecución - Mejora la multitarea y la eficiencia del sistema| -Facilita el manejo de errores y excepciones en el programa. -Proporciona un mecanismo controlado por transacciones al modo Kernel|
|Desventajas|-Puede introducir complejidad a la gestión del sistema. -Riesgo de errores debido a la necesidad de manejar múltiples interrupciones. |-Limitadas a eventos generados internamente por el programa.-No pueden manejar eventos externos|
