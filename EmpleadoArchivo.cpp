#include "EmpleadoArchivo.h"




EmpleadoArchivo::EmpleadoArchivo()
{
    strcpy(_nombreArchivo,"empleados.dat");
}

EmpleadoArchivo::EmpleadoArchivo(const char *nombreArchivo)
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

void EmpleadoArchivo::leerVector(Empleado *vec,int cantidadRegistros)
{
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == NULL)
    {
        return;
    }

    fread(&vec[0], sizeof(Empleado), cantidadRegistros, p);
    fclose(p);

}

bool EmpleadoArchivo::guardarVector(Empleado *vec,int cantidadRegistros)
{

    FILE *p = fopen(_nombreArchivo, "ab");
    if (p == NULL)
    {
        return false;
    }

    int cantidadRegistrosEscritos=fwrite(&vec[0], sizeof(Empleado), cantidadRegistros, p);
    fclose(p);
    return cantidadRegistrosEscritos==cantidadRegistros;
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

    bool verificar=false;

    while(fread(&empleado,sizeof(Empleado),1,p)!=0)
    {
        if(anio==empleado.getFechaIngreso().getAnio())
        {
            cout<<"ID Empleado #"<<empleado.getId()<<endl;
            empleado.mostrarEmpleado();
            verificar=true;
            cout<<endl;
        }
    }
    if(!verificar)
    {
        cout<<"NO EXISTEN EMPLEADOS QUE HAYAN INGRESADO EN EL ANIO"<<anio<<endl;
    }
    fclose(p);


}

bool EmpleadoArchivo::buscarPorID(int id)
{
    Empleado em;
    FILE *p=fopen(_nombreArchivo,"rb");
    if(p==NULL)
    {
        return false;
    }
    bool verificar=false;

    while(fread(&em,sizeof(Empleado),1,p)!=0)
    {
        if(em.getId()==id)
        {
            cout<<"ID Empleado #"<<em.getId()<<endl;
            em.mostrarEmpleado();
            verificar=true;
        }
    }

    return verificar;

}

int EmpleadoArchivo::buscarRegistroPorId(int id)
{
    FILE *p=fopen(_nombreArchivo,"rb");
    if(p==NULL)
    {
        return -1;
    }
    int pos=0;
    for(int i=0;i<cantidadEmpleados();i++)
    {
        Empleado em=leer(i);
        if(id==em.getId())
        {
            return pos;
        }
        pos++;
    }
    return -2;
}


void EmpleadoArchivo::bajaLogica(int id)
{
    FILE *p=fopen(_nombreArchivo,"rb+");
    if(p==NULL)
    {
        return;
    }

    int nroRegistro=buscarRegistroPorId(id);
    if(nroRegistro>=0)
    {
        cout<<"Va a eliminar el registro de empleado"<<endl;
        Empleado em=leer(nroRegistro);
        em.mostrarEmpleado();
        cout<<endl;
        em.setEstado(false);
        fseek(p,sizeof(Empleado)*nroRegistro,0);
        fwrite(&em,sizeof(Empleado),1,p);
        fclose(p);

    }else if(nroRegistro==-2)
    {
        cout<<"No existe ese ID"<<endl;
    }else
    {
        cout<<"No se pudo abrir el archivo"<<endl;
    }

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

void EmpleadoArchivo::vaciar()
{
    FILE *p=fopen(_nombreArchivo,"wb");
    if(p==NULL)
    {
        return;
    }
    fclose(p);
}
