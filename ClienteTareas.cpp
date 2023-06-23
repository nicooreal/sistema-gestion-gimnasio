#include "ClienteTareas.h"
#include "Cliente.h"
#include "ClienteArchivo.h"
#include "GimnasioMenu.h"
#include "PagoTareas.h"
void ClienteTareas::cargar()
{

    PagoTareas pagoTareas;
    Cliente cliente;
    cliente.cargarCliente();

    _archivoCliente.guardar(cliente);
    cout <<"-------------------------------"<< endl;
    pagoTareas.cargarPago(true,cliente.getDni());

}
void ClienteTareas::modificar()
{
    int numeroRegistro = _archivoCliente.buscarRegistro();
    if (numeroRegistro>=0)
    {

        Cliente cliente=_archivoCliente.leer(numeroRegistro);

        if( cliente.getEstado() == true )
        {

            cout <<"el cliente que usted quiere modificar es: " << endl;
            cliente.mostrarCliente();
            system("pause");
            cout << endl;
            cout << "Modifique al cliente"<<endl;


            elegirQueModificar(cliente);


            bool exito = _archivoCliente.editar(cliente, numeroRegistro);
            if (exito)
            {
                cout << "Registro modificado exitosamente." << endl;
            }
            else
            {
                cout << "No se pudo modificar el registro." << endl;
            }


        }
        else
        {
            cout <<"no se encontro el registro" << endl;
        }
    }
}



void ClienteTareas::consultarPorDni()
{
    int documento;
    cout <<"ingrese documento: " << endl;
    cin >> documento;
    int cantidadDeClientes = _archivoCliente.getCantidad();


    for (int i = 0; i < cantidadDeClientes; i++ )
    {
        Cliente cliente = _archivoCliente.leer(i);

        if ( documento == cliente.getDni() )
        {
            cliente.mostrarCliente();


        }


    }



}

void ClienteTareas::mostrarTodos()
{
    int cantidadDeClientes = _archivoCliente.getCantidad();
    for (int i = 0; i < cantidadDeClientes; i++ )
    {
        Cliente cliente = _archivoCliente.leer(i);
        if(cliente.getEstado())/// HICE ESTA COMPARACION PARA VERIFICAR QUE HAYAN CLIENTES
        {
            cliente.mostrarCliente();
            cout << endl;
            cout <<"--------------------------------------"<< endl;
        }


    }




}


void ClienteTareas::darBajaCliente()
{
    int op;
    int numeroRegistro = _archivoCliente.buscarRegistro();
    if (numeroRegistro>=0)
    {
        cout <<"el cliente que usted quiere dar de baja es: " << endl;
        Cliente cliente=_archivoCliente.leer(numeroRegistro);
        cliente.mostrarCliente();
        system("pause");
        cout <<"¿desea dar la baja?" <<endl;
        cout <<"1 - SI o 2 - NO" << endl;
        cin >> op;
        if (op == 1)
        {
            Cliente clienteEnBaja = cliente;
            clienteEnBaja.setEstado(false);

            bool exito = _archivoCliente.editar(clienteEnBaja, numeroRegistro);
            if (exito)
            {
                cout << "Registro dado de baja exitosamente." << endl;

            }
            else
            {
                cout << "No se pudo modificar el registro." << endl;
            }


        }



    }

}

