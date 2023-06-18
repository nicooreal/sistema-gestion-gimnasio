#include "EmpleadoTareas.h"

void EmpleadoTareas::listados()
{
    int opcion;
    do
    {
        do
        {
            system("cls");
            cout<<"\tLISTADOS"<<endl;
            cout<<"--------------------------------------------"<<endl;
            cout<<"1 - TODOS LOS REGISTROS"<<endl;
            cout<<"2 - POR NOMBRE"<<endl;
            cout<<"3 - POR ANIO"<<endl;
            cout<<"4 - POR EDAD"<<endl;
            cout<<"5 - POR SUELDO "<<endl;
            cout<<"6 - DADOS DE BAJA"<<endl;
            cout<<"0 - SALIR"<<endl;
            cout<<"--------------------------------------------"<<endl;
            cout<<"OPCION: ";
            cin>>opcion;
            system("cls");

        }
        while(opcion<0||opcion>6);
        switch(opcion)
        {
        case 1:
            listarRegistros();
            break;
        case 2:
            listarOrdenadosPorNombre();
            break;
        case 3:
            listarEmpleadosPorAnio();
            break;
        case 4:
            listarPorEdad();
            break;
        case 5:
            listarPorSueldo();
            break;
        case 6:
            listarEmpleadosDadosDeBaja();
            break;
        }

        if(opcion!=0)
        {
            system("pause");
        }

    }
    while(opcion!=0);
}

void EmpleadoTareas::listarRegistros()
{
    int cant=_archivo.cantidadEmpleados();
    for(int i=0; i<cant; i++)
    {

        Empleado em=_archivo.leer(i);
        cout<<"ID Empleado #"<<em.getId()<<endl;
        em.mostrarEmpleado();
        cout<<"---------------------------------------"<<endl;
    }
}

void EmpleadoTareas::listarEmpleadosPorAnio()
{
    int anio;
    cout<<"Ingrese el anio para listar empleados"<<endl;
    cin>>anio;
    cout<<endl;
    _archivo.buscarPorAnio(anio);

}

void EmpleadoTareas::listarOrdenadosPorNombre()
{
    int orden;
    do
    {
        cout<<"Ingrese el orden(1 - Ordenados de mayor a menor, 2 - Ordenados de menor a mayor)"<<endl;
        cin>>orden;
    }
    while(orden<1||orden>2);
    EmpleadoArchivo archivo("empleados.dat");

    int cantidad=archivo.cantidadEmpleados();
    Empleado *vEmpleados=new Empleado[cantidad];
    Empleado aux;
    if(vEmpleados==NULL)
    {
        cout<<"Error al intentar cargar el vector dinamico"<<endl;
        return;
    }
    archivo.leerVector(vEmpleados,cantidad);

    if(orden==1)
    {
        int mayor=0;

        for(int i=0; i<cantidad-1; i++)
        {
            mayor=i;
            for(int x=i+1; x<cantidad; x++)
            {
                if(strcmp(vEmpleados[x].getNombre(),vEmpleados[mayor].getNombre())>0)
                {
                    mayor=x;
                }
            }
            if(mayor!=i)
            {
                aux=vEmpleados[i];
                vEmpleados[i]=vEmpleados[mayor];
                vEmpleados[mayor]=aux;
            }
        }


    }
    else
    {
        int menor=0;

        for(int i=0; i<cantidad-1; i++)
        {
            menor=i;
            for(int x=i+1; x<cantidad; x++)
            {
                if(strcmp(vEmpleados[x].getNombre(),vEmpleados[menor].getNombre())<0)
                {
                    menor=x;
                }
            }
            if(menor!=i)
            {
                aux=vEmpleados[i];
                vEmpleados[i]=vEmpleados[menor];
                vEmpleados[menor]=aux;
            }
        }


    }

    for(int i=0; i<cantidad; i++)
    {
        cout<<"ID Empleados #"<<vEmpleados[i].getId()<<endl;
        vEmpleados[i].mostrarEmpleado();
        cout<<endl;
    }

    delete []vEmpleados;
}

void EmpleadoTareas::listarPorEdad()
{
    Fecha hoy;

    int orden;
    do
    {
        cout<<"Ingrese el orden (1 - Ordenados de mayor a menor, 2 - Ordenados de menor a mayor)"<<endl;
        cin>>orden;

    }
    while(orden<1||orden>2);

    EmpleadoArchivo archivo("empleados.dat");
    int cantidad=archivo.cantidadEmpleados();
    Empleado aux;
    Empleado *vEmpleados=new Empleado[cantidad];
    archivo.leerVector(vEmpleados,cantidad);

    if(vEmpleados==NULL)
    {
        cout<<"Error al cargar el vector"<<endl;
        return;
    }

    if(orden==1)
    {
        int mayor=0;
        for(int i=0; i<cantidad-1; i++)
        {
            mayor=i;
            for(int x=i+1; x<cantidad; x++)
            {
                if(calcularEdad(vEmpleados[x].getFechaNacimiento())>calcularEdad(vEmpleados[mayor].getFechaNacimiento()))
                {
                    mayor=x;
                }
            }
            if(mayor!=i)
            {
                aux=vEmpleados[i];
                vEmpleados[i]=vEmpleados[mayor];
                vEmpleados[mayor]=aux;
            }
        }



    }
    else
    {
        int menor=0;
        for(int i=0; i<cantidad-1; i++)
        {
            menor=i;
            for(int x=i+1; x<cantidad; x++)
            {
                if(calcularEdad(vEmpleados[x].getFechaNacimiento())<calcularEdad(vEmpleados[menor].getFechaNacimiento()))
                {
                    menor=x;
                }
            }
            if(menor!=i)
            {
                aux=vEmpleados[i];
                vEmpleados[i]=vEmpleados[menor];
                vEmpleados[menor]=aux;
            }
        }



    }

    for(int i=0; i<cantidad; i++)
    {
        cout<<"ID Empleado #"<<vEmpleados[i].getId()<<endl;
        vEmpleados[i].mostrarEmpleado();
        cout<<endl;
    }
    delete []vEmpleados;
}

