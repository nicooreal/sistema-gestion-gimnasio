#pragma once
#include "PagoArchivos.h"

PagoArchivos::PagoArchivos()
{
    strcpy(_nombreArchivo,"Pagos.dat");
}

PagoArchivos::PagoArchivos(const char *nombreArchivo)
{
    strcpy(_nombreArchivo,nombreArchivo);
}


int PagoArchivos::getCantidad()
{
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == NULL)
    {
        return 0;
    }
    fseek(p, 0,2);
    int cant = ftell(p) / sizeof(Pago);
    fclose(p);
    return cant;
}

bool PagoArchivos::guardar(Pago pago)
{
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == NULL)
    {
        return false;
    }
    bool ok = fwrite(&pago, sizeof(Pago), 1, p);
    fclose(p);
    return ok;
}


Pago PagoArchivos::leer(int nroRegistro)
{
    Pago pago;
    FILE* p;
    p = fopen(_nombreArchivo, "rb");
    if (p == NULL)
    {
        return pago;
    }
    fseek(p, nroRegistro * sizeof(Pago), SEEK_SET);
    fread(&pago, sizeof(Pago), 1, p);
    fclose(p);
    return pago;

}


bool PagoArchivos::editar(Pago pago, int identificador) {

    FILE* p = fopen(_nombreArchivo,"rb+");
    if (p== NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO." <<endl;
        return false;
    }

    fseek(p, identificador * sizeof(Pago),0);
    bool ok = fwrite(&pago, sizeof(Pago), 1, p);

    fclose(p);
    return ok;
}
void PagoArchivos::leerVector(Pago *vec,int cantidadRegistros)
{
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == NULL)
    {
        return;
    }

    fread(&vec[0], sizeof(Pago), cantidadRegistros, p);
    fclose(p);

}
bool PagoArchivos::guardarVector(Pago *vec,int cantidadRegistros)
{

    FILE *p = fopen(_nombreArchivo, "ab");
    if (p == NULL)
    {
        return false;
    }

    int cantidadRegistrosEscritos=fwrite(&vec[0], sizeof(Pago), cantidadRegistros, p);
    fclose(p);
    return cantidadRegistrosEscritos==cantidadRegistros;
}

void PagoArchivos::vaciar()
{
    FILE *p=fopen(_nombreArchivo,"wb");
    if(p==NULL)
    {
        return;
    }

    fclose(p);
}



