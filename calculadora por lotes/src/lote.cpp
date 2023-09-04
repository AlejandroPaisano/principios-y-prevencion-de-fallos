#include "lote.h"

lote::lote()
{
    //ctor
}

void lote::setnombre(string nombre){

    this->nombre=nombre;
}

void lote::setsigno(string signo){

    this->signo=signo;
}

void lote::setres(string res){
    this->resultado=res;
}

void lote::setllegadast(bool llegada){
    this->llegada=llegada;
}

void lote::setrespuestast(bool respuesta){
    this->respuesta=respuesta;
}

void lote::settme(int tme){

    this->tme=tme;
}

void lote::setn1(int n1){

    this->n1=n1;
}

void lote::setn2(int n2){

    this->n2=n2;
}

void lote::setid(int id){

    this->id=id;
}

void lote::settiempot(int tt){

    this->tt=tt;

}

void lote::settiempoe(int te){

    this->te=te;

}

void lote::settiempor(int tr){

    this->tr=tr;

}

void lote::settres(int tres){
    this->tres=tres;
}

void lote::settiempob(int tb){

    this->tb=tb;

}

void lote::setllegada(int tll){
    this->tll=tll;
}

void lote::setpagina(int pag){
    this->paginas=pag;
}

string lote::getnombre(){

    return this->nombre;
}

string lote::getsigno(){

    return this->signo;
}

string lote::getres(){

    return this->resultado;
}

bool lote::getllegadast(){
    return this->llegada;
}

bool lote::getrespuestast(){
    return this->respuesta;
}

int lote::gettme(){

    return this->tme;
}

int lote::getn1(){

    return this->n1;
}

int lote::getn2(){

    return this->n2;
}

int lote::getid(){

    return this->id;
}

int lote::gettiempot(){

    return this->tt;
}

int lote::gettiempoe(){

    return this->te;
}

int lote::gettiempor(){

    return this->tr;
}

int lote::gettiempob(){

    return this->tb;
}

int lote::getresp(){
    return this->tres;
}

int lote::getllegada(){
    return this->tll;

}

int lote::getpagina(){
    return this->paginas;
}
lote::~lote()
{
    //dtor
}
