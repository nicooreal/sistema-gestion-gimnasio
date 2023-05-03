#include "Direccion.h"
#include "funciones.h"

Direccion::Direccion()
{
    ponerCeroDireccion();
}

Direccion::Direccion(char *calle,int numero,char *codigoPostal,char *localidad,int piso)
{
    strcpy(_calle,calle);
    _numero=numero;
    strcpy(_codigoPostal,codigoPostal);
    strcpy(_localidad,localidad);
    _piso=piso;

}

void Direccion::cargar()
{
    cout<<"Calle: "; cargarCadena(_calle,29);
    cout<<"Numero: "; cin>>_numero;
    cout<<"Codigo postal: "; cargarCadena(_codigoPostal,29);
    cout<<"Localidad: "; cargarCadena(_localidad,29);
    cout<<"Piso: "; cin>>_piso;
}

void Direccion::mostrar()
{
    cout<<"Calle: "<<_calle<<endl;
    cout<<"Numero: "<<_numero<<endl;
    cout<<"Codigo postal: "<<_codigoPostal<<endl;
    cout<<"Localidad: "<<_localidad<<endl;
    cout<<"Piso: "<<_piso<<endl;
}

void Direccion::ponerCeroDireccion()
{
    strcpy(_calle,"");
    _numero=0;
    strcpy(_codigoPostal,"");
    strcpy(_localidad,"");
    _piso=0;
}

void Direccion::setCalle(char *calle)
{
    strcpy(_calle,calle);
}

void Direccion::setNumero(int numero)
{
    _numero=numero;
}

void Direccion::setCodigoPostal(char *codigoPostal)
{
    strcpy(_codigoPostal,codigoPostal);
}

void Direccion::setLocalidad(char *localidad)
{
    strcpy(_localidad,localidad);
}

void Direccion::setPiso(int piso)
{
    _piso=piso;
}

const char *Direccion::getCalle()
{
    return _calle;
}

int Direccion::getNumero()
{
    return _numero;
}

const char *Direccion::getCodigoPostal()
{
    return _codigoPostal;
}

const char *Direccion::getLocalidad()
{
    return _localidad;
}

int Direccion::getPiso()
{
    return _piso;
}
