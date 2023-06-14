#include "EmpleadoTareas.h"

void EmpleadoTareas::cargar()
{
    Empleado reg;
    int id=generarID();
    cout<<"ID Empleado #"<<id<<endl;
    reg.setId(id);
    cout<<endl;
    reg.cargarEmpleado();


    _archivo.guardar(reg);
}

void EmpleadoTareas::listarRegistros()
{
    int cant=_archivo.cantidadEmpleados();
    for(int i=0;i<cant;i++)
    {

        Empleado em=_archivo.leer(i);
        cout<<"ID Empleado #"<<em.getId()<<endl;
        em.mostrarEmpleado();
        cout<<"---------------------------------------"<<endl;
    }
}

void EmpleadoTareas::listarEmpleadosPorAnio()
{
    int anio;
    cout<<"Ingrese el anio para listar empleados"<<endl;
    cin>>anio;
    cout<<endl;
    _archivo.buscarPorAnio(anio);

}

void EmpleadoTareas::listarPorId()
{
    int id;
    cout<<"Ingrese el id"<<endl;
    cin>>id;
    _archivo.buscarPorID(id);

}

void EmpleadoTareas::modificar()
{
Empleado empleado;

    int numeroRegistro = _archivo.buscarRegistro();
    if (numeroRegistro>=0)
    {



        cout << "Modifique al empleado"<<endl;
        Empleado empleadoModificado ;
        empleadoModificado.cargarEmpleado();

        bool exito = _archivo.editar(empleadoModificado, numeroRegistro);
        if (exito)
        {
            cout << "Registro modificado exitosamente." << endl;
        }
        else
        {
            cout << "No se pudo modificar el registro." << endl;
        }
    }
}

void EmpleadoTareas::borrarRegistros()
{
    _archivo.vaciar();
}

int EmpleadoTareas::generarID()
{
    return _archivo.cantidadEmpleados()+1;
}
