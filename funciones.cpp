#include "funciones.h"

cout<<"Angel crack"<<endl;

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
