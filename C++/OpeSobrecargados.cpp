/*
Autor:      Josué Gómez
Compilador: g++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilado:  g++ OpeSobrecargados.cpp -o OpeSobrecargados.out
Fecha:      Tue May 10 13:12:47 CST 2022
Librerias:  iostream (u otras)
Resumen:    Este es un ejemplo del uso de operadores sobrecargados
Entada:    
Salida:  
UML:
---------------------
Posicion
---------------------
+ x:int
+ y:int
---------------------
+ suma
+ validar igualar
---------------------  
*/

//Librerias
#include <iostream>
class Posicion
{
    public:
        //Atributos publicos
        int x = 10;
        int y = 20;
    public:
        //Operador sobrecargado para sumar la posicion dle objeto 
        //Veamos porque se llama sobrecargado 
        Posicion operator +(Posicion pos){
            //creamos un operados que se llma + y le parciamos un objeto que se llma pos
            //creamos un nuevo objeto que llamamos pocision
            Posicion nueva_posicion;

            //tengo un nuevo obejto, tengo su valor x, tomo ese valor  lo sumamos la poscion de x del obejto que ingres
            //tomamos un objeto y lo sumamos entre ellos. 
            nueva_posicion.x = x+pos.x;
            nueva_posicion.y = y+pos.y;
            return nueva_posicion;
        }

        //Operador sobrecargado para una respuesta booleano
        bool operator == (Posicion pos){
            if ( x==pos.x && y ==pos.y)
            {
                return true;
            }else{
                return false;
            }
        }
};

//4. Finalizada la clase se usa la cales
int main(){
    //creo dos obejtos, de posicion creo pos 1 y el objeto pso2
    Posicion pos1, pos2;
    std::cout << pos1.x << "," << pos1.y <<std::endl;
    //Valores a la posicion
    pos1.x = 2;
    std::cout << pos1.x << "," << pos1.y <<std::endl;
    Posicion pos3 = pos1 + pos2;
    std::cout << pos3.x << "," << pos3.y <<std::endl;

    //Validación 
    if (pos1 == pos2)
    {
        std::cout << "Sí son iguales \n";
    }else{
        std::cout <<"No son iguales \n";
    }
    

}