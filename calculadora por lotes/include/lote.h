#ifndef LOTE_H
#define LOTE_H
#include <iostream>

using namespace std;

class lote
{
    public:
        lote();
        virtual ~lote();

        void setnombre(string);
        void setsigno(string);
        void setres(string);
        void setllegadast(bool);
        void setrespuestast(bool);
        void settme(int);
        void setn1(int);
        void setn2(int);
        void setid(int);
        void settiempot(int);
        void settiempoe(int);
        void settiempor(int);
        void settiempob(int);
        void settres(int);
        void setllegada(int);
        void setpagina(int);

        string getnombre();
        string getsigno();
        string getres();
        bool getllegadast();
        bool getrespuestast();
        int gettme();
        int getn1();
        int getn2();
        int getid();
        int gettiempot();
        int gettiempoe();
        int gettiempor();
        int gettiempob();
        int getresp();
        int getllegada();
        int getpagina();
        lote *siguiente;

    protected:

    private:
        string nombre;
        string signo;
        string resultado;
        bool llegada;
        bool respuesta;
        int tme;
        int n1;
        int n2;
        int id;
        int tt;
        int te;
        int tr;
        int tb;
        int tl;
        int tres;
        int tll;
        int paginas;
};

#endif // LOTE_H
