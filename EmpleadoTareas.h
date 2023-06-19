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
    void listarOrdenadosPorApellido();
    void listarPorEdad();
    void listarPorSueldo();
    void listarEmpleadosDadosDeBaja();


    void consultas();
    void consultaPorId();
    void consultaPorDni();
    void consultaPorNombre();
    void consultaPorApellido();
    void consultaPorEdad();


};

#endif // EMPLEADOTAREAS_H
