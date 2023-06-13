#ifndef BOXEO_H
#define BOXEO_H
#include "Fecha.h"

class Boxeo
{
    private:
bool _activo;
Fecha _fechaAlta;
Fecha _fechaLimitePago;
float _cuotaMensual;

    public:
Boxeo();
bool getActivo();
void setActivo(bool activo);

Fecha getFechaAlta();
void setFechaAlta(Fecha fecha);

Fecha getFechaLimitePago();
void setFechaLimitePago(Fecha fecha);

float getCuotaMensual();
void setCuotaMensual(float cuota);

};

#endif // BOXEO_H
