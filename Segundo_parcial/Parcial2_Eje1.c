/*
Autor:      Josué Gómez
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilado:  gcc Parcial2_Eje1.c -o Parcial2_Eje1.out -lm
Fecha:      Sat Apr 30 18:41:37 CST 2022
Librerias:  stdio, math, stdlib.h
Resumen:    Con el método númerico de mínimos cuadrados, y a partir de los datos obtenidos
            del experimento de ondas estacionarias con una cuerda, se obtendra una gráfica
            de los datos y así mismo se estimará una recta que mejor se aproxime a los datos
            obtenidos para así conseguir su ecuación correspondiente y a partir de ella,
            determinar la densidad lineal de la cuerda y la longitud de onda cuando la tension 
            sea de 6N a una frecuencia de 60Hz. 
Entada:    
Salida:    
*/

//Librerias 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//1.Declaracion e inicializacion de variables globales y datos del problema
float ten[]={4.694,1.264,0.578,0.284,0.196}, ldo[]={3,1.5,1,0.75,0.6}, er = 0.001;
float fre = 60, tsion = 60;  

int n = sizeof(ten)/sizeof(ten[0]); 

//2. Prototipado de funciones
//2.1 Imprimir resultados
void imprimir(float datos[]);
//2.2 Sumatorias con sumas
float suma(float datos[]);
//2.2 Sumatorias con multimplicaciones
float sumaMulti(float datos1[], float datos2[]);

//3. Funcion principal
void main(){
    //3.1 Variables de la ecuación 
    float b, m, r, deltam, deltab;
    float resultado = 0;
    //3.2 Imprimir los valores 
    imprimir(ten);
    imprimir(ldo);
    //3.3 Para m
    m = (n*sumaMulti(ten,ldo)-(suma(ten)*suma(ldo)))/(n*sumaMulti(ten,ten)-(suma(ten)*suma(ten)));
    //3.4 Para b
    b = (suma(ldo)-m*suma(ten))/(n);
    //3.5 Para la correlación
    r = (n*sumaMulti(ten,ldo)-(suma(ten)*suma(ldo)))/(sqrt((n*sumaMulti(ten,ten)-(suma(ten)*suma(ten)))*(n*sumaMulti(ldo,ldo)-(suma(ldo)*suma(ldo)))));
    //3.6 Para el error de la variable
    deltam = (sqrt(n)*er)/(sqrt(n*sumaMulti(ten,ten)-(suma(ten)*suma(ten))));
    deltab = er/sqrt(n);
    //3.7 Calculo de la longitud de onda a cierta tensión
    resultado = m*tsion+b;

    //3.3 Imprimir los resultados de los cálculos
    printf("\nFunción que se aproxima a los datos: f(x)= %fx + %f\n", m,b);
    printf("\nCoeficiente de determinacion: %f\n", r*r);
    printf("\nLas incertezas de m y b son: %f y %f respectivamente \n",deltam,deltab);
    printf("\nLa longitud de onda cuando la tensión sea de %.0f N será: %.3f(+- %f)m \n ",tsion,resultado,deltab+deltam);
    puts("\n");

    //3.4 Generación de archivos para los datos originales y los de comparacion
    FILE* datos;
    FILE* regresion;
        //3.4.1 Archivo con datos iniciales
        datos=fopen("Datos", "wr");
        for (int i = 0; i < n; i++)
        {
            fprintf(datos, "%f\t%f\n",ten[i],ldo[i]);
        }
        fclose(datos);
        //3.4.2 Comparacion
        regresion=fopen("grafica.gp", "wr");
            //3.4.2.1 Creacion de la grafica
            fprintf(regresion, "unset label\n");
            fprintf(regresion, "clear\n");
            fprintf(regresion, "set terminal jpeg\n");
            fprintf(regresion, "set output 'comparacion.jpeg'\n");
            fprintf(regresion, "set title 'Tensión vs. Longitud de Onda'\n");
            fprintf(regresion, "set xlabel 'Tensión [N]'\n");
            fprintf(regresion, "set ylabel 'Longitud de Onda [m]'\n");
            fprintf(regresion, "set xrange [0:5]\n");
            fprintf(regresion, "set yrange [0:4]\n");
            fprintf(regresion, "set grid\n");
            fprintf(regresion, "set style data dots\n");
            fprintf(regresion, "set style data linespoints\n");
            fprintf(regresion, "plot \"Datos\" with linespoints, %f*x+%f with linespoints",m,b);
            fclose(regresion);
    //3.5 Apertura del archivo
    system("gnuplot grafica.gp");
}

//4. Función que imprime los datos ingresados
void imprimir(float datos[]){
    puts("Datos ingresados");
    for (int i = 0; i < n; i++) 
    {
        printf("%.3f ",datos[i]);
    }
    puts("\n");
}

//5. Funcion de sumatorias, suma los elementos de un vector
//   ingresados
float suma(float datos[]){
    float resp = 0;
    //acumulación de elementos para sumarlos
    for (int i = 0; i < n; i++)
    {
        resp += datos[i];
    }
    return resp;
}

//6. Suma la multiplicacion entre elementos de dos vectores ingresados
float sumaMulti(float datos1[], float datos2[]){
    float resp = 0;
    //acumulación de elementos para sumarlos
    for (int i = 0; i < n; i++)
    {
        resp += datos1[i]*datos2[i];
    }
    return resp;
}





