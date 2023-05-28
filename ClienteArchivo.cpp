#include "ClienteArchivo.h"
#include "Cliente.h"
#include <iostream>
#include <cstring>

ClienteArchivo::ClienteArchivo()
{
    strcpy(_nombreArchivo,"clientes.dat");
}

ClienteArchivo::ClienteArchivo(char *nombreArchivo)
{
    strcpy(_nombreArchivo,nombreArchivo);
}

int ClienteArchivo::getCantidad()
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == NULL) {
        return 0;
    }
    fseek(p, 0,2);
    int cant = ftell(p) / sizeof(Cliente);
    fclose(p);
    return cant;
}

bool ClienteArchivo::guardar(Cliente cliente) {
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == NULL) {
        return false;
    }
    bool ok = fwrite(&cliente, sizeof(Cliente), 1, p);
    fclose(p);
    return ok;
}

Cliente ClienteArchivo::leer(int nroRegistro) {
    Cliente cliente;
    FILE* p;
    p = fopen(_nombreArchivo, "rb");
    if (p == NULL) {
        return cliente;
    }
    fseek(p, nroRegistro * sizeof(Cliente),0);
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

int ClienteArchivo::buscarRegistro()
{
    int numeroRegistro,dni;
    cout <<"Ingrese DNI del cliente que desea editar"<<endl;
    cout <<"DNI: ";
    cin >> dni;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == NULL)
    {
        cout << "No se pudo abrir el archivo." <<endl;
        return -1;
    }

    Cliente cliente;
    numeroRegistro=0;
    while (fread(&cliente, sizeof(Cliente), 1,p) != 0)
    {
        if (cliente.getDni ()==dni)
        {

            return numeroRegistro;
        }
            numeroRegistro++;

    }

    fclose(p);
    cout <<"No existe el numero de DNI" <<endl;
    return -2;
}
bool ClienteArchivo::editar(Cliente cliente, int nroRegistro) {

    FILE* p = fopen(_nombreArchivo,"rb+");
    if (p== NULL) {
        cout << "No se pudo abrir el archivo." <<endl;
        return 0;
    }

    fseek(p, nroRegistro * sizeof(Cliente),0);
    bool ok = fwrite(&cliente, sizeof(Cliente), 1, p);

    fclose(p);
    return ok;
}



