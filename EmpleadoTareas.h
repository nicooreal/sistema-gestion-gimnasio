#ifndef EMPLEADOTAREAS_H
#define EMPLEADOTAREAS_H
#include "EmpleadoArchivo.h"


class EmpleadoTareas
{
private:
    EmpleadoArchivo _archivo;
    int generarID();

public:
    void cargar();
    void listarRegistros();
    void listarEmpleadosPorAnio();
    void modificar();
    void borrarRegistros();
    void listarPorId();

};

#endif // EMPLEADOTAREAS_H
