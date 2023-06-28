#pragma once
#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>

using namespace std;
#include "Boxeo.h"
#include "Yoga.h"
#include "Persona.h"
#include "string.h"


class Cliente : public Persona
{
private:

    int _numeroDeSocio;
    Fecha _fechaDelAlta;
    Fecha _fechaLimiteParaPagarAbono;
    float _abonoMensual;
    Boxeo _boxeo;
    Yoga _yoga;
    bool _pesas;
    int _controlDeIngresosPesas;

public:



    int getNumeroDeSocio();
    void setNumeroDeSocio(int nSocio);

    Fecha getFechaDelAlta();
    void setFechaDelAlta(Fecha f);

    Fecha getFechaLimiteParaPagarAbono();
    void setFechaLimite(Fecha f);

    float getAbonoMensual();
    void setAbonoMensual(float abonoM);

    void setNombreDeporte(int nombreDeporte);

    void cargarCliente();
    void mostrarCliente();

    void setPesas(bool pesas);
    bool getPesas();

    void setControlIngresos(int control);
    int getControlIngresos();



    Boxeo getBoxeo();
    void setBoxeo(Boxeo boxeo);

    Yoga getYoga();
    void setYoga(Yoga yoga);

    void hacePesas();
    void establecerPlanMensual(int opcion);
    void establecerOpcionExtra(int opcion);
    void calcularUnMesDeEntreno();
    void mostrarClienteDadoDeBaja();

};

#endif // CLIENTE_H
