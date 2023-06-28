#pragma once
#ifndef YOGA_H
#define YOGA_H
#include "Fecha.h"

class Yoga
{
     private:
bool _activo;
Fecha _fechaAlta;
Fecha _fechaLimitePago;
float _cuotaMensual;

    public:
Yoga();
bool getActivo();
void setActivo(bool activo);

Fecha getFechaAlta();
void setFechaAlta(Fecha fecha);

Fecha getFechaLimitePago();
void setFechaLimitePago(Fecha fecha);

float getCuotaMensual();
void setCuotaMensual(float cuota);
};

#endif // YOGA_H
