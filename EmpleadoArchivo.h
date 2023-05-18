#ifndef EMPLEADOARCHIVO_H
#define EMPLEADOARCHIVO_H
#include "Empleado.h"

class EmpleadoArchivo
{
    public:
bool guardar(Empleado empl);
Empleado leer(int nroRegistro);

};

#endif // EMPLEADOARCHIVO_H