void EmpleadoTareas::listarPorSueldo()
{
    int orden;
    do
    {
        cout<<"Ingrese el orden (1 - Ordenados de sueldo minimo a maximo, 2 - Ordenados de sueldo minimo a maximo)"<<endl;
        cin>>orden;

    }
    while(orden<1||orden>2);

    EmpleadoArchivo archivo("empleados.dat");
    int cantidad=archivo.cantidadEmpleados();
    Empleado aux;
    Empleado *vEmpleados=new Empleado[cantidad];
    if(vEmpleados==NULL)
    {
        cout<<"Error al cargar el vector de empleados"<<endl;
        return;
    }

    if(orden==1)
    {
        int mayor=0;
        for(int i=0; i<cantidad; i++)
        {
            mayor=i;
            for(int x=0; x<cantidad; x++)
            {
                if(vEmpleados[x].getSueldo()>vEmpleados[mayor].getSueldo())
                {
                    mayor=x;
                }
            }
            if(mayor!=i)
            {
                aux=vEmpleados[i];
                vEmpleados[i]=vEmpleados[mayor];
                vEmpleados[mayor]=aux;
            }
        }
    }
    else
    {
        int menor=0;
        for(int i=0; i<cantidad; i++)
        {
            menor=i;
            for(int x=0; x<cantidad; x++)
            {
                if(vEmpleados[x].getSueldo()<vEmpleados[menor].getSueldo())
                {
                    menor=x;
                }
            }
            if(menor!=i)
            {
                aux=vEmpleados[i];
                vEmpleados[i]=vEmpleados[menor];
                vEmpleados[menor]=aux;
            }
        }
    }

    for(int i=0;i<cantidad;i++)
    {
        cout<<"ID Empleado #"<<vEmpleados[i].getId()<<endl;
        vEmpleados[i].mostrarEmpleado();
        cout<<endl;
    }

    delete []vEmpleados;

}

void EmpleadoTareas::listarEmpleadosDadosDeBaja()
{

    EmpleadoArchivo archivo("empleados.dat");
    int cantidad=archivo.cantidadEmpleados();
    Empleado em;

    for(int i=0;i<cantidad;i++)
    {
        em=archivo.leer(i);
        if(em.getEstado()==false)
        {
            em.mostrarEmpleado();
        }
    }


}

void EmpleadoTareas::darDeBajaEmpleado()
{
    EmpleadoArchivo archivo("empleados.dat");
    int id;
    cout<<"Ingrese el ID del empleado que quiere dar de baja"<<endl;
    cin>>id;
    archivo.bajaLogica(id);
}

void EmpleadoTareas::consultas()
{

}

void EmpleadoTareas::consultaPorId()
{
    int id;
    cout<<"Ingrese el id"<<endl;
    cin>>id;
    _archivo.buscarPorID(id);

}


void EmpleadoTareas::cargar()
{
    Empleado reg;
    int id=generarID();
    cout<<"ID Empleado #"<<id<<endl;
    reg.setId(id);
    cout<<endl;
    reg.cargarEmpleado();


    _archivo.guardar(reg);
}







void EmpleadoTareas::modificar()
{
    Empleado empleado;

    int numeroRegistro = _archivo.buscarRegistro();
    if (numeroRegistro>=0)
    {
        cout << "Modifique al empleado"<<endl;
        Empleado empleadoModificado ;
        empleadoModificado.cargarEmpleado();

        bool exito = _archivo.editar(empleadoModificado, numeroRegistro);
        if (exito)
        {
            cout << "Registro modificado exitosamente." << endl;
        }
        else
        {
            cout << "No se pudo modificar el registro." << endl;
        }
    }
}

void EmpleadoTareas::borrarRegistros()
{
    _archivo.vaciar();
}

int EmpleadoTareas::generarID()
{
    return _archivo.cantidadEmpleados()+1;
}

int EmpleadoTareas::calcularEdad(Fecha fechaNacimiento)
{
    Fecha hoy;
    int edad;
    edad=hoy.getAnio()-fechaNacimiento.getAnio(); /// OBTENGO EL AÑO ACTUAL

    if(hoy.getMes()<fechaNacimiento.getMes()||hoy.getMes()==fechaNacimiento.getMes()&&hoy.getDia()<fechaNacimiento.getDia())
    {
        edad--;
    }

    return edad;
}
