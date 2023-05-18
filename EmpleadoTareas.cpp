#include "EmpleadoTareas.h"

void EmpleadoTareas::cargar()
{
    Empleado empleado;
    empleado.cargarEmpleado();

    _archivo.guardar(empleado);
}
