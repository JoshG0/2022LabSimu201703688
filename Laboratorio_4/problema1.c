/*
Autor:      Josué Gómez
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilado:  gcc problema1.c -o problema1.out
Fecha:      Fri May 6 16:53:35 CST 2022
Librerias:  stdio, ctype
Resumen:    Tenemos un programa que muestra información de números, el usurio tendrá
            un menú de selección de tal manera que este le permita ver en orden ascendete 
            o desscente los datos almacenados. El menu presenta las opciones valida, de modo 
            que si el usuario ingresa una distinta el programa volvera a requerir el correcto, 
            al hacerlo, mostara la informacion y el programa finalizara.
Entada:     a, orden ascendente
Salida:     val
*/

//Librerias
#include <stdio.h>
#include <ctype.h>

//1. Declaraición e inicialización de variables
char val;
int datos[10] = {2,4,6,8,10,12,14,16,18,20};
int i = 0;

//2. Funcion principal
int main(){
    //2.1 Interaccion con el usuario
    puts("      ---||Mostrar orden de los datos||---      ");
    printf("\nDe manera ascendente ingrese \"a\"\n");
    puts("--------------------------------------");
    printf("De manera descendete ingrese \"d\"\n");
    val = getchar();
    //2.2 Inicio del loop
    while (val != 'a' || val != 'd')
    {
        //Validacion del caracter
        if (val == 'a')
        {
            puts("Los valores son: ");
            for ( i = 0; i < 10; i++)
            {
                printf("%d ",datos[i]);
            }
            puts("\n");
            break;
        }
        if (val == 'd')
        {
            puts("Los valores son; ");
            for ( i = 9; i >= 0; i--)
            {
                printf("%d ",datos[i]);
            }
            puts("\n");
            break;
        }

     //Cuando se ingrese un valor distinto
     puts("Esta no es una opcion valida\n");
     val = getchar();
    }
}
    
   