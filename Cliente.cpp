
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







const char *Cliente::getNombreDeporte()
{
    if(_nombreDeporte==1)
    {
        _abonoMensual += 1500;
        return "Boxeo";
    }
    else if(_nombreDeporte==2)
    {
        _abonoMensual+= 1500;
        return "Yoga";
    }
    else if(_nombreDeporte==3)
    {
        _abonoMensual+= 2000;
        return "Boxeo y yoga";
    }
    else
    {
        return "SIN ACTIVIDAD EXTRA";
    }

}


void Cliente::cargarCliente()
{
    ClienteArchivo clienteArch;
    int cantidadDeSocios = clienteArch.getCantidad();

    Persona::cargarPersona(); // metodo de persona.h
    _numeroDeSocio = cantidadDeSocios + 1;
    _fechaDelAlta.fechaDeHoy();
    cout<<"Fecha limite para pagar bono"<<endl;
    _fechaLimiteParaPagarAbono.cargar(); // estaria bueno poder armar esta funcion para que se calcule y no haya que hacerlo manual
    cout <<"INGRESE EL MONTO MENSUAL A PAGAR: " << endl;
    cout <<"3 Dias - $1000  , 5 Dias - $1200 , PASE LIBRE $1400" << endl;
    cin >> _abonoMensual;
    cout <<"SERVICIO DE PESAS:(ingrese 1-SI o 2-NO ):" << endl;
    cin >> _pesas;
    cout<<"NOMBRE DE LA ACTIVIDAD EXTRA (1 - BOXEO $1000, 2 - YOGA $1000, 3 - BOXEO Y YOGA $2500 4 - NINGUNA )"<<endl;
    cin>>_nombreDeporte;
    setNombreDeporte(_nombreDeporte);

}

void Cliente::mostrarCliente()
{
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




/*string Cliente::getNombreActividad(){
return _actividad;

}


void Cliente::setNombreDeActividad(string nombreAct){

_actividad = nombreAct;

}
*/
