#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>

using namespace std;
#include "Boxeo.h"
#include "Yoga.h"
#include "Persona.h"
#include "string.h"







//clase boxeo, yoga y pago(vector dinamico, para calcular los anios minimos y maximos de los pagos)



class Cliente : public Persona
{
private:
    int _numeroDeSocio;
    Fecha _fechaDelAlta;
    Fecha _fechaLimiteParaPagarAbono;
    float _abonoMensual;
    Boxeo _boxeo;
    Yoga _yoga;
    int _nombreDeporte; // no se usa mas, ponemos clase boxeo y yoga
    bool _pesas;
    int _controlDeIngresosPesas;
    bool _estado;
//bool boxeo;
//bool yoga;

//string _actividad;

public:
    int getNumeroDeSocio();
    void setNumeroDeSocio(int nSocio);

    Fecha getFechaDelAlta();
    void setFechaDelAlta(Fecha f);

    float getAbonoMensual();
    void setAbonoMensual(float abonoM);

    void setNombreDeporte(int nombreDeporte);
    const char *getNombreDeporte();

    void cargarCliente();
    void mostrarCliente();

    void setPesas(bool pesas);
    bool getPesas();

    void setControl(int control);
    int getControl();

    void setEstado(bool estado);
    bool getEstado();

    Boxeo getBoxeo();
    void setBoxeo(Boxeo boxeo);

    void hacePesas();
    void establecerPlanMensual(int opcion);
    void calcularUnMesDeEntreno();
//string getNombreActividad();
//void setNombreDeActividad(string nombreAct);
};

#endif // CLIENTE_H
