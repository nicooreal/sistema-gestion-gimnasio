#include "EmpleadoArchivo.h"
#include "funciones.h"



EmpleadoArchivo::EmpleadoArchivo()
{
    strcpy(_nombreArchivo,"empleados.dat");
}

EmpleadoArchivo::EmpleadoArchivo(const char *nombreArchivo)
{
    strcpy(_nombreArchivo,nombreArchivo);
}


bool EmpleadoArchivo::guardar(Empleado empleado)
{
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == NULL)
    {
        return false;
    }

    bool ok=false;

    if(existeEmpleado(empleado)==0)
    {
        ok = fwrite(&empleado, sizeof(Empleado), 1, p);
        cout<<"REGISTRO GUARDADO EXITOSAMENTE"<<endl;
    }
    else if(existeEmpleado(empleado)==-1)
    {
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    }
    else
    {
        cout<<"YA EXISTE UN EMPLEADO CON ESE DNI"<<endl;
    }
    fclose(p);
    return ok;
}

int EmpleadoArchivo::existeEmpleado(Empleado empleado)
{
    FILE *p=fopen(_nombreArchivo,"rb");
    if(p==NULL)
    {
        return -1;
    }


    for(int i=0; i<cantidadEmpleados(); i++)
    {
        Empleado aux=leer(i);
        if(empleado.getDni()==aux.getDni())
        {
            fclose(p);
            return 1;
        }
    }
    fclose(p);
    return 0;
}

