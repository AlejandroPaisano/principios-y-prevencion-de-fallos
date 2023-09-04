#include "lista.h"

lista::lista()
{
    //ctor
}

void lista::setnmarco(int marco)
{
    this->nmarco=marco;
}

void lista::setpagina(int pagina)
{
    this->paginas=pagina;
}

void lista::setsiguiente(lista* siguiente)
{
    this->siguiente=siguiente;
}

void lista::setproceso(string pros)
{
    this->nproceso=pros;
}

void lista::setestado(string estado){
    this->estado=estado;
}

int lista::getnmarco()
{
    return this->nmarco;
}

int lista::getpagina()
{
    return this->paginas;
}

lista* lista::getsiguiente()
{
    return this->siguiente;
}

string lista::getproceso()
{
    return this->nproceso;
}

string lista::getestado(){
    return this->estado;
}

lista::~lista()
{
    //dtor
}
