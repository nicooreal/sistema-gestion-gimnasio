#ifndef DIRECCION_H_INCLUDED
#define DIRECCION_H_INCLUDED
#include <iostream>
#include <string.h>

using namespace std;

class Direccion
{
private:
    ///calle, número, código postal, localidad, piso
    char _calle[30];
    int _numero;
    char _codigoPostal[30];
    char _localidad[30];
    int _piso;

public:
    Direccion();
    Direccion(char *calle,int numero,char *codigoPostal,char *localidad,int piso);

    void cargar();
    void mostrar();
    void ponerCeroDireccion();

    void setCalle(char *calle);
    void setNumero(int numero);
    void setCodigoPostal(char *codigoPostal);
    void setLocalidad(char *localidad);
    void setPiso(int piso);

    const char *getCalle();
    int getNumero();
    const char *getCodigoPostal();
    const char *getLocalidad();
    int getPiso();


};


#endif // DIRECCION_H_INCLUDED
