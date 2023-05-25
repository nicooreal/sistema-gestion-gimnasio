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
int EmpleadoArchivo::buscarRegistro()
{
    int numeroRegistro,dni;
    cout <<"Ingrese DNI del empleado que desea editar"<<endl;
    cout <<"DNI: ";
    cin >> dni;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == NULL)
    {
        cout << "No se pudo abrir el archivo." <<endl;
        return -1;
    }

    Empleado empleado;
    numeroRegistro=0;
    while (fread(&empleado, sizeof(Empleado), 1,p) != 0)
    {
        if (empleado.getDni ()==dni)
        {

            return numeroRegistro;
        }
            numeroRegistro++;

    }

    fclose(p);
    cout <<"No existe el numero de DNI" <<endl;
    return -2;
}
bool EmpleadoArchivo::editar(Empleado empleado, int nroRegistro) {

    FILE* p = fopen(_nombreArchivo,"rb+");
    if (p== NULL) {
        cout << "No se pudo abrir el archivo." <<endl;
        return 0;
    }

    fseek(p, nroRegistro * sizeof(Empleado),0);
    bool ok = fwrite(&empleado, sizeof(Empleado), 1, p);

    fclose(p);
    return ok;
}
