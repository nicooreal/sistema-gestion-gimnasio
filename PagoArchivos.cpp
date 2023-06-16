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
