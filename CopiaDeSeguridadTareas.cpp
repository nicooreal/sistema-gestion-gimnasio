#include "CopiaDeSeguridadTareas.h"
#include "funciones.h"

void CopiaDeSeguridadTareas::hacerCopiaDeClientes()
{
    ClienteArchivo archivo;
    int cantidadClientes=archivo.getCantidad();
    Cliente *vClientes=new Cliente[cantidadClientes];
    if(vClientes==nullptr)
    {
        cout<<"FALLA AL REALIZAR BACKUP"<<endl;
        return;
    }
    archivo.leerVector(vClientes,cantidadClientes);
    _archivoBackupCLiente.vaciar();
    if(_archivoBackupCLiente.guardarVector(vClientes,cantidadClientes))
    {
        cout<<"BACKUP REALIZADO CORRECTAMENTE"<<endl;
    }
    else
    {
        cout<<"FALLA AL REALIZAR BACKUP"<<endl;
    }

    delete[]vClientes;
}

void CopiaDeSeguridadTareas::hacerCopiaDeEmpleados()
{
    EmpleadoArchivo archivo;
    int cantidadEmpleados=archivo.cantidadEmpleados();
    Empleado *vEmpleados=new Empleado[cantidadEmpleados];
    if(vEmpleados==nullptr)
    {
        cout<<"FALLA AL REALIZAR BACKUP"<<endl;
        return;
    }
    archivo.leerVector(vEmpleados,cantidadEmpleados);
    _archivoBackupEmpleado.vaciar();
    if(_archivoBackupEmpleado.guardarVector(vEmpleados,cantidadEmpleados))
    {
        cout<<"BACKUP REALIZADO CORRECTAMENTE"<<endl;
    }
    else
    {
        cout<<"FALLA AL REALIZAR BACKUP"<<endl;
    }

    delete[]vEmpleados;
}

void CopiaDeSeguridadTareas::restaurarCopiaDeClientes()
{
    ClienteArchivo archivo;
    int cantidadRegistros=_archivoBackupCLiente.getCantidad();
    Cliente *vec=new Cliente[cantidadRegistros];

    if(vec==nullptr)
    {
        cout<<"Falla al restaurar backup "<<endl;
        return;
    }

    _archivoBackupCLiente.leerVector(vec,cantidadRegistros);
    archivo.vaciar();
    if(archivo.guardarVector(vec,cantidadRegistros))
    {
        cout<<"Backup restaurado correctamente"<<endl;
    }
    else
    {
        cout<<"Falla al restaurar backup"<<endl;
    }


    delete [] vec;
}

void CopiaDeSeguridadTareas::restaurarCopiaDeEmpleados()
{
    EmpleadoArchivo archivo;
    int cantidadRegistros=_archivoBackupEmpleado.cantidadEmpleados();
    Empleado *vec=new Empleado[cantidadRegistros];

    if(vec==nullptr)
    {
        cout<<"Falla al restaurar backup"<<endl;
        return;
    }

    _archivoBackupEmpleado.leerVector(vec,cantidadRegistros);
    archivo.vaciar();
    if(archivo.guardarVector(vec,cantidadRegistros))
    {
        cout<<"Backup restaurado correctamente"<<endl;
    }
    else
    {
        cout<<"Falla al restaurar backup"<<endl;
    }


    delete [] vec;
}

void CopiaDeSeguridadTareas::hacerCopiaDeTodo()
{
    hacerCopiaDeClientes();
    hacerCopiaDeEmpleados();
}

void CopiaDeSeguridadTareas::restaurarCopiaDeTodo()
{
    restaurarCopiaDeClientes();
    restaurarCopiaDeEmpleados();
}

void CopiaDeSeguridadTareas::ElegirTipoBackup()
{
    int opcion;
    do
    {
        do
        {
            system("cls");
            cout<<"\tTIPO BACKUP"<<endl;
            cout<<"-----------------------------------"<<endl;
            cout<<"1 - BACKUP CLIENTES"<<endl;
            cout<<"2 - BACKUP EMPLEADOS"<<endl;
            cout<<"3 - BACKUP A TODOS LOS ARCHIVOS"<<endl;
            cout<<"0 - SALIR"<<endl;
            cout<<"-----------------------------------"<<endl;
            cout<<"OPCION: ";
            cin>>opcion;
            validar(opcion);
            system("cls");

        }
        while(opcion<0||opcion>3);
        switch(opcion)
        {
        case 1:
            hacerCopiaDeClientes();
            break;
        case 2:
            hacerCopiaDeEmpleados();
            break;
        case 3:
            hacerCopiaDeTodo();
            break;
        }
        if(opcion!=0)
        {
            system("pause");
        }

    }
    while(opcion!=0);
}

void CopiaDeSeguridadTareas::ElegirRestaurarTipoBackup()
{
    int opcion;
    do
    {
        do
        {
            system("cls");
            cout<<"\tTIPO RESTAURACION BACKUP"<<endl;
            cout<<"-----------------------------------"<<endl;
            cout<<"1 - RESTAURAR CLIENTES"<<endl;
            cout<<"2 - RESTAURAR EMPLEADOS"<<endl;
            cout<<"3 - RESTAURAR A TODOS LOS ARCHIVOS"<<endl;
            cout<<"0 - SALIR"<<endl;
            cout<<"-----------------------------------"<<endl;
            cout<<"OPCION: ";
            cin>>opcion;
            validar(opcion);
            system("cls");

        }
        while(opcion<0||opcion>3);
        switch(opcion)
        {
        case 1:
            restaurarCopiaDeClientes();
            break;
        case 2:
            restaurarCopiaDeEmpleados();
            break;
        case 3:
            restaurarCopiaDeTodo();
            break;
        }
        if(opcion!=0)
        {
            system("pause");
        }

    }
    while(opcion!=0);
}
