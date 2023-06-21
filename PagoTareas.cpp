# include<iostream>
# include<cstdlib>
using namespace std;
#include "PagoTareas.h"
#include "Pago.h"
#include "PagoArchivos.h"
#include "ClienteArchivo.h"
PagoTareas::PagoTareas()
{
    //ctor
}

 void PagoTareas::cargarPago()
{
Pago pago;
int dni;
Fecha fechaHoy;

ClienteArchivo clienteArch;
PagoArchivos pagoArch;
int cantidadClientes = clienteArch.getCantidad();


for (int i = 0; i < cantidadClientes; i++ ){
Cliente cliente = clienteArch.leer(i);
cout << "ingrese la fecha de pago"<<endl;
fechaHoy.cargar();

    pago.setDni(cliente.getDni());
    pago.setFechaPago( fechaHoy );
    pago.setPago(cliente.getAbonoMensual()) ;  // generar un metodo con el abono total(boxeo,joya,etc),este metodo es solo pesas
    pagoArch.guardar(pago);
}
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








