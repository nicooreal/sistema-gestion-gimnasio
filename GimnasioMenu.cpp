#include "GimnasioMenu.h"
#include"marco_menu.h"
#include "rlutil.h"
#include "ClienteTareas.h"
#include "PagoTareas.h"
void GimnasioMenu::mostrar()
{

    int opcion;
    ClienteTareas clienteTareas;

    do
    {

        do
        {


            system("cls");
            cout<<"----------------------------------"<<endl;
            cout <<"\tMENU GIMNASIO"<<endl;
            cout <<"1 - REGISTRAR PAGO"<<endl;
            cout <<"2 - MOSTRAR LOS PAGOS"<< endl;
            cout <<"3 - MOSTRAR CLIENTES CON FECHA POR VENCER" << endl;
            cout <<"4 - MOSTRAR RECAUDACION ANUAL" << endl;
            cout <<"5 - ELIMINAR PAGO ERRONEO" << endl;
            cout <<"6 - REGISTRAR INGRESOS" << endl;
            cout <<"7 - ELIMINAR TODOS LOS REGISTROS DE PAGOS"<<endl;
            cout <<"8 - RECAUDACION POR CLIENTES"<<endl;
            cout<<"0 - SALIR"<<endl;
            cout<<"----------------------------------"<<endl;
            cout<<"OPCION: ";
            cin>>opcion;
            system("cls");
        }
        while(opcion<0||opcion>8);

        switch(opcion)
        {
        case 1:
            _pagoTareas.cargarPago(false,0);
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

            _pagoTareas.eliminarPago();

            break;

        case 6:

            clienteTareas.registrarIngresos();

            break;
        case 7:
            _pagoTareas.eliminarTodosLosPagos();
            break;
        case 8:
            _pagoTareas.recaudacionPorClientes();
            break;


        }
        if(opcion!=0)
        {
            system("pause");
        }

    }
    while(opcion!=0);
}
