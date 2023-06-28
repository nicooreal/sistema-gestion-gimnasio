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




    if(_archivoCliente.guardar(cliente))
    {

        cout <<"-------------------------------"<< endl;
        pagoTareas.cargarPago(true,cliente.getDni());
    }





}
void ClienteTareas::modificar()
{
    int numeroRegistro = _archivoCliente.buscarRegistro();
    if (numeroRegistro>=0)
    {

        Cliente cliente=_archivoCliente.leer(numeroRegistro);

        if( cliente.getEstado() == true )
        {

            cout <<"EL CLIENTE QUE USTED QUIERE MODIFICAR ES: " << endl << endl;
            cliente.mostrarCliente();
            system("pause");
            cout << endl;
            cout << "MODIFIQUE AL CLIENTE"<<endl;


            elegirQueModificar(cliente);


            bool exito = _archivoCliente.editar(cliente, numeroRegistro);
            if (exito)
            {
                cout << "REGISTRO MODIFICADO." << endl;
            }
            else
            {
                cout << "NO SE PUDO MODIFICAR EL REGISTRO." << endl;
            }


        }
        else
        {
            cout <<"NO SE ENCONTRO EL REGISTRO" << endl;
        }
    }
}


void ClienteTareas::consultarPorDni()
{

    bool esValido = false;
    int documento;
    cout <<"INGRESE EL DNI: " << endl;
    cin >> documento;

validarIngresos(documento);







    if(_archivoCliente.buscarPorDni(documento)>0)
    {
        cout<<"DNI ENCONTRADO!"<<endl<<endl;
    }
    else if(_archivoCliente.buscarPorDni(documento)==-1)
    {
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    }
    else
    {
        cout<<"NO EXISTE UN CLIENTE CON ESE DNI O ESE CLIENTE ESTA DADO DE BAJA"<<endl;
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
    Cliente cliente=_archivoCliente.leer(numeroRegistro);
    if (numeroRegistro>=0 && cliente.getEstado() == true )
    {
        cout <<"EL CLIENTE QUE USTED QUIERE DAR DE BAJA ES:" << endl << endl;
        cliente.mostrarCliente();
        system("pause");
        cout <<"DESEA DAR LA BAJA?" <<endl;
        cout <<"1 - SI o 0 - NO" << endl;

        cin >> op;
        validarIngresos(op);

        if (op == 1)
        {
            Cliente clienteEnBaja = cliente;
            clienteEnBaja.setEstado(false);

            bool exito = _archivoCliente.editar(clienteEnBaja, numeroRegistro);
            if (exito)
            {
                cout << "REGISTRO DADO DE BAJA EXITOSAMENTE." << endl;

            }
            else
            {
                cout << "NO SE PUDO MODIFICAR EL REGISTRO." << endl;
            }


        }

        if (op == 2 )
        {

            cout <<"CLIENTE NO MODIFICADO"<< endl;

        }



    }
    else
    {
        cout <<"EL USUARIO NO SE ENCUENTRA"<< endl;
    }

}

void ClienteTareas::elegirQueModificar(Cliente &clienteModificado)
{
    int opcion;
    char nombre[30],apellido[30];
    char genero;
    int dni;

    Fecha fechaNacimiento,fechaAlta,fechaLimiteParaPagarAbono;


    do
    {
        do
        {
            system("cls");
            cout<<"\tMODIFICAR CLIENTE"<<endl;
            cout<<"-------------------------------------"<<endl;
            cout<<"1  - MODIFICAR NOMBRE"<<endl;
            cout<<"2  - MODIFICAR APELLIDO"<<endl;
            cout<<"3  - MODIFICAR DNI"<<endl;
            cout<<"4  - MODIFICAR GENERO"<<endl;
            cout<<"5  - MODIFICAR FECHA NACIMIENTO"<<endl;
            cout<<"6  - MODIFICAR FECHA DE ALTA"<<endl;
            cout<<"7  - MODIFICAR FECHA LIMITE PARA PAGAR ABONO"<<endl;
            cout<<"8  - MODIFICAR ABONO MENSUAL"<<endl;
            cout<<"9  - MODIFICAR ACTIVIDADES" << endl;
            cout<<"10 - MODIFICAR TODO EL REGISTRO"<<endl;
            cout<<"-------------------------------------"<<endl;
            cout<<"0 - SALIR"<<endl;
            cout<<"OPCION: ";
            cin>>opcion;
           validarIngresos(opcion);




            system("cls");
        }
        while(opcion<0||opcion>10);



        switch(opcion)
        {
        case 1:
            cout<<"INGRESE NUEVO NOMBRE"<<endl;
            cargarCadena(nombre,29);
            convertirAMayusculas(nombre);
            clienteModificado.setNombre(nombre);
            cout <<"NOMBRE CAMBIADO CON EXITO"<< endl;
            break;
        case 2:
            cout<<"INGRESE NUEVO APELLIDO"<<endl;
            cargarCadena(apellido,29);
            convertirAMayusculas(apellido);
            clienteModificado.setApellido(apellido);
            cout <<"APELLIDO CAMBIADO CON EXITO"<< endl;
            break;
        case 3:
            do
            {
                cout<<"INGRESE NUEVO DNI "<<endl;
                cin>>dni;
                validarIngresos(dni);
                clienteModificado.setDni(dni);

            }
            while(_archivoCliente.existeCliente(clienteModificado)!=0);

            break;
        case 4:
            do
            {
                cout<<"INGRESE EL NUEVO GENERO (M - MASCULINO, F - FEMENINO) "<<endl;
                cin>>genero;
                toupper(genero);
            }
            while(genero!='F'&&genero!='f'&&genero!='m'&&genero!='M');

            clienteModificado.setSexo(genero);
            break;
        case 5:
            cout<<"INGRESE NUEVA FECHA DE NACIMIENTO "<<endl;
            fechaNacimiento.cargar();
            clienteModificado.setFechaNacimiento(fechaNacimiento);
            clienteModificado.setEdad(calcularEdad(fechaNacimiento));
            cout <<"FECHA CAMBIADA CON EXITO"<< endl;
            break;
        case 6:
            cout<<"INGRESE LA NUEVA FECHA DEL ALTA"<<endl;
            fechaAlta.cargar();
            clienteModificado.setFechaDelAlta(fechaAlta);
            cout <<"FECHA CAMBIADA CON EXITO"<< endl;
            break;
        case 7:
            cout<<"INGRESE LA NUEVA FECHA LIMITE "<<endl;


            cambiarAlgunaFechaLimite(clienteModificado );
            break;
        case 8:
            cambiarMontoDeAlgunAbono(clienteModificado);
            break;
        case 9:
            cambiarActividades(clienteModificado);
            break;
        case 10:
            cout<<"INGRESE EL NUEVO REGISTRO DEL CLIENTE"<<endl;
            int socio=clienteModificado.getNumeroDeSocio();
            clienteModificado.cargarCliente();
            clienteModificado.setNumeroDeSocio(socio);
            break;


        }
        if(opcion!=0)
        {
            system("pause");
        }


    }
    while(opcion!=0);

}


void ClienteTareas::cambiarActividades(Cliente &clienteModificado)
{
    Fecha fechaHoy;
    ClienteArchivo clienteArch;
    int op,opMensual;
    int numeroRegistro = clienteModificado.getNumeroDeSocio();
    Fecha nuevaFecha;
    Boxeo box;
    Yoga yog;

    if ( clienteModificado.getPesas() == true)
    {
        cout <<"INGRESE 1 PARA DAR DE BAJA SERVICIO PESAS"<< endl;
    }
    else
    {
        cout <<"INGRESE 4 PARA DAR DE ALTA SERVICIO PESAS"<< endl;
    }
    if ( clienteModificado.getBoxeo().getActivo() == true)
    {
        cout <<"INGRESE 2 PARA DAR DE BAJA SERVICIO DE BOXEO"<< endl;
    }
    else
    {
        cout <<"INGRESE 5 PARA DAR DE ALTA SERVICIO DE BOXEO"<< endl;
    }
    if ( clienteModificado.getYoga().getActivo() == true)
    {
        cout <<"INGRESE 3 PARA DAR DE BAJA SERVICIO DE YOGA"<< endl;
    }
    else
    {
        cout <<"INGRESE 6 PARA DAR DE ALTA SERVICIO DE YOGA"<< endl;
    }

    cout <<"INGRESE 0 PARA VOLVER" << endl;
    cin >> op;
validarIngresos(op);

    if ( clienteModificado.getPesas() == true && op== 1 )
    {

        clienteModificado.setAbonoMensual(0);
        clienteModificado.setPesas(false);
        cout <<"SERVICIO DE PESAS DESACTIVADO" << endl;

    }

    if ( clienteModificado.getBoxeo().getActivo() == true && op == 2 )
    {


        box = clienteModificado.getBoxeo();
        box.setActivo(false) ;
        box.setCuotaMensual(0);
        clienteModificado.setBoxeo(box);
        cout <<"SERVICIO DE BOXEO DESACTIVADO" << endl;
    }

    if ( clienteModificado.getYoga().getActivo() == true  && op == 3)
    {

        yog = clienteModificado.getYoga();
        yog.setActivo(false);
        yog.setCuotaMensual(0);
        clienteModificado.setYoga(yog);
        cout <<"SERVICIO DE YOGA DESACTIVADO" << endl;
    }



    if ( clienteModificado.getPesas() == false && op== 4 )
    {


        clienteModificado.setPesas(true);
        cout <<"INGRESE LA OPCION(numero) PARA EL MONTO MENSUAL A PAGAR: " << endl;
        cout <<"OPCION 1 - 3 Dias - $1000" << endl;
        cout <<"OPCION 2 - 4 Dias - $1200" << endl;
        cout <<"OPCION 3 - 5 PASE LIBRE $1400" << endl;
        cin >> opMensual;
        clienteModificado.establecerPlanMensual(opMensual);

    }

    if ( clienteModificado.getBoxeo().getActivo() == false && op == 5 )
    {



        clienteModificado.setBoxeo(box); // el constructor por defecto pone los valores correspondientes a un alta
        cout <<"SERVICIO DE BOXEO ACTIVADO" << endl;
    }

    if ( clienteModificado.getYoga().getActivo() == false  && op == 6)
    {


        clienteModificado.setYoga(yog);  //el constructor por defecto pone los valores correspondientes a un alta
        cout <<"SERVICIO DE YOGA ACTIVADO" << endl;
    }

    cout <<"VOLVIENDO AL MENU ANTERIOR"<< endl;
}


void ClienteTareas::cambiarMontoDeAlgunAbono( Cliente &clienteModificado)
{
    ClienteArchivo clienteArch;
    int cantidadDeClientes = clienteArch.getCantidad();
    int op;
    int numeroRegistro = clienteModificado.getNumeroDeSocio();
    Fecha nuevaFecha;
    Boxeo box;
    Yoga yog;
    int nuevoMonto;

    if ( clienteModificado.getPesas() == true)   cout <<"INGRESE 1 PARA CAMBIAR EL MONTO DEL SERVICIO PESAS"<< endl;
    if ( clienteModificado.getBoxeo().getActivo() == true)  cout <<"INGRESE 2 PARA CAMBIAR EL MONTO DEL SERVICIO DE BOXEO"<< endl;
    if ( clienteModificado.getYoga().getActivo() == true)  cout <<"INGRESE 3 PARA CAMBIAR EL MONTO DEL SERVICIO DE YOGA"<< endl;


    cout <<"INGRESE 0 PARA VOLVER" << endl;
    cin >> op;
validarIngresos(op);

    if ( clienteModificado.getPesas() == true && op== 1 )
    {

        cout <<"INGRESE NUEVO MONTO"<< endl;
        cin>>nuevoMonto;
        validarIngresos(nuevoMonto);

        clienteModificado.setAbonoMensual(nuevoMonto);
        cout <<"MONTO CAMBIADO CON EXITO"<< endl;
    }

    if ( clienteModificado.getBoxeo().getActivo() == true && op == 2 )
    {

        cout <<"INGRESE NUEVO MONTO"<< endl;
        cin>>nuevoMonto;
        validarIngresos(nuevoMonto);

        box = clienteModificado.getBoxeo();
        box.setCuotaMensual(nuevoMonto);
        clienteModificado.setBoxeo(box);
        cout <<"MONTO CAMBIADO CON EXITO"<< endl;
    }

    if ( clienteModificado.getYoga().getActivo() == true  && op == 3)
    {
        cout <<"INGRESE NUEVO MONTO"<< endl;
        cin>>nuevoMonto;
        validarIngresos(nuevoMonto);

        yog = clienteModificado.getYoga();
        yog.setCuotaMensual(nuevoMonto);
        clienteModificado.setYoga(yog);
        cout <<"MONTO CAMBIADO CON EXITO"<< endl;
    }

    cout <<"VOLVIENDO AL MENU ANTERIOR"<< endl;




}

void ClienteTareas::cambiarAlgunaFechaLimite(Cliente &clienteModificado)
{
    ClienteArchivo clienteArch;
    int cantidadDeClientes = clienteArch.getCantidad();
    int op;
    int numeroRegistro = clienteModificado.getNumeroDeSocio();
    Fecha nuevaFecha;
    Boxeo box;
    Yoga yog;

    if ( clienteModificado.getPesas() == true)   cout <<"INGRESE 1 PARA CAMBIAR LA FECHA DEL SERVICIO PESAS"<< endl;
    if ( clienteModificado.getBoxeo().getActivo() == true)  cout <<"INGRESE 2 PARA CAMBIAR LA FECHA DEL SERVICIO DE BOXEO"<< endl;
    if ( clienteModificado.getYoga().getActivo() == true)  cout <<"INGRESE 3 PARA CAMBIAR LA FECHA DEL SERVICIO DE YOGA"<< endl;


    cout <<"INGRESE 0 PARA VOLVER" << endl;
    cin >> op;
    validarIngresos(op);

    if ( clienteModificado.getPesas() == true && op== 1 )
    {

        nuevaFecha.cargar();
        clienteModificado.setFechaLimite(nuevaFecha);
        cout <<"FECHA CAMBIADA CON EXITO"<< endl;
    }

    if ( clienteModificado.getBoxeo().getActivo() == true && op == 2 )
    {
        nuevaFecha.cargar();

        box = clienteModificado.getBoxeo();
        box.setFechaLimitePago(nuevaFecha);
        clienteModificado.setBoxeo(box);
        cout <<"FECHA CAMBIADA CON EXITO"<< endl;
    }

    if ( clienteModificado.getYoga().getActivo() == true  && op == 3)
    {

        nuevaFecha.cargar();

        yog = clienteModificado.getYoga();
        yog.setFechaLimitePago(nuevaFecha);
        clienteModificado.setYoga(yog);
        cout <<"FECHA CAMBIADA CON EXITO"<< endl;
    }

    cout <<"VOLVIENDO AL MENU ANTERIOR"<< endl;




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
    validarIngresos(documento);

    int cantidadDeClientes = _archivoCliente.getCantidad();


    for (int i = 0; i < cantidadDeClientes; i++ )
    {
        Cliente cliente = _archivoCliente.leer(i);
        int numeroRegistro = i;

        if ( documento == cliente.getDni() )
        {



            cout <<"NOMBRE: " << cliente.getNombre() <<endl;
            cout <<"APELLIDO: " <<cliente.getApellido() <<endl;
            cout<<"INGRESOS RESTANTES: "<< cliente.getControlIngresos() - 1 << endl;
            cout <<"FECHA DE VENCIMIENTO: ";
            cliente.getFechaLimiteParaPagarAbono().mostrar();

            cliente.setControlIngresos( cliente.getControlIngresos() - 1);
            _archivoCliente.editar(cliente,numeroRegistro);
            break;
        }

    }






}


void ClienteTareas::mostrarClientesConFechaPorVencer() // hace los calculos sobre los 3 servicios

{

    Fecha fechaHoy;
    int cantidadRegistros =_archivoCliente.getCantidad();
    int diasPorMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (fechaHoy.esBisiesto()==true)
    {
        diasPorMes[1]++;
    }
    bool algunCliente=true;

    for (int i = 0; i < cantidadRegistros; i++)
    {
        Cliente cliente =_archivoCliente.leer(i);


        if (cliente.getPesas() && cliente.getEstado() )

        {


            if ( cliente.getFechaLimiteParaPagarAbono().getAnio() == fechaHoy.getAnio()&& cliente.getFechaLimiteParaPagarAbono().getMes() == fechaHoy.getMes() && cliente.getEstado())
            {

                if ( cliente.getFechaLimiteParaPagarAbono().getDia() - fechaHoy.getDia() <= 6 )
                {
                    algunCliente=false;
                    cliente.mostrarCliente();

                }

            }

            if ( cliente.getFechaLimiteParaPagarAbono().getAnio()== fechaHoy.getAnio() && cliente.getFechaLimiteParaPagarAbono().getMes() != fechaHoy.getMes() && cliente.getEstado())
            {
                int diasParaTerminarELmes = diasPorMes[ fechaHoy.getMes()- 1 ] - fechaHoy.getDia();
                if(diasParaTerminarELmes+cliente.getFechaLimiteParaPagarAbono().getDia()<=6)
                {
                    algunCliente=false;
                    cliente.mostrarCliente();
                }



            }

        }


        if ( cliente.getBoxeo().getActivo() && cliente.getEstado() )


        {

            if ( cliente.getYoga().getFechaLimitePago().getAnio() == fechaHoy.getAnio() && cliente.getYoga().getFechaLimitePago().getMes() == fechaHoy.getMes())
            {

                if ( cliente.getYoga().getFechaLimitePago().getDia() - fechaHoy.getDia() <= 6 )
                {
                    algunCliente=false;
                    cliente.mostrarCliente();

                }

            }

            if ( cliente.getBoxeo().getFechaLimitePago().getAnio() == fechaHoy.getAnio() && cliente.getBoxeo().getFechaLimitePago().getMes() != fechaHoy.getMes())
            {
                int diasParaTerminarELmes = diasPorMes[ fechaHoy.getMes()- 1 ] - fechaHoy.getDia();
                if(diasParaTerminarELmes + cliente.getBoxeo().getFechaLimitePago().getDia()<=6)
                {
                    algunCliente=false;
                    cliente.mostrarCliente();
                }

            }



        }




        if ( cliente.getYoga().getActivo() && cliente.getEstado() )


        {

            if ( cliente.getYoga().getFechaLimitePago().getAnio() == fechaHoy.getAnio() && cliente.getYoga().getFechaLimitePago().getMes() == fechaHoy.getMes())
            {

                if ( cliente.getYoga().getFechaLimitePago().getDia() - fechaHoy.getDia() <= 6 )
                {
                    algunCliente=false;
                    cliente.mostrarCliente();

                }

            }

            if ( cliente.getYoga().getFechaLimitePago().getAnio() == fechaHoy.getAnio() && cliente.getYoga().getFechaLimitePago().getMes() != fechaHoy.getMes())
            {
                int diasParaTerminarELmes = diasPorMes[ fechaHoy.getMes()- 1 ] - fechaHoy.getDia();
                if(diasParaTerminarELmes + cliente.getYoga().getFechaLimitePago().getDia()<=6)
                {
                    algunCliente=false;
                    cliente.mostrarCliente();
                }

            }





        }




    }

        if(algunCliente==true)
        {
            cout << "NO SE ENCONTRARON CLIENTES POR FECHA POR VENCER (6 DIAS O MEN0S DE VENCIMIENTO)"<<endl;
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
            cout<<"4 - POR ANIO DE INGRESO"<<endl;
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
            listarPorEdad();

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
            consultaPorEdad();
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

        if ( cliente.getDni()  == dni )
        {

            Boxeo boxeoNuevo = cliente.getBoxeo();
            Yoga YogaNuevo = cliente.getYoga();






            Fecha fechaBox = boxeoNuevo.getFechaLimitePago();
            Fecha fechaYog = YogaNuevo.getFechaLimitePago();              // declaro xq alfinal no puedo setear desde un get
            Fecha fechaPesas = cliente.getFechaLimiteParaPagarAbono();

            if ( boxeoNuevo.getActivo() == true )

            {

                if ( fechaBox.getMes() == 12 )

                {


                    fechaBox.setMes(1);

                }

                else


                {

                    fechaBox.setMes( fechaBox.getMes() + 1 );
                }


            }



            if ( YogaNuevo.getActivo() == true )
            {

                if ( fechaYog.getMes() == 12 )

                {


                    fechaYog.setMes(1);

                }


                else
                {


                    fechaYog.setMes( fechaYog.getMes() + 1 );

                }



            }




            if (cliente.getPesas() == true )

            {

                if (fechaPesas.getMes() == 12 )
                {

                    fechaPesas.setMes(1);

                }

                else

                {

                    fechaPesas.setMes(fechaPesas.getMes() + 1  );

                }


            }




            boxeoNuevo.setFechaLimitePago( fechaBox);
            YogaNuevo.setFechaLimitePago(fechaYog);


            cliente.setFechaLimite(fechaPesas);
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


void ClienteTareas::listarPorNombre()
{

    int orden;
    do
    {
        cout<<"INGRESE EL ORDEN (1 - MAYOR A MENOR, 2 - MENOR A MAYOR)"<<endl;
        cin>>orden;
    }
    while(orden<1||orden>2);
    ClienteArchivo archivo("clientes.dat");

    int cantidad=archivo.getCantidad();
    Cliente *vCliente=new Cliente[cantidad];
    Cliente aux;
    if(vCliente==NULL)
    {
        cout<<"ERROR AL INTENTAR CARGAR EL VECTOR DINAMICO"<<endl;
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

    for (int i = 0; i < _archivoCliente.getCantidad(); i++ )
    {

        if ( anio == _archivoCliente.leer(i).getFechaDelAlta().getAnio() )
        {

            _archivoCliente.leer(i).mostrarCliente();
            cout <<"-------------------------------------"<< endl;

        }

    }
}

int ClienteTareas::calcularEdad(Fecha fechaNacimiento)
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


void ClienteTareas::listarOrdenadosPorApellido()
{
    int orden;
    do
    {
        cout<<"INGRESE EL ORDEN(1 - MAYOR A MENOR, 2 - MENOR A MAYOR)"<<endl;
        cin>>orden;
    }
    while(orden<1||orden>2);
    ClienteArchivo archivo("clientes.dat");

    int cantidad=archivo.getCantidad() ;
    Cliente *vCliente=new Cliente[cantidad];
    Cliente aux;
    if(vCliente==NULL)
    {
        cout<<"ERROR AL INTENTAR CARGAR EL VECTOR DINAMICO"<<endl;
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


void ClienteTareas::listarPorEdad()
{
    Fecha hoy;

    int orden;
    do
    {
        cout<<"INGRESE EL ORDEN (1 - MAYOR A MENOR, 2 - MENOR A MAYOR)"<<endl;
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
        vCliente[i].mostrarCliente();
        cout<<endl;
    }
    delete []vCliente;
}



void ClienteTareas::consultaPorNombre()
{
    char nombre[30];
    cout<<"INGRESE EL NOMBRE"<<endl;
    cargarCadena(nombre,29);
    convertirAMayusculas(nombre);
    if(_archivoCliente.buscarPorNombre(nombre)>0)
    {
        cout<<"NOMBRE ENCONTRADO!"<<endl<<endl;
    }
    else if(_archivoCliente.buscarPorNombre(nombre)==-1)
    {
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    }
    else
    {
        cout<<"NO EXISTE UN CLIENTE CON ESE NOMBRE O ESE CLIENTE ESTA DADO DE BAJA"<<endl;
    }

}


void ClienteTareas::consultaPorApellido()
{
    char apellido[30];
    cout<<"INGRESE APELLIDO"<<endl;
    cargarCadena(apellido,29);
    convertirAMayusculas(apellido);
    if(_archivoCliente.buscarPorApellido(apellido)>0)
    {
        cout<<"APELLIDO ENCONTRADO!"<<endl<<endl;
    }
    else if(_archivoCliente.buscarPorApellido(apellido)==-1)
    {
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    }
    else
    {
        cout<<"NO EXISTE UN CLIENTE CON ESE APELLIDO O ESE CLIENTE ESTA DADO DE BAJA"<<endl;
    }
}


void ClienteTareas::consultaPorEdad()
{
    int edad;
    cout<<"INGRESE EDAD"<<endl;
    cin>>edad;
    if(_archivoCliente.buscarPorEdad(edad)>0)
    {
        cout<<"EDAD ENCONTRADA!"<<endl<<endl;
    }
    else if(_archivoCliente.buscarPorEdad(edad)==-1)
    {
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    }
    else
    {
        cout<<"ESE CLIENTE ESTA DADO DE BAJA O NO EXISTE UN CLIENTE CON ESA EDAD"<<endl;
    }
}


void ClienteTareas::consultarPorNumeroSocio()
{
    int NumSocio;
    cout <<"INGRESE EL NUMERO DE SOCIO:" << endl;
    cin >> NumSocio;
    if (_archivoCliente.buscarPorNumeroDeSocio(NumSocio) == NumSocio )
    {

        cout<<"NUMERO DE SOCIO ENCONTRADO!"<<endl;

    }
    else if(_archivoCliente.buscarPorNumeroDeSocio(NumSocio) == -1)
    {
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    }
    else
    {
        cout<<"NO EXISTE UN CLIENTE CON ESE NUMERO DE SOCIO O ESE CLIENTE ESTA DADO DE BAJA"<<endl;
    }


}


