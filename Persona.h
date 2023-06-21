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
    int _edad; // tendriamos que sacar poder calcularla con la fecha de nacimiento
    char _genero;
    Fecha _fechaNacimiento;/// COMPOSICION
    bool _estado;



public:
    Persona();
    Persona(char *nombre,char *apellido,int dni,int edad,char genero,Fecha nacimiento,bool estado);

    void cargarPersona();
    void mostrarPersona();

    void setEstado(bool estado);
    bool getEstado();

    void setNombre(char *nombre);
    void setApellido(char *apellido);
    void setDni(int dni);
    void setEdad(int edad);
    void setSexo(char genero);
    void setFechaNacimiento(Fecha fechaNacimiento);


    const char *getNombre();
    const char *getApellido();
    int getDni();
    int getEdad();
    char getGenero();
    Fecha getFechaNacimiento();

    void calcularEdad();



};


#endif // PERSONA_H_INCLUDED
