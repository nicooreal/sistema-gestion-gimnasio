#include "Boxeo.h"


Boxeo::Boxeo(){
Fecha fecha;
_fechaAlta = fecha;
_fechaLimitePago = fecha.calcularUnMesDeEntreno(fecha); // el constructor establece por defecto un alta con cuota 1000 y pone la fecha de pago a un mes
_cuotaMensual =  1000;
_activo = true;
}


bool Boxeo::getActivo(){

return _activo;

}
void Boxeo::setActivo(bool activo){

_activo = activo;

}

Fecha Boxeo::getFechaAlta(){

return _fechaAlta;

}
void Boxeo::setFechaAlta(Fecha fecha){

_fechaAlta = fecha;

}

Fecha Boxeo::getFechaLimitePago(){

return _fechaLimitePago;

}
void Boxeo::setFechaLimitePago(Fecha fecha){

_fechaLimitePago = fecha;

}

float Boxeo::getCuotaMensual(){

return _cuotaMensual;


}
void Boxeo::setCuotaMensual(float cuota){


_cuotaMensual = cuota;

}
