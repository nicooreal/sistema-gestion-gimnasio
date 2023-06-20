# include<iostream>
# include<cstdlib>
using namespace std;
#include "Pago.h"
#include "Cliente.h"
Pago::Pago()
{
 //vAniosMeses[50][12]{};
}
 int Pago::getvAniosMeses() {
 return _vAniosMeses[50][12]; // revisar
 }

/*
 int Pago::setRecaudacionAnual(int vAnMe[][12]){
    _vAniosMeses[][12]= vAnMe[][12];

 }

*/
 void Pago::Mostrar(){
     int  vAniosMeses[50][12] ;
     int i;
     for(i=0; i<50; i++)
        {
            for (int j=0; j<12; j++)
            {
                cout << vAniosMeses[i][j] <<endl;
            }
        }
 }
