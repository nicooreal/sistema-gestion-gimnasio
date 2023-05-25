#ifndef EMPLEADOTAREAS_H
#define EMPLEADOTAREAS_H
#include "EmpleadoArchivo.h"


class EmpleadoTareas
{
private:
    EmpleadoArchivo _archivo;

public:
    void cargar();
    void listarEmpleadosPorAnio();
    void modificar() ;

};

#endif // EMPLEADOTAREAS_H
