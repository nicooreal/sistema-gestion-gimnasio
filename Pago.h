#ifndef PAGO_H
#define PAGO_H
#include "Cliente.h"
#include "Fecha.h"
class Pago
{
    private:
   int  _vAniosMeses[50][12];
/*
dni de cliente
numero socio
float pago
actividad que pago
fecha de pago





*/

    public:
     Pago();
     int setRecaudacionAnual();
     int getvAniosMeses() ;
     void gsetvAniosMeses(int vAnMe[][12]) ;
     void Mostrar();

/*
void cargarPago()
{

cout<<"ingrese el dni del cliente"<< endl;
cin>>dni;
setNumeroSocio()
setFechapago()
mostrar cliente.
cout<<"elija la actividad a pagar"<< endl;
cin>> actividad;

guardarPago;




}
*/



};

#endif // PAGO_H
