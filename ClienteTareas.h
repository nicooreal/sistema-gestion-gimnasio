#pragma once
#ifndef CLIENTETAREAS_H
#define CLIENTETAREAS_H
#include "ClienteArchivo.h"
#include "funciones.h"

class ClienteTareas
{
   private:

   ClienteArchivo _archivoCliente;
   void elegirQueModificar(Cliente &clienteModificado);
   int calcularEdad(Fecha fechaNacimiento);

    public:
void cargar();
void listarClientesBox();
void modificar() ;
void consultarPorDni();
void mostrarTodos();
void darBajaCliente();
void limpiarArchivoClientes();
void registrarIngresos();
void mostrarClientesConFechaPorVencer();
void listados();
void consultas();
void listarClientesBoxeo();
void listarClientesYoga();
float acumularAbonos(int dni);
void actualizarFechaPago(int dni);
void listarTodosLosClientesDadosDeBaja();
void reactivarCliente();
void listarPorNombre();
void listarClientesPorAnioIngreso();
void listarOrdenadosPorApellido();
void consultaPorNombre();
void consultaPorApellido();
void consultaPorEdad();
void consultarPorNumeroSocio();
void cambiarAlgunaFechaLimite(Cliente &clienteModificado);
void cambiarMontoDeAlgunAbono(Cliente &clienteModificado);
void cambiarActividades(Cliente &clienteModificado);
void listarPorEdad();
};

#endif // CLIENTETAREAS_H
