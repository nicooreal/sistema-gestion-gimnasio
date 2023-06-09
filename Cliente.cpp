
#include "Cliente.h"
#include "ClienteArchivo.h"

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

        cout <<"Realiza el servicio de pesas" << endl;
    }
    else
    {
        cout<< "No realiza el servicio de pesas"<< endl;
    }

}

void Cliente::setControl(int control){

_controlDeIngresosPesas = control;

}

int Cliente::getControl(){

return _controlDeIngresosPesas;

}



const char *Cliente::getNombreDeporte() // esto creo q esta mal, tendria q setearse al momento de cargarse, no cuando use el get.
{
    if(_nombreDeporte==1)
    {
        _abonoMensual += 1500;
        return "boxeo";
    }
    else if(_nombreDeporte==2)
    {
        _abonoMensual+= 1500;
        return "yoga";
    }
    else if(_nombreDeporte==3)
    {
        _abonoMensual+= 2000;
        return "boxeo y yoga";
    }
    else
    {
        return "SIN ACTIVIDAD EXTRA";
    }

}


void Cliente::setEstado(bool estado){
_estado = estado;

}

bool Cliente::getEstado(){
return _estado;
}


void Cliente::calcularUnMesDeEntreno(){

    Fecha fecha;
    int dia, mes,anio;


if (fecha.getMes() == 12) {
    mes = 1;
    anio = fecha.getAnio() + 1;
    dia = fecha.getDia();
}

// falta ver lo del mes de Febrero y si es biciesto


if (fecha.getDia() == 31) {dia = 30;} else {dia = fecha.getDia();}
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
    int opcionMensual;
    Persona::cargarPersona(); // metodo de persona.h
    _numeroDeSocio = cantidadDeSocios + 1;
    _fechaDelAlta.fechaDeHoy();
    calcularUnMesDeEntreno();
    //cout<<"Fecha limite para pagar bono"<<endl;
    //_fechaLimiteParaPagarAbono.cargar(); // estaria bueno poder armar esta funcion para que se calcule y no haya que hacerlo manual
    cout <<"INGRESE LA OPCION(numero) PARA EL MONTO MENSUAL A PAGAR: " << endl;
    cout <<"OPCION 1 - 3 Dias - $1000" << endl;
    cout <<"OPCION 2 - 4 Dias - $1200" << endl;
    cout <<"OPCION 3 - 5 DPASE LIBRE $1400" << endl;
    cin >>opcionMensual;
    establecerPlanMensual(opcionMensual);
    cout <<"SERVICIO DE PESAS:(ingrese 1-SI o 0-NO ):" << endl;
    cin >> _pesas;
    cout<<"NOMBRE DE LA ACTIVIDAD EXTRA (1 - BOXEO $1000, 2 - YOGA $1000, 3 - BOXEO Y YOGA $2500 4 - NINGUNA )"<<endl;
    cin>>_nombreDeporte;
    setNombreDeporte(_nombreDeporte);
_estado = true;
}

void Cliente::mostrarCliente()
{
  if (_estado == true) {
    Persona::mostrarPersona();
    cout<<"Numero de socio "<<_numeroDeSocio<<endl;
    cout<<"Fecha de alta: "<<endl;
    _fechaDelAlta.mostrar();
    cout <<"Servicio de pesas: " << endl;  hacePesas();
    cout<<"Actividad extra: "<<getNombreDeporte() << endl;
    cout<<"Abono mensual: "<<_abonoMensual<<endl;
    cout<<"Fecha limite para pagar abono"<<endl;
    _fechaLimiteParaPagarAbono.mostrar();
  }
}



void Cliente::establecerPlanMensual(int opc){

if (opc == 1) {_abonoMensual = 1000; _controlDeIngresosPesas = 12; } // 12 xq viene 3 veces a la semana durante un mes
if (opc == 2) {_abonoMensual = 1200; _controlDeIngresosPesas = 16; }
if (opc == 3) {_abonoMensual = 1400; _controlDeIngresosPesas = 31; }


}

/*string Cliente::getNombreActividad(){
return _actividad;

}


void Cliente::setNombreDeActividad(string nombreAct){

_actividad = nombreAct;

}
*/
