![Actividad 1](https://github.com/HenrryBran-Hub/so1_actividades_201314439/blob/main/actividad1/Imagenes/img1.png)

#1 
## Tipos de Kernel y sus diferencias

| Tipo de Kernel       | Descripción     | Ventajas        | Desventajas     | Ejemplos        | Otros puntos    |
|----------------------|-----------------|-----------------|-----------------|-----------------|-----------------|
|Monolítico|Es un sistema operativo en que el núcleo y los servicios del sistema operativo se ejecutan en el mismo espacio e memoria, todas sus funcionalidades(gestion de memoria, controladores etc.) residen en el kernel.|Rendimiento eficiente debido a que la comunicacion es directa.|Menor modularidad.|Linux, Windows, MacOS, FreeBSD|Menor sobrecarga entre módulos|
|Microkernel|En este solo las funciones esenciales del núcleo(gestión de memoria, gestion de comunicación etc.) residen en el kernel. los servicios adicionales se ejecutan en modo usuario.|Mayor modularidad, menor riesgo a fallos|Menor rendimiento, implementacion mas compleja| QNX, MINIX,Hurd|Los servicios en el espacio del usuario mejoran la estabilidad.|
|Hibrido|Combina caracteristicas de kernels monoliticos y microkernels|Combinacion de rendimiento y Modularidad|Puede heredar las desventajas|Windows Nt, MacOS X, Solaris|Equilibra rendimiento y modularidad|
|Exokernel|Delega funciones del sistema operativo al espacio del usuario, permitiendo mayor control sobre los recursos del hardware|Alta flexibilidad y control para las aplicaciones, Eficiencia y optimizacion de recursos|Mayor complejidad, Riesgo a incompatibilidad|ExoOS,Nemesis|Mayor control a las aplicaciones por delegacion de politicas|
|NanoKernel|Solo proporciona funciones esenciales, dejando la mayoria de funciones del sistema operativo a servicos externos.|Minimo consumo de recursos,Mayor seguridad|Menos funcionalidades integradas|Sistemas embebidos, como Amoeba, RaOS, RadiOS,L4|Simplicidad y seguridad|


#2 
## User vs Kernel Mode

| Tipo de Kernel       | User            | Kernel Mode     |
|----------------------|-----------------|-----------------|
|Ubicacion en el CPU kernel|Accesible al usuario |Accesible solo al kernel|
|Permisos|Restringidos|Acceso completo a todos los recursos|
|Ejecucion de codigo|Ejecuta aplicaciones y programas de usuairo|Ejecuta el nucleo del sistema operativo|
|Interrupciones y exepciones|No puede manejar interrupciones del hardware|pude manejar interrupciones del hardware y excepciones|
|Capacidad para acceder a hardware|No pude realizar operaciones directas en el hardware|Si puede realizar operaciones directas en el hardware|
|Proteccion de memoria|Limitada por el sistema operativo y el hardware|Mayor proteccion debido a privilegios elevados|
|Tiempo de ejecucion interrumpible|Puedeser interrumpido por el sistema opertavio o enetos externos|Generalmente se ejecuta sin interrupciones|
|Ventajas|-Aislamiento de aplicaciones -Mayor estabilidad del sistema - Mayor seguridad debido a las restricciones de privilegios|-Acceso completo a los recursos del sistema -Mayor control y gestion del sistema -Capacidad para mejorar interrupciones|
|Desventajas|-Limitaciones en el acceso a recursos del sistema -Menor capacidad para realizar operaciones de bajo nivel directamente en el hardware|-Mayor riesgo de errores y fallos criticos -Mayor complejidad en el desarrollo de codigo de kernel -Menor estabilidad si ocurre un error|
|Modos|Tambien se conoce como modo no priviligeado,modo restringido o modo esclavo|Tambien conocido como modo privilegiado modo maestro o modo sistema|
|Bloqueo del sistema|un bloque se recupera simplemente reanudando la sesion|Es grave y complica las cosas|
|Referencias de memoria|Solo accede a la memoria asignada para su modo|Puede hacer referencias tanto a las areas de memoria del modo usuario como del modo kernel|


#3 
## Interruptions vs Traps

|                      | Interruptions   | Traps           |
|----------------------|-----------------|-----------------|
|Definicion|Es una señal al procesador emitida por el hardware que indica un evento que necesita atencion inmediata|Es una señal proviniente de un programa de usuario qu eindica que el sistema operativo dbe realizar alguna funcionalidad inmediatamente|
|Origen|Generadas por eventos externos o hardware.|Generadas por el propio programa en ejecucion|
|causas|Eventos externos como temporizadores, dispositivos de entrada/salida | Instrucciones especificas en el codigo del programa|
|Manejo |Requiere un controlador de interrupciones para determinar la accion a tomar. puden cambiar el contexto de ejecucion|Manejadas directametne por el sistema operativo|Pueden generar una excepcion en el programa|
|Privilegios|puden ocurrir en cualquier nivel de privilegio|Suelen ocurrir en modo usuario y se utilizan para transacciones controladas al modo kernel|
|Ejemplos|-Interrupcion de temporizador -Interrupcion de disco -Interrupcion de red|-Division por cero -llamada al sistema -excepcion de punto flotante|
|Uso comun| Manejo de eventos externos, multitareas, eficiencia de recursos|Manejo de errores especificos del programa, llamadas al sistema|
|Ventajas|Permite manejar eficientemente eventos externos sin bloquear la ejecucion - Mejora la multitarea y la eficiencia del sistema| -Facilita el manejo de errores y excepciones en el programa. -Proporciona un mecanismo controlado por transacciones al modo kernel|
|Desventajas|-Puede introducir complejidad a la gestion del sistema. -Riesgo de errores debido a la necesidad de manejar multiples interrupciones.|-Limitadas a eventos generados internamente por el programa.-No pueden manejar eventos externos|