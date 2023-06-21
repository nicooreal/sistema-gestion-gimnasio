# include<iostream>
# include<cstdlib>
using namespace std;
#include "Empleado.h"

Empleado::Empleado()
{
    _id=0;
    _sueldo=120000;
    _fechaIngreso.fechaDeHoy();
    _especializacion=0;
    _estado=false;

}
Empleado::Empleado(int id,float sueldo,Fecha fechaIngreso,int especializacion,bool estado)
{
    _id=id;
    _sueldo=sueldo;
    _fechaIngreso=fechaIngreso;
    _especializacion=especializacion;
    _estado=estado;
}

void Empleado::setEstado(bool estado)
{
    _estado=estado;
}

bool Empleado::getEstado()
{
    return _estado;
}

void Empleado::setId(int id)
{
    _id=id;
}

int Empleado::getId()
{
    return _id;
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

void Empleado::setEspecializacion(int especializacion)
{
    _especializacion=especializacion;
}
char *Empleado::getEspecializacion()
{
    char especializaciones[3][15]={"Profesor","Administrativo","Limpieza"};
    return especializaciones[_especializacion-1];
}
void Empleado::cargarEmpleado()
{
    cargarPersona();
    cout <<"Sueldo: "<<endl;
    cin >> _sueldo;
    cout <<"Fecha De Ingreso: "<<endl;
    _fechaIngreso.cargar();
    do
    {
        cout <<"Especializacion(1 - Profesor, 2 - Administrativo, 3 - Limpieza): "<<endl;
        cin >> _especializacion;
    }
    while(_especializacion<1||_especializacion>3);
    _estado=true;

}
void Empleado::mostrarEmpleado()
{
   if ( _estado == true ){

    char especializaciones[3][15]={"Profesor","Administrativo","Limpieza"};
    cout <<"ID DE EMPLEADO #" << _id << endl;
    mostrarPersona();
    cout <<"Con un sueldo de $ "<<_sueldo<<endl;
    cout <<"Ingreso el dia "    ;
    _fechaIngreso.mostrar();
    cout <<"se especializa en " <<especializaciones[_especializacion-1]<<endl;

cout <<"-----------------------------------------"<< endl;
   }
}
