#pragma once
#ifndef GIMNASIOMENU_H
#define GIMNASIOMENU_H
#include <iostream>

using namespace std;
#include "GimnasioTareas.h"
#include "PagoTareas.h"

class GimnasioMenu
{
private:
    PagoTareas _pagoTareas;

public:
    void mostrar();

};

#endif // GIMNASIOMENU_H
