#include "ClienteMenu.h"
#include "ClienteTareas.h"
#include"marco_menu.h"
#include "rlutil.h"


void ClienteMenu::mostrar()
{
    ClienteTareas clienteTareas;

    int opcion;
    do
    {
        system("cls");

        cout<<"----------------------------------"<<endl;
        cout<<"\tMENU CLIENTES"<<endl;
        cout<<"1 - CARGAR "<<endl;
        cout<<"2 - EDITAR "<<endl;
        cout<<"3 - LISTADOS"<<endl;
        cout<<"4 - CONSULTAS "<<endl;
        cout<<"5 - DAR DE BAJA UN CLIENTE"<<endl;
        cout<<"6 - REACTIVAR UN CLIENTE"<<endl;
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
            clienteTareas.cargar();
            break;
        case 2:
            clienteTareas.modificar();
            break;
        case 3:
            clienteTareas.listados();

            break;
        case 4:
            clienteTareas.consultas();

            break;
        case 5:
            clienteTareas.darBajaCliente();
            break;
        case 6:
            clienteTareas.reactivarCliente();
            break;


        case 7:
            clienteTareas.limpiarArchivoClientes();

            break;
        }
        if(opcion!=0)
        {
            system("pause");
        }

    }
    while(opcion!=0);
}
