#include "Programa.h"
#include"marco_menu.h"
#include "rlutil.h"

void Programa::ejecutar()
{
    int opcion;
   // marco_menu marco;
    do
    {
        //marco.mostrar_menu();
        system("cls");
        cout<<"--------------------------"<<endl;
        cout<<"\tMENU PRINCIPAL"<<endl;
        cout<<"1 - EMPLEADOS"<<endl;
        cout<<"2 - CLIENTES"<<endl;
        cout<<"3 - PROVEEDORES"<<endl;
        cout<<"4 - GIMNASIO"<<endl; /// PODIAMOS INCLUIR CLASES COMO BACKUP Y RESTAURAR BACKUP PARA CADA UNA(Recomiendo ver la ultima clase de labo)
        cout<<"5 - BACKUPS"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"--------------------------"<<endl;
        rlutil::locate(10,18);
        cout<<"OPCION: ";
        cin>>opcion;
        system("cls");

        switch(opcion)
        {
        case 1:
            _empleadoMenu.mostrar();
            break;
        case 2:
            _clienteMenu.mostrar();
            break;
        case 3:
            _proveedorMenu.mostrar();
            break;
        case 4:
            _gimnasioMenu.mostrar();
            break;
        case 5:
            _configuracionMenu.mostrar();
            break;

        }
        //system("pause");

    }while(opcion!=0);

}
