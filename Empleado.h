#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Persona.h"
using namespace std;
class Empleado: public Persona
{
private:
    int _id;
    float   _sueldo;
    Fecha _fechaIngreso;
    char  _especializacion[30];

public:
    Empleado();
    Empleado(int id,float sueldo,Fecha fechaIngreso,const char* especializacion)  ;

    void setId(int id);
    int getId();

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
