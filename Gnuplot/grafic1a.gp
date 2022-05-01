unset label
clear 
set terminal jpeg
set output 'grafica1.jpeg'
set title 'TENSIÓN VS LONGITUD DE ONDA'
set xlabel 'Tensión (N)'
set ylabel 'Longitud de Onda (m)'
set grid 
set style data linespoints
plot "Datos", 3*x+6
