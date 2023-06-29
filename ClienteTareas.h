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
void modificar() ;
void cambiarAlgunaFechaLimite(Cliente &clienteModificado);
void cambiarMontoDeAlgunAbono(Cliente &clienteModificado);
void cambiarActividades(Cliente &clienteModificado);
void darBajaCliente();
void registrarIngresos();
void actualizarFechaPago(int dni);
void reactivarCliente();
void limpiarArchivoClientes();
float acumularAbonos(int dni);

void consultas();
void consultaPorNombre();
void consultaPorApellido();
void consultarPorNumeroSocio();
void consultarPorDni();
void consultaPorEdad();

void mostrarTodos();
void mostrarClientesConFechaPorVencer();
void listados();
void listarClientesBoxeo();
void listarClientesYoga();
void listarTodosLosClientesDadosDeBaja();
void listarPorNombre();
void listarClientesPorAnioIngreso();
void listarOrdenadosPorApellido();
void listarPorEdad();
};

#endif // CLIENTETAREAS_H
