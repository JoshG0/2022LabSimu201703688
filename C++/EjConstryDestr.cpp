/*
Autor:      Josué Gómez
Compilador: g++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilado:  g++ EjConstryDestr.cpp -o EjConstryDestr.out
Fecha:      Tue May 10 12:17:12 CST 2022
Librerias:  stdio (u otras)
Resumen:    Será un ejemplo sencillo de un constructor y destructor
Entada:    
Salida:   
UML: 
-------------------
Imaginarios
-------------------
+ Real
+ Img
-------------------
+ Imaginarios
+ ~Imaginarios
-------------------
*/

//Librerias
#include <iostream>

//1. Crea la clase con los atributos real e imag, y los metodso 
//   de constructor y destructor

class Complejos //Nombre de la clase
{
public: //Son los elemnteos
    //Atributos es igual a definri variables
    double real, img;
public:
    //Metodos = funciones de la clase
    //Cosntructor
    Complejos(double a, double b){ // aca definimos la variable tienen que ser del mismo tipo
        real = a;
        img =b ;
    }
    ~Complejos(){};
};

//2. Se realiza la función principal
int main(void){
    //Crea objetos y se inicializan los valores de los atributos
    Complejos valor1(1.,2.); //este es el primer objeto
    //Ya creamos el objeto, y lo podemos usar con los objetos
    //Vamos a mostrar el valor en consola del objeto
    std::cout << "Numero Complejo: "<<valor1.real<<"+"<<valor1.img<<"i"<<std::endl; //Estos son los métodos de la clase
    //Esto fue loq ue mostramos en consola std
    
    //Elimiinaos el bojeto con el destructor
    valor1.~Complejos();
    std::cout << "Numero Complejo: "<<valor1.real<<"+"<<valor1.img<<"i"<<std::endl; //Estos son los métodos de la clase
    //Imprimimos despues, el espacio de memoria se libero, se sobreescribe, como elmiminar cosas en el disco duro 
    return 0;
}
