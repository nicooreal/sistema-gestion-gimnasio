#ifndef EMPLEADOTAREAS_H
#define EMPLEADOTAREAS_H
#include "EmpleadoArchivo.h"


class EmpleadoTareas
{
private:
    EmpleadoArchivo _archivo;

public:
    void cargar();
    void listarEmpleados2023();

};

#endif // EMPLEADOTAREAS_H
