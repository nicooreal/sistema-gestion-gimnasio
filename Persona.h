#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <string.h>
#include <cstdio>
#include <iostream>
#include "Fecha.h"
#include "Direccion.h"

using namespace std;

class Persona
{
protected:
    char _nombre[30];
    char _apellido[30];
    int _dni;
    int _cuil;
    int _edad;
    char _genero[30];
    Fecha _fechaNacimiento;/// COMPOSICION
    Direccion _direccion;  /// COMPOSICION


public:
    Persona();
    Persona(char *nombre,char *apellido,int dni,int cuil,int edad,char *genero,Fecha nacimiento,Direccion direccion);

    void cargarPersona();
    void mostrarPersona();

    void setNombre(char *nombre);
    void setApellido(char *apellido);
    void setDni(int dni);
    void setCuil(int cuil);
    void setEdad(int edad);
    void setSexo(char *genero);
    void setFechaNacimiento(Fecha fechaNacimiento);
    void setDireccion(Direccion direccion);

    const char *getNombre();
    const char *getApellido();
    int getDni();
    int getCuil();
    int getEdad();
    const char *getGenero();
    Fecha getFechaNacimiento();
    Direccion getDireccion();



};


#endif // PERSONA_H_INCLUDED
