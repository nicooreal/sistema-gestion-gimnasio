#include "funciones.h"
#include "Persona.h"
#include "Empleado.h"
using namespace std;

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


/*int calcularAntiguedad(){
   int antiguedad;
    Empleado antig;
    Fecha fechaAct;
    antiguedad= aca deberia ir antig.xxxx - fechaAct.xxxx de esta forma llamandos metodos que devuevan enteros y que haga una resta entre si


return antiguedad;
} */
