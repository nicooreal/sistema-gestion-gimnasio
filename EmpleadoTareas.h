#ifndef EMPLEADOTAREAS_H
#define EMPLEADOTAREAS_H
#include "EmpleadoArchivo.h"


class EmpleadoTareas
{
private:
    EmpleadoArchivo _archivo;
    int generarID();
    int calcularEdad(Fecha fechaNacimiento);

public:
    void cargar();
    void modificar();
    void borrarRegistros();
    void darDeBajaEmpleado();


    void listados();
    void listarRegistros();
    void listarEmpleadosPorAnio();
    void listarOrdenadosPorNombre();
    void listarPorEdad();
    void listarPorSueldo();
    void listarEmpleadosDadosDeBaja();


    void consultas();
    void consultaPorId();


};

#endif // EMPLEADOTAREAS_H
