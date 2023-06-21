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
    int _especializacion;


public:
    Empleado();
    Empleado(int id,float sueldo,Fecha fechaIngreso,int especializacion);



    void setId(int id);
    int getId();

    void setSueldo(float sueldo);
    float getSueldo();

    void setFechaIngreso(Fecha fechaIngreso) ;
    Fecha getFechaIngreso();

    void setEspecializacion(int especializacion);
    char *getEspecializacion();

    void cargarEmpleado();
    void mostrarEmpleado();


};

#endif // EMPLEADO_H
