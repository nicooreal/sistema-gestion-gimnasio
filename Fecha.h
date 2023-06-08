#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>

using namespace std;

class Fecha
{
private:
    int _dia,_mes,_anio;



public:
    Fecha();
    Fecha(int dia,int mes,int anio);

    void cargar();
    void mostrar();
    void fechaDeHoy();

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    int getDia();
    int getMes();
    int getAnio();

    int calcularAniosDeVida();


};



#endif // FECHA_H_INCLUDED
