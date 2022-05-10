/*
Autor:      Josué Gómez
Compilador: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilado:  gcc problema6.c -o problema6.out -lm
Fecha:      Mon May 9 17:44:45 CST 2022
Librerias:  stdio (u otras)
Resumen:    Tendremos un set de sumatorias, que tendran el límite fijado por el usuario, el usuario al poner ese nomero determinara que valoes desplegará el programa
Entada:    
Salida:    
*/

//Librerias
#include <stdio.h>
#include <math.h>

//1. Declaración de variables

//2.Prototipo de funciones
int insa(int n);
float insb(int n);
float insc(int n);
float bode(int n);

//3. Funcion principal
int main(){
    int n;
    puts("  *** ALGUNAS SUMATORIAS ***  ");
    puts("\n Ingrese un límite para la sumatoria: ");
    scanf("%d",&n);
    printf("La sumatoria a. hasta %d es: %d\n",n,insa(n));
    printf("La sumatoria b. hasta %d es: %.3f\n",n,insb(n));
    printf("La sumatoria c. hasta %d es: %.3f\n",n,insc(n));
    printf("La sumatoria a. hasta %d es: %.3f\n",n,bode(n));
    puts("\nFIN");

    return 0;
}

//4. Inciso a
int insa(int val){
    int total = 0;
    for ( int k = 1; k <= val; k++)
    {
        total += k*k*(k-3);
    }
    return total;
}

//5. Inciso b
float insb(int val){
    float total = 0;
    for (int k = 2; k <= val; k++)
    {
        total += 3/(k-1);
    }
    return total;
}
//6. Inciso c
float insc(int val){
    float total = 0;
    float cte = sqrt(5);
    for (int k = 1; k <= val; k++)
    {
        total += (cte*pow((1+sqrt(5))/2,k))-(cte*pow((1-sqrt(5))/2,k));
    }
    return total;
}
//7. Inciso d
float bode(int val){
    float total = 0;
    for (int k = 2; k <= val; k++)
    {
        total += 0.1*(3*pow(2,(k-2))+4);
    }
    return total;
}
