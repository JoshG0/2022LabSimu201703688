# Segundo Examen Parcial.
Dentro de esta carpeta se recoplian los ejercicios a correspondientes al sgundo examen parcial del laboratorio de Simulación. La sección de problemas que se desarrollan corresponde al carné con terminación 8. En este caso se realiza un programa que a partir de datos dados, se aplica el algoritmo de mínimos cuadrados para obtener una funcíon que refleje una aproximación del comportamiento de los datos. También se calcula una raiz de una función dada a través del método numérico de Newton Raphson. 

## Problema 1
Para este [problema](/Segundo_parcial/Parcial2_Eje1.c) aplicamos el método númerico de mínimos cuadrados el cual dados un conjunto de pares ordenados y una familia de funciones, se intenta encontrar la función continua, dentro de dicha familia, que mejor se aproxime a los datos, un "mejor ajuste", de acuerdo con el criterio de mínimo error cuadrático. Para aplicarlo, se relizó un experimento de ondas estacionarias con una cuerda, se compara la longitud de onda en función de la tensión de la cuerda y la frecuenca a la que está estaba vibrando que en este caso era de 60Hz; se realiza un programa que aplica el método numérico antes mencionado a los datos obtenidos y a su vez proporciona una gráfica que compara los valores obtenidos en el laboratorio con la recta que mejor aproxima el comportamiento a partir de los mismos datos obtenidos. Además se estima el valor de la densidad líneal  y la longitud de onda cuando la tensión aplicada a la cuerda sea de 6N.

El diagrama de flujo correspondiente a este problema es el siguiente: 

Variables de entrada y salida:
- ten: vector con los valores de las tensiones de la cuerda.
- ldo: longitud de onda en función de la tensión aplicada.
- er: incertidumbre de las mediciones.
- fre: frecuencia a la cual oscilaba la cuerda. 
- tsion: tensión a la cual se quiere estimar la longitud de onda. 
- n: tamaño de los vectores, varible de control.
- i: variable de conteo
- m: pendiente de la reca resultante.
- b: intersección del eje vertical de la recta resultante.
- deltam: incertidumbre de la pendiente m.
- deltab: incertidumbre de la intersección en el eje vertical
- r: coeficiente de correlación
- resp: almacenamiento para las iteraciones en las sumatorias. 
- datos: puntero del archivo donde se almacenan los datos del experimento.
- regresion: puntero del archivo donde se almacenan las isntrucciones para realizar la gráfica correspondiente.
- resultado: valor de la longitud de onda a una tensión determinada.

### Compilación
La forma de compilar y ejecutra el programa será:
```
$ gcc Parcial2_Eje1.c -o Parcial2_Eje1.out -lm
$ Parcial2_Eje1.out
```
