# include<iostream>
# include<cstdlib>
using namespace std;
#include "Empleado.h"

Empleado::Empleado()
{
    _numeroLegajo=0000;
    _sueldo=120000;
    strcpy(_especializacion,"Tareas Basicas");

}
Empleado::Empleado(int numeroLegajo,float sueldo,Fecha fechaIngreso,const char *especializacion)
{
    _numeroLegajo=numeroLegajo;
    _sueldo=sueldo;
    _fechaIngreso=fechaIngreso;
    strcpy(_especializacion, especializacion);
}

void Empleado::setNumeroLegajo(int numeroLegajo)
{
    _numeroLegajo=numeroLegajo;
}
int Empleado::getnumLegajo()
{
    return _numeroLegajo;
}

void Empleado::setSueldo(float sueldo)
{
    _sueldo=sueldo;
}
float Empleado::getSueldo()
{
    return _sueldo;
}

void Empleado::setFechaIngreso(Fecha fechaIngreso)
{
    _fechaIngreso=fechaIngreso;
}
Fecha Empleado::getFechaIngreso()
{
    return _fechaIngreso;
}

void Empleado::setEspecializacion(const char *especializacion)
{
    strcpy(_especializacion, especializacion);
}
const char* Empleado::getEspecializacion()
{
    return _especializacion;
}
void Empleado::cargarEmpleado()
{
    cargarPersona();
    cout <<"Numero de Legajo: "<<endl;
    cin >> _numeroLegajo;
    cout <<"Sueldo: "<<endl;
    cin >> _sueldo;
    cout <<"Fecha De Ingreso: "<<endl;
    _fechaIngreso.cargar();
    cout <<"Especializacion: "<<endl;
    cin >> _especializacion;
}
void Empleado::mostrarEmpleado()
{
    mostrarPersona();
    cout <<"El Legajo es "<<_numeroLegajo<<", ";
    cout <<"Con un sueldo de $ "<<_sueldo<<", ";
    cout <<"Ingreso el dia "    ;
    _fechaIngreso.mostrar();
    cout <<"se especializa en " <<_especializacion;


}
