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


}
Empleado::Empleado(int id,float sueldo,Fecha fechaIngreso,int especializacion)
{
    _id=id;
    _sueldo=sueldo;
    _fechaIngreso=fechaIngreso;
    _especializacion=especializacion;

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
    char especializaciones[3][15]= {"PROFESOR","ADMINISTRATIVO","LIMPIEZA"};
    return especializaciones[_especializacion-1];
}

void Empleado::mostrarEmpleado()
{
    if ( _estado == true )
    {

        char especializaciones[3][15]= {"PROFESOR","ADMINISTRATIVO","LIMPIEZA"};
        cout <<"ID DE EMPLEADO #" << _id << endl;
        mostrarPersona();
        cout <<"CON UN SUELDO DE $ "<<_sueldo<<endl;
        cout <<"INGRESO EL DIA "    ;
        _fechaIngreso.mostrar();
        cout <<"SE ESPECIALIZA EN " <<especializaciones[_especializacion-1]<<endl;

        cout<<"----------------------------------"<< endl;
    }
}

void Empleado::mostrarEmpleadosDadosDeBaja()
{
    if(!_estado)
    {
       // cout<<"\tESTE EMPLEADO ESTA DADO DE BAJA"<<endl;
        char especializaciones[3][15]= {"PROFESOR","ADMINISTRATIVO","LIMPIEZA"};
        cout<<"ID DE EMPLEADO #"<<_id<<endl;
        mostrarPersona();
        cout<<"CON UN SUELDO DE $ "<<_sueldo<<endl;
        cout<<"INGRESO EL DIA ";
        _fechaIngreso.mostrar();
        cout<<"SE ESPECIALIZA EN " <<especializaciones[_especializacion-1]<<endl;

        cout<<"-----------------------------------------"<<endl;

    }
}
