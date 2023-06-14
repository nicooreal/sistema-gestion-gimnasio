#ifndef CLIENTEARCHIVO_H
#define CLIENTEARCHIVO_H
#include "cliente.h"


class ClienteArchivo
{
private:
    char _nombreArchivo[30];

public:
     ClienteArchivo();/// CONSTRUCTOR PARA PONER POR DEFECTO clientes.dat
    ClienteArchivo(char *nombreArchivo);/// CONSTRUCTOR PARA ELEGIR ALGUN OTRO NOMBRE QUE NO SEA clientes.dat
    int getCantidad();
    bool guardar(Cliente cliente);
    bool editar(Cliente cliente, int nroRegistro);
    Cliente leer(int nroRegistro);
    int buscarRegistroCliente(char nombre[30]);
    int buscarRegistro();      // busc registros por dni
    void vaciar();




};

#endif // CLIENTEARCHIVO_H
