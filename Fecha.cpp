#include "Fecha.h"


void Fecha::ponerPrimerDiaDelAnio()
{
    _dia=1;
    _mes=1;
    _anio=2023;
}

Fecha::Fecha()
{
    ponerPrimerDiaDelAnio();
}

Fecha::Fecha(int dia,int mes,int anio)
{
    _dia=dia;
    _mes=mes;
    _anio=anio;
}

void Fecha::cargar()
{
    cout<<"Dia: "; cin>>_dia;
    cout<<"Mes: "; cin>>_mes;
    cout<<"Anio: "; cin>>_anio;
}

void Fecha::mostrar()
{
    cout<<_dia<<"/"<<_mes<<"/"<<_anio<<endl;
}

void Fecha::setDia(int dia)
{
    _dia=dia;
}

void Fecha::setMes(int mes)
{
    _mes=mes;
}

void Fecha::setAnio(int anio)
{
    _anio=anio;
}

int Fecha::getDia()
{
    return _dia;
}

int Fecha::getMes()
{
    return _mes;
}

int Fecha::getAnio()
{
    return _anio;
}