void ClienteTareas::elegirQueModificar(Cliente &clienteModificado)
{
    int opcion;
    char nombre[30],apellido[30];
    char genero;
    int dni;

    Fecha fechaNacimiento,fechaAlta,fechaLimiteParaPagarAbono;
    float abono;

    do
    {
        do
        {
            system("cls");
            cout<<"\tMODIFICAR CLIENTE"<<endl;
            cout<<"-------------------------------------"<<endl;
            cout<<"1 - MODIFICAR NOMBRE"<<endl;
            cout<<"2 - MODIFICAR APELLIDO"<<endl;
            cout<<"3 - MODIFICAR DNI"<<endl;
            cout<<"4 - MODIFICAR GENERO"<<endl;
            cout<<"5 - MODIFICAR FECHA NACIMIENTO"<<endl;
            cout<<"6 - MODIFICAR FECHA DE ALTA"<<endl;
            cout<<"7 - MODIFICAR FECHA LIMITE PARA PAGAR ABONO"<<endl;
            cout<<"8 - MODIFICAR ABONO MENSUAL"<<endl;
            cout<<"9 - MODIFICAR TODO EL REGISTRO"<<endl;
            cout<<"-------------------------------------"<<endl;
            cout<<"0 - SALIR"<<endl;
            cout<<"OPCION: ";
            cin>>opcion;
            system("cls");
        }
        while(opcion<0||opcion>9);



        switch(opcion)
        {
        case 1:
            cout<<"Ingrese el nuevo nombre"<<endl;
            cargarCadena(nombre,29);
            clienteModificado.setNombre(nombre);
            break;
        case 2:
            cout<<"Ingrese el nuevo apellido"<<endl;
            cargarCadena(apellido,29);
            clienteModificado.setApellido(apellido);
            break;
        case 3:
            cout<<"Ingrese el nuevo DNI "<<endl;
            cin>>dni;
            clienteModificado.setDni(dni);
            break;
        case 4:
            do
            {
                cout<<"Ingrese el nuevo genero(M - MASCULINO, F - FEMENINO) "<<endl;
                cin>>genero;
            }
            while(genero!='F'&&genero!='f'&&genero!='m'&&genero!='M');

            clienteModificado.setSexo(genero);
            break;
        case 5:
            cout<<"Ingrese la nueva fecha de nacimiento "<<endl;
            fechaNacimiento.cargar();
            clienteModificado.setFechaNacimiento(fechaNacimiento);
            clienteModificado.calcularEdad();
            break;
        case 6:
            cout<<"Ingrese la nueva fecha de alta"<<endl;
            fechaAlta.cargar();
            clienteModificado.setFechaDelAlta(fechaAlta);
            break;
        case 7:
            cout<<"Ingrese la nueva fecha limite "<<endl;
            fechaLimiteParaPagarAbono.cargar();
            clienteModificado.setFechaLimite(fechaLimiteParaPagarAbono);
            break;
        case 8:
            cout<<"Ingrese el nuevo abono mensual"<<endl;
            cin>>abono;
            clienteModificado.setAbonoMensual(abono);
            break;
        case 9:
            cout<<"Ingrese el nuevo registro de Cliente"<<endl;
            clienteModificado.cargarCliente();
            break;
        }
        if(opcion!=0)
        {
            system("pause");
        }


    }
    while(opcion!=0);

}

void ClienteTareas::limpiarArchivoClientes()
{
    _archivoCliente.vaciar();
}

int ClienteTareas::generarID()
{
    return _archivoCliente.getCantidad()+1;
}


void ClienteTareas::registrarIngresos()
{
    int documento;
    GimnasioMenu gimMenu;


    cout <<"NUMERO DE DOCUMENTO: " << endl; // ES PARA PODER VER CUANTOS INGRESOS LE QUEDA A CADA CLIENTE QUE VIENE


    cin >> documento;
    int cantidadDeClientes = _archivoCliente.getCantidad();


    for (int i = 0; i < cantidadDeClientes; i++ )
    {
        Cliente cliente = _archivoCliente.leer(i);
        int numeroRegistro = i;

        if ( documento == cliente.getDni() )
        {



            cout <<"nombre: " << cliente.getNombre() <<endl;
            cout <<"apellido: " <<cliente.getApellido() <<endl;
            cout<<"ingresos restantes: "<< cliente.getControlIngresos() - 1 << endl;
            cout <<"fecha de vencimento: ";
            cliente.getFechaLimiteParaPagarAbono().mostrar();

            cliente.setControlIngresos( cliente.getControlIngresos() - 1);
            _archivoCliente.editar(cliente,numeroRegistro);
            break;
        }

    }






}


void ClienteTareas::mostrarClientesConFechaPorVencer()
{

    Fecha fechaHoy;
    int cantidadRegistros =_archivoCliente.getCantidad();
    int diasPorMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < cantidadRegistros; i++)
    {
        Cliente cliente =_archivoCliente.leer(i);

        if ( cliente.getFechaLimiteParaPagarAbono().getMes() == fechaHoy.getMes())
        {

            if ( cliente.getFechaLimiteParaPagarAbono().getDia() - fechaHoy.getDia() <= 7 )
            {

                cliente.mostrarCliente();

            }

        }

        if ( cliente.getFechaLimiteParaPagarAbono().getMes() != fechaHoy.getMes())
        {


            int diasParaTerminarELmes = diasPorMes[ fechaHoy.getMes()- 1 ] - fechaHoy.getDia();


            if ( diasParaTerminarELmes + cliente.getFechaLimiteParaPagarAbono().getDia() <= 7 )

            {


                cliente.mostrarCliente();


            }


            // incompleto, mejor habria q hacer un metodo para contar los dias del anio


        }




    }



}



