/*
Autor:      Josué Gómez
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilado:  gcc Problema3.c -o Problema3.out
Fecha:      Thu Apr 28 20:32:40 CST 2022
Librerias:  stdio (u otras)
Resumen:    Es un programa que calcula la raiz cuadrada entera por defecto 
            de un numero N positivo dado, R>0, tal que R^2 <= N.
Entada:     Números positivos
Salida:     Raiz cuadrada entera
*/

//Librerias
#include <stdio.h>

//1.Función principal
int main(){
    //1.1 Declaración de variables
    int i;
    float N;
    //1.2 Interacción con el usuario, recopilación de datos
    puts("Ingrese un número natural positivo");
    scanf("%f",&N);
    i = 1;

    //2. Calculo de la raiz
    while(i*i <= N)
    {
        i ++;
    }
    printf("La raiz cuadrada entera por defecto es: %d \n",i-1);
    

    return 0;
}