Empleado EmpleadoArchivo::leer(int nroRegistro)
{
    Empleado empleado;
    FILE* p;
    p = fopen(_nombreArchivo, "rb");
    if (p == NULL)
    {
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
    bool noActivos=false;

    while(fread(&empleado,sizeof(Empleado),1,p)!=0)
    {
        if(anio==empleado.getFechaIngreso().getAnio()&&empleado.getEstado())
        {
            empleado.mostrarEmpleado();
            verificar=true;
            cout<<endl;
        }



    }
    if(!verificar)
    {
        cout<<"NO EXISTEN EMPLEADOS QUE HAYAN INGRESADO EN EL ANIO O ESTAN DADOS DE BAJA"<<anio<<endl;
    }


    fclose(p);


}

int EmpleadoArchivo::buscarPorID(int id)
{
    Empleado em;
    FILE *p=fopen(_nombreArchivo,"rb");
    if(p==NULL)
    {
        return -1;
    }


    while(fread(&em,sizeof(Empleado),1,p)!=0)
    {
        if(em.getId()==id&&em.getEstado())
        {
            em.mostrarEmpleado();
            cout<<endl;
            fclose(p);
            return 1;
        }
    }
    fclose(p);
    return 0;

}

int EmpleadoArchivo::calcularEdad(Fecha fechaNacimiento)
{
    Fecha fecha;
// el contructor por defecto pone la fecha de hoy, por eso con get anio sale 2023

    int edad = fecha.getAnio() - fechaNacimiento.getAnio();
    if(fecha.getMes()<fechaNacimiento.getMes()||fecha.getMes()==fechaNacimiento.getMes()&&fecha.getDia()<fechaNacimiento.getDia())
    {
        edad--;
    }
    return edad;
}



int EmpleadoArchivo::buscarPorEdad(int edad)
{
    int hayEdad = 0;
    FILE *p=fopen(_nombreArchivo,"rb");
    if(p==NULL)
    {
        return -1;
    }

    for(int i=0; i<cantidadEmpleados(); i++)
    {
        Empleado em=leer(i);

        if(edad==calcularEdad(em.getFechaNacimiento())&&em.getEstado())
        {
            em.mostrarEmpleado();
            hayEdad = 1;
            //fclose(p);
            //return 1;
        }
    }
    fclose(p);
    return hayEdad;
}

int EmpleadoArchivo::buscarPorNombre(char *nombre)
{
    int hayNombre = 0;
    FILE *p=fopen(_nombreArchivo,"rb");
    if(p==NULL)
    {
        return -1;
    }

    for(int i=0; i<cantidadEmpleados(); i++)
    {
        Empleado em=leer(i);
        if(strcmp(nombre,em.getNombre())==0&&em.getEstado())
        {
            em.mostrarEmpleado();
            //fclose(p);
            //return 1;
        hayNombre = 1;
        }
    }
    fclose(p);
    return hayNombre;
}

int EmpleadoArchivo::buscarPorApellido(char *apellido)
{
    int hayNombre = 0;
    FILE *p=fopen(_nombreArchivo,"rb");
    if(p==NULL)
    {
        return -1;
    }
    for(int i=0; i<cantidadEmpleados(); i++)
    {
        Empleado em=leer(i);
        if(strcmp(apellido,em.getApellido())==0&&em.getEstado())
        {
            em.mostrarEmpleado();
            hayNombre = 1;
            //fclose(p);
            //return 1;
        }
    }
    fclose(p);
    return hayNombre;
}

int EmpleadoArchivo::buscarRegistroPorId(int id)
{
    FILE *p=fopen(_nombreArchivo,"rb");
    if(p==NULL)
    {
        return -1;
    }
    int pos=0;
    for(int i=0; i<cantidadEmpleados(); i++)
    {
        Empleado em=leer(i);
        if(id==em.getId())
        {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -2;
}


void EmpleadoArchivo::bajaLogica(int id)
{
    int opcion = 0;
    FILE *p=fopen(_nombreArchivo,"rb+");
    if(p==NULL)
    {
        return;
    }

    int nroRegistro=buscarRegistroPorId(id);
    if(nroRegistro>=0)
    {
        cout<<"VA A ELIMINAR EL REGISTRO DE EMPLEADO, ESTA SEGURO? (1- SI o 0 - NO)"<<endl;
        Empleado em=leer(nroRegistro);
        em.mostrarEmpleado();
        cout<<endl;
        cin >> opcion;
        validarQueNoSeaNegativa(opcion);
        if ( opcion == 1)
        {

            em.setEstado(false);
            fseek(p,sizeof(Empleado)*nroRegistro,0);
            fwrite(&em,sizeof(Empleado),1,p);
            fclose(p);
        }



    }
    else if(nroRegistro==-2)
    {
        cout<<"NO EXISTE ESE ID"<<endl;
    }
    else
    {
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
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
    fclose(p);
    return cant/sizeof(Empleado);/// PARA SABER LA CANTIDAD DE EMPLEADOS
}

int EmpleadoArchivo::buscarPorDni(int dni)
{
    FILE *p=fopen(_nombreArchivo,"rb");
    if(p==NULL)
    {
        return -1;
    }

    for(int i=0; i<cantidadEmpleados(); i++)
    {
        Empleado em=leer(i);
        if(dni==em.getDni()&&em.getEstado())
        {
            em.mostrarEmpleado();
            cout<<endl;
            fclose(p);
            return 1;
        }
    }
    fclose(p);
    return 0;
}

int EmpleadoArchivo::buscarRegistro()
{
    int numeroRegistro,dni;
    cout <<"INGRESE EL DNI DEL EMPLEADO QUE DESEA EDITAR"<<endl;
    cout <<"DNI: ";
    cin >> dni;
    validarIngresos(dni);
    validarQueNoSeaNegativa(dni);

    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" <<endl;
        return -1;
    }

    Empleado empleado;
    numeroRegistro=0;
    while (fread(&empleado, sizeof(Empleado), 1,p) != 0)
    {
        if (empleado.getDni ()==dni)
        {
            fclose(p);
            return numeroRegistro;
        }
        numeroRegistro++;

    }

    fclose(p);
    cout <<"NO EXISTE EL NUMERO DE DNI" <<endl;
    return -2;
}
bool EmpleadoArchivo::editar(Empleado empleado, int nroRegistro)
{

    FILE* p = fopen(_nombreArchivo,"rb+");
    if (p== NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO." <<endl;
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
