/*
Autor:      Josué Gómez
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilado:  gcc Problema1.c -o Problema1.out
Fecha:      Thu Mar 24 20:50:10 CST 2022
Librerias:  stdio (u otras)
Resumen:    Se le pedirá al usuario ingrese una serie de números, con estos, el programa realizará la media aritmética.
Entada:     Números reales positivos
Salida:     Media aritmética
*/

//Librerias
#include <stdio.h>

int main(){
//1. declaración e inicialización de variables.
    float x = 0, media = 0;
    int i = 0, n = 0;
//2. validar el numero de elmentos ingresados hasta que llegue a 3
    puts("Calculadora de media aritmética");

    while (i<3)//porque genera la secuecnia
    {
//3. Interacción con el usuario
        puts("Ingrese un número: ");
        scanf("%f",&x);
//4. Validar que el número sea  positivo o cero
        if (x>=0)
        {
//5. Si es verdadero. Acumular la canidad de elementos, y sumar el valor
            n++;
            media+=x; //al valor que ya tiene le sumamos x
        }
        i++;
//6. Validar si todos los número son negativos
    }
    if (n==0)
    {
//7. Indica que no son número positivos
        puts("Los valores ingresados son negativos \n");
    }else{
//8. Si los números son correctos, realizar el cálcuo
        printf("La media aritmética es: %.3f \n", media/n); //el .3 reduce el numero de decimales
    }
    return 0;   
}
