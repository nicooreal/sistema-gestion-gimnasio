#ifndef PAGO_H
#define PAGO_H
#include "Cliente.h"
#include "Fecha.h"
class Pago
{
    private:



int _dni;
float _pago;
int _id;
Fecha _fechaDePago;
bool _estado;






    public:
     Pago();
     int setRecaudacionAnual();
     int getvAniosMeses() ;
     void gsetvAniosMeses(int vAnMe[][12]) ;
     void  MostrarRecaudacionAnual(float vRecaudacionAnual[12]);



     int getDni();
     float getPago();
     Fecha getFecha();
     bool getEstado();
     int getId();

     void setDni(int dni );
     void setPago(float pago);
     void setFechaPago(Fecha fechaPAgo);
     void setEstado(bool estado);
     void setId(int id);

/*





}
*/



};

#endif // PAGO_H
