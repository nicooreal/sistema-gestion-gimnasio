#pragma once
#ifndef EMPLEADOMENU_H
#define EMPLEADOMENU_H
#include <iostream>

using namespace std;
#include "EmpleadoTareas.h"

class EmpleadoMenu
{
    private:
        EmpleadoTareas _empleadoTareas;

    public:
        void mostrar();
};

#endif // EMPLEADOMENU_H
