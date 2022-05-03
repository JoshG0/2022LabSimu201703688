/*
Autor:      Josué Gómez
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilado:  gcc Biseccion.c -o Biseccion.out -lm
Fecha:      Mon May 1 13:33:59 CST 2022
Librerias:  stdio, math, srdlib
Resumen:    Se desarrolla un código para ejecutar el metodo numerico de bisección, 
            el cual nos ayudará a determinar ya sea una solución exacta o una aproximación
            de la raiz de una función. En este caso se aplica a la función f(x)=cos(x)/sen(x)
Entada:    
Salida:    
*/

//Librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define c 100

//1. Declaración e inicializacion de varialbes globales
    //Datos del problema
    float ina = 0, inb = 3;
    int n = 100;
float funcion = 0, raiz = 0, error = 0;

//2. Prototipo de funciones
float biseccion(float inicial, float final);
float biseccione(float inicial, float final);

//5. Funcion Principal 
int main(){
    //5.1 Información en consola
    puts("La función ingresada es: \n   Cos(x)/Sin(x)\n");
    printf("Se tomó el intervalo [%.0f, %.0f], con %d iteraciones. \n",ina,inb,n);
    //5.2 Funcion que realiza el metodo numerico
    raiz = biseccion(ina, inb);
    float ep = biseccione(ina, inb);
    error = ((raiz - ep)*c)/(raiz);
    printf("\nLa raíz se encuentra en x = %0.4f\n",raiz);
    printf("El error de esta aproximación es del: %f porciento \n",error);

    //5.3 Creación y ejecución de grafica.
        FILE* comparacion; //declaración del puntero
        comparacion = fopen("FucionyRaiz.gp", "wr");
            fprintf(comparacion, "unset label\n");
            fprintf(comparacion, "clear\n");
            fprintf(comparacion, "set terminal jpeg\n");
            fprintf(comparacion, "set output 'Funcion_y_raiz.jpeg'\n");
            fprintf(comparacion, "set title 'Función vs. Aproximación'\n");
            fprintf(comparacion, "set xlabel 'x'\n");
            fprintf(comparacion, "set ylabel 'f(x)'\n");
            fprintf(comparacion, "set xrange [%.0f:%.0f]\n",ina,inb);
            fprintf(comparacion, "set yrange [-5:5]\n");
            fprintf(comparacion, "set grid\n");
            fprintf(comparacion, "set style data linespoints\n");
            fprintf(comparacion, "plot cos(x)/sin(x)\n");        
        fclose(comparacion);
    //5.4 Grafica 
    system("gnuplot FucionyRaiz.gp");
    
}

//3. Fucnion que realiza el metodo numerico de Biseccion
    // Se indica donde se debe colocar la funcion a anilzar
float biseccion(float inicial, float final){
    // variables locales
    float medio = 0,  funa = 0, check = 0;
    for (int i = 0; i < n; i++){

        medio = (inicial + final)/2;
        funcion= cos(medio)/sin(medio); // acá se coloca la función a analizar
        funa = cos(inicial)/sin(inicial); // acá se coloca la funcón a analizar
        check = funa*funcion;

        if (check == 0)
        {
            puts("La raiz es: x = 0");
            break;
        }
        else if (check < 0)
        {
            final = medio;
        }
        else if(check > 0){
            inicial = medio;
        }

    }
    return medio;
}

//4. Fucnion que realiza el metodo numerico de Biseccion a un termino anterior
float biseccione(float inicial, float final){
    //4.1 variables locales
    float medioe = 0,  funa = 0, check = 0;
    for (int i = 0; i < n-1; i++){

        medioe = (inicial + final)/2;
        funcion= cos(medioe)/sin(medioe); // acá se coloca la función a analizar
        funa = cos(inicial)/sin(inicial); // acá se coloca la funcón a analizar
        check = funa*funcion;

        if (check == 0)
        {
            puts("La raiz es: x = 0");
            break;
        }
        else if (check < 0)
        {
            final = medioe;
        }
        else if(check > 0){
            inicial = medioe;
        }

    }
    return medioe;
}



