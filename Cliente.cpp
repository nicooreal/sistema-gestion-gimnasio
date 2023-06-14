
#include "Cliente.h"
#include "ClienteArchivo.h"
#include "Boxeo.h"

int Cliente::getNumeroDeSocio()
{

    return _numeroDeSocio;
}

void Cliente::setNumeroDeSocio(int nSocio)
{

    _numeroDeSocio = nSocio;

}

void Cliente::setFechaDelAlta(Fecha f)
{

    _fechaDelAlta = f;

}

Fecha Cliente::getFechaDelAlta()
{

    return _fechaDelAlta;

}


float Cliente::getAbonoMensual()
{

    return _abonoMensual;
}



void Cliente::setAbonoMensual(float abonoM)
{

    _abonoMensual = abonoM;
}


void Cliente::setBoxeo(Boxeo boxe)
{

    _boxeo = boxe;

}


Boxeo Cliente::getBoxeo()
{

    return _boxeo;

}

/*
void Cliente::setNombreDeporte(int nombreDeporte)
{

    if(nombreDeporte>=1&&nombreDeporte<=3)
    {
        _nombreDeporte=nombreDeporte;
    }
    else
    {
        _nombreDeporte=0;
    }

}
*/

void Cliente::setPesas(bool pesas)
{

    _pesas = pesas;

}
bool Cliente::getPesas()
{

    if ( _pesas == true)
    {

        cout <<"Realiza el servicio de pesas" << endl;
    }
    else
    {
        cout<< "No realiza el servicio de pesas"<< endl;
    }

    return _pesas;
}



void Cliente::hacePesas()
{

    if ( _pesas == true)
    {

        cout <<"SI" << endl;
    }
    else
    {
        cout<< "NO"<< endl;
    }

}

void Cliente::setControl(int control)
{

    _controlDeIngresosPesas = control;

}

int Cliente::getControl()
{

    return _controlDeIngresosPesas;

}




void Cliente::setEstado(bool estado)
{
    _estado = estado;

}

bool Cliente::getEstado()
{
    return _estado;
}

Fecha Cliente::getFechaLimiteParaPagarAbono()
{
    return _fechaLimiteParaPagarAbono;
}

void Cliente::setFechaLimite(Fecha f)
{
    _fechaLimiteParaPagarAbono=f;
}


void Cliente::calcularUnMesDeEntreno()
{

    Fecha fecha;
    int dia, mes,anio;


    if (fecha.getMes() == 12)
    {
        mes = 1;
        anio = fecha.getAnio() + 1;
        dia = fecha.getDia();
    }

// falta ver lo del mes de Febrero y si es biciesto


    if (fecha.getDia() == 31)
    {
        dia = 30;
    }
    else
    {
        dia = fecha.getDia();
    }
    mes = fecha.getMes() + 1;
    anio = fecha.getAnio();





    _fechaLimiteParaPagarAbono.setDia(dia);
    _fechaLimiteParaPagarAbono.setMes(mes);
    _fechaLimiteParaPagarAbono.setAnio(anio);

}



void Cliente::cargarCliente()
{
    ClienteArchivo clienteArch;
    int cantidadDeSocios = clienteArch.getCantidad();
    int opcionMensual = 0;
    int opcionExtra;
    Persona::cargarPersona(); // metodo de persona.h
    _numeroDeSocio = cantidadDeSocios + 1;
    _fechaDelAlta.fechaDeHoy();
    cout <<"SERVICIO DE PESAS:(ingrese 1-SI o 0-NO ):" << endl;
    cin >> _pesas;
    if ( _pesas == true )
    {

    calcularUnMesDeEntreno();
    cout <<"INGRESE LA OPCION(numero) PARA EL MONTO MENSUAL A PAGAR: " << endl;
    cout <<"OPCION 1 - 3 Dias - $1000" << endl;
    cout <<"OPCION 2 - 4 Dias - $1200" << endl;
    cout <<"OPCION 3 - 5 PASE LIBRE $1400" << endl;
    cin >>opcionMensual;
    }
    establecerPlanMensual(opcionMensual);
    cout<<"NOMBRE DE LA ACTIVIDAD EXTRA (1 - BOXEO $1000, 2 - YOGA $1000, 3 - BOXEO Y YOGA $1500 4 - NINGUNA )"<<endl;
    cin >> opcionExtra;

establecerOpcionExtra(opcionExtra);



    _estado = true;
}

