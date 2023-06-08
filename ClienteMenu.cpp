#include "ClienteMenu.h"
#include "ClienteTareas.h"
#include"marco_menu.h"
#include "rlutil.h"


void ClienteMenu::mostrar()
{
    ClienteTareas clienteTareas;
   // marco_menu marco;
    int opcion;
    do
    {
        system("cls");
      // marco.mostrar_cliente();
        cout<<"----------------------------------"<<endl;
        cout<<"\tMENU CLIENTES"<<endl;
        cout<<"1 - CARGAR "<<endl;
        cout<<"2 - EDITAR "<<endl;
        cout<<"3 - LISTAR TODOS"<<endl;
        cout<<"4 - LISTAR POR NUMERO DE SOCIO"<<endl;/// Y MAS OPCIONES
        cout<<"5 - LISTAR CLIENTES QUE PRACTICAN BOXEO"<<endl;
        cout<<"6 - BUSCAR "<<endl;
        cout <<"7 - DAR DE BAJA UN CLIENTE" << endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"----------------------------------"<<endl;
        cout<<"OPCION: ";
        rlutil::locate(10,22);
        cout<<"OPCION: ";
        cin>>opcion;
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
clienteTareas.mostrarTodos();
 system("pause");
            break;
        case 6:
clienteTareas.mostrarPorDni();
 system("pause");
 break;
        case 7:
clienteTareas.darBajaCliente();
            break;
        }
      //  if(opcion!=0)
     //   {
      //      system("pause");
      //  }

    }
    while(opcion!=0);
}
