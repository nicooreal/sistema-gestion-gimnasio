# include<iostream>
# include<cstdlib>
using namespace std;
#include "Pago.h"
#include "PagoArchivos.h"
#include "Cliente.h"
Pago::Pago()
{
//vAniosMeses[50][12]{};
}
int Pago::getvAniosMeses()
{

}



int Pago::getDni()
{
    return _dni;

}

float Pago::getPago()
{
    return _pago;
}

Fecha Pago::getFecha()
{
    return _fechaDePago;
}


bool Pago::getEstado()
{
    return _estado;

}

int Pago::getId()
{
    return _id;
}

void Pago::setDni(int dni )
{
    _dni = dni;

}
void Pago::setPago(float pago)
{
    _pago = pago;


}
void Pago::setFechaPago(Fecha fechaPago)
{
    _fechaDePago = fechaPago;


}

void Pago::setEstado(bool estado )
{
    _estado = estado;


}

void Pago::setId(int id)
{
    _id = id;


}


void Pago::mostrarPago()
{
   if (_estado) {
    cout << "ID DE PAGO: #" << getId() << endl;
    cout << "DNI CLIENTE: " <<getDni()<< endl;
    cout << "FECHA DEL PAGO: "<< getFecha().getDia() <<"/"<< getFecha().getMes()<<"/"<< getFecha().getAnio()<< endl;
    cout << "MONTO DEL PAGO: "<< getPago() << endl;
    cout <<"-------------------------"<< endl;
   }

}





