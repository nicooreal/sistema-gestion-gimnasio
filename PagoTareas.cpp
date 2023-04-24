#include "PagoTareas.h"


void PagoTareas::cargarPago(bool primerPago, int dni)
{
    Pago pago;
    Fecha fechaHoy;
    ClienteTareas clienteTareas;
    ClienteArchivo clienteArch;
    PagoArchivos pagoArch;
    int cantidadDePagos = pagoArch.getCantidad();
    int cantidadClientes = clienteArch.getCantidad();
    bool verificar = false;

    if (primerPago == false)
    {
        cout <<"ingrese el dni del cliente a pagar "<< endl;
        cin >> dni;


    }

    for (int i = 0; i < cantidadClientes; i++ )
    {
        Cliente cliente = clienteArch.leer(i);

        if ( dni == cliente.getDni()  )
        {


            pago.setId(cantidadDePagos );
            pago.setDni(dni);
            pago.setFechaPago( fechaHoy );
            pago.setPago( clienteTareas.acumularAbonos(dni)  ) ;  // generar un metodo con el abono total(boxeo,joya,etc),este metodo es solo pesas
            pago.setEstado(true);
            pagoArch.guardar(pago);


            verificar = true;
        }
    }


    if ( verificar == false && primerPago == false )
    {

        cout <<"EL CLIENTE NO EXISTE"<< endl;

    }
    else
    {

        if (primerPago == false)
        {
            clienteTareas.actualizarFechaPago(dni);
        }
        cout <<"PAGO GUARDADO EXITOSAMENTE"<< endl;
        cout <<"EL MONTO QUE SE GUARDO ES "<<clienteTareas.acumularAbonos(dni)<< endl;
        cout <<"DEL CLIENTE CON DNI: " << dni << endl;
    }



}




int PagoTareas::calcularcantidadAniosDeRegistro()
{

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
    float VrecaudacionAnual[12] {};

    for(int x=0; x<CantArch; x++)
    {
        pago=pagoArchi.leer(x);
        VrecaudacionAnual[pago.getFecha().getMes()-1] += pago.getPago();

    }
    mostrarRecaudacionAnual(VrecaudacionAnual) ;
}

void PagoTareas::mostrarRecaudacionAnual(float vRecaudacionAnual[12])
{
    for(int i=0; i<12; i++)
    {
        cout <<"Mes "<< i+1 << endl;
        cout << "Recaudacion: "<< vRecaudacionAnual[i]<<endl;

    }
}

void PagoTareas::eliminarTodosLosPagos()
{
    _archivoPagos.vaciar();
}



void PagoTareas::mostrarTodos()
{
    PagoArchivos pagoArch;

    int cantidadPagos = pagoArch.getCantidad();

    for (int i = 0; i<cantidadPagos; i ++)
    {

        Pago pago = pagoArch.leer(i);

        if (pago.getEstado() == true )
        {
        pago.mostrarPago();
        }

    }




}


void PagoTareas::eliminarPago()
{

    int seEncontroPago = false;
    PagoArchivos pagoArch;
    int id, op;
    cout <<"INGRESE EL ID DEL PAGO QUE SE VA A ELIMINAR"<< endl;
    cin >> id;
    int cantidadDePagos = pagoArch.getCantidad();
    for(int i = 0; i < cantidadDePagos; i++)
    {

        Pago pago = pagoArch.leer(i);

        if ( pago.getId() == id && pago.getEstado() == true )
        {

           seEncontroPago == true;

            cout <<"ESTA SEGURO QUE QUIERE ELIMINAR EL PAGO? NO SE PODRA RECUPERAR( 1 - SI o 0 - NO )"<< endl;
           pago.mostrarPago();


           cin >> op;
            if (op == 1 )
            {

            pago.setEstado(false);

            pagoArch.editar(pago,id);
            cout <<"PAGO ELIMINADO"<< endl;

            }
            else if (op == 0 )
            {

                cout <<"NO SE ELIMINO EL PAGO"<< endl;

            }


        }


    }

cout<<"VOLVIENDO AL MENU ANTERIOR"<< endl;



}


