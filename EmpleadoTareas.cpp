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

    int nroRegistro,dni;
    cout <<"Ingrese DNI del empleado que desea editar"<<endl;
    cout <<"DNI: ";
    cin >> dni;
    bool encontrado = _archivo.buscarRegistro(dni, nroRegistro);
    if (encontrado) {
        cout << "Modifique al empleado"<<endl;
        Empleado empleadoModificado ;
        empleadoModificado.cargarEmpleado();

        bool exito = _archivo.editar(empleadoModificado, nroRegistro);
        if (exito) {
            cout << "Registro modificado exitosamente." << endl;
        } else {
            cout << "No se pudo modificar el registro." << endl;
        }
    } else {
        cout << "No se encontro ningun registro con el DNI proporcionado." <<endl;
    }
}
