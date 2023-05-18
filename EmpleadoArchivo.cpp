#include "EmpleadoArchivo.h"




EmpleadoArchivo::EmpleadoArchivo()
{
    strcpy(_nombreArchivo,"empleados.dat");
}

EmpleadoArchivo::EmpleadoArchivo(char *nombreArchivo)
{
    strcpy(_nombreArchivo,nombreArchivo);
}


bool EmpleadoArchivo::guardar(Empleado empleado) {
    FILE* p = fopen("empleados.dat", "ab");
    if (p == NULL) {
        return false;
    }
    bool ok = fwrite(&empleado, sizeof(Empleado), 1, p);
    fclose(p);
    return ok;
}

Empleado EmpleadoArchivo::leer(int nroRegistro) {
    Empleado empleado;
    FILE* p;
    p = fopen("empleados.dat", "rb");
    if (p == NULL) {
        return empleado;
    }
    fseek(p, nroRegistro * sizeof(Empleado), SEEK_SET);
    fread(&empleado, sizeof(Empleado), 1, p);
    fclose(p);
    return empleado;

}
