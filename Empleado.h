#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Persona.h"
 using namespace std;
class Empleado: public Persona
{
 private:
     int   _numeroLegajo;
     int   _sueldo;
     Fecha _fechaIngreso;
     //int  _antiguedad=calcularAntiguedad()
     char  _especializacion[30];

    public:
        Empleado();
        Empleado(int numeroLegajo,int sueldo,Fecha fechaIngreso,const char* especializacion)  ;

        void setNumeroLegajo(int numeroLegajo) ;
        int getnumLegajo() ;

        void setSueldo(int sueldo);
        int getSueldo();

        void setFechaIngreso(Fecha fechaIngreso) ;
        Fecha getFechaIngreso();

        void setEspecializacion(const char* especializacion);
       const char* getEspecializacion() ;
         void cargarEmpleado();
         void mostrarEmpleado();

};

#endif // EMPLEADO_H
