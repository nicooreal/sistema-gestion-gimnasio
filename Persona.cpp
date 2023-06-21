#include "Persona.h"
#include "funciones.h"

Persona::Persona()
{
    strcpy(_nombre,"sinNombre");
    strcpy(_apellido,"sinApellido");
    _dni=0;
    _edad=0;
    _genero='0';
    _fechaNacimiento.fechaDeHoy();
    _estado=false;

}

Persona::Persona(char *nombre,char *apellido,int dni,int edad,char genero,Fecha fechaNacimiento,bool estado)
{
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
    cout<<"Nombre: ";
    cargarCadena(_nombre,29);
    cout<<"Apellido: ";
    cargarCadena(_apellido,29);
    cout<<"DNI: ";
    cin>>_dni;
    cout<<"Fecha nacimiento: "<<endl;
    _fechaNacimiento.cargar();
    calcularEdad();
    do
    {
        cout<<"Genero(M - MASCULINO, F - FEMENINO): ";
        cin>>_genero;

    }
    while(_genero!='F'&&_genero!='f'&&_genero!='m'&&_genero!='M');
    _estado=true;
}

void Persona::mostrarPersona()
{
    cout<<"Nombre: "<<_nombre<<endl;
    cout<<"Apellido: "<<_apellido<<endl;
    cout<<"DNI: "<<_dni<<endl;
    cout<<"Edad: "<<_edad<<endl;
    cout<<"Genero: "<<_genero<<endl;
    cout<<"Fecha nacimiento: "<<endl;
    _fechaNacimiento.mostrar();
}

void Persona::calcularEdad()
{
    Fecha fecha;
// el contructor por defecto pone la fecha de hoy, por eso con get anio sale 2023

    _edad = fecha.getAnio() - _fechaNacimiento.getAnio();
    if(fecha.getMes()<_fechaNacimiento.getMes()||fecha.getMes()==_fechaNacimiento.getMes()&&fecha.getDia()<_fechaNacimiento.getDia())
    {
        _edad--;
    }

}

void Persona::setNombre(char *nombre)
{
    strcpy(_nombre,nombre);
}

void Persona::setApellido(char *apellido)
{
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

