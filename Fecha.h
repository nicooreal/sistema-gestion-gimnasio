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

    bool operator>(Fecha fecha)
    {
        if(_anio>fecha.getAnio())
        {
            return true;
        }else if(_anio==fecha.getAnio()&&_mes>fecha.getMes())
        {
            return true;
        }else if(_anio==fecha.getAnio()&&_mes==fecha.getMes()&&_dia>fecha.getDia())
        {
            return true;
        }
        return false;
    }


    int calcularAniosDeVida();
    Fecha calcularUnMesDeEntreno(Fecha fec);
    Fecha FechaInicial();
};



#endif // FECHA_H_INCLUDED
