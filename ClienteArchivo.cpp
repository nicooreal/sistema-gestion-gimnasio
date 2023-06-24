#include "ClienteArchivo.h"
#include "Cliente.h"
#include <iostream>
#include <cstring>

ClienteArchivo::ClienteArchivo()
{
    strcpy(_nombreArchivo,"clientes.dat");
}

ClienteArchivo::ClienteArchivo(const char *nombreArchivo)
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

void ClienteArchivo::leerVector(Cliente *vec,int cantidadRegistros)
{
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == NULL)
    {
        return;
    }

    fread(&vec[0], sizeof(Cliente), cantidadRegistros, p);
    fclose(p);

}

bool ClienteArchivo::guardarVector(Cliente *vec,int cantidadRegistros)
{

    FILE *p = fopen(_nombreArchivo, "ab");
    if (p == NULL)
    {
        return false;
    }

    int cantidadRegistrosEscritos=fwrite(&vec[0], sizeof(Cliente), cantidadRegistros, p);
    fclose(p);
    return cantidadRegistrosEscritos==cantidadRegistros;
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
cout <<1;

    int cant = getCantidad();
    int x;
    for (x = 0; x < cant; x++) {
        Cliente cliente = leer(x); // Leer el cliente en la posición x
        if (strcmp(cliente.getNombre(), nombre) == 0) { // Acceder al método getNombre() del cliente
            return x;
        }
    }
    cout <<"no se encontro el registro" << endl;
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
    system("pause");
    return -2;
}
bool ClienteArchivo::editar(Cliente cliente, int nroRegistro) {

    FILE* p = fopen(_nombreArchivo,"rb+");
    if (p== NULL) {
        cout << "No se pudo abrir el archivo." <<endl;
        return false;
    }

    fseek(p, nroRegistro * sizeof(Cliente),0);
    bool ok = fwrite(&cliente, sizeof(Cliente), 1, p);

    fclose(p);
    return ok;
}

void ClienteArchivo::vaciar()
{
    FILE *p=fopen(_nombreArchivo,"wb");
    if(p==NULL)
    {
        return;
    }
    fclose(p);
}

int ClienteArchivo::buscarPorDni(int dni)
{
    FILE *p=fopen(_nombreArchivo,"rb");
    if(p==NULL)
    {
        return -1;
    }

    for(int i=0;i< getCantidad() ;i++)
    {
        Cliente cliente=leer(i);
        if(dni==cliente.getDni()&&cliente.getEstado())
        {

            cliente.mostrarCliente();
            cout <<"----------------------------"<< endl;
            fclose(p);
            return 1;
        }
    }
    fclose(p);
    return 0;
}

int ClienteArchivo::buscarPorNombre(char *nombre)
{
    FILE *p=fopen(_nombreArchivo,"rb");
    if(p==NULL)
    {
        return -1;
    }

    for(int i=0;i< getCantidad() ;i++)
    {
        Cliente cliente=leer(i);
        if(strcmp(nombre,cliente.getNombre())==0&&cliente.getEstado())
        {

            cliente.mostrarCliente();
            cout <<"----------------------------"<< endl;
            fclose(p);
            return 1;
        }
    }
    fclose(p);
    return 0;
}

int ClienteArchivo::buscarPorNumeroDeSocio(int numSocio)
{
    FILE *p=fopen(_nombreArchivo,"rb");
    if(p==NULL)
    {
        return -1;
    }
    for(int i=0;i< getCantidad() ;i++)
    {
        Cliente cliente=leer(i);
        if( numSocio == cliente.getNumeroDeSocio() && cliente.getEstado()==true)
        {

            cliente.mostrarCliente();
            fclose(p);
            return numSocio;
        }
    }
    fclose(p);
    return 0;
}

int ClienteArchivo::buscarPorApellido(char *apellido)
{
    FILE *p=fopen(_nombreArchivo,"rb");
    if(p==NULL)
    {
        return -1;
    }
    for(int i=0;i< getCantidad() ;i++)
    {
        Cliente cliente=leer(i);
        if(strcmp(apellido,cliente.getApellido())==0&&cliente.getEstado())
        {

            cliente.mostrarCliente();
            fclose(p);
            return 1;
        }
    }
    fclose(p);
    return 0;
}

int ClienteArchivo::buscarPorEdad(int edad)
{

    FILE *p=fopen(_nombreArchivo,"rb");
    if(p==NULL)
    {
        return -1;
    }

    for(int i=0;i<getCantidad() ;i++)
    {
        Cliente cliente=leer(i);

        Fecha fechaNacimiento = cliente.getFechaNacimiento();

        if(edad == cliente.calcularEdad(fechaNacimiento)&&cliente.getEstado())
        {

            cliente.mostrarCliente();
            fclose(p);
            return 1;
        }
    }
    fclose(p);

    return 0;
}
