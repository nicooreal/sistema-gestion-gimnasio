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

void PagoTareas::recaudacionAnual() {
   Fecha fecha;
   PagoArchivos pagoArchi;
   Pago pago;
   int anios,meses;
   anios = 2023- fecha.FechaInicial().getAnio() ;
   int vAniosMeses[anios][12]{};

   ClienteArchivo clienteArch;
    int cantidadDeClientes = clienteArch.getCantidad();

    for (int i = 0; i < cantidadDeClientes; i++)
    {
        Cliente cliente =  clienteArch.leer(i);

 if (cliente.getFechaDelAlta()> fecha.FechaInicial() && cliente.getFechaDelAlta().getAnio()<= 2023 && cliente.getEstado() )
        {
            pago=vAniosMeses[cliente.getFechaDelAlta().getAnio()-fecha.FechaInicial().getAnio()][cliente.getFechaDelAlta().getMes()-1] += cliente.getAbonoMensual() ;

            pagoArchi.guardar(pago)  ;
        }
    }
}

void PagoTareas::regPago() { // resta hacer la accion

}
void PagoTareas::mostrarTodos()
{
    PagoArchivos pagoArch;
    Pago pago;
    int cantPagos= pagoArch.getCantidad() ;
    for(int x=0; x<cantPagos; x++)
    {  pago=pagoArch.leer(x);
        pago.Mostrar() ;

    }
}
