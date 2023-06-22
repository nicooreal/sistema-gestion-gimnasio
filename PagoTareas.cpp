# include<iostream>
# include<cstdlib>
using namespace std;
#include "PagoTareas.h"
#include "Pago.h"
#include "PagoArchivos.h"
#include "ClienteArchivo.h"
#include "ClienteTareas.h"
PagoTareas::PagoTareas()
{
    //ctor
}

 void PagoTareas::cargarPago()
{
Pago pago;
int dni;
Fecha fechaHoy;
ClienteTareas clienteTareas;
ClienteArchivo clienteArch;
PagoArchivos pagoArch;
int cantidadClientes = clienteArch.getCantidad();
bool verificar = false;
cout <<"ingrese el dni del cliente a pagar "<< endl;
cin >> dni;


for (int i = 0; i < cantidadClientes; i++ ){
Cliente cliente = clienteArch.leer(i);

if ( dni == cliente.getDni()  ) {



    pago.setDni(dni);
    pago.setFechaPago( fechaHoy );
    pago.setPago( clienteTareas.acumularAbonos(dni)  ) ;  // generar un metodo con el abono total(boxeo,joya,etc),este metodo es solo pesas
    pago.setEstado(true);
    pagoArch.guardar(pago);
//

  verificar = true;
                                }
}


if ( verificar == false ) {

    cout <<"EL CLIENTE NO EXISTE"<< endl;

} else {

clienteTareas.actualizarFechaPago(dni);
cout <<"REGISTRO GUARDADO EXITOSAMENTE"<< endl;
cout <<"EL MONTO QUE SE GUARDO ES "<<clienteTareas.acumularAbonos(dni)<< endl;
}



}




int PagoTareas::calcularcantidadAniosDeRegistro(){

PagoArchivos pagoArchi;
Pago pago = pagoArchi.leer(0);
Fecha fechaHoy;

int anioMinimo = pago.getFecha().getAnio();
int anioMax = fechaHoy.getAnio();



return anioMax - anioMinimo + 1;






}






void PagoTareas::recaudacionAnual()
{




    PagoArchivos pagoArchi;
    Pago pago;
    int CantArch=pagoArchi.getCantidad();
    float VrecaudacionAnual[12]{};





    for(int x=0; x<CantArch; x++)
    {
        pago=pagoArchi.leer(x);
        VrecaudacionAnual[pago.getFecha().getMes()-1] += pago.getPago();

    }
    pago.MostrarRecaudacionAnual(VrecaudacionAnual) ;
}

void PagoTareas::regPago() { // resta hacer la accion

}
/*void PagoTareas::mostrarTodos()
{
    PagoArchivos pagoArchi;
    Pago pago;
    int cantPagos= pagoArchi.getCantidad() ;
    for(int x=0; x<cantPagos; x++)
    {  pago=pagoArch.leer(x);
        pago.Mostrar() ;

    }
}   */








