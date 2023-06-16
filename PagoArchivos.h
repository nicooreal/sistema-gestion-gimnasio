#ifndef PAGOARCHIVOS_H
#define PAGOARCHIVOS_H
#include <iostream>
#include <string.h>

using namespace std;
#include "Pago.h"

class PagoArchivos
{
    private:    char _nombreArchivo[30];

    public:
    PagoArchivos();/// CONSTRUCTOR PARA PONER POR DEFECTO pago.dat
    PagoArchivos(const char *nombreArchivo);/// CONSTRUCTOR PARA ELEGIR ALGUN OTRO NOMBRE QUE NO SEA pago.dat
    bool  guardar(Pago pago)  ;
    Pago leer(int nroRegistro);
     int getCantidad();

};

#endif // PAGOARCHIVOS_H
