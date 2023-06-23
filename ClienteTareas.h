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
   int calcularEdad(Fecha fechaNacimiento);

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
void listarClientesBoxeo();
void listarClientesYoga();
void listarClientesDadosDeBaja();
float acumularAbonos(int dni);
void actualizarFechaPago(int dni);
void listarTodosLosClientesDadosDeBaja();
void reactivarCliente();
void listarPorNombre();
void listarClientesPorAnioIngreso();
};

#endif // CLIENTETAREAS_H
