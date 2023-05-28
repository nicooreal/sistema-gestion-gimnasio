#include "ClienteTareas.h"
#include "Cliente.h"
#include "ClienteArchivo.h"

void ClienteTareas::cargar(){

    Cliente cliente;
    cliente.cargarCliente();

    _archivoCliente.guardar(cliente);


}
void ClienteTareas::modificar()
{


    int numeroRegistro = _archivoCliente.buscarRegistro();
    if (numeroRegistro>=0)
    {
        cout << "Modifique al cliente"<<endl;
        Cliente clienteModificado ;
        clienteModificado.cargarCliente();

        bool exito = _archivoCliente.editar(clienteModificado, numeroRegistro);
        if (exito)
        {
            cout << "Registro modificado exitosamente." << endl;
        }
        else
        {
            cout << "No se pudo modificar el registro." << endl;
        }
    }
}
/*void listarClientesBox(){

     cout <<"Los clientes que realizan :"<< endl;

}
  */






