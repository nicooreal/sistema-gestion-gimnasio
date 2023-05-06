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
        cout<<"\t1 - CARGAR INFORMACION DEL GIMNASIO"<<endl; /// ES SOLO PARA CARGAR LOS DATOS DE TU GIMNASIO EJEMPLO: CARGAR NUEVO CLIENTE,PROVEEDOR,EMPLEADO,NUMERO GIM
        cout<<"\t2 - VER TIPOS DE CLASES"<<endl;  /// PODEMOS PONER DENTRO UN MENU QUE NOS MUESTRE CLASE YOGA - LISTAR PROFESORES - ORDENADOS POR AÑOS DE EXPERIENCIA
        cout<<"\t3 - VER PROVEEDORES"<<endl; /// LISTAR PROVEEDORES QUE OFRECEN DESCUENTOS O LISTAR PROVEEDORES ORDENADOS POR PRECIO(DEL MAS BARATO AL MAS CARO)
        cout<<"\t4 - DATOS DE CLIENTES"<<endl; /// LISTAR CLIENTES QUE SE LES HAN VENCIDO EL MES - LISTAR CANTIDAD DE CLIENTES INSCRIPTOS EN EL AÑO 2002
        cout<<"\t5 - DATOS DE EMPLEADOS"<<endl; /// MAS DE LO MISMO QUE TIENE CLIENTE
        cout<<"\t6 - VER FORMAS DE PAGO"<<endl; /// ESTO LO PODRIAMOS CAMBIAR
        cout<<"\t7 - VER INSCRIPCIONES"<<endl; ///
        cout<<"\t8 - VER SEDES"<<endl; ///
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
