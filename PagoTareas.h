#pragma once
#ifndef PAGOTAREAS_H
#define PAGOTAREAS_H
# include<iostream>
# include<cstdlib>
using namespace std;
#include "PagoTareas.h"
#include "Pago.h"
#include "PagoArchivos.h"
#include "ClienteArchivo.h"
#include "ClienteTareas.h"

class PagoTareas
{
    private:
        PagoArchivos _archivoPagos;
    public:


        void regPago();
        void recaudacionAnual();
        void mostrarTodos();
        void cargarPago(bool primerPago,int dni);
        int calcularcantidadAniosDeRegistro();
        void eliminarPago();
        void mostrarRecaudacionAnual(float vRecaudacionAnual[12]);
        void eliminarTodosLosPagos();
        void recaudacionPorClientes();


};

#endif // PAGOTAREAS_H
