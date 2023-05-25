#include "EmpleadoTareas.h"

void EmpleadoTareas::cargar()
{
    Empleado reg;
    reg.cargarEmpleado();


    _archivo.guardar(reg);
}

void EmpleadoTareas::listarEmpleadosPorAnio()
{
    int anio;
    cout<<"Ingrese el anio para listar empleados"<<endl;
    cin>>anio;
    cout<<endl;
    _archivo.buscarPorAnio(anio);

}

void EmpleadoTareas::modificar() {


     int numeroRegistro = _archivo.buscarRegistro();
    if (numeroRegistro>=0) {
        cout << "Modifique al empleado"<<endl;
        Empleado empleadoModificado ;
        empleadoModificado.cargarEmpleado();

        bool exito = _archivo.editar(empleadoModificado, numeroRegistro);
        if (exito) {
            cout << "Registro modificado exitosamente." << endl;
        } else {
            cout << "No se pudo modificar el registro." << endl;
        }
    }
}
