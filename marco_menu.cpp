#include <iostream>
#include <cstdio>
#include "marco_menu.h"
#include "rlutil.h"
using namespace std;

void marco_menu::mostrar_menu(){

        system("cls");
        rlutil::locate(10,4);
        cout<<char(201);
        rlutil::locate(11,4);
        for(int i=1;i<=43;i++){cout<<char(205);}
        rlutil::locate(10,5);
        cout<<char(186);
        rlutil::locate(53,4);
        cout<<char(187);
        rlutil::locate(53,5);
        cout<<char(186);
        rlutil::locate(12,5);
        cout<<"MENU PRINCIPAL";
        rlutil::locate(10,6);
        cout<<char(186);
        rlutil::locate(53,6);
        cout<<char(186);
        rlutil::locate(10,6);
        cout<<char(201);
        rlutil::locate(11,6);
        for(int i=1;i<=43;i++){cout<<char(205);}
        rlutil::locate(53,6);
        cout<<char(188);
        rlutil::locate(10,6);
        cout<<char(200);
        ///----------------------------
        rlutil::locate(10,7);
        cout<<char(218);
        rlutil::locate(11,7);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(10,8);
        cout<<char(179);
        rlutil::locate(53,7);
        cout<<char(191);
        rlutil::locate(53,8);
        cout<<char(179);
        rlutil::locate(12,8);
        cout<<"1 - EMPLEADOS";
        rlutil::locate(10,9);
        cout<<char(179);
        rlutil::locate(53,9);
        cout<<char(179);
        rlutil::locate(10,9);
        cout<<char(195);
        rlutil::locate(11,9);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(53,9);
        cout<<char(180);
         ///----------------------------
        rlutil::locate(10,10);
        cout<<char(179);
        rlutil::locate(53,10);
        cout<<char(179);
        rlutil::locate(12,10);
        cout<<"2 - CLIENTES";
        rlutil::locate(10,10);
        cout<<char(179);
        rlutil::locate(53,10);
        cout<<char(179);
        rlutil::locate(10,11);
        cout<<char(195);
        rlutil::locate(11,11);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(53,11);
        cout<<char(180);
        ///----------------------------
        rlutil::locate(10,12);
        cout<<char(179);
        rlutil::locate(53,12);
        cout<<char(179);
        rlutil::locate(12,12);
        cout<<"3 - PROVEEDORES";
        rlutil::locate(10,12);
        cout<<char(179);
        rlutil::locate(53,12);
        cout<<char(179);
        rlutil::locate(10,13);
        cout<<char(195);
        rlutil::locate(11,13);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(53,13);
        cout<<char(180);
        ///----------------------------
        rlutil::locate(10,14);
        cout<<char(179);
        rlutil::locate(53,14);
        cout<<char(179);
        rlutil::locate(12,14);
        cout<<"4 - GIMNASIO";
        rlutil::locate(10,14);
        cout<<char(179);
        rlutil::locate(53,14);
        cout<<char(179);
        rlutil::locate(10,15);
        cout<<char(195);
        rlutil::locate(11,15);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(53,15);
        cout<<char(180);
        ///----------------------------
        rlutil::locate(10,16);
        cout<<char(179);
        rlutil::locate(53,16);
        cout<<char(179);
        rlutil::locate(12,16);
        cout<<"0 - SALIR";
        rlutil::locate(10,16);
        cout<<char(179);
        rlutil::locate(53,16);
        cout<<char(179);
        rlutil::locate(10,17);
        cout<<char(192);
        rlutil::locate(11,17);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(53,17);
        cout<<char(217);
        ///----------------------------

       /* system("cls");
        cout<<"--------------------------"<<endl;
        cout<<"\tMENU PRINCIPAL"<<endl;
        cout<<"1 - EMPLEADOS"<<endl;
        cout<<"2 - CLIENTES"<<endl;
        cout<<"3 - PROVEEDORES"<<endl;
        cout<<"4 - GIMNASIO"<<endl; /// PODIAMOS INCLUIR CLASES COMO BACKUP Y RESTAURAR BACKUP PARA CADA UNA(Recomiendo ver la ultima clase de labo)
        cout<<"0 - SALIR"<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"OPCION: "<<endl;*/
}
void marco_menu::mostrar_cliente()
{
        system("cls");
        rlutil::locate(10,4);
        cout<<char(201);
        rlutil::locate(11,4);
        for(int i=1;i<=43;i++){cout<<char(205);}
        rlutil::locate(10,5);
        cout<<char(186);
        rlutil::locate(53,4);
        cout<<char(187);
        rlutil::locate(53,5);
        cout<<char(186);
        rlutil::locate(12,5);
        cout<<"MENU CLIENTES";
        rlutil::locate(10,6);
        cout<<char(186);
        rlutil::locate(53,6);
        cout<<char(186);
        rlutil::locate(10,6);
        cout<<char(201);
        rlutil::locate(11,6);
        for(int i=1;i<=43;i++){cout<<char(205);}
        rlutil::locate(53,6);
        cout<<char(188);
        rlutil::locate(10,6);
        cout<<char(200);
        ///----------------------------
        rlutil::locate(10,7);
        cout<<char(218);
        rlutil::locate(11,7);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(10,8);
        cout<<char(179);
        rlutil::locate(53,7);
        cout<<char(191);
        rlutil::locate(53,8);
        cout<<char(179);
        rlutil::locate(12,8);
        cout<<"1 - CARGAR";
        rlutil::locate(10,9);
        cout<<char(179);
        rlutil::locate(53,9);
        cout<<char(179);
        rlutil::locate(10,9);
        cout<<char(195);
        rlutil::locate(11,9);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(53,9);
        cout<<char(180);
         ///----------------------------
        rlutil::locate(10,10);
        cout<<char(179);
        rlutil::locate(53,10);
        cout<<char(179);
        rlutil::locate(12,10);
        cout<<"2 - EDITAR";
        rlutil::locate(10,10);
        cout<<char(179);
        rlutil::locate(53,10);
        cout<<char(179);
        rlutil::locate(10,11);
        cout<<char(195);
        rlutil::locate(11,11);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(53,11);
        cout<<char(180);
        ///----------------------------
        rlutil::locate(10,12);
        cout<<char(179);
        rlutil::locate(53,12);
        cout<<char(179);
        rlutil::locate(12,12);
        cout<<"3 - LISTAR TODOS";
        rlutil::locate(10,12);
        cout<<char(179);
        rlutil::locate(53,12);
        cout<<char(179);
        rlutil::locate(10,13);
        cout<<char(195);
        rlutil::locate(11,13);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(53,13);
        cout<<char(180);
        ///----------------------------
        rlutil::locate(10,14);
        cout<<char(179);
        rlutil::locate(53,14);
        cout<<char(179);
        rlutil::locate(12,14);
        cout<<"4 - LISTAR POR ID";
        rlutil::locate(10,14);
        cout<<char(179);
        rlutil::locate(53,14);
        cout<<char(179);
        rlutil::locate(10,15);
        cout<<char(195);
        rlutil::locate(11,15);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(53,15);
        cout<<char(180);
        ///----------------------------
        rlutil::locate(10,16);
        cout<<char(179);
        rlutil::locate(53,16);
        cout<<char(179);
        rlutil::locate(12,16);
        cout<<"5 - LISTAR CLIENTES QUE PRACTICAN BOXEO";
        rlutil::locate(10,16);
        cout<<char(179);
        rlutil::locate(53,16);
        cout<<char(179);
        rlutil::locate(10,17);
        cout<<char(195);
        rlutil::locate(11,17);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(53,17);
        cout<<char(180);
        ///----------------------------
        rlutil::locate(10,18);
        cout<<char(179);
        rlutil::locate(53,18);
        cout<<char(179);
        rlutil::locate(12,18);
        cout<<"0 - SALIR";
        rlutil::locate(10,18);
        cout<<char(179);
        rlutil::locate(53,18);
        cout<<char(179);
        rlutil::locate(10,19);
        cout<<char(192);
        rlutil::locate(11,19);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(53,19);
        cout<<char(217);

}
void marco_menu::mostrar_empleado(){

        system("cls");
        //----------------------------------------------
         system("cls");
        rlutil::locate(10,4);
        cout<<char(201);
        rlutil::locate(11,4);
        for(int i=1;i<=48;i++){cout<<char(205);}
        rlutil::locate(10,5);
        cout<<char(186);
        rlutil::locate(58,4);
        cout<<char(187);
        rlutil::locate(58,5);
        cout<<char(186);
        rlutil::locate(12,5);
        cout<<"MENU EMPLEADOS";
        rlutil::locate(10,6);
        cout<<char(186);
        rlutil::locate(58,6);
        cout<<char(186);
        rlutil::locate(10,6);
        cout<<char(201);
        rlutil::locate(11,6);
        for(int i=1;i<=48;i++){cout<<char(205);}
        rlutil::locate(58,6);
        cout<<char(188);
        rlutil::locate(10,6);
        cout<<char(200);
        ///----------------------------
        rlutil::locate(10,7);
        cout<<char(218);
        rlutil::locate(11,7);
        for(int i=1;i<=48;i++){cout<<char(196);}
        rlutil::locate(10,8);
        cout<<char(179);
        rlutil::locate(58,7);
        cout<<char(191);
        rlutil::locate(58,8);
        cout<<char(179);
        rlutil::locate(12,8);
        cout<<"1 - CARGAR";
        rlutil::locate(10,9);
        cout<<char(179);
        rlutil::locate(53,9);
        cout<<char(179);
        rlutil::locate(10,9);
        cout<<char(195);
        rlutil::locate(11,9);
        for(int i=1;i<=48;i++){cout<<char(196);}
        rlutil::locate(58,9);
        cout<<char(180);
         ///----------------------------
        rlutil::locate(10,10);
        cout<<char(179);
        rlutil::locate(58,10);
        cout<<char(179);
        rlutil::locate(12,10);
        cout<<"2 - EDITAR";
        rlutil::locate(10,10);
        cout<<char(179);
        rlutil::locate(58,10);
        cout<<char(179);
        rlutil::locate(10,11);
        cout<<char(195);
        rlutil::locate(11,11);
        for(int i=1;i<=48;i++){cout<<char(196);}
        rlutil::locate(58,11);
        cout<<char(180);
        ///----------------------------
        rlutil::locate(10,12);
        cout<<char(179);
        rlutil::locate(58,12);
        cout<<char(179);
        rlutil::locate(12,12);
        cout<<"3 - LISTAR TODOS";
        rlutil::locate(10,12);
        cout<<char(179);
        rlutil::locate(58,12);
        cout<<char(179);
        rlutil::locate(10,13);
        cout<<char(195);
        rlutil::locate(11,13);
        for(int i=1;i<=48;i++){cout<<char(196);}
        rlutil::locate(58,13);
        cout<<char(180);
        ///----------------------------
        rlutil::locate(10,14);
        cout<<char(179);
        rlutil::locate(58,14);
        cout<<char(179);
        rlutil::locate(12,14);
        cout<<"4 - LISTAR POR ID";
        rlutil::locate(10,14);
        cout<<char(179);
        rlutil::locate(58,14);
        cout<<char(179);
        rlutil::locate(10,15);
        cout<<char(195);
        rlutil::locate(11,15);
        for(int i=1;i<=48;i++){cout<<char(196);}
        rlutil::locate(58,15);
        cout<<char(180);
        ///----------------------------
        rlutil::locate(10,16);
        cout<<char(179);
        rlutil::locate(58,16);
        cout<<char(179);
        rlutil::locate(12,16);
        cout<<"5 - LIMPIAR ARCHIVO";
        rlutil::locate(10,16);
        cout<<char(179);
        rlutil::locate(58,16);
        cout<<char(179);
        rlutil::locate(10,17);
        cout<<char(195);
        rlutil::locate(11,17);
        for(int i=1;i<=48;i++){cout<<char(196);}
        rlutil::locate(58,17);
        cout<<char(180);
        ///----------------------------
        rlutil::locate(10,18);
        cout<<char(179);
        rlutil::locate(58,18);
        cout<<char(179);
        rlutil::locate(12,18);
        cout<<"6 - LISTAR EMPLEADOS QUE INGRESARON EN X ANIO";
        rlutil::locate(10,18);
        cout<<char(179);
        rlutil::locate(58,18);
        cout<<char(179);
        rlutil::locate(10,19);
        cout<<char(195);
        rlutil::locate(11,19);
        for(int i=1;i<=48;i++){cout<<char(196);}
        rlutil::locate(58,19);
        cout<<char(180);
        ///----------------------------
        rlutil::locate(10,20);
        cout<<char(179);
        rlutil::locate(58,20);
        cout<<char(179);
        rlutil::locate(12,20);
        cout<<"0 - SALIR";
        rlutil::locate(10,20);
        cout<<char(179);
        rlutil::locate(58,20);
        cout<<char(179);
        rlutil::locate(10,21);
        cout<<char(192);
        rlutil::locate(11,21);
        for(int i=1;i<=48;i++){cout<<char(196);}
        rlutil::locate(58,21);
        cout<<char(217);

}