void ClienteTareas::listados()
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
            cout<<"3 - POR APELLIDO"<<endl;
            cout<<"4 - POR ANIO"<<endl;
            cout<<"5 - POR EDAD"<<endl;
            cout<<"6 - LOS QUE HACEN BOXEO" << endl;
            cout<<"7 - LOS QUE HACEN YOGA" << endl;
            cout<<"8 - DADOS DE BAJA"<<endl;
            cout<<"0 - SALIR"<<endl;
            cout<<"--------------------------------------------"<<endl;
            cout<<"OPCION: ";
            cin>>opcion;
            system("cls");

        }
        while(opcion<0||opcion>9);
        switch(opcion)
        {
        case 1:
            mostrarTodos();
            break;
        case 2:
            listarPorNombre();
            break;
        case 3:
            listarOrdenadosPorApellido();
            break;
        case 4:
            listarClientesPorAnioIngreso();
            break;
        case 5:
  //metodo hecho pero no terminado
            break;
        case 6:
            listarClientesBoxeo();

            break;
        case 7:
            listarClientesYoga();

            break;
        case 8:
            listarTodosLosClientesDadosDeBaja();
            break;

        }


        if(opcion!=0)
        {
            system("pause");
        }

    }
    while(opcion!=0);
}


void ClienteTareas::consultas()
{
    int opcion;
    do
    {
        do
        {
            system("cls");
            cout<<"\tCONSULTAS"<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<"1 - BUSCAR POR NUMERO DE SOCIO"<<endl;
            cout<<"2 - BUSCAR POR DNI"<<endl;
            cout<<"3 - BUSCAR POR NOMBRE"<<endl;
            cout<<"4 - BUSCAR POR APELLIDO"<<endl;
            cout<<"5 - BUSCAR POR EDAD"<<endl;
            cout<<"0 - SALIR"<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<"OPCION: ";
            cin>>opcion;
            system("cls");
        }
        while(opcion<0||opcion>5);
        switch(opcion)
        {
        case 1:
            consultarPorNumeroSocio();
            break;
        case 2:
            consultarPorDni();
            break;
        case 3:
            consultaPorNombre();
            break;
        case 4:
            consultaPorApellido();
            break;
        case 5:
          // metodo hecho pero no terminado
            break;
        }
        if(opcion!=0)
        {
            system("pause");
        }

    }
    while(opcion!=0);
}

void ClienteTareas::listarClientesBoxeo()
{

    int cantidadDeClientes = _archivoCliente.getCantidad();
    for (int i = 0; i < cantidadDeClientes; i++ )
    {
        Cliente cliente = _archivoCliente.leer(i);
        if(cliente.getBoxeo().getActivo() == true )
        {
            cliente.mostrarCliente();
            cout << endl;
            cout <<"--------------------------------------"<< endl;
        }



    }
}
void ClienteTareas::listarClientesYoga()
{

    int cantidadDeClientes = _archivoCliente.getCantidad();
    for (int i = 0; i < cantidadDeClientes; i++ )
    {
        Cliente cliente = _archivoCliente.leer(i);
        if(cliente.getYoga().getActivo() == true )
        {
            cliente.mostrarCliente();
            cout << endl;
            cout <<"--------------------------------------"<< endl;
        }



    }
}
void ClienteTareas::listarClientesDadosDeBaja()
{


    int cantidadDeClientes = _archivoCliente.getCantidad();
    for (int i = 0; i < cantidadDeClientes; i++ )
    {
        Cliente cliente = _archivoCliente.leer(i);
        if(cliente.getEstado() == false  )
        {
            cliente.setEstado(true);
            cliente.mostrarCliente();
            cliente.setEstado(false);
            cout << endl;
            cout <<"--------------------------------------"<< endl;
        }



    }



}


float ClienteTareas::acumularAbonos(int dni)
{

    float montoAcumulado = 0;
    int cantidadClientes =_archivoCliente.getCantidad();


    for (int i = 0; i < cantidadClientes ; i++ )
    {
        Cliente cliente = _archivoCliente.leer(i);

        if ( dni == cliente.getDni())
        {

            montoAcumulado   =  cliente.getYoga().getCuotaMensual() + cliente.getBoxeo().getCuotaMensual()  + cliente.getAbonoMensual();




        }




    }


    return montoAcumulado;


}



