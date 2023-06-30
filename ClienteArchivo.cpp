#include "ClienteArchivo.h"
#include "Cliente.h"
#include <iostream>
#include <cstring>
#include "funciones.h"

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

    fread(&vec[0], sizeof(Cliente), cantidadRegistros, p); //esta grabando en la direccion de memoria(&vec) los registros del archivo
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
    bool ok=false;
    if(existeCliente(cliente)==0)
    {
        ok = fwrite(&cliente, sizeof(Cliente), 1, p);
        cout<<"REGISTRO GUARDADO EXITOSAMENTE!"<<endl;
    }else if(existeCliente(cliente)==-1)
    {
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    }else
    {
        cout<<"YA EXISTE UN CLIENTE CON ESE DNI"<<endl;
    }
    fclose(p);
    return ok;
}

int ClienteArchivo::existeCliente(Cliente cliente)
{
    FILE *p=fopen(_nombreArchivo,"rb");
    if(p==NULL)
    {
        return -1;
    }


    for(int i=0;i<getCantidad();i++)
    {
        Cliente aux=leer(i);
        if(cliente.getDni()==aux.getDni())
        {
            fclose(p);
            return 1;
        }
    }
    fclose(p);
    return 0;
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


int ClienteArchivo::buscarRegistro()
{
    int numeroRegistro,dni;
    cout <<"INGRESE EL DNI DEL CLIENTE QUE QUIERE BUSCAR"<<endl;
    cout <<"DNI: ";
    cin >> dni;
    validarQueNoSeaNegativa(dni);
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO." <<endl;
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
    cout <<"No EXISTE NUMERO DE DNI" <<endl;
    system("pause");
    return -2;
}
bool ClienteArchivo::editar(Cliente cliente, int nroRegistro) {

    FILE* p = fopen(_nombreArchivo,"rb+");
    if (p== NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO." <<endl;
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
    int hayNombre = 0;
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
            hayNombre = 1;
            cout <<"--------------------------------------"<< endl;

            //fclose(p);
            //return 1;
        }
    }
    fclose(p);
    return hayNombre;
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
            cout <<"--------------------------------------"<< endl;
            fclose(p);
            return numSocio;
        }
    }
    fclose(p);
    return 0;
}

int ClienteArchivo::buscarPorApellido(char *apellido)
{
    int hayApellido = 0;
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
            cout <<"--------------------------------------"<< endl;
            hayApellido = 1;
            //fclose(p);
            //return 1;
        }
    }
    fclose(p);
    return hayApellido;
}

int ClienteArchivo::buscarPorEdad(int edad)
{

    int hayEdad = 0;
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
            cout <<"--------------------------------------"<< endl;
            hayEdad = 1;
            //fclose(p);
            //return 1;
        }
    }
    fclose(p);

    return hayEdad;
}
