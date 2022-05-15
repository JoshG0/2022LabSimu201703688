/*
Autor:      Josué Gómez
Compilador: g++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilado:  g++ EJjClasesSimples.cpp -o EJjClasesSimples.out
Fecha:      Tue May 10 12:47:14 CST 2022
Librerias:  iostream (u otras)
Resumen:    Lo que haremos es un ejemplo del uso de clases simples, es otra forma de constructor
Entada:    
Salida:    
*/

//Librerias
#include <iostream>
//1. NOs permite dejar de utilizar el std:: para el out
//   Para fijar la programación de las directivas de string
using namespace std;

//2. Declaramos clase con atributos y metodos
class Fecha{
    //Atributos privados, no decimos nada en el atributos
    int dia, mes, anyo;
    //Metodos sin constructor ni destructor
    public:
        void fijFecha(int, int, int); //no hay nobre de variable solo el tipo
        void mostFecha(); //no necesitamos ningun elemnto
};

//3. DEfinimos el metodo y le forma en que opera el metidos
//   notemos que va fuera de la clase.
//   Para definir la función(método) de la clase es necesario el nombre  de la clase y el 
//   operados ::

void Fecha::fijFecha(int d, int m, int a)
{
    //constructores
    dia = d;
    mes = m; 
    anyo = a;
}

//SE define la función sin variables
void Fecha::mostFecha() // el void es el tipo de la declaracion 
{
    //escribir la fecha en consola 
    cout <<dia<<"/"<<mes<<"/"<<anyo;
}

//3. Creamos y utlizamos obejtos
int main(){
    //Declaro variables locales
    int d, m, a;
    //Declarar objetos
    Fecha fHoy; //eclaramos con FEcha y el nobmre que le dimos fue fho
    Fecha otraFecha;
    
    //inicializar los objetos
    fHoy.fijFecha(10,5,2022);
    
    //para que muestre la fecha anterior
    cout << "La fecha de hoy es: ";
    fHoy.mostFecha();
    cout << endl; // con esto nos ahorramos el std::
    cout << "Ingrese la fecha que desee: \n";
    cout << "Ingrese el día: \n";
    //para mandarla a una variable
    cin >> d; // cin lo que enter, el >> es como el &
    cout << "Ingrese el mes: \n";
    cin >> m;
    cout << "Ingrese el año: \n";
    cin >> a;

    //Ingresamos el metodo de la clase y luego lo usamos
    cout << "Su fecha ingresada es: ";
    otraFecha.fijFecha(d,m,a);
    otraFecha.mostFecha();
    cout << endl; //cerrar la comunicacion, para eso es 
    return 0;
}




