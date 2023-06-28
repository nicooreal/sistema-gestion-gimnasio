#include "EmpleadoMenu.h"
#include"marco_menu.h"
#include "rlutil.h"
#include "funciones.h"


void EmpleadoMenu::mostrar()
{

    int opcion;
    do
    {

        system("cls");
        cout<<"----------------------------------"<<endl;
        cout<<"\tMENU EMPLEADOS"<<endl;
        cout<<"1 - CARGAR "<<endl;
        cout<<"2 - EDITAR "<<endl;
        cout<<"3 - LISTADOS"<<endl;
        cout<<"4 - CONSULTAS"<<endl; /// Y MAS OPCIONES
        cout<<"5 - DAR DE BAJA EMPLEADO"<<endl;
        cout<<"6 - REACTIVAR EMPLEADO" << endl;
        cout<<"7 - ELIMINAR TODOS LOS REGISTROS"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"----------------------------------"<<endl;

        cout<<"OPCION: ";
        cin>>opcion;
        validarDosRangos(opcion,0,7);

        system("cls");

        switch(opcion)
        {
        case 1:
            _empleadoTareas.cargar();
            break;
        case 2:
            _empleadoTareas.modificar();

            break;
        case 3:
            _empleadoTareas.listados();

            break;
        case 4:
            _empleadoTareas.consultas();
            break;
        case 5:
            _empleadoTareas.darDeBajaEmpleado();
            break;

        case 6:
            _empleadoTareas.reactivarEmpleado();
            break;

                case 7:
            _empleadoTareas.borrarRegistros();
            break;
        }
        if(opcion!=0)
        {
            system("pause");
        }

    }while(opcion!=0);
}
