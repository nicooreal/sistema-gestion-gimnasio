#ifndef CLIENTEARCHIVO_H
#define CLIENTEARCHIVO_H
#include "cliente.h"


class ClienteArchivo
{
    public:
int getCantidad();
bool guardar(Cliente cliente);
bool editar(Cliente cliente, int nroRegistro);
Cliente leer(int nroRegistro);
int buscarRegistroCliente(char nombre[30]);



};

#endif // CLIENTEARCHIVO_H
