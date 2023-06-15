#ifndef COPIADESEGURIDADTAREAS_H
#define COPIADESEGURIDADTAREAS_H
#include "ClienteArchivo.h"
#include "EmpleadoArchivo.h"


class CopiaDeSeguridadTareas
{
private:
    ClienteArchivo _archivoBackupCLiente=ClienteArchivo("clientes.bkp");
    EmpleadoArchivo _archivoBackupEmpleado=EmpleadoArchivo("empleados.bkp");

public:
    void hacerCopiaDeClientes();
    void hacerCopiaDeEmpleados();
    void hacerCopiaDeTodo();

    void restaurarCopiaDeClientes();
    void restaurarCopiaDeEmpleados();
    void restaurarCopiaDeTodo();

    void ElegirTipoBackup();
    void ElegirRestaurarTipoBackup();


};

#endif // COPIADESEGURIDADTAREAS_H
