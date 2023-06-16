#ifndef PAGO_H
#define PAGO_H
#include "Cliente.h"
#include "Fecha.h"
class Pago
{
    private:
   int  _vAniosMeses[50][12];

    public:
     Pago();
     int setRecaudacionAnual();
     int getvAniosMeses() ;
     void gsetvAniosMeses(int vAnMe[][12]) ;
     void Mostrar();
};

#endif // PAGO_H
