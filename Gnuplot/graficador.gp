unset label 
clear
set terminal epslatex
set output "Ej4.tex"
set title "Prueba de grafico"
set xlabel "eje x"
set ylabel "eje y: Datos"
set grid 
set style data boxplot
plot "Datos" using 2:3
