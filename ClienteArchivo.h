#pragma once
#ifndef CLIENTEARCHIVO_H
#define CLIENTEARCHIVO_H
#include "cliente.h"


class ClienteArchivo
{
private:
    char _nombreArchivo[30];

public:
    ClienteArchivo();/// CONSTRUCTOR PARA PONER POR DEFECTO clientes.dat
    ClienteArchivo(const char *nombreArchivo);/// CONSTRUCTOR PARA ELEGIR ALGUN OTRO NOMBRE QUE NO SEA clientes.dat
    int getCantidad();
    bool guardar(Cliente cliente);
    bool editar(Cliente cliente, int nroRegistro);
    Cliente leer(int nroRegistro);
    int buscarRegistroCliente(char nombre[30]);
    int buscarRegistro();      // busc registros por dni
    void vaciar();
    void leerVector(Cliente *vec,int cantidadRegistros);
    bool guardarVector(Cliente *vec,int cantidadRegistros);
    int buscarPorNombre(char * nombre);
    int buscarPorApellido(char *apellido);
    int buscarPorEdad(int edad);
    int buscarPorNumeroDeSocio(int numSocio);
    int buscarPorDni(int dni);
    int existeCliente(Cliente cliente);
};

#endif // CLIENTEARCHIVO_H