void Cliente::establecerOpcionExtra(int opcionExtra){
Fecha fecha;

    if (opcionExtra == 1)
    {
        _boxeo.setActivo(true);
        _boxeo.setFechaAlta(fecha);
        _boxeo.setFechaLimitePago( fecha.calcularUnMesDeEntreno(fecha) );
        _boxeo.setCuotaMensual(1000);

        _yoga.setActivo(false);

    }
    if (opcionExtra == 2)
    {
        _yoga.setActivo(true);
        _yoga.setFechaLimitePago(fecha.calcularUnMesDeEntreno(fecha) );
        _yoga.setFechaAlta(fecha);
        _yoga.setCuotaMensual(1000);

       _boxeo.setActivo(false);
    }
    if  (opcionExtra== 3)
    {
        _yoga.setActivo(true);
        _yoga.setFechaLimitePago(fecha.calcularUnMesDeEntreno(fecha) );
        _yoga.setFechaAlta(fecha);
        _yoga.setCuotaMensual(750);

        _boxeo.setActivo(true);
        _boxeo.setFechaAlta(fecha);
        _boxeo.setFechaLimitePago( fecha.calcularUnMesDeEntreno(fecha) );
        _boxeo.setCuotaMensual(750);

    }
    if (opcionExtra == 4)
    {
        _boxeo.setActivo(false);
        _yoga.setActivo(false);
    }

}




void Cliente::mostrarCliente()
{
    if (_estado == true)
    {
        Persona::mostrarPersona();
        cout<<"Numero de socio "<<_numeroDeSocio<<endl;
        cout<<"Fecha de alta: ";
        _fechaDelAlta.mostrar();
        cout <<"Servicio de pesas: ";
        hacePesas();
       if ( _pesas == true ) {
        cout<<"Abono mensual: "<<_abonoMensual<<endl;
        cout<<"Fecha limite para pagar abono: ";
        _fechaLimiteParaPagarAbono.mostrar();
       }
        cout << endl;

        cout <<"ACTIVIDADES EXTRA: " << endl;
         if (_boxeo.getActivo() == true  ) {
           cout <<"BOXEO"<<endl;
             cout << "fecha del alta: " ; _boxeo.getFechaAlta().mostrar();
             cout << "cuota mensual: " << _boxeo.getCuotaMensual() << endl;
             cout << "fecha limite para pagar: "; _boxeo.getFechaLimitePago().mostrar();
         cout <<"------------------------------------"<< endl;
         }
               if (_yoga.getActivo() == true ) {
             cout <<"YOGA" << endl;
             cout << "fecha del alta: " ; _yoga.getFechaAlta().mostrar();
             cout << "cuota mensual: " << _yoga.getCuotaMensual() << endl;
             cout << "fecha limite para pagar: " ; _yoga.getFechaLimitePago().mostrar();



    }
}


}


void Cliente::establecerPlanMensual(int opc)
{

    if (opc == 1)
    {
        _abonoMensual = 1000;    // 12 xq viene 3 veces a la semana durante un mes
        _controlDeIngresosPesas = 12;
    }
    if (opc == 2)
    {
        _abonoMensual = 1200;
        _controlDeIngresosPesas = 16;
    }
    if (opc == 3)
    {
        _abonoMensual = 1400;
        _controlDeIngresosPesas = 31;
    }


    if (opc == 0)
    {
        _abonoMensual = 0;
        _controlDeIngresosPesas = 0;
    }
}

/*string Cliente::getNombreActividad(){
return _actividad;

}


void Cliente::setNombreDeActividad(string nombreAct){

_actividad = nombreAct;

}
*/