void ClienteTareas::actualizarFechaPago(int dni)
{

    int cantidadDeClientes =_archivoCliente.getCantidad();
    Fecha fechaHoy;
    fechaHoy.setMes(fechaHoy.getMes() + 1 );

    for (int i = 0; i < cantidadDeClientes; i++ )
    {
        Cliente cliente = _archivoCliente.leer(i);

        Boxeo boxeoNuevo = cliente.getBoxeo();
        boxeoNuevo.setFechaLimitePago(fechaHoy);

        Yoga YogaNuevo = cliente.getYoga();
        YogaNuevo.setFechaLimitePago(fechaHoy);


        if ( cliente.getDni()  == dni )
        {


            cliente.setFechaLimite(fechaHoy);
            cliente.setBoxeo( boxeoNuevo)  ;
            cliente.setYoga(YogaNuevo);





            _archivoCliente.editar(cliente,i);

        }


    }


}

void ClienteTareas::listarTodosLosClientesDadosDeBaja()
{

    int cantidadDeClientes = _archivoCliente.getCantidad();
    for (int i = 0; i < cantidadDeClientes; i++ )
    {
        Cliente cliente = _archivoCliente.leer(i);

        cliente.mostrarClienteDadoDeBaja();
        cout <<"----------------------------------------------" << endl;
    }
}



void ClienteTareas::reactivarCliente()
{
    int dni,op = 2;
    cout <<"INGRESE EL DOCUMENTO DEL CLIENTE QUE QUIERE REACTICVAR"<< endl;
    cin >> dni;
    int cantidadDeClientes = _archivoCliente.getCantidad();
    for (int i = 0; i < cantidadDeClientes; i++ )
    {
        Cliente cliente = _archivoCliente.leer(i);


        if ( cliente.getDni() == dni && cliente.getEstado() == false )
        {


            cout <<"USTED VA A REACTIVAR A:"<< endl;
            cliente.mostrarClienteDadoDeBaja();
            cout <<endl;
            cout <<"ESTA SEGURO?"<< endl;
            cout <<"1 - SI o 0 - NO" << endl;
            cin >> op;
            if (op == 1)
            {

                cliente.setEstado(true);
                _archivoCliente.editar(cliente,i);

                cout << endl;
                cout <<"REGISTRO ACTIVADO"<< endl;
            }

        }



    }
}


void ClienteTareas::listarPorNombre(){

int orden;
    do
    {
        cout<<"Ingrese el orden(1 - Ordenados de mayor a menor, 2 - Ordenados de menor a mayor)"<<endl;
        cin>>orden;
    }
    while(orden<1||orden>2);
    ClienteArchivo archivo("clientes.dat");

    int cantidad=archivo.getCantidad();
    Cliente *vCliente=new Cliente[cantidad];
    Cliente aux;
    if(vCliente==NULL)
    {
        cout<<"Error al intentar cargar el vector dinamico"<<endl;
        return;
    }
    archivo.leerVector(vCliente,cantidad);

    if(orden==1)
    {
        int mayor=0;

        for(int i=0; i<cantidad-1; i++)
        {
            mayor=i;
            for(int x=i+1; x<cantidad; x++)
            {
                if(strcmp(vCliente[x].getNombre(),vCliente[mayor].getNombre())>0)
                {
                    mayor=x;
                }
            }
            if(mayor!=i)
            {
                aux=vCliente[i];
                vCliente[i]=vCliente[mayor];
                vCliente[mayor]=aux;
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
                if(strcmp(vCliente[x].getNombre(),vCliente[menor].getNombre())<0)
                {
                    menor=x;
                }
            }
            if(menor!=i)
            {
                aux=vCliente[i];
                vCliente[i]=vCliente[menor];
                vCliente[menor]=aux;
            }
        }


    }

    for(int i=0; i<cantidad; i++)
    {
        vCliente[i].mostrarCliente();
        cout<<endl;
    }

    delete []vCliente;
}



void ClienteTareas::listarClientesPorAnioIngreso()
{
    int anio;
    cout<<"INGRESE EL ANIO DE INGRESO PARA LISTAR LOS CLIENTES"<<endl;
    cin>>anio;
    cout<<endl;

    for (int i = 0; i < _archivoCliente.getCantidad(); i++ ){

      if ( anio == _archivoCliente.leer(i).getFechaDelAlta().getAnio() ) {

        _archivoCliente.leer(i).mostrarCliente();
        cout <<"-------------------------------------"<< endl;

      }

    }
}


