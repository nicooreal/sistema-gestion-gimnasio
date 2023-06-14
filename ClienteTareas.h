#ifndef CLIENTETAREAS_H
#define CLIENTETAREAS_H
#include "ClienteArchivo.h"
#include "funciones.h"

class ClienteTareas
{
   private:

   ClienteArchivo _archivoCliente;
   void elegirQueModificar(Cliente &clienteModificado);
   int generarID();

    public:
void cargar();
void listarClientesBox();
void modificar() ;
void mostrarPorDni();
void mostrarTodos();
void darBajaCliente();
void limpiarArchivoClientes();
void registrarIngresos();
// void clienteBoxeo();


};

#endif // CLIENTETAREAS_H
