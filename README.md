# Control PID para un esterilizador

---

Se pretende implementar un control PID a un esterilizado con aireacción forzada marca Gemmyco. Actualmente, este equipo se encuentra averiado, por tal motivo se le retiró todos los componentes eléctricos y electrónicos para remplazarlos por una Arduino y una Rapsberry

Inicialmente la comunicación con este equipo se va a realizar a través de ssh, y sólo va incluir un interruptor (botón de encendido de la raspberry) como interfaz de hardware. 

Por el momento, se va a realizar de esta manera, por que no se cuenta con elelemetos electronicos (display, botones, resistores ...) para ampliar la interfaz de usuario.

* Especificaciones del Esterilizador: [YCO-N01(Digital)](https://github.com/josdanind/Esterilizador/blob/master/Documentacion/Especificaciones_Esterilizador.pdf)
