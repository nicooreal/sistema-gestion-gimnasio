#include "Fecha.h"
#include <ctime>




Fecha::Fecha() {
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

/*Fecha::Fecha()
{
    ponerPrimerDiaDelAnio();
}

Fecha::Fecha(int dia,int mes,int anio)
{
    _dia=dia;
    _mes=mes;
    _anio=anio;
}
*/






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

Fecha Fecha::calcularUnMesDeEntreno(Fecha fech)
{

    int dia, mes,anio;


    if (fech.getMes() == 12)
    {
        mes = 1;
        anio = fech.getAnio() + 1;
        dia = fech.getDia();
    }

// falta ver lo del mes de Febrero y si es biciesto


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





