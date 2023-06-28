#include "Fecha.h"
#include <ctime>
#include <cctype>
#include "funciones.h"



Fecha::Fecha()
{
    time_t rawtime;
    struct tm timeinfo;

    time(&rawtime);
    timeinfo = *(localtime(&rawtime));

    _dia = timeinfo.tm_mday;
    _mes = timeinfo.tm_mon + 1;
    _anio = timeinfo.tm_year + 1900;

}

void Fecha::fechaDeHoy()
{
    Fecha(); // constructor con fecha de hoy
}


bool Fecha::esBisiesto()
{
    if ((_anio % 4 == 0 && _anio % 100 != 0) || _anio % 400 == 0)
    {
        return true;
    }
    return false;
}

void Fecha::agregarDia()
{
    int dias[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (esBisiesto())
    {
        dias[1]++;
    }

    _dia++;
    if (_dia > dias[_mes-1])
    {
        _dia = 1;
        _mes++;
        if (_mes > 12)
        {
            _mes = 1;
            _anio++;
        }
    }
}

void Fecha::cargar()
{
    do
    {
        cout<<"DIA: ";
        cin>>_dia;
        validarIngresos(_dia);
        validarQueNoSeaNegativa(_dia);

        cout<<"MES: ";
        cin>>_mes;
        validarIngresos(_mes);
        validarQueNoSeaNegativa(_mes);
        cout<<"ANIO: ";
        cin>>_anio;
    validarIngresos(_anio);
    validarQueNoSeaNegativa(_anio);
    }
    while(_dia<=0||_mes<=0||_anio<=0);



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

Fecha Fecha::calcularUnMesDeEntreno(Fecha fech)
{

    int dia, mes,anio;


    if (fech.getMes() == 12)
    {
        mes = 1;
        anio = fech.getAnio() + 1;
        dia = fech.getDia();
    }
    if (fech.getMes()==2 && fech.getDia()==29)
    {

        dia = 31;
    }

    if (fech.getDia() == 31)
    {
        dia = 30;
    }
    else
    {
        dia = fech.getDia();
    }
    mes = fech.getMes() + 1;
    anio = fech.getAnio();






    fech.setDia(dia);
    fech.setMes(mes);
    fech.setAnio(anio);

    return fech;
}








