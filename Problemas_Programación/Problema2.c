/*
Autor:      Josué Gómez
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilado:  gcc Problema2.c -o Problema2.out
Fecha:      Thu Apr 28 19:06:44 CST 2022
Librerias:  stdio (u otras)
Resumen:    Este será un programa que lea un número indeterminado de alturas, 
            se detnedrá cuando el usuario ingrese un valor negativo, para ese momento  
            calculara el máximo, el mínimo y la media de los valores proporcionados.
Entada:     Valores positivos decimales
Salida:     Media, valor mínimo y valor máximo
*/

//Librerias
#include <stdio.h>

//1. Declaracion e inicializacion de variables
float n = 0, med = 0, max = 0, min = 0, x = 0;

//2. Funcion principal
int main(){
    //3. Obtenr los datos del usuario
    puts(" ** Media, valor máximo y valor mínimo **\n");
    puts("Ingrese valores enteros de alturas y para finlizar ingrese un valor negativo \n");
    puts("Ingrese el valor de una altura");
    scanf("%f",&x);
    //4. Almacenar los valores
    max = x;
    min = x;
    //5. Validamos sí son valores positivos
    while (x >= 0)
    {
        n ++;
        med += x;

        //6. Evaluamos si el valor ingresado es el máximo hasta el momento
        if (x > max)
        {
            max = x;
        }
        //7. Evaluamos si el valor ingresado es el mínimo hasta el momento

        if (x < min)
        {
            min = x;
        }

        //8. Leer nuevos valores
        puts("Ingrese otra altura: ");
        scanf("%f", &x);
    }

    //9. Verifica si el valor de n sea mayor a 0
    if (n == 0)
    {
        puts("Este no es un valor válido");
    }else{
            med=med/n;
            printf("Los resultados son: \n La media es: %.1f \n El valór mínimo es: %.1f \n El valor máximo es: %.1f \n",med,min,max);   
         }
    



 return 0;

}

