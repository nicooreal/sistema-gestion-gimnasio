#ifndef PAGO_H
#define PAGO_H
#include "Cliente.h"
#include "Fecha.h"
class Pago
{
    private:



int _dni;
float _pago;
//actividad que pago
Fecha _fechaDePago;







    public:
     Pago();
     int setRecaudacionAnual();
     int getvAniosMeses() ;
     void gsetvAniosMeses(int vAnMe[][12]) ;
     void Mostrar();

     int getDni();
     float getPago();
     Fecha getFecha();

     void setDni(int dni );
     void setPago(float pago);
     void setFechaPago(Fecha fechaPAgo);


/*





}
*/



};

#endif // PAGO_H
