#include "GimnasioMenu.h"
#include"marco_menu.h"
#include "rlutil.h"

void GimnasioMenu::mostrar()
{
   // marco_menu marco;
    int opcion;
    do
    {
     //   marco.mostrar_gimnasio();
        system("cls");
        cout<<"----------------------------------"<<endl;
        cout<<"\tMENU GIMNASIO"<<endl;
        cout<<"1 - CANTIDAD EMPLEADOS "<<endl;
        cout<<"2 - CANTIDAD CLIENTES "<<endl;
        cout<<"3 - GUARDAR CLIENTES QUE PRACTICAN BOXEO"<<endl; /// LO GUARDARIAMOS EN UN ARCHIVO .DAT
        cout<<"0 - SALIR"<<endl;
        cout<<"----------------------------------"<<endl;
        //rlutil::locate(10,18);
        cout<<"OPCION: ";
        cin>>opcion;
        system("cls");

        switch(opcion)
        {
        case 1:
            _gimnasioTareas.cantidadEmpleados();
            break;
        }
       // if(opcion!=0)
      //  {
      //      system("pause");
      //  }

    }
    while(opcion!=0);
}
