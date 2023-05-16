#include "EmpleadoArchivo.h"

bool EmpleadoArchivo::guardar(Empleado empleado) {
    FILE* p = fopen("empleado.dat", "ab");
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
    p = fopen("empleado.dat", "rb");
    if (p == NULL) {
        return empleado;
    }
    fseek(p, nroRegistro * sizeof(Empleado), SEEK_SET);
    fread(&empleado, sizeof(Empleado), 1, p);
    fclose(p);
    return empleado;

}
