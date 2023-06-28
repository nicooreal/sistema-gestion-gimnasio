#pragma once
#ifndef COPIADESEGURIDADTAREAS_H
#define COPIADESEGURIDADTAREAS_H
#include "ClienteArchivo.h"
#include "EmpleadoArchivo.h"
#include "PagoArchivos.h"

class CopiaDeSeguridadTareas
{
private:
    ClienteArchivo _archivoBackupCLiente=ClienteArchivo("clientes.bkp");
    EmpleadoArchivo _archivoBackupEmpleado=EmpleadoArchivo("empleados.bkp");
    PagoArchivos _archivoBackupPagos=PagoArchivos("pagos.bkp") ;
public:
    void hacerCopiaDeClientes();
    void hacerCopiaDeEmpleados();
    void hacerCopiaDePagos();
    void hacerCopiaDeTodo();

    void restaurarCopiaDeClientes();
    void restaurarCopiaDeEmpleados();
    void restaurarCopiaPagos();
    void restaurarCopiaDeTodo();

    void ElegirTipoBackup();
    void ElegirRestaurarTipoBackup();


};

#endif // COPIADESEGURIDADTAREAS_H
