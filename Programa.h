#ifndef PROGRAMA_H
#define PROGRAMA_H
#include <iostream>

using namespace std;
#include "EmpleadoMenu.h"
#include "ClienteMenu.h"
#include "ProveedorMenu.h"
#include "GimnasioMenu.h"

class Programa
{
    private:
        EmpleadoMenu _empleadoMenu;
        ClienteMenu _clienteMenu;
        ProveedorMenu _proveedorMenu;
        GimnasioMenu _gimnasioMenu;

    public:

        void ejecutar();


};

#endif // PROGRAMA_H
