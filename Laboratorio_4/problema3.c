/*
Autor:      Josué Gómez
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilado:  gcc problema3.c -o problema3.out -lm
Fecha:      Sat May 7 17:10:41 CST 2022
Librerias:  stdio (u otras)
Resumen:    A partir de dos vectores de tres componentes (x,y,z),
            que ingrese el usuario, se calculará la magnitud de 
            los mismos, se hará un producto escalar, se sumará los 
            vectores y se realizará el producto vectorial
Entada:    
Salida:    
*/

//Librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//1. Declaración de varialbles
int i, escalar;
float m1, m2;
int n= 3;



//2. Funcion Principal
void main(){
    int Vec1[n], Vec2[n], Sum[n], Vect[n];
    puts("***   OPERACIONES CON VECTORES DE 3 COMPONENTES   ***\n");
    puts("Ingrese los elementos de V1:");
    for ( i = 0; i < n; i++)
    {
        puts("Ingrese un valor y presione enter: ");
        scanf("%d",&Vec1[i]);
    }
    puts("\n");
    puts("Ingrese los elementos de V2:");
    for ( i = 0; i < n; i++)
    {
        puts("Ingrese un valor y presione enter: ");
        scanf("%d",&Vec2[i]);
    }
    puts("\n");
    puts("El vector 1 es: ");
    for ( i = 0; i < n; i++)
    {
        printf("%d, ",Vec1[i]);
    }
    puts("\n");
    puts("El vector 2 es: ");
    for ( i = 0; i < n; i++)
    {
        printf("%d, ",Vec2[i]);
    }
    puts("\n");
    //2.1 Magnitud de los vectores
    m1 = sqrt(Vec1[0]*Vec1[0]+Vec1[1]*Vec1[1]+Vec1[2]*Vec1[2]);
    m2 = sqrt(Vec2[0]*Vec2[0]+Vec2[1]*Vec2[1]+Vec2[2]*Vec2[2]);

    //2.2 Suma de los vectores
    for ( i = 0; i < n; i++)
    {
        Sum[i] = Vec1[i]+Vec2[i];
    }

    //2.3 Producto escalar
    escalar = Vec1[0]*Vec2[0]+Vec1[1]*Vec2[1]+Vec1[2]*Vec2[2];

    //2.4 Producto vectorial
    Vect[0]=Vec1[1]*Vec2[2]-Vec1[2]*Vec2[1];
    Vect[1]=Vec1[2]*Vec2[0]-Vec1[0]*Vec2[2];
    Vect[2]=Vec1[0]*Vec2[1]-Vec1[1]*Vec2[0];

    //2.resutlados:
    printf("La magnitud de los vectores es: \n|V1|= %.2f y |V2|= %.2f \n\n",m1,m2);
    puts("La suma de los vectores será: ");
    for ( i = 0; i < n; i++)
    {
        printf("%d, ",Sum[i]);
    }
    puts("\n");
    printf("El producto escalar es:\n%d\n\n",escalar);
    puts("EL producto vectorial es: ");
    for ( i = 0; i < n; i++)
    {
        printf("%d, ",Vect[i]);
    }
    puts("\n");
    puts("FIN");   
}


