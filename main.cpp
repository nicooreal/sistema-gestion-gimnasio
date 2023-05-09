#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include "Persona.h"
#include "funciones.h"
#include "Cliente.h"
#include "Empleado.h"
using namespace std;

int main()
{
    setlocale(LC_ALL,"");

    int opcion;
    char salir;

    system("pause");
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
            verMenuGimnasio();

            break;
        case 2:

            break;

        case 0:
            cout<<"ESTÁ SEGURO QUE DESEA SALIR(S - SI, N - NO): "; cin>>salir;
            if(salir=='s'||salir=='S')
            {
                return 0;
            }
            break;
        default:
            cout<<"OPCION NO VALIDA"<<endl;
            break;

        }

        system("pause");

    }





    system("pause");
    return 0;
}
