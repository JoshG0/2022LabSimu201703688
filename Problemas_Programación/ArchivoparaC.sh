#!/bin/bash     

#Autor:      Josué Gómez
#Tipo:       Script de Bash
#Se ejecuta: ./ArchivoparaC.sh
#Resumen:    Este es un generador automático  de comentarios para scripts de C

#INTERACCIÓN CON EL USARIO, OBTENCIÓN DE DATOS

echo ""
echo "             * **|  GENERADOR DE COMENTARIOS PARA ESCRIPTS DE C  |** *         " 
echo ""
read -p "Ingrese el nombre para su archvo: " nombre  
fnombre=$nombre".c" 
#validación del nombre del archivo, para que no se cree un
#archivo vacio.
if [ -z $nombre ]; then 
   echo "¡Este espacio no puede quedar en blanco!"
   echo "--Ejecute nuevamenten el programa--"
   echo ""
   exit 2
fi 
#para finalizar if, utilizamos if


echo "Escriba un resumen del funcionamiento de su script: "
read resumen
echo "Entrada: "
read entrada
echo "Salida: "
read salida 

#información del sistema, creación de variables
fecha=$(date)
version=$(gcc --version | head -n 1)

#creando el contenido:
echo "/*" > $fnombre  
echo "Autor:      Josué Gómez" >> $fnombre
echo "Compilador:   " $version >> $fnombre
#cómo se guardará el archivo y como se compilará
echo "Compilado:    " gcc $fnombre -o $nombre".out" >> $fnombre 
echo "Fecha:        " $fecha >> $fnombre 
echo "Librerias:    stdio (u otras)" >> $fnombre
echo "Resumen:      " $resumen >> $fnombre
echo "Entada:       " $entrada >> $fnombre
echo "Salida:       " $salida >> $fnombre
echo "*/" >> $fnombre
echo "" >> $fnombre
echo  //Librerias >> $fnombre
echo "#include <stdio.h>" >> $fnombre
echo ""
echo "       **| Su archivo ha sido creado exitosamente |**       "
echo ""
