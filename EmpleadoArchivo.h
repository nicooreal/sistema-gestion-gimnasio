#ifndef EMPLEADOARCHIVO_H
#define EMPLEADOARCHIVO_H
#include <iostream>
#include <string.h>

using namespace std;
#include "Empleado.h"

class EmpleadoArchivo
{
private:
    char _nombreArchivo[30];

public:
    EmpleadoArchivo();/// CONSTRUCTOR PARA PONER POR DEFECTO empleados.dat
    EmpleadoArchivo(const char *nombreArchivo);/// CONSTRUCTOR PARA ELEGIR ALGUN OTRO NOMBRE QUE NO SEA empleados.dat

    bool guardar(Empleado empl);
    Empleado leer(int nroRegistro);
    void buscarPorAnio(int anio);
    int cantidadEmpleados();
    int buscarRegistro();
    bool editar(Empleado empleado, int nroRegistro);
    void vaciar();
    int buscarPorID(int id);
    void leerVector(Empleado *vec,int cantidadRegistros);
    bool guardarVector(Empleado *vec,int cantidadRegistros);
    void bajaLogica(int id);
    int buscarRegistroPorId(int id);
    int buscarPorDni(int dni);
    int buscarPorNombre(char *nombre);
    int buscarPorApellido(char *apellido);
    int buscarPorEdad(int edad);
    int existeEmpleado(Empleado empleado);

    int calcularEdad(Fecha fechaNacimiento);



};

#endif // EMPLEADOARCHIVO_H
