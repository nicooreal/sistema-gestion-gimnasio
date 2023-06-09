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
        cout<<"1 - REGISTRAR PAGO"<<endl;
        cout <<"2 - MOSTRAR RECAUDACION ANUAL" << endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"----------------------------------"<<endl;
        //rlutil::locate(10,18);
        cout<<"OPCION: ";
        cin>>opcion;
        system("cls");

        switch(opcion)
        {
        case 1:

            break;
        }
       // if(opcion!=0)
      //  {
      //      system("pause");
      //  }

    }
    while(opcion!=0);
}
