#include <algorithm>
#include "funciones.h"
#include "Persona.h"
#include "Empleado.h"
using namespace std;

void cargarCadena(char *pal,int tam)
{

    int i;

    fflush(stdin);

    for(i=0; i<tam; i++)
    {

        pal[i]=cin.get();

        if(pal[i]=='\n') break;

    }

    pal[i]='\0';

    fflush(stdin);

}

void convertirAMayusculas(char* str)
{
    transform(str, str + strlen(str), str, [](unsigned char c)
    {
        return toupper(c);
    });
}

bool validar(int ingreso)
{
    bool esLetra=false;

    if (cin)
    {
        // Se ingresó un entero correctamente
        esLetra=true;
    }
    else
    {
        // Se ingresó un valor no válido


        // Limpiamos el estado de error de cin
        cin.clear();

        // Descartamos el contenido inválido ingresado por el usuario
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }


    return esLetra;




}

void validarIngresos(int &ingreso){
bool esValido = false;

     while(!esValido)
        {
            if(!validar(ingreso))
            {
                cout<<"INGRESE UN CARACTER VALIDO"<<endl;
                cin>>ingreso;
            }
            else {break;}

        }



}
