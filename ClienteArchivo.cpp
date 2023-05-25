#include "ClienteArchivo.h"
#include "Cliente.h"
#include <iostream>
#include <cstring>

int ClienteArchivo::getCantidad()
{
    FILE* p = fopen("Cliente.dat", "rb");
    if (p == NULL) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(Cliente);
    fclose(p);
    return cant;
}

bool ClienteArchivo::guardar(Cliente cliente) {
    FILE* p = fopen("Cliente", "ab");
    if (p == NULL) {
        return false;
    }
    bool ok = fwrite(&cliente, sizeof(Cliente), 1, p);
    fclose(p);
    return ok;
}

bool ClienteArchivo::editar(Cliente cliente, int nroRegistro) {
    FILE* p = fopen("Cliente.dat", "rb+");
    if (p == NULL) {
        return false;
    }
    fseek(p, nroRegistro * sizeof(Cliente), 0);
    bool ok = fwrite(&cliente, sizeof(Cliente), 1, p);
    fclose(p);
    return ok;
}

Cliente ClienteArchivo::leer(int nroRegistro) {
    Cliente cliente;
    FILE* p;
    p = fopen("Cliente.dat", "rb");
    if (p == NULL) {
        return cliente;
    }
    fseek(p, nroRegistro * sizeof(Cliente), SEEK_SET);
    fread(&cliente, sizeof(Cliente), 1, p);
    fclose(p);
    return cliente;

}

int ClienteArchivo::buscarRegistroCliente(char nombre[30])     {

    int cant = getCantidad();
    int x;
    for (x = 0; x < cant; x++) {
        Cliente cliente = leer(x); // Leer el cliente en la posición x
        if (strcmp(cliente.getNombre(), nombre) == 0) { // Acceder al método getNombre() del cliente
            return x;
        }
    }
    return -1;
    }



