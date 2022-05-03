unset label
clear
set terminal jpeg
set output 'Funcion_y_raiz.jpeg'
set title 'Función vs. Aproximación'
set xlabel 'x'
set ylabel 'f(x)'
set xrange [0:3]
set yrange [-5:5]
set grid
set style data linespoints
xA=1.571
set arrow from xA, -5 to xA,5 nohead dt 2 lc -1
 plot cos(x)/sin(x) 
