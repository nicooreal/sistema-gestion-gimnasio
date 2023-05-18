#include "ClienteMenu.h"

void ClienteMenu::mostrar()
{
    int opcion;
    do
    {
        system("cls");
        cout<<"----------------------------------"<<endl;
        cout<<"\tMENU CLIENTES"<<endl;
        cout<<"1 - CARGAR "<<endl;
        cout<<"2 - EDITAR "<<endl;
        cout<<"3 - LISTAR TODOS"<<endl;
        cout<<"4 - LISTAR POR ID"<<endl; /// Y MAS OPCIONES
        cout<<"0 - SALIR"<<endl;
        cout<<"----------------------------------"<<endl;
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
