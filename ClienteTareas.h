#ifndef CLIENTETAREAS_H
#define CLIENTETAREAS_H
#include "ClienteArchivo.h"

class ClienteTareas
{
   private:

   ClienteArchivo _archivoCliente;

    public:
void cargar();
void listarClientesBox();
void modificar() ;
void mostrarPorDni();
void mostrarTodos();

// void clienteBoxeo();


};

#endif // CLIENTETAREAS_H
