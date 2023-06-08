#include "ProveedorMenu.h"
#include"marco_menu.h"
#include "rlutil.h"


void ProveedorMenu::mostrar()
{
   // marco_menu marco;
    int opcion;
    do
    {
        //marco.mostrar_proveedores();
        system("cls");
        cout<<"----------------------------------"<<endl;
        cout<<"\tMENU PROVEEDORES"<<endl;
        cout<<"1 - CARGAR "<<endl;
        cout<<"2 - EDITAR "<<endl;
        cout<<"3 - LISTAR TODOS"<<endl;
        cout<<"4 - LISTAR POR ID"<<endl; /// Y MAS OPCIONES
        cout<<"0 - SALIR"<<endl;
        cout<<"----------------------------------"<<endl;
       // rlutil::locate(10,23);
        cout<<"OPCION: "; cin>>opcion;
        system("cls");

        switch(opcion)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        }
        if(opcion!=0)
        {
            system("pause");
        }

    }while(opcion!=0);
}
