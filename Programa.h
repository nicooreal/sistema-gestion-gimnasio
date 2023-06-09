#pragma once
#ifndef PROGRAMA_H
#define PROGRAMA_H
#include <iostream>

using namespace std;
#include "EmpleadoMenu.h"
#include "ClienteMenu.h"
#include "GimnasioMenu.h"
#include "ConfiguracionesMenu.h"

class Programa
{
    private:
        EmpleadoMenu _empleadoMenu;
        ClienteMenu _clienteMenu;
        GimnasioMenu _gimnasioMenu;
        ConfiguracionesMenu _configuracionMenu;

    public:

        void ejecutar();


};

#endif // PROGRAMA_H
