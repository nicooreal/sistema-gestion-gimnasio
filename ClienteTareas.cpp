#include "ClienteTareas.h"
#include "Cliente.h"
#include "ClienteArchivo.h"

void ClienteTareas::cargar(){

    Cliente cliente;
    cliente.cargarCliente();

    _archivoCliente.guardar(cliente);





}

