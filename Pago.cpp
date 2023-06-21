# include<iostream>
# include<cstdlib>
using namespace std;
#include "Pago.h"
#include "Cliente.h"
Pago::Pago()
{
 //vAniosMeses[50][12]{};
}
 int Pago::getvAniosMeses() {

 }

/*
 int Pago::setRecaudacionAnual(int vAnMe[][12]){
    _vAniosMeses[][12]= vAnMe[][12];

 }

*/
 void Pago::Mostrar(){
     int  vAniosMeses[50][12] ;
     int i;
     for(i=0; i<50; i++)
        {
            for (int j=0; j<12; j++)
            {
                cout << vAniosMeses[i][j] <<endl;
            }
        }
 }


     int Pago::getDni(){
     return _dni;

     }

     float Pago::getPago(){
     return _pago;
     }

     Fecha Pago::getFecha(){
     return _fechaDePago;
     }

     void Pago::setDni(int dni ){
     _dni = dni;

     }
     void Pago::setPago(float pago){
     _pago = pago;


     }
     void Pago::setFechaPago(Fecha fechaPago){
     _fechaDePago = fechaPago;


     }
