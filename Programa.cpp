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
        do
        {
            system("cls");
            cout<<"--------------------------"<<endl;
            cout<<"\tMENU PRINCIPAL"<<endl;
            cout<<"1 - EMPLEADOS"<<endl;
            cout<<"2 - CLIENTES"<<endl;
            cout<<"3 - GIMNASIO"<<endl; /// PODIAMOS INCLUIR CLASES COMO BACKUP Y RESTAURAR BACKUP PARA CADA UNA(Recomiendo ver la ultima clase de labo)
            cout<<"4 - BACKUPS"<<endl;
            cout<<"0 - SALIR"<<endl;
            cout<<"--------------------------"<<endl;

            cout<<"OPCION: ";
            cin>>opcion;
            system("cls");
        }
        while(opcion<0||opcion>4);


        switch(opcion)
        {
        case 1:
            _empleadoMenu.mostrar();
            break;
        case 2:
            _clienteMenu.mostrar();
            break;
        case 3:
            _gimnasioMenu.mostrar();
            break;
        case 4:
            _configuracionMenu.mostrar();
            break;

        }
        //system("pause");

    }
    while(opcion!=0);

}
