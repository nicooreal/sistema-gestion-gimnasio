#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include "Persona.h"

using namespace std;

int main()
{
    setlocale(LC_ALL,"");

    int opcion;
    char salir;
    cout<<"Hola soy Alexis"<<endl;
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
            int op;
            do
            {
                system("cls");
                cout<<"--------------------------------------------------"<<endl;
                cout<<"\t1 - CARGA LA INFORMACION DE TU GIMNASIO"<<endl;/// ES SOLO PARA CARGAR LOS DATOS DE TU GIMNASIO
                cout<<"\t2 - VER TIPOS DE CLASES"<<endl;
                cout<<"\t3 - VER PROVEEDORES"<<endl;
                cout<<"\t4 - DATOS DE CLIENTES"<<endl;
                cout<<"\t5 - DATOS DE EMPLEADOS"<<endl;
                cout<<"\t6 - VER FORMAS DE PAGO"<<endl;
                cout<<"\t7 - VER INSCRIPCIONES"<<endl;
                cout<<"\t0 - SALIR"<<endl;
                cout<<"--------------------------------------------------"<<endl;
                cout<<"OPCION: "; cin>>op;
                system("cls");
                switch(op)
                {
                case 1:

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
                case 7:

                    break;



                }
                if(op!=0) /// PARA QUE NO SE REPITA 2 VECES EL "PAUSE"
                {
                    system("pause");
                }

            }while(op!=0);


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
