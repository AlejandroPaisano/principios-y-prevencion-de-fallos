# principios-y-prevencion-de-fallos
# introduccion
Este programa es una modificacion realizada a un programa viejo cuyo objetivo principal era el de simular la paginacion que hace un sistema operativo, las interrupciones que puede haber durante la ejecucion de los procesos, y su suspension por estar mucho tiempo en memoria.

En el caso de este programa, solo modificamos una pequeña parte para que la tecla b pueda guarda manualmente los procesos, y añadimos una condicional a su reloj para que se guarde de forma automatica cada 5  segundos.

# desarrollo
En este caso, el programa pide la introduccion de un numero de "procesos" asi como un quantum que se refire al tiempo maximo de ejecucion que un proceso puede tener. Una vez que se tiene esto, el programa funcionara de forma normal a la vez que crearemos nuestro archivo txt donde guardaremos la informacion.

![3](https://github.com/AlejandroPaisano/principios-y-prevencion-de-fallos/assets/91223611/ffc85c78-121b-43e8-88e6-03edf0db5c57)

Cada 5 segundos se escribe en un archivo .txt donde guarda la informacion basica de cada proceso introducido, ademas de guardar tambien la posicion que tiene el proceso en ese momento. Esto se logra mediante un if que nos confirma si han pasado 5 segundo desde el ultimo guardado, claro, esto se maneja por medio de un relok inerno del programa, para facilitarnos los problemas de medir el tiempo.
![2](https://github.com/AlejandroPaisano/principios-y-prevencion-de-fallos/assets/91223611/bf8483e0-3619-45a2-a6d3-e7d17521cee4)

Por ultimo esta el ultimo caso en el que se puede guardar la informacion del sistema, esto es gracias a presionar la tecla b, el sistema funciona de la misma forma que el contador de los 5 segundos, la unica diferencia notable seria el hecho de que se muestra mas informacion al presionar la b, esto por que en el programa original la b servia como un metodo para mostrar todos los procesos.![1](https://github.com/AlejandroPaisano/principios-y-prevencion-de-fallos/assets/91223611/e4d410af-7c8a-4e99-8f05-ec2a822f040b)


# conclusion
Construir un sistema que tenga la capacidad de sobrevivir a multiples formas de errores no solo es una tarea larga, tambien resulta estresante, mas en aspectos como revisar que la informacion se este guardando de la forma adecuada. Añadido a eso esta la capacidad de que alguien se robe nuestra informacion debido a que nuestro sistema sea facil de penetrar, sumado a que los daños causados podrian ser aun peores debido a que si no tuvieramos sistemas de guardado, perderiamos toda nuestra informacion.

Tambien debo decir que seria interesante conocer nuevas formas para proteger los sistemas, no solo de perdidas de memporia, si no tambien de problemas de hardware y de problemas originados por la incompatibilidades de sistemas que hayan quedado obsoltetos. Adicional a esto, debo decir que tuve varios problemas con el manejo de archivos, no por que fueran complicados, si no por que  perdi la preactica para trabajar con ellos 
