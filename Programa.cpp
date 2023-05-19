#include "Programa.h"

void Programa::ejecutar()
{
    int opcion;

    do
    {
        system("cls");
        cout<<"--------------------------"<<endl;
        cout<<"\tMENU PRINCIPAL"<<endl;
        cout<<"1 - EMPLEADOS"<<endl;
        cout<<"2 - CLIENTES"<<endl;
        cout<<"3 - PROVEEDORES"<<endl;
        cout<<"4 - GIMNASIO"<<endl; /// PODIAMOS INCLUIR CLASES COMO BACKUP Y RESTAURAR BACKUP PARA CADA UNA(Recomiendo ver la ultima clase de labo)
        cout<<"0 - SALIR"<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"OPCION: "<<endl;
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

        }
        system("pause");

    }while(opcion!=0);

}
