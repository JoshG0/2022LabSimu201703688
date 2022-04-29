/*
Autor:      Josué Gómez
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilado:  gcc Problema5.c -o Problema5.out
Fecha:      Fri Apr 29 00:10:48 CST 2022
Librerias:  stdio (u otras)
Resumen:    Este ejercicio, consiste en realizar un programa que lea dos números enteros 
            para generar un rango y que muestre todos los númeroque se continen en ese rango.
Entada:     Dos números enteros
Salida:     Números primos entre los dos números ingresados
*/

//Librerias
#include <stdio.h>

//1. Declaración de variables
int N1, N2, i, j, primo;
//2. Funcíon principal
int main(){
    puts("Ingrese un número entero positivo: ");
    scanf("%d",&N1);
    puts("Ingrese un número entero positivo: ");
    scanf("%d",&N2);
    i = N1;
    //2.1 Loop que guarda los datos
    while (i <= N2)
    {
        j = 2;
        primo = 1;

        while (j < i && primo == 1)
        {
            if (i%j==0)
            {
                primo = 0;
            }
            j++;
        }
        
        if (primo == 1)
        {
            printf("%d ",i);   
        }
        i++;
    }
    puts("\n");
    return 0;
}