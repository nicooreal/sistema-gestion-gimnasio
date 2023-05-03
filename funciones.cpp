#include "funciones.h"



void cargarCadena(char *pal,int tam)
{

    int i;

    fflush(stdin);

    for(i=0;i<tam;i++){

        pal[i]=cin.get();

        if(pal[i]=='\n') break;

    }

    pal[i]='\0';

    fflush(stdin);

}

void verMenuGimnasio()
{
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
}
