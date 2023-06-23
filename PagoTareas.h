#ifndef PAGOTAREAS_H
#define PAGOTAREAS_H


class PagoTareas
{
    private:

    public:
        PagoTareas();
        void regPago();
        void recaudacionAnual();
        void mostrarTodos();
        void cargarPago(bool primerPago,int dni);
        int calcularcantidadAniosDeRegistro();
        void eliminarPago();

};

#endif // PAGOTAREAS_H
