#include "Persona.h"
#include "funciones.h"
#include "funciones.h"
#include <cctype>


Persona::Persona()
{
    strcpy(_nombre,"SINNOMBRE");
    strcpy(_apellido,"SINAPELLIDO");
    _dni=0;
    _edad=0;
    _genero='0';
    _fechaNacimiento.fechaDeHoy();
    _estado=false;

}

Persona::Persona(char *nombre,char *apellido,int dni,int edad,char genero,Fecha fechaNacimiento,bool estado)
{
    convertirAMayusculas(nombre);
    convertirAMayusculas(apellido);
    toupper(genero);

    strcpy(_nombre,nombre);
    strcpy(_apellido,apellido);
    _dni=dni;
    _edad=edad;
    _genero=genero;
    _fechaNacimiento=fechaNacimiento;
    _estado=estado;
}

void Persona::setEstado(bool estado)
{
    _estado=estado;
}

bool Persona::getEstado()
{
    return _estado;
}

void Persona::cargarPersona()
{
    cout<<"NOMBRE: ";
    cargarCadena(_nombre,29);
    convertirAMayusculas(_nombre);
    cout<<"APELLIDO: ";
    cargarCadena(_apellido,29);
    convertirAMayusculas(_apellido);
    do
    {
       cout<<"DNI: ";
       cin>>_dni;
    }while(_dni<=0);

    cout<<"Fecha nacimiento: "<<endl;
    _fechaNacimiento.cargar();
    _edad=calcularEdad(_fechaNacimiento);
    do
    {
        cout<<"GENERO (M - MASCULINO, F - FEMENINO): ";
        cin>>_genero;
        toupper(_genero);

    }
    while(_genero!='F'&&_genero!='f'&&_genero!='m'&&_genero!='M');
    _estado=true;
}

void Persona::mostrarPersona()
{
    cout<<"NOMBRE: "<<_nombre<<endl;
    cout<<"APELLIDO: "<<_apellido<<endl;
    cout<<"DNI: "<<_dni<<endl;
    cout<<"EDAD: "<<_edad<<endl;
    cout<<"GENERO: "<<_genero<<endl;
    cout<<"FECHA NACIMIENTO: "<<endl;
    _fechaNacimiento.mostrar();
}



void Persona::setNombre(char *nombre)
{
    convertirAMayusculas(nombre);
    strcpy(_nombre,nombre);
}

void Persona::setApellido(char *apellido)
{
    convertirAMayusculas(apellido);
    strcpy(_apellido,apellido);
}

void Persona::setDni(int dni)
{
    _dni=dni;
}

void Persona::setEdad(int edad)
{
    _edad=edad;
}

void Persona::setSexo(char genero)
{
    toupper(genero);
    _genero=genero;
}

void Persona::setFechaNacimiento(Fecha fechaNacimiento)
{
    _fechaNacimiento=fechaNacimiento;
}

const char *Persona::getNombre()
{
    return _nombre;
}

const char *Persona::getApellido()
{
    return _apellido;
}

int Persona::getDni()
{
    return _dni;
}

int Persona::getEdad()
{
    return _edad;
}

char Persona::getGenero()
{
    return _genero;
}

Fecha Persona::getFechaNacimiento()
{
    return _fechaNacimiento;
}

int Persona::calcularEdad(Fecha fechaNacimiento)
{
    Fecha hoy;
    int edad;
    edad=hoy.getAnio()-fechaNacimiento.getAnio(); /// OBTENGO EL AÑO ACTUAL

    if(hoy.getMes()<fechaNacimiento.getMes()||hoy.getMes()==fechaNacimiento.getMes()&&hoy.getDia()<fechaNacimiento.getDia())
    {
        edad--;
    }

    return edad;
}

