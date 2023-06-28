#pragma once
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include <string.h>

using namespace std;

void cargarCadena(char *pal,int tam);
void convertirAMayusculas(char* str);
bool validar(int opcionMensual);
void validarIngresos(int &ingreso);
void validarDosRangos(int &ingreso,int rangoMin,int rangoMax);
void validarQueNoSeaNegativa(int &ingreso);


#endif // FUNCIONES_H_INCLUDED

