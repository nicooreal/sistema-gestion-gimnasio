#include "EmpleadoTareas.h"

void EmpleadoTareas::cargar()
{
    Empleado reg;
    reg.cargarEmpleado();

    _archivo.guardar(reg);
}

void EmpleadoTareas::listarEmpleados2023()
{
    int anio;
    cout<<"Ingrese el anio para listar empleados"<<endl;
    cin>>anio;
    cout<<endl;
    _archivo.buscarPorAnio(anio);

}
