#ifndef CLIENTETAREAS_H
#define CLIENTETAREAS_H
#include "ClienteArchivo.h"
#include "funciones.h"

class ClienteTareas
{
   private:

   ClienteArchivo _archivoCliente;
   int generarID();
   void elegirQueModificar(Cliente &clienteModificado);

    public:
void cargar();
void listarClientesBox();
void modificar() ;
void mostrarPorDni();
void mostrarTodos();
void darBajaCliente();
void limpiarArchivoClientes();
void registrarIngresos();
void mostrarClientesConFechaPorVencer();
void listados();
void consultas();
// void clienteBoxeo();


};

#endif // CLIENTETAREAS_H
