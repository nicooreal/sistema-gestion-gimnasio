#include "ConfiguracionesMenu.h"
#include "funciones.h"

void ConfiguracionesMenu::mostrar()
{
    int opcion;
    CopiaDeSeguridadTareas configuracionTareas;


    do
    {
        system("cls");
        cout<<"MENU CONFIGURACION"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"1 - HACER COPIA DE SEGURIDAD"<<endl;
        cout<<"2 - RESTAURAR COPIA DE SEGURIDAD"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"OPCION: ";
        cin>>opcion;
        validarDosRangos(opcion,0,2);

        system("cls");

        switch(opcion)
        {
        case 1:
            configuracionTareas.ElegirTipoBackup();
            break;
        case 2:
            configuracionTareas.ElegirRestaurarTipoBackup();
            break;

        }
        if(opcion!=0)
        {
            system("pause");
        }

    }while(opcion!=0);
}
