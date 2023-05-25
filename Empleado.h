#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Persona.h"
using namespace std;
class Empleado: public Persona
{
private:
    int   _numeroLegajo;
    float   _sueldo;
    Fecha _fechaIngreso;
    //int  _antiguedad=calcularAntiguedad()
    char  _especializacion[30];

public:
    Empleado();
    Empleado(int numeroLegajo,float sueldo,Fecha fechaIngreso,const char* especializacion)  ;

    void setNumeroLegajo(int numeroLegajo) ;
    int getnumLegajo() ;

    void setSueldo(float sueldo);
    float getSueldo();

    void setFechaIngreso(Fecha fechaIngreso) ;
    Fecha getFechaIngreso();

    void setEspecializacion(const char* especializacion);
    const char* getEspecializacion() ;
    void cargarEmpleado();
    void mostrarEmpleado();
    Persona datosPersona; //para acceder a los get/set

};

#endif // EMPLEADO_H
