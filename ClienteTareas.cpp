#include "ClienteTareas.h"
#include "Cliente.h"
#include "ClienteArchivo.h"
#include "GimnasioMenu.h"

void ClienteTareas::cargar()
{

    int id=generarID();
    Cliente cliente;
    cout<<"ID Cliente #"<<id<<endl;
    cliente.setId(id);
    cliente.cargarCliente();

    _archivoCliente.guardar(cliente);


}
void ClienteTareas::modificar()
{
    int numeroRegistro = _archivoCliente.buscarRegistro();
    if (numeroRegistro>=0)
    {
        cout <<"el cliente que usted quiere modificar es: " << endl;

        Cliente cliente=_archivoCliente.leer(numeroRegistro);
        cout<<"ID Cliente #"<<cliente.getId()<<endl;
        cliente.mostrarCliente();
        cout << endl;
        cout << "Modifique al cliente"<<endl;
        Cliente clienteModificado;

        elegirQueModificar(clienteModificado);


        bool exito = _archivoCliente.editar(clienteModificado, numeroRegistro);
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
void ClienteTareas::listarClientesBox()
{
    ClienteArchivo clienteArch;
    int cantidadDeClientes = clienteArch.getCantidad();

    for (int i = 0; i < cantidadDeClientes; i++)
    {
        Cliente cliente =  clienteArch.leer(i);


        if ( strcmp( "", "boxeo") == 0 )  // este metodo hay que rehacerlo
        {
            cout<<"ID Cliente #"<<cliente.getId()<<endl; /// AÑADI EL ID
            cliente.mostrarCliente();
            cout <<"----------------------------"<< endl;

        }


    }

}



void ClienteTareas::mostrarPorDni()
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
            cout<<"ID Cliente #"<<cliente.getId()<<endl;
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
            cout<<"ID Cliente #"<<cliente.getId()<<endl;
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
        Cliente em=_archivoCliente.leer(numeroRegistro);
        cout<<"ID Cliente #"<<em.getId()<<endl;;
        em.mostrarCliente();
        system("pause");
        cout <<"¿desea dar la baja?" <<endl;
        cout <<"1 - SI o 2 - NO" << endl;
        cin >> op;
        if (op == 1)
        {
            Cliente clienteEnBaja ;
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
    char nombre[30],apellido[30],genero[30];
    int dni,edad,numeroSocio;

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
            cout<<"4 - MODIFICAR EDAD"<<endl;
            cout<<"5 - MODIFICAR GENERO"<<endl;
            cout<<"6 - MODIFICAR FECHA NACIMIENTO"<<endl;
            cout<<"7 - MODIFICAR NUMERO DE SOCIO"<<endl;
            cout<<"8 - MODIFICAR FECHA DE ALTA"<<endl;
            cout<<"9 - MODIFICAR FECHA LIMITE PARA PAGAR ABONO"<<endl;
            cout<<"10 - MODIFICAR ABONO MENSUAL"<<endl;
            cout<<"11 - MODIFICAR TODO EL REGISTRO"<<endl;
            cout<<"-------------------------------------"<<endl;
            cout<<"0 - SALIR"<<endl;
            cout<<"OPCION: ";
            cin>>opcion;
            system("cls");
        }
        while(opcion<0||opcion>11);



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
            cout<<"Ingrese la nueva edad "<<endl;
            cin>>edad;
            clienteModificado.setEdad(edad);
            break;
        case 5:
            cout<<"Ingrese el nuevo genero "<<endl;
            cargarCadena(genero,29);
            clienteModificado.setSexo(genero);
            break;
        case 6:
            cout<<"Ingrese la nueva fecha de nacimiento "<<endl;
            fechaNacimiento.cargar();
            clienteModificado.setFechaNacimiento(fechaNacimiento);
            break;
        case 7:
            cout<<"Ingrese el nuevo numero de socio "<<endl;
            cin>>numeroSocio;
            clienteModificado.setNumeroDeSocio(numeroSocio);
            break;
        case 8:
            cout<<"Ingrese la nueva fecha de alta"<<endl;
            fechaAlta.cargar();
            clienteModificado.setFechaDelAlta(fechaAlta);
            break;
        case 9:
            cout<<"Ingrese la nueva fecha limite "<<endl;
            fechaLimiteParaPagarAbono.cargar();
            clienteModificado.setFechaLimite(fechaLimiteParaPagarAbono);
            break;
        case 10:
            cout<<"Ingrese el nuevo abono mensual"<<endl;
            cin>>abono;
            clienteModificado.setAbonoMensual(abono);
            break;
        case 11:
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


void ClienteTareas::registrarIngresos(){
int documento;
GimnasioMenu gimMenu;


    cout <<"NUMERO DE DOCUMENTO: " << endl;


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
            cout <<"fecha de vencimento: "; cliente.getFechaLimiteParaPagarAbono().mostrar();

            cliente.setControlIngresos( cliente.getControlIngresos() - 1);
           _archivoCliente.editar(cliente,numeroRegistro);
          break;
        }

    }






}


void ClienteTareas::mostrarClientesConFechaPorVencer(){

Fecha fechaHoy;
int cantidadRegistros =_archivoCliente.getCantidad();

for (int i = 0; i < cantidadRegistros; i++){
Cliente cliente =_archivoCliente.leer(i);

if ( cliente.getFechaLimiteParaPagarAbono().getMes() == fechaHoy.getMes())
{

if ( cliente.getFechaLimiteParaPagarAbono().getDia() - fechaHoy.getDia() <= 7 ) {

    cliente.mostrarCliente();

}

}

if ( cliente.getFechaLimiteParaPagarAbono().getMes() > fechaHoy.getMes()) {

    // incompleto, mejor habria q hacer un metodo para contar los dias del anio


}




}



}
