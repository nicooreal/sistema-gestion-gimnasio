#include "Cliente.h"

int Cliente::getNumeroDeSocio(){

return _numeroDeSocio;
}

void Cliente::setNumeroDeSocio(int nSocio){

_numeroDeSocio = nSocio;

}

void Cliente::setFechaDelAlta(Fecha f){

_fechaDelAlta = f;

}

Fecha Cliente::getFechaDelAlta(){

return _fechaDelAlta;

}


float Cliente::getAbonoMensual(){

return _abonoMensual;
}



void Cliente::setAbonoMensual(float abonoM){

_abonoMensual = abonoM;
}

void Cliente::setGimnasio(bool gimnasio){

_gimnasio = gimnasio;


}

bool Cliente::getGimnasio(){
return _gimnasio;
}


void Cliente::AltaCliente(){

int opcion;

Persona::cargar(); // metodo de persona.h
cout <<"CUANTOS DIAS VA A LA SEMANA VA A ENTRENAR?" << endl;
cout <<"3 - $1000  , 5 - $1200 , PASE LIBRE $1400" << endl;
cin >> opcion;


}




/*string Cliente::getNombreActividad(){
return _actividad;

}


void Cliente::setNombreDeActividad(string nombreAct){

_actividad = nombreAct;

}
*/