void marco_menu::mostrar_gimnasio(){

        system("cls");
        rlutil::locate(10,4);
        cout<<char(201);
        rlutil::locate(11,4);
        for(int i=1;i<=43;i++){cout<<char(205);}
        rlutil::locate(10,5);
        cout<<char(186);
        rlutil::locate(53,4);
        cout<<char(187);
        rlutil::locate(53,5);
        cout<<char(186);
        rlutil::locate(12,5);
        cout<<"MENU GIMNASIO";
        rlutil::locate(10,6);
        cout<<char(186);
        rlutil::locate(53,6);
        cout<<char(186);
        rlutil::locate(10,6);
        cout<<char(201);
        rlutil::locate(11,6);
        for(int i=1;i<=43;i++){cout<<char(205);}
        rlutil::locate(53,6);
        cout<<char(188);
        rlutil::locate(10,6);
        cout<<char(200);
        ///----------------------------
        rlutil::locate(10,7);
        cout<<char(218);
        rlutil::locate(11,7);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(10,8);
        cout<<char(179);
        rlutil::locate(53,7);
        cout<<char(191);
        rlutil::locate(53,8);
        cout<<char(179);
        rlutil::locate(12,8);
        cout<<"1 - CANTIDAD EMPLEADOS";
        rlutil::locate(10,9);
        cout<<char(179);
        rlutil::locate(53,9);
        cout<<char(179);
        rlutil::locate(10,9);
        cout<<char(195);
        rlutil::locate(11,9);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(53,9);
        cout<<char(180);
         ///----------------------------
        rlutil::locate(10,10);
        cout<<char(179);
        rlutil::locate(53,10);
        cout<<char(179);
        rlutil::locate(12,10);
        cout<<"2 - CANTIDAD CLIENTES";
        rlutil::locate(10,10);
        cout<<char(179);
        rlutil::locate(53,10);
        cout<<char(179);
        rlutil::locate(10,11);
        cout<<char(195);
        rlutil::locate(11,11);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(53,11);
        cout<<char(180);
        ///----------------------------
        rlutil::locate(10,12);
        cout<<char(179);
        rlutil::locate(53,12);
        cout<<char(179);
        rlutil::locate(12,12);
        cout<<"3 - GUARDAR CLIENTES QUE PRACTICAN BOXEO";
        rlutil::locate(10,12);
        cout<<char(179);
        rlutil::locate(53,12);
        cout<<char(179);
        rlutil::locate(10,13);
        cout<<char(195);
        rlutil::locate(11,13);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(53,13);
        cout<<char(180);
        ///----------------------------
        rlutil::locate(10,14);
        cout<<char(179);
        rlutil::locate(53,14);
        cout<<char(179);
        rlutil::locate(12,14);
        cout<<"0 - SALIR";
        rlutil::locate(10,14);
        cout<<char(179);
        rlutil::locate(53,14);
        cout<<char(179);
        rlutil::locate(10,15);
        cout<<char(192);
        rlutil::locate(11,15);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(53,15);
        cout<<char(217);
        ///----------------------------

}
void marco_menu::mostrar_proveedores(){
        system("cls");
        rlutil::locate(10,4);
        cout<<char(201);
        rlutil::locate(11,4);
        for(int i=1;i<=43;i++){cout<<char(205);}
        rlutil::locate(10,5);
        cout<<char(186);
        rlutil::locate(53,4);
        cout<<char(187);
        rlutil::locate(53,5);
        cout<<char(186);
        rlutil::locate(12,5);
        cout<<"MENU PROVEEDORES";
        rlutil::locate(10,6);
        cout<<char(186);
        rlutil::locate(53,6);
        cout<<char(186);
        rlutil::locate(10,6);
        cout<<char(201);
        rlutil::locate(11,6);
        for(int i=1;i<=43;i++){cout<<char(205);}
        rlutil::locate(53,6);
        cout<<char(188);
        rlutil::locate(10,6);
        cout<<char(200);
        ///----------------------------
        rlutil::locate(10,7);
        cout<<char(218);
        rlutil::locate(11,7);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(10,8);
        cout<<char(179);
        rlutil::locate(53,7);
        cout<<char(191);
        rlutil::locate(53,8);
        cout<<char(179);
        rlutil::locate(12,8);
        cout<<"1 - CARGAR";
        rlutil::locate(10,9);
        cout<<char(179);
        rlutil::locate(53,9);
        cout<<char(179);
        rlutil::locate(10,9);
        cout<<char(195);
        rlutil::locate(11,9);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(53,9);
        cout<<char(180);
         ///----------------------------
        rlutil::locate(10,10);
        cout<<char(179);
        rlutil::locate(53,10);
        cout<<char(179);
        rlutil::locate(12,10);
        cout<<"2 - EDITAR";
        rlutil::locate(10,10);
        cout<<char(179);
        rlutil::locate(53,10);
        cout<<char(179);
        rlutil::locate(10,11);
        cout<<char(195);
        rlutil::locate(11,11);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(53,11);
        cout<<char(180);
        ///----------------------------
        rlutil::locate(10,12);
        cout<<char(179);
        rlutil::locate(53,12);
        cout<<char(179);
        rlutil::locate(12,12);
        cout<<"3 - LISTAR TODOS";
        rlutil::locate(10,12);
        cout<<char(179);
        rlutil::locate(53,12);
        cout<<char(179);
        rlutil::locate(10,13);
        cout<<char(195);
        rlutil::locate(11,13);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(53,13);
        cout<<char(180);
        ///----------------------------
        rlutil::locate(10,14);
        cout<<char(179);
        rlutil::locate(53,14);
        cout<<char(179);
        rlutil::locate(12,14);
        cout<<"4 - LISTAR POR ID";
        rlutil::locate(10,14);
        cout<<char(179);
        rlutil::locate(53,14);
        cout<<char(179);
        rlutil::locate(10,15);
        cout<<char(195);
        rlutil::locate(11,15);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(53,15);
        cout<<char(180);
        ///----------------------------
        rlutil::locate(10,16);
        cout<<char(179);
        rlutil::locate(53,16);
        cout<<char(179);
        rlutil::locate(12,16);
        cout<<"0 - SALIR";
        rlutil::locate(10,16);
        cout<<char(179);
        rlutil::locate(53,16);
        cout<<char(179);
        rlutil::locate(10,17);
        cout<<char(192);
        rlutil::locate(11,17);
        for(int i=1;i<=43;i++){cout<<char(196);}
        rlutil::locate(53,17);
        cout<<char(217);
        ///----------------------------

}
