#ifndef LISTA_H
#define LISTA_H
#include <iostream>

using namespace std;

class lista
{
    public:
        lista();
        virtual ~lista();
        void setnmarco(int marco);
        void setpagina(int pagina);
        void setsiguiente(lista* siguiente);
        void setproceso(string pros);
        void setestado(string estado);

        int getnmarco();
        int getpagina();
        lista* getsiguiente();
        string getproceso();
        string getestado();

    protected:

    private:
        int nmarco;
        int paginas;
        string nproceso;
        string estado;
        lista* siguiente;
};

#endif // LISTA_H
