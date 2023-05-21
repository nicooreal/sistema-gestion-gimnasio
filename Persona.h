#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <string.h>
#include <cstdio>
#include <iostream>
#include "Fecha.h"


using namespace std;

class Persona
{
protected:
    char _nombre[30];
    char _apellido[30];
    int _dni;
    int _edad;
    char _genero[30];
    Fecha _fechaNacimiento;/// COMPOSICION



public:
    Persona();
    Persona(char *nombre,char *apellido,int dni,int edad,char *genero,Fecha nacimiento);

    void cargarPersona();
    void mostrarPersona();

    void setNombre(char *nombre);
    void setApellido(char *apellido);
    void setDni(int dni);
    void setEdad(int edad);
    void setSexo(char *genero);
    void setFechaNacimiento(Fecha fechaNacimiento);


    const char *getNombre();
    const char *getApellido();
    int getDni();
    int getEdad();
    const char *getGenero();
    Fecha getFechaNacimiento();




};


#endif // PERSONA_H_INCLUDED
