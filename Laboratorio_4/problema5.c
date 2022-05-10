/*
Autor:      Josué Gómez
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilado:  gcc problema5.c -o problema5.out 
Fecha:      Mon May 9 10:05:08 CST 2022
Librerias:  stdio (u otras)
Resumen:    Dado un número por el usuario, se calcula el factorial.
Entada:    
Salida:    
*/

//Librerias
#include <stdio.h>

//1. Prototipo de funciones
long int factorial(long int val);

//3. Función principal
int main(){
    long int val;
    puts("Ingrese un número entero y presione enter para calcular: ");
    scanf("%ld",&val);
    printf("El factorial de %ld es: %ld\n",val, factorial(val));
    return 0;
}

//4. Funcion recursiva
long int factorial(long int valor){
    if (valor > 1)
    {
        return valor*factorial(valor-1);
    }else{
            return 1;
         }   
}
