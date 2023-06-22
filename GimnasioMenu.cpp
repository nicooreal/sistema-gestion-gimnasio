#include "GimnasioMenu.h"
#include"marco_menu.h"
#include "rlutil.h"
#include "ClienteTareas.h"
#include "PagoTareas.h"
void GimnasioMenu::mostrar()
{
    // marco_menu marco;
    int opcion;
    ClienteTareas clienteTareas;

    do
    {
        //   marco.mostrar_gimnasio();
        system("cls");
        cout<<"----------------------------------"<<endl;
        cout <<"\tMENU GIMNASIO"<<endl;
        cout <<"1 - REGISTRAR PAGO"<<endl;
        cout <<"2 - MOSTRAR LOS PAGOS"<< endl;
        cout <<"3 - MOSTRAR CLIENTES CON FECHA POR VENCER" << endl;
        cout <<"4 - MOSTRAR RECAUDACION ANUAL" << endl;
        cout <<"5 - REGISTRAR INGRESOS" << endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"----------------------------------"<<endl;
        //rlutil::locate(10,18);
        cout<<"OPCION: ";
        cin>>opcion;
        system("cls");

        switch(opcion)
        {
        case 1:
            _pagoTareas.cargarPago();
            break;

        case 2:
            _pagoTareas.mostrarTodos();
            break;

        case 3:
            clienteTareas.mostrarClientesConFechaPorVencer(); //metodo incompleto

            break;

                case 4:

            _pagoTareas.recaudacionAnual();


            break;


        case 5:

clienteTareas.registrarIngresos();

            break;


        }
        if(opcion!=0)
        {
            system("pause");
        }

    }
    while(opcion!=0);
}
