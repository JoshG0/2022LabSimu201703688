#ifndef ELEMENTOS_H
#define ELEMENTOS_H
class Proyectil
{
public:
    float posx, posy, masa;
public:
    Proyectil();
    ~Proyectil();
};

class Blanco
{
public:
    float posx, posy, diametro;
public:
    Blanco();
    ~Blanco();
};
#endif