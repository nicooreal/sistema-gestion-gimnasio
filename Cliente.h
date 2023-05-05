#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"

class Cliente : public Persona
{
private:
int _numeroDeSocio;
Fecha _fechaDelAlta;
Fecha _fechaLimiteParaPagarAbono;
float _abonoMensual;
bool _gimnasio;
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

void setGimnasio(bool gimnasio);
bool getGimnasio();

void AltaCliente();

//string getNombreActividad();
//void setNombreDeActividad(string nombreAct);
};

#endif // CLIENTE_H
