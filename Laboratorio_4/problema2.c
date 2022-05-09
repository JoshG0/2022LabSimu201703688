/*
Autor:      Josué Gómez
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilado:  gcc problema2.c -o problema2.out
Fecha:      Fri May 6 22:36:31 CST 2022
Librerias:  stdio, stdlib
Resumen:    Se crea un programa en el cual, el usuario ingresará valores aleatorios 
            y luego se presentan ordenasamente de forma ascendente
Entada:    
Salida:    
*/

//Librerias
#include <stdio.h>
#include <stdlib.h>

//1. Funcion principal
void main(){
    int n = 5; 
    int datos[n];
    //1.1 Interacción con el usuario
    for ( int i = 0; i < n; i++)
    {
        puts("Ingrese un número");
        scanf("%d", &datos[i]);
        
    }
    puts("Los valores ingresados fueron: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",datos[i]);
    }
    //1.2 Variables de conteo, para ver el interruptor y la pasada que llevamos
    int interruptor = 1;
    int iteracion, j;
    //1.3 Conteo de iteraciones, tienen que ser n-1
    for (iteracion = 0; iteracion < n-1 && interruptor; iteracion++)
    {
        interruptor = 0;
        //1.3.1 Escanea j, que son las poscisiones del vector, j depende de la iteracion
        for (j = 0; j < n-iteracion-1; j++)
        {
            //guaradar el valor cambiado, aca se ven los cambios
            if (datos[j] > datos[j+1])
            {
                int save;
                save = datos[j];
                datos[j] = datos[j+1];
                datos[j+1] = save;
            }
            //valida la comparación,
            interruptor = 1;
        }
    }
    //1.4 Vector ordenado
    puts("\n");
    puts("Los valores ordenados de menor a mayor son: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",datos[i]);
    }
    puts("\n");
    
}