void ClienteTareas::listarOrdenadosPorApellido()
{
    int orden;
    do
    {
        cout<<"Ingrese el orden(1 - Ordenados de mayor a menor, 2 - Ordenados de menor a mayor)"<<endl;
        cin>>orden;
    }
    while(orden<1||orden>2);
    ClienteArchivo archivo("clientes.dat");

    int cantidad=archivo.getCantidad() ;
    Cliente *vCliente=new Cliente[cantidad];
    Cliente aux;
    if(vCliente==NULL)
    {
        cout<<"Error al intentar cargar el vector dinamico"<<endl;
        return;
    }
    archivo.leerVector(vCliente,cantidad);

    if(orden==1)
    {
        int mayor=0;

        for(int i=0; i<cantidad-1; i++)
        {
            mayor=i;
            for(int x=i+1; x<cantidad; x++)
            {
                if(strcmp(vCliente[x].getApellido(),vCliente[mayor].getApellido())>0)
                {
                    mayor=x;
                }
            }
            if(mayor!=i)
            {
                aux=vCliente[i];
                vCliente[i]=vCliente[mayor];
                vCliente[mayor]=aux;
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
                if(strcmp(vCliente[x].getApellido(),vCliente[menor].getApellido())<0)
                {
                    menor=x;
                }
            }
            if(menor!=i)
            {
                aux=vCliente[i];
                vCliente[i]=vCliente[menor];
                vCliente[menor]=aux;
            }
        }


    }

    for(int i=0; i<cantidad; i++)
    {
        vCliente[i].mostrarCliente();
        cout<<endl;
    }

    delete []vCliente;
}

/*
void ClienteTareas::listarPorEdad()
{
    Fecha hoy;

    int orden;
    do
    {
        cout<<"Ingrese el orden (1 - Ordenados de mayor a menor, 2 - Ordenados de menor a mayor)"<<endl;
        cin>>orden;

    }
    while(orden<1||orden>2);

    ClienteArchivo archivo("clientes.dat");
    int cantidad=archivo.getCantidad();
    Cliente aux;
    Cliente *vCliente=new Cliente[cantidad];
    archivo.leerVector(vCliente,cantidad);

    if(vCliente==NULL)
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
                if(calcularEdad(vCliente[x].getFechaNacimiento())>calcularEdad(vCliente[mayor].getFechaNacimiento()))
                {
                    mayor=x;
                }
            }
            if(mayor!=i)
            {
                aux=vCliente[i];
                vCliente[i]=vCliente[mayor];
                vCliente[mayor]=aux;
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
                if(calcularEdad(vCliente[x].getFechaNacimiento())<calcularEdad(vCliente[menor].getFechaNacimiento()))
                {
                    menor=x;
                }
            }
            if(menor!=i)
            {
                aux=vCliente[i];
                vCliente[i]=vCliente[menor];
                vCliente[menor]=aux;
            }
        }



    }

    for(int i=0; i<cantidad; i++)
    {
        vCliente[i].mostrarCLiente();
        cout<<endl;
    }
    delete []vCliente;
}
*/


void ClienteTareas::consultaPorNombre()
{
    char nombre[30];
    cout<<"Ingrese el nombre"<<endl;
    cargarCadena(nombre,29);
    if(_archivoCliente.buscarPorNombre(nombre)>0)
    {
        cout<<"NOMBRE Encontrado!"<<endl<<endl;
    }else
    {
        cout<<"No existe ese nombre o no se pudo abrir el archivo"<<endl;
    }

}


void ClienteTareas::consultaPorApellido()
{
    char apellido[30];
    cout<<"Ingrese el apellido"<<endl;
    cargarCadena(apellido,29);
    if(_archivoCliente.buscarPorApellido(apellido)>0)
    {
        cout<<"APELLIDO Encontrado!"<<endl<<endl;
    }else
    {
        cout<<"No existe ese apellido o no se pudo abrir el archivo"<<endl;
    }
}


void ClienteTareas::consultaPorEdad()
{
    int edad;
    cout<<"Ingrese la edad"<<endl;
    cin>>edad;
    if(_archivoCliente.buscarPorEdad(edad)>0)
    {
        cout<<"EDAD ENCONTRADA!"<<endl<<endl;
    }else
    {
        cout<<"NO EXISTE ESA EDAD O NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    }
}


void ClienteTareas::consultarPorNumeroSocio(){
int NumSocio;
cout <<"INGRESE EL NUMERO DE SOCIO:" << endl;
cin >> NumSocio;
if (_archivoCliente.buscarPorNumeroDeSocio(NumSocio) == NumSocio ){

     cout<<"ID ENCONTRADO"<<endl;

 } else
    {
        cout<<"NO EXISTE ESE SOCIO O NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    }


}


