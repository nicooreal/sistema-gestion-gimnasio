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

void  Pago::MostrarRecaudacionAnual(float vRecaudacionAnual[12]){
    for(int i=0;i<12;i++) {
     cout <<"Mes "<< i+1 << endl;
     cout << "Recaudacion: "<< vRecaudacionAnual[i]<<endl;

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


     bool Pago::getEstado(){
     return _estado;

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

     void Pago::setEstado(bool estado ){
     _estado = estado;


     }
