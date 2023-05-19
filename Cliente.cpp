
#include "Cliente.h"

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

    if(nombreDeporte>=1&&nombreDeporte<=2)
    {
        _nombreDeporte=nombreDeporte;
    }
    else
    {
        _nombreDeporte=0;
    }

}

const char *Cliente::getNombreDeporte()
{
    if(_nombreDeporte==1)
    {
        return "Boxeo";
    }
    else if(_nombreDeporte==2)
    {
        return "Yoga";
    }
    else
    {
        return "Desconocido";
    }

}


void Cliente::cargarCliente()
{
    Persona::cargarPersona(); // metodo de persona.h
    cout<<"NUMERO DE SOCIO"<<endl;
    cin>>_numeroDeSocio;
    cout<<"Fecha de alta"<<endl;
    _fechaDelAlta.cargar();
    cout<<"Fecha limite para pagar bono"<<endl;
    _fechaLimiteParaPagarAbono.cargar();
    cout <<"CUANTOS DIAS VA A LA SEMANA VA A ENTRENAR?" << endl;
    cout <<"3 Dias - $1000  , 5 Dias - $1200 , PASE LIBRE $1400" << endl;
    cin >> _abonoMensual;
    cout<<"NOMBRE DEL DEPORTE (1 - BOXEO, 2 - YOGA)"<<endl;
    cin>>_nombreDeporte;
    setNombreDeporte(_nombreDeporte);

}

void Cliente::mostrarCliente()
{
    Persona::mostrarPersona();
    cout<<"Numero de socio "<<_numeroDeSocio<<endl;
    cout<<"Fecha de alta: "<<endl;
    _fechaDelAlta.mostrar();
    cout<<"Fecha limite para pagar bono"<<endl;
    _fechaLimiteParaPagarAbono.mostrar();
    cout<<"Abono mensual: "<<_abonoMensual<<endl;
    cout<<"Nombre del deporte: "<<getNombreDeporte();
}




/*string Cliente::getNombreActividad(){
return _actividad;

}


void Cliente::setNombreDeActividad(string nombreAct){

_actividad = nombreAct;

}
*/
