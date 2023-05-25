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
    FILE* p = fopen(_nombreArchivo, "ab");
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
    p = fopen(_nombreArchivo, "rb");
    if (p == NULL) {
        return empleado;
    }
    fseek(p, nroRegistro * sizeof(Empleado), SEEK_SET);
    fread(&empleado, sizeof(Empleado), 1, p);
    fclose(p);
    return empleado;

}

void EmpleadoArchivo::buscarPorAnio(int anio)
{
    Empleado empleado;
    FILE *p;
    p=fopen(_nombreArchivo,"rb");
    if(p==NULL)
    {

        return;
    }

    bool verificar2023=false;

    while(fread(&empleado,sizeof(Empleado),1,p)!=0)
    {
        if(anio==empleado.getFechaIngreso().getAnio())
        {
            empleado.mostrarEmpleado();
            verificar2023=true;
            cout<<endl;
        }
    }
    if(!verificar2023)
    {
        cout<<"NO EXISTEN EMPLEADOS QUE HAYAN INGRESADO EN EL 2023"<<endl;
    }
    fclose(p);


}

int EmpleadoArchivo::cantidadEmpleados()
{
    Empleado reg;
    FILE *p=fopen(_nombreArchivo,"rb");
    if(p==NULL)
    {
        return 0;
    }

    fseek(p,0,2);
    int cant=ftell(p);
    return cant/sizeof(Empleado);/// PARA SABER LA CANTIDAD DE EMPLEADOS
}
bool EmpleadoArchivo::buscarRegistro(int& dni, int& nroRegistro) {
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo." <<endl;
        return false;
    }

    Empleado empleado;
    nroRegistro = 0;
    bool encontrado = false;

    while (fread(&empleado, sizeof(Empleado), 1,p) != 0 && encontrado==false) {
        if (empleado._datosPersona.getDni()==dni) {
            encontrado = true;
        }
        nroRegistro++;

    }

    fclose(p);
    return encontrado;
}
bool EmpleadoArchivo::editar(Empleado empleado, int nroRegistro) {

    FILE* p = fopen(_nombreArchivo,"rb+");
    if (p== NULL) {
        cout << "No se pudo abrir el archivo." <<endl;
        return 0;
    }

    fseek(p, nroRegistro * sizeof(Empleado), SEEK_SET);
    bool ok = fwrite(&empleado, sizeof(Empleado), 1, p);

    fclose(p);
    return ok;
}
