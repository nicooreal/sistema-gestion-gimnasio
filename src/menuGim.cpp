#include "menuGim.h"
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include "Persona.h"
#include "funciones.h"
#include "Cliente.h"
#include "Empleado.h"
using namespace std;




void menuGim::mostrarMenuPrincipal(){


 setlocale(LC_ALL,"");

    int opcion;
    char salir;


    while(true)
    {
        system("cls");
        cout<<"------------------------------------------------------"<<endl;
        cout<<"\t1 - VER GIMNASIO"<<endl;
        cout<<"\t2 - HISTORIAL DEL GIMNASIO"<<endl;
        cout<<"\t0 - SALIR"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<"\tOPCION: "; cin>>opcion;
        system("cls");

        switch(opcion)
        {
        case 1:
            subMenu1();

            break;
        case 2:

            break;

        case 0:
            cout<<"ESTÁ SEGURO QUE DESEA SALIR(S - SI, N - NO): "; cin>>salir;
            if(salir=='s'||salir=='S')
            {
                exit(0);
            }
            break;
        default:
            cout<<"OPCION NO VALIDA"<<endl;
            break;

        }

        system("pause");

    }





    system("pause");

}


void menuGim::subMenu1(){

  int op;
    do
    {
        system("cls");
        cout<<"--------------------------------------------------"<<endl;
        cout<<"\t1 - CARGAR INFORMACION DEL GIMNASIO"<<endl; /// ES SOLO PARA CARGAR LOS DATOS DE TU GIMNASIO EJEMPLO: CARGAR NUEVO CLIENTE,PROVEEDOR,EMPLEADO,NUMERO GIM
        cout<<"\t2 - VER TIPOS DE CLASES"<<endl;  /// PODEMOS PONER DENTRO UN MENU QUE NOS MUESTRE CLASE YOGA - LISTAR PROFESORES - ORDENADOS POR AÑOS DE EXPERIENCIA
        cout<<"\t3 - VER PROVEEDORES"<<endl; /// LISTAR PROVEEDORES QUE OFRECEN DESCUENTOS O LISTAR PROVEEDORES ORDENADOS POR PRECIO(DEL MAS BARATO AL MAS CARO)
        cout<<"\t4 - DATOS DE CLIENTES"<<endl; /// LISTAR CLIENTES QUE SE LES HAN VENCIDO EL MES - LISTAR CANTIDAD DE CLIENTES INSCRIPTOS EN EL AÑO 2002
        cout<<"\t5 - DATOS DE EMPLEADOS"<<endl; /// MAS DE LO MISMO QUE TIENE CLIENTE
        cout<<"\t6 - VER INSCRIPCIONES"<<endl; ///
        cout<<"\t0 - SALIR"<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<"OPCION: "; cin>>op;
        system("cls");

        Persona per;
        Empleado emp;
    switch(op)
    {

        case 1:
            // Lo dejo aca para que vean que funciona pero despues escribiremos el archivo y  lo leeremos en el punto 5
            cargarInformacionGimnasio();
            break;

        case 2:

           break;
        case 3:

           break;
        case 4:

           break;
       case 5:


          break;
        case 6:

            break;
        default:
            cout<<"Opción no valida"<<endl;
            break;

    }
    if(op!=0) /// PARA QUE NO SE REPITA 2 VECES EL "PAUSE"
    {
        system("pause");
    }

    }while(op!=0);



}

void menuGim::cargarInformacionGimnasio()
{
    int opcion;
    do
    {
        system("cls");
        cout<<"---------------------------------"<<endl;
        cout<<"1- NUEVO EMPLEADO"<<endl;
        cout<<"2- NUEVO CLIENTE"<<endl;
        cout<<"0- Salir"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"Opcion: "; cin>>opcion;

        switch(opcion)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 0:
            cout<<"SALIENDO..."<<endl;
            break;
        }
        if(opcion!=0)
        {
            system("pause");
        }
    }while(opcion!=0);
}

