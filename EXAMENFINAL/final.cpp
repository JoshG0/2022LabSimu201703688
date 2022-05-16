/*
Autor:      Josué Gómez
Compilador: g++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Compilado:  g++ final.cpp -o final.out -lm
Fecha:      Mon May 16 08:12:24 CST 2022
Librerias:  iostream, stdio, math, stdlib, iostream 
Resumen:    Examen fnal, laboratorio de simulaicón.
Entada:    
Salida:    
*/

//Librerias
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

//1. Constantes del problema
float G = 6.693E-11, Rt = 6.378E6, Mt = 5.9736E24;
float R = 287.06, L = 6.5E-3;
float go = 9.81, To = 288.15, Po = 101325;
float Ho = 0.88, delta = 0.1;

//2. Declaración de variables
int i = 0; 
//2.1 datos de cada cohete
float Eo, TSFC, CD, A, mo, mfo;
//2.2 varibales de salida
float y, vel, mf, Mc, dy, F, E, g, rho;

//3. Prototipo de funciones 
float densidad(float rho);
float gravedad(float g);
float fircca(float Fa);
float consumogas(float dm);
float vm(float mc);
float ef(float e);
float edo(float dy);

// 6. Presentacion de datos

//5. Clases  Cohete
class Cohete
{
    //Nombre del cohete, caraceristicas y posición
    string nomcohete; 
    float Eo, TSFC, CD, A, mo, mfo;
    float y; // pocision
public: 
    //5.1 Cosntructor de la clase cohete
    Cohete(string nombre, float empuje, float tsfc, float cd, float area, float masa, float gasolina, float altura){
        nomcohete = nombre;
        Eo = empuje;
        TSFC = tsfc;
        CD = cd;
        A = area;
        mo = masa;
        mfo = gasolina;
        y = altura;
    }
    //5.2 Destructor de la clase cohete
    ~Cohete(){};
    //5.3 otros meetodos
};

void Cohete::despegar(){
    y = 0.88;
    vel = 0;
    i = 0;
    //Creación de archivos
    FILE* datosy1;
    FILE* datosy2;
    FILE* datosy3;
    FILE* datosvel1;
    FILE* datosvel2;
    FILE* datosvel3;
    //apertura de los archivos, Y corresponde a la altura, y 1 al numero de cohete: Y_1, altura para cohete  1
    datosy1 = fopen("Datos_Y_1","wt");
    datosvel1 = fopen("Datos_Vel_1","wt");
    datosy2 = fopen("Datos_Y_2","wt");
    datosvel2 = fopen("Datos_Vel_2","wt");
    datosy3 = fopen("Datos_Y_3","wt");
    datosvel3 = fopen("Datos_Vel_3","wt");
    
    //Calculo de y: altura y v: velocidad
    while (i < 1800 && y > Ho)
    {
        //escritura de datos mientras se ejecuta el programa
        fprintf(datosy1, "%lf\t %lf \n", delta*i, y);
        fprintf(datosy2, "%lf\t %lf \n", delta*i, y);
        fprintf(datosy3, "%lf\t %lf \n", delta*i, y);
        fprintf(datosvel1, "%lf\t %lf \n", delta*i, y);
        fprintf(datosvel2, "%lf\t %lf \n", delta*i, y);
        fprintf(datosvel3, "%lf\t %lf \n", delta*i, y);

        //calculo de velocidad y altura
        vel = vel + delta*EDO(dy)*i;
        y = y+delta*vel*i
        i++;
    }
    


}

//4. Funciones
//4.1 Para la densidad
float densidad(float rho){
    float ren(rho);
    // validamos el parámetro dado
    if (y < To/L)
    {
        rho = (Po)/(R*To)*pow((1-(L*y/To)),go/(R*L));
        
    }else
    {
        rho = 0;
    }
    return rho;
}

//4.2 para la gravedada
float gravedad(float g){
    g = (G*Mt)/(pow(Rt+y,2));
    return g;
}

//4.3 para la friccion
float fricca(float Ffr){
    Ffr = 0.5*densidad(rho)*CD*A*vel*abs(vel);
    return Ffr;
}

//4.4 consumo del combustible
float consumogas(float dm){
    float resp; 
    resp =-TSFC*Eo;
    return resp;
}

//4.5 para la variacion de la masa
float vm(float mc){
    float mc;
    mc = mo + consumogas(y);
    return mc;
}

//4.6
float ef(float e){
    if (mf == 0)
    {
        E = 0;
    }else
    {
        e=Eo;
    }
    return E;
    
    
}

//4.6 Ecuacion deiferencial 
float EDO(float dy){
    dy = ef(E)/vm(Mc)-fricca(F)/vm(Mc)-gravedad(G);
    return dy;
}

//Para las gráficas
void grafica(){
    FILE * graf;
    graf=fopen("grafica.gp", "wt");
    fprintf(graf, "plot 'grafica.txt'");
    fclose(graf);
}
int main(){
    Cohete c1(3E7,3.248E-4, 61.27, 201.06, 1.1E5, 1.5E6, 0.00, 0.00);
    Cohete c2(2E7,2.248E-4, 61.27, 201.06, 1.1E5, 1.5E6, 0.00, 0.00);
    Cohete c3(2.5E7,2.248E-4, 70.25, 215.00, 1.8E5, 2.1E6, 0.00, 0.00);
    c1.despegar();
    c2.despegar();
    c3.despegar();
    system("gnuplot -p grafica.gp");
    system("replot datosy1.dat, datosy2.dat, datosy3.dat, datosvel1.dat, datosvel2.dat, datosvel3.dat");
}








