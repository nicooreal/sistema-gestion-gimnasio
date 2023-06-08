#include "EmpleadoMenu.h"
#include"marco_menu.h"
#include "rlutil.h"

void EmpleadoMenu::mostrar()
{
  //  marco_menu marco;
    int opcion;
    do
    {
    //    marco.mostrar_empleado();
        system("cls");
        cout<<"----------------------------------"<<endl;
        cout<<"\tMENU EMPLEADOS"<<endl;
        cout<<"1 - CARGAR "<<endl;
        cout<<"2 - EDITAR "<<endl;
        cout<<"3 - LISTAR TODOS"<<endl;
        cout<<"4 - LISTAR POR ID"<<endl; /// Y MAS OPCIONES
        cout<<"5 - LIMPIAR ARCHIVO"<<endl;
        cout<<"6 - LISTAR EMPLEADOS QUE INGRESARON EN X ANIO"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"----------------------------------"<<endl;
       //  rlutil::locate(10,23);
        cout<<"OPCION: "; cin>>opcion;
        system("cls");

        switch(opcion)
        {
        case 1:
            _empleadoTareas.cargar();
            break;
        case 2:
            _empleadoTareas.modificar();
            break;

        case 6:
            _empleadoTareas.listarEmpleadosPorAnio();
            break;
        }
        if(opcion!=0)
        {
            system("pause");
        }

    }while(opcion!=0);
}
