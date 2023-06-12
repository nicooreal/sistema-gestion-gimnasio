#include "Yoga.h"

Yoga::Yoga(){
Fecha fecha;
_fechaAlta = fecha;
_fechaLimitePago = fecha; // falta funcion para calcular;
_cuotaMensual =  3000;

}


bool Yoga::getActivo(){

return _activo;

}
void Yoga::setActivo(bool activo){

_activo = activo;

}

Fecha Yoga::getFechaAlta(){

return _fechaAlta;

}
void Yoga::setFechaAlta(Fecha fecha){

_fechaAlta = fecha;

}

Fecha Yoga::getFechaLimitePago(){

return _fechaLimitePago;

}
void Yoga::setFechaLimitePago(Fecha fecha){

_fechaLimitePago = fecha;

}

bool Yoga::getCuotaMensual(){

return _cuotaMensual;


}
void Yoga::setCuotaMensual(float cuota){


_cuotaMensual = cuota;

}

