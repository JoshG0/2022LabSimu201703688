#!/bin/bash
#Datos del clima de Guatemala para el día de hoy
echo ""
echo "             ***|| ESTADO DEL TIEMPO CIUDAD DE GUATEMALA ||***       "
echo ""
touch "InformacionClima"
#Tomamos la información de la página y ya creado el 
#archivo InfoClima, se guarda la información allí
echo "$(curl wttr.in/Guatemala)" > "InformacionClima"
#Escribimos las primeras  7 líneas y eliminamos el 
#archivo
head -7 InformacionClima
rm InformacionClima
echo ""
