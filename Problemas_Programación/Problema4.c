/*
Autor:      Josué Gómez
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilado:  gcc Problema4.c -o Problema4.out
Fecha:      Thu Apr 28 23:39:40 CST 2022
Librerias:  stdio (u otras)
Resumen:    Este es un programa que lee un número mayor que uno y va a determian si este es primo.
Entada:     Número entero mayor a uno
Salida:     Es primo o no
*/

//Librerias
#include <stdio.h>

//1. función principal
int main(){
    //1.1 Declaración e inicialización de variables. Obtencion de datos
    int primo = 0, N = 0, i = 0;
    puts("Ingrese un número mayor que 1: ");
    scanf("%d",&N);
    i = 2;
    primo = 1;

    //1.2 Inicio del loop
    while(i < N-1 && primo == 1)
    {
        if (N%i == 0)
        {
            primo = 0;
        }
        i++;   
    }

    if (primo == 0)
    {
        puts("No es un número primo");
    }
    else
    {
        puts("Es un número primo");
    }
    return 0;
}
