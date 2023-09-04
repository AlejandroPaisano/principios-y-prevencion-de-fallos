#include <iostream>
#include <windows.h>
#include <string>
#include <lote.h>
#include <lista.h>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <fstream>
#include  <istream>
using namespace std;
COORD pos={0,0};
lista *lp, *lu;
bool lleno=false;
int main()
{
    int numero1=0, numero2=0, cantidad=0, x=0, comprobador=0, auxi=0, tme=0, id=0,auxin=0, pendiente=0, tt=0, tp=0, punto1=0,punto2=0;
    int nprocesos=0,cuenta=0, esp=0, tem=0, res=0,pot=0, raux=0, pag=0, sig=0, tiempo=0, col=0, marcos=0, dispo=0, pagmod=0, listasys=0;
    int TiempoT=0, TiempoB=0, TiempoE=0, TiempoR=0, TiempoLL=0,TiempoF=0, ter=0, quantum=0, quac=0, nuevos=0, suspendidos=0;
    bool llegadast=false, respuestast=false;
    bool flag=false, rep=false, primero=false,nulo=false, lleno=false, primerosus=false, segundosus=false, inicio=false;
    bool stop=false, impen=false, error=false, salto=false, nuevo=false, vacio=true;
    lote l, cabezera;
    string aux="", operacion="", signo="",nombre="",ress="", prel="", linea="", avan="", sub="", carga="";
    char tecla, tec;
    cabezera.setid(-1);
    ifstream lectura;
    ifstream templec;
    ifstream lecmem;

    fstream escritura;
    fstream tempesc;
    fstream tempmem;


    lectura.open("secundario.txt",ios::in);
    templec.open("temporal.txt",ios::in);
    lecmem.open("memo.txt",ios::in);

    escritura.open("secundario.txt",ios::out);
    tempesc.open("temporal.txt",ios::out);
    tempmem.open("memo.txt",ios::app);

    lote *frentenuevo=NULL;
    lote *finnuevo=NULL;
    lote *frentelistos=NULL;
    lote *finlistos=NULL;
    lote *frenteejecucion=NULL;
    lote *finejecucion=NULL;

    lote *frentebloq=NULL;
    lote *finbloq=NULL;
    lote *frentetem=NULL;
    lote *fintem=NULL;
    lote *frenteim=NULL;
    lote *finim=NULL;

    void gotoxy(int, int);
    bool lotevacio(lote *);
    void insertarLote(lote *&,lote *&, string,string, bool, bool, int, int, int, int, int, int, int, int, int, int, int);
    void vaciarLote(lote *&,lote *&,string &,string&, bool &, bool &, int &, int &, int &,  int &, int &, int &, int &, int&, int&, int&, int&);
    void buscarLote(lote *&,lote *&,string &, int &, int &, int &, int &, int, bool);
    void insertarenl(int marc);
    void mostrarl();

    srand(time(NULL));
    auxi=0;
    while(auxi<44){
        insertarenl(auxi);
        auxi++;
    }

    auxi=0;
    while(flag==false){
        while(!lecmem.eof()){
            pot++;
            carga="";
            punto1=0;
            punto2=-1;
            getline(lecmem,carga);
            if(carga!=""){
            while(punto1>-1){

            vacio=false;
            punto1=carga.find(".");
            sub=carga.substr(punto1+1);
            avan=carga.substr(0,punto1);
            carga=sub;
            switch (punto2){
                case 0:
                    signo=avan;
                break;
                case 1:
                    ress=avan;
                break;
                case 2:
                    llegadast=stoi(avan);
                break;
                case 3:
                    respuestast=stoi(avan);
                break;
                case 4:
                    pag=stoi(avan);
                break;
                case 5:
                    numero1=stoi(avan);
                break;
                case 6:
                    numero2=stoi(avan);
                break;
                case 7:
                    tme=stoi(avan);
                break;
                case 8:
                    id=stoi(avan);
                break;
                case 9:
                    TiempoB=stoi(avan);
                break;
                case 10:
                    TiempoE=stoi(avan);
                break;
                case 11:
                    TiempoR=stoi(avan);
                break;
                case 12:
                    TiempoLL=stoi(avan);
                break;
                case 13:
                    TiempoF=stoi(avan);
                break;
                default:{
                        if(avan=="listo"){
                            esp=1;
                        }
                        if(avan=="ejecucion"){
                            esp=2;
                        }
                        if(avan=="bloqueados"){
                            esp=3;
                        }
                        if(avan=="terminados"){
                            esp=4;
                        }
                    }
                    break;
                }


                punto2++;
            }
            if(esp==1){
                insertarLote(frentenuevo,finnuevo,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                cout<<"id: "<<id<<" operacion: "<<numero1<<signo<<numero2<<" Resultado: "<<ress<<endl;
                nprocesos++;
            }

            if(esp==2){
                insertarLote(frentenuevo,finnuevo,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                cout<<"id: "<<id<<" operacion: "<<numero1<<signo<<numero2<<" Resultado: "<<ress<<endl;
                nprocesos++;
            }

            if(esp==3){
                insertarLote(frentebloq,finbloq,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                cout<<"id: "<<id<<" operacion: "<<numero1<<signo<<numero2<<" Resultado: "<<ress<<endl;
                nprocesos++;
            }
            if(esp==4){
                insertarLote(frentetem,fintem,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                cout<<"id: "<<id<<" operacion: "<<numero1<<signo<<numero2<<" Resultado: "<<ress<<endl;
                nprocesos++;
            }


            }
        }
        if(pot<2){
        aux="";
        comprobador=0;
        cout<<"Introduce la cantidad de procesos que deseas realizar"<<endl;
        cin>>aux;
        while(aux.length()>x){
            if(isdigit(aux[x])==false){
                comprobador++;
            }
            x++;

        }
        if(comprobador<=0){
            cantidad=stoi(aux);
            if(cantidad>0){
                flag=true;
            }
            else{
                cout<<"Has introducido un numero invalido"<<endl;
            }
        }
        else{
            cout<<"Has introducido caracteres invalidos"<<endl;
        }
    }
    else{
        flag=true;
        cout<<"Introduce la cantidad de procesos que deseas realizar"<<endl;
        auxi=cantidad;
    }
    }

    while(auxi<cantidad){
        numero1=rand()%100+1;
        numero2=rand()%100+1;
        sig=rand()%6+1;
         switch(sig){
            case 1:{
                signo="+";

            }break;
            case 2:{
                signo="-";

            }break;
            case 3:{
                signo="*";

            }break;
            case 4:{
                signo="/";

            }break;
            case 5:{
                signo="%";

            }break;
            case 6:{
                signo="^";
                numero1=rand()%6+1;
                numero2=rand()%6+1;

            }break;
            }
        tme=rand()%10+6;
        pag=rand()%27+6;

        insertarLote(frentenuevo,finnuevo,signo,"0",false,false,pag,numero1,numero2,tme,auxi+1,0,0,0,0,0,0);
        auxi++;
        col++;
    }

    system("cls");
    flag=false;
    while(flag==false){
        aux="";
        fflush(stdin);
        comprobador=0;
        cout<<"Introduce el quantum"<<endl;
        cin>>aux;
        while(aux.length()>x){
            if(isdigit(aux[x])==false){
                comprobador++;
            }
            x++;

        }
        if(comprobador<=0){
            quantum=stoi(aux);
            if(cantidad>=0){
                flag=true;
            }
            else{
                cout<<"Has introducido un numero invalido"<<endl;
            }
        }
        else{
            cout<<"Has introducido caracteres invalidos"<<endl;
        }
    }
    system("cls");
    flag=false;

    col=nprocesos;
    tempmem.close();
    tempmem.open("memo.txt",ios::out);
    cout<<nprocesos<<endl;
    cout<<"Numero de procesos nuevos: "<<cantidad<<endl;
    cout<<"tiempo transcurrido: "<<tt<<endl;
    cout<<"Procesos listos\t\t";
    cout<<"Proceso en ejecucion\t\t";
    cout<<"Terminados"<<endl;
    gotoxy(24,13);
    cout<<"Procesos bloqueados"<<endl;
    gotoxy(30,0);
    cout<<"Procesos suspendidos: "<<suspendidos<<endl;
    lista *laux=new lista;
    laux=lp;

    while(frentelistos!=NULL||frentebloq!=NULL||frenteejecucion!=NULL||frentenuevo!=NULL||suspendidos>0){

            /*Introduccion de la pila de nuevos a la de listos, siempre y cuando haya procesos en nuevo*/
            if(suspendidos>0&&frentelistos==NULL&&frentebloq==NULL&&frenteejecucion==NULL&&frentenuevo==NULL){
                nulo=true;
            }
            while(lleno==false&&frentenuevo!=NULL){
                nprocesos++;
                auxin++;
                vaciarLote(frentenuevo,finnuevo,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                if(llegadast==false){
                    TiempoLL=tt;
                    llegadast=true;
                }
                if(pag%5!=0){
                    marcos=pag/5;
                    marcos++;
                }
                else{
                    marcos=pag/5;
                }
                do{
                    if(laux->getpagina()==0){
                        marcos--;
                    }
                    laux=laux->getsiguiente();
                }while(laux!=lp&&marcos>0);

                if(marcos>0){
                    lleno=true;
                    insertarLote(frentenuevo,finnuevo,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                }

                else{

                    marcos=pag;
                    pagmod=pag%5;
                    laux=lp;
                    while(marcos>0){

                        if(laux->getpagina()==0){
                            if(marcos>=5){

                                laux->setpagina(5);
                                laux->setproceso(to_string(id));
                                laux->setestado("Listo");

                                marcos-=5;
                            }
                            else{
                                laux->setpagina(pagmod);
                                laux->setproceso(to_string(id));
                                laux->setestado("Listo");
                                marcos=0;
                                pagmod=0;
                            }
                        }
                        laux=laux->getsiguiente();

                    }
                    insertarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                    cantidad--;
                    gotoxy(0,0);
                    cout<<"Numero de procesos nuevos: "<<cantidad<<endl;

                }
            }

/*
            while(frentenuevo!=NULL&&nprocesos<3){
                nprocesos++;
                auxin++;
                vaciarLote(frentenuevo,finnuevo,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                if(llegadast==false){
                    TiempoLL=tt;
                    llegadast=true;
                }
                insertarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
            }
*/

            if(lleno==true||frentenuevo==NULL){
                cuenta=0;
                while(frentetem!=NULL){

                                    vaciarLote(frentetem,fintem,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    auxi=1;
                                    x=0;
                                    while(x<ress.size()){
                                        if(isalpha(ress[x])==true){
                                            auxi=0;
                                        }
                                        x++;
                                    }
                                    gotoxy(56,5+cuenta);
                                    if(auxi==0){
                                        cout<<"id: "<<id<<" Error"<<endl;
                                    }
                                    else{
                                         cout<<"id: "<<id<<" operacion: "<<numero1<<signo<<numero2<<" Resultado: "<<ress<<endl;
                                    }
                                    cuenta++;
                                    insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }

                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frentetem,fintem,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }

                cuenta=0;
                gotoxy(0,0);
                cout<<"Numero de procesos nuevos: "<<cantidad<<endl;
                while(cuenta<4){
                    gotoxy(0,5+cuenta);
                    cout<<"                      "<<endl;
                    cuenta++;
                }
                cuenta=0;
                tp=0;
                int reloj=0;
                /*Introduccion de la pila de listos a la de ejecucion asi como la ejecucion del desarrollo*/
                if(nulo==false){
                    laux=lp;
                    vaciarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                    do{
                        x=0;
                        comprobador=0;
                        prel=laux->getproceso();
                        while(prel.length()>x){
                            if(isalpha(prel[x])){
                                comprobador++;
                            }
                            x++;
                        }
                        if(comprobador==0){
                            nuevos=stoi(prel);
                            if(nuevos==id){
                                laux->setestado("En ejecucion");
                            }
                        }
                        laux=laux->getsiguiente();
                    }while(laux!=lp);

                    if(respuestast==false){
                        TiempoR=tt-TiempoLL;
                        respuestast=true;
                    }
                    insertarLote(frenteejecucion,finejecucion,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                    cuenta=0;
                    tp=0;
                }

                if(nulo==true){
                    gotoxy(25,5);
                    cout<<"                               "<<endl;
                    gotoxy(25,6);
                    cout<<"                               "<<endl;
                    gotoxy(25,7);
                    cout<<"                               "<<endl;
                    gotoxy(25,8);
                    cout<<"                            "<<endl;
                    gotoxy(25,8);
                    cout<<"                            "<<endl;
                    gotoxy(25,9);
                    cout<<"                               "<<endl;
                    gotoxy(25,10);
                    cout<<"                               "<<endl;
                    gotoxy(25,11);
                    cout<<"                           "<<endl;
                }

                if(frenteejecucion!=NULL&&nulo==false){
                    while(listasys<45){
                            cout<<"                                                                                                                                "<<endl;
                            gotoxy(70,15+listasys);
                            listasys++;
                        }
                    listasys=0;
                    gotoxy(70,15);
                    mostrarl();
                    laux=lp;

                    do{
                        x=0;
                        comprobador=0;
                        prel=laux->getproceso();
                        while(prel.length()>x){
                            if(isalpha(prel[x])){
                                comprobador++;
                            }
                            x++;
                        }
                        if(comprobador==0){
                            nuevos=stoi(prel);
                            if(nuevos==id){
                                laux->setestado("En ejecucion");
                            }
                        }
                        laux=laux->getsiguiente();
                    }while(laux!=lp);
                    gotoxy(25,5);
                    cout<<"ID: "<<id<<endl;
                    gotoxy(25,6);
                    cout<<"Operacion "<<numero1<<signo<<numero2<<endl;
                    gotoxy(25,7);
                    tiempo=tme-TiempoE;
                    tp=0;
                    cout<<"TME: "<<tme<<endl;
                    gotoxy(25,8);
                    cout<<"                            "<<endl;
                    gotoxy(25,8);
                    cout<<"Tiempo de ejecucion: "<<TiempoE<<endl;
                    gotoxy(25,9);
                    cout<<"                           "<<endl;
                    gotoxy(25,9);
                    cout<<"Tiempo restante: "<<tme-TiempoE<<endl;
                    gotoxy(25,10);
                    cout<<"Tiempo de quantum: "<<quac<<endl;
                    gotoxy(25,11);
                    cout<<"                         "<<endl;
                    gotoxy(25,11);
                    cout<<"Paginas "<<pag<<endl;
                }

                while(frentelistos!=NULL){
                    laux=lp;
                    vaciarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                    do{
                        x=0;
                        comprobador=0;
                        prel=laux->getproceso();
                        while(prel.length()>x){
                            if(isalpha(prel[x])){
                                comprobador++;
                            }
                            x++;
                        }
                        if(comprobador==0){
                            nuevos=stoi(prel);
                            if(nuevos==id){
                                laux->setestado("Listo");
                            }
                        }
                        laux=laux->getsiguiente();
                    }while(laux!=lp);
                    gotoxy(0,5+cuenta);
                    cout<<"id: "<<id<<" TME: "<<tme<<" TT: "<<TiempoE<<endl;
                    cuenta++;
                    insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                }

                while(frenteim!=NULL){
                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                    insertarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                }
                if(nulo==true){
                    tiempo=9999;
                }
                quac=0;
                while(tp<tiempo){

                    Sleep(1);
                    reloj++;

                    tecla=' ';
                    if(kbhit()){
                        tecla=getch();
                        switch(tecla){
                            case 'p':
                                stop=true;
                                break;
                            case 'c':
                                stop=false;
                                break;
                            case 'w':
                                if(stop==false&&nulo==false){
                                    error=true;
                                    tp=tiempo;
                                }
                                break;
                            case 'e':
                                if(stop==false&&nulo==false){
                                    salto=true;
                                    auxin=tp;
                                    tp=tiempo;
                                }
                                break;
                            case 'n':
                                if(stop==false){
                                    numero1=rand()%100+1;
                                    numero2=rand()%100+1;
                                    sig=rand()%6+1;
                                     switch(sig){
                                        case 1:{
                                            signo="+";

                                        }break;
                                        case 2:{
                                            signo="-";

                                        }break;
                                        case 3:{
                                            signo="*";

                                        }break;
                                        case 4:{
                                            signo="/";

                                        }break;
                                        case 5:{
                                            signo="%";

                                        }break;
                                        case 6:{
                                            signo="^";
                                            numero1=rand()%6+1;
                                            numero2=rand()%6+1;

                                        }break;
                                        }
                                    tme=rand()%10+6;
                                    pag=rand()%28+6;
                                    if(nulo==true&&lleno==false){
                                        marcos=pag/5;
                                        pagmod=pag%5;
                                        if(pagmod>0){
                                            marcos++;
                                        }
                                        laux=lp;
                                        do{
                                            if(laux->getpagina()==0){
                                                marcos--;
                                            }
                                            laux=laux->getsiguiente();
                                        }while(laux!=lp);

                                        if(marcos>0){
                                            lleno=true;
                                            insertarLote(frentenuevo,finnuevo,signo,"0",false,false,pag,numero1,numero2,tme,col+1,0,0,0,0,0,0);
                                            cantidad++;
                                            cout<<"                              "<<endl;
                                            gotoxy(0,0);
                                            cout<<"Numero de procesos nuevos: "<<cantidad<<endl;
                                        }

                                        else{
                                            marcos=pag;
                                            pagmod=pag%5;
                                            laux=lp;
                                            while(marcos>0){
                                                if(laux->getpagina()==0){
                                                    if(marcos>=5){
                                                        laux->setpagina(5);
                                                        laux->setproceso(to_string(col+1));
                                                        laux->setestado("Listo");
                                                        marcos-=5;
                                                    }
                                                    else{
                                                        laux->setpagina(pagmod);
                                                        laux->setproceso(to_string(col+1));
                                                        laux->setestado("Listo");
                                                        marcos=0;
                                                        pagmod=0;
                                                    }
                                                }
                                                laux=laux->getsiguiente();
                                            }
                                            nulo=false;
                                            tp=9999;
                                            salto=true;
                                            nuevo=true;
                                            insertarLote(frentelistos,finlistos,signo,"0",true,false,pag,numero1,numero2,tme,col+1,0,0,0,0,tt,0);
                                            nprocesos++;
                                            cantidad++;

                                            while(listasys<45){
                                                cout<<"                                                                                                                                "<<endl;
                                                gotoxy(70,15+listasys);
                                                listasys++;
                                            }
                                            listasys=0;
                                            gotoxy(70,15);
                                            mostrarl();

                                        }
                                    }
                                    else if(lleno==false){
                                        marcos=pag/5;
                                        pagmod=pag%5;
                                        if(pagmod>0){
                                            marcos++;
                                        }
                                        laux=lp;
                                        do{
                                            if(laux->getpagina()==0){
                                                marcos--;
                                            }
                                            laux=laux->getsiguiente();
                                        }while(laux!=lp);

                                        if(marcos>0){
                                            lleno=true;
                                            insertarLote(frentenuevo,finnuevo,signo,"0",false,false,pag,numero1,numero2,tme,col+1,0,0,0,0,0,0);
                                            cantidad++;
                                            cout<<"                              "<<endl;
                                            gotoxy(0,0);
                                            cout<<"Numero de procesos nuevos: "<<cantidad<<endl;
                                        }

                                        else{
                                            marcos=pag;
                                            pagmod=pag%5;
                                            laux=lp;
                                            while(marcos>0){
                                                if(laux->getpagina()==0){
                                                    if(marcos>=5){
                                                        laux->setpagina(5);
                                                        laux->setproceso(to_string(col+1));
                                                        laux->setestado("Listo");
                                                        marcos-=5;
                                                    }
                                                    else{
                                                        laux->setpagina(pagmod);
                                                        laux->setproceso(to_string(col+1));
                                                        laux->setestado("Listo");
                                                        marcos=0;
                                                        pagmod=0;
                                                    }
                                                }
                                                laux=laux->getsiguiente();
                                            }

                                            insertarLote(frentelistos,finlistos,signo,"0",true,false,pag,numero1,numero2,tme,col+1,0,0,0,0,tt,0);
                                            cuenta=0;
                                            while(frentelistos!=NULL){
                                                vaciarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                                gotoxy(0,5+cuenta);
                                                cout<<"id: "<<id<<" TME: "<<tme<<" TT: "<<TiempoE<<endl;
                                                cuenta++;
                                                insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                            }

                                            while(frenteim!=NULL){
                                                vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                                insertarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                            }
                                            nprocesos++;
                                            while(listasys<45){
                                                cout<<"                                                                                                                                "<<endl;
                                                gotoxy(70,15+listasys);
                                                listasys++;
                                            }
                                            listasys=0;
                                            gotoxy(70,15);
                                            mostrarl();
                                        }
                                    }
                                    else{
                                        insertarLote(frentenuevo,finnuevo,signo,"0",false,false,pag,numero1,numero2,tme,col+1,0,0,0,0,0,0);
                                        cantidad++;
                                        cout<<"                              "<<endl;
                                        gotoxy(0,0);
                                        cout<<"Numero de procesos nuevos: "<<cantidad<<endl;
                                    }

                                    col++;
                                }
                                break;
                            case 'b':
                                system("cls");
                                cout<<"Tiempo transcurrido "<<tt<<endl;
                                cout<<"ID\t"<<"resultado "<<"       TME  "<<"estado"<<"\tTiempo de llegada"<<"  Tiempo de finalizacion  "<<"Tiempo de retorno"<<" Tiempo de respuesta"<<"  Tiempo de espera  "
                                <<"Tiempo de servicio"<<"  Tiempo restante en bloqueo"<<"\tTiempo restante en CPU"<<endl;
                                cuenta=2;
                                tempmem.close();
                                tempmem.open("memo.txt",ios::app);
                                while(frentenuevo!=NULL){
                                        vaciarLote(frentenuevo,finnuevo,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                            gotoxy(0,1+cuenta);
                                            cout<<id<<"\t"<<numero1<<signo<<numero2<<"=Pendiente";
                                            gotoxy(25,1+cuenta);
                                            cout<<tme;
                                            gotoxy(30,1+cuenta);
                                            cout<<"nuevo"<<endl;
                                            gotoxy(48,1+cuenta);
                                            cout<<"-";
                                            gotoxy(68,1+cuenta);
                                            cout<<"-";
                                            gotoxy(91,1+cuenta);
                                            cout<<"-";
                                            gotoxy(110,1+cuenta);
                                            cout<<"-";
                                            gotoxy(130,1+cuenta);
                                            cout<<"-";
                                            gotoxy(148,1+cuenta);
                                            cout<<"-";
                                            gotoxy(171,1+cuenta);
                                            cout<<"-";
                                            gotoxy(200,1+cuenta);
                                            cout<<"-";
                                            tempmem<<"nuevo"<<"."<<signo<<"."<<ress<<"."<<llegadast<<"."<<respuestast<<"."<<pag<<"."<<numero1<<"."<<numero2<<"."<<tme<<"."
                                            <<id<<"."<<TiempoT<<"."<<TiempoB<<"."<<TiempoE<<"."<<TiempoR<<"."<<TiempoLL<<"."<<TiempoF<<endl;



                                        insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                        cuenta++;
                                }

                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frentenuevo,finnuevo,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }

                                while(frentelistos!=NULL){
                                        vaciarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                        insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                            gotoxy(0,1+cuenta);
                                            tempmem<<"listo"<<"."<<signo<<"."<<ress<<"."<<llegadast<<"."<<respuestast<<"."<<pag<<"."<<numero1<<"."<<numero2<<"."<<tme<<"."
                                            <<id<<"."<<TiempoT<<"."<<TiempoB<<"."<<TiempoE<<"."<<TiempoR<<"."<<TiempoLL<<"."<<TiempoF<<endl;
                                            cout<<id<<"\t"<<numero1<<signo<<numero2<<"=Pendiente";
                                            gotoxy(25,1+cuenta);
                                            cout<<tme;
                                            gotoxy(30,1+cuenta);
                                            cout<<"listo"<<endl;
                                            gotoxy(48,1+cuenta);
                                            cout<<TiempoLL;
                                            gotoxy(68,1+cuenta);
                                            cout<<"-";
                                            gotoxy(91,1+cuenta);
                                            cout<<"-";
                                            gotoxy(110,1+cuenta);
                                            if(respuestast==false){
                                                cout<<"-";
                                            }
                                            else{
                                                cout<<TiempoR<<endl;
                                            }
                                            gotoxy(130,1+cuenta);
                                            cout<<TiempoT;
                                            gotoxy(148,1+cuenta);
                                            cout<<TiempoE;
                                            gotoxy(171,1+cuenta);
                                            cout<<"-"<<"\t\t";
                                            gotoxy(200,1+cuenta);
                                            cout<<tme-TiempoE;


                                        cuenta++;
                                }

                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }

                                while(frenteejecucion!=NULL){
                                        vaciarLote(frenteejecucion,finejecucion,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                        insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                        tempmem<<"ejecucion"<<"."<<signo<<"."<<ress<<"."<<llegadast<<"."<<respuestast<<"."<<pag<<"."<<numero1<<"."<<numero2<<"."<<tme<<"."
                                            <<id<<"."<<TiempoT<<"."<<TiempoB<<"."<<TiempoE<<"."<<TiempoR<<"."<<TiempoLL<<"."<<TiempoF<<endl;
                                            gotoxy(0,1+cuenta);
                                            cout<<id<<"\t"<<numero1<<signo<<numero2<<"=Pendiente";
                                            gotoxy(25,1+cuenta);
                                            cout<<tme;
                                            gotoxy(30,1+cuenta);
                                            cout<<"ejecucion"<<endl;
                                            gotoxy(48,1+cuenta);
                                            cout<<TiempoLL;
                                            gotoxy(68,1+cuenta);
                                            cout<<"-";
                                            gotoxy(91,1+cuenta);
                                            cout<<"-";
                                            gotoxy(110,1+cuenta);
                                            cout<<TiempoR<<endl;
                                            gotoxy(130,1+cuenta);
                                            cout<<TiempoT;
                                            gotoxy(148,1+cuenta);
                                            cout<<TiempoE;
                                            gotoxy(171,1+cuenta);
                                            cout<<"-\t\t";
                                            gotoxy(200,1+cuenta);
                                            cout<<tme-TiempoE;
                                        cuenta++;
                                }

                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frenteejecucion,finejecucion,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }

                                while(frentebloq!=NULL){
                                        vaciarLote(frentebloq,finbloq,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                        insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                        tempmem<<"bloqueados"<<"."<<signo<<"."<<ress<<"."<<llegadast<<"."<<respuestast<<"."<<pag<<"."<<numero1<<"."<<numero2<<"."<<tme<<"."
                                            <<id<<"."<<TiempoT<<"."<<TiempoB<<"."<<TiempoE<<"."<<TiempoR<<"."<<TiempoLL<<"."<<TiempoF<<endl;
                                            gotoxy(0,1+cuenta);
                                            cout<<id<<"\t"<<numero1<<signo<<numero2<<"=Pendiente";
                                            gotoxy(25,1+cuenta);
                                            cout<<tme;
                                            gotoxy(30,1+cuenta);
                                            cout<<"bloqueo"<<endl;
                                            gotoxy(48,1+cuenta);
                                            cout<<TiempoLL;
                                            gotoxy(68,1+cuenta);
                                            cout<<"-";
                                            gotoxy(91,1+cuenta);
                                            cout<<"-";
                                            gotoxy(110,1+cuenta);
                                            cout<<TiempoR<<endl;
                                            gotoxy(130,1+cuenta);
                                            cout<<TiempoT;
                                            gotoxy(148,1+cuenta);
                                            cout<<TiempoE;
                                            gotoxy(171,1+cuenta);
                                            cout<<7-TiempoB<<"\t\t";
                                            gotoxy(200,1+cuenta);
                                            cout<<tme-TiempoE;


                                        cuenta++;
                                }

                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frentebloq,finbloq,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);

                                }
                                while(frentetem!=NULL){
                                    vaciarLote(frentetem,fintem,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    auxi=1;
                                    x=0;
                                    while(x<ress.size()){
                                        if(isalpha(ress[x])==true){
                                            auxi=0;
                                        }
                                        x++;
                                    }
                                    if(auxi==0){
                                        tempmem<<"terminados"<<"."<<signo<<"."<<ress<<"."<<llegadast<<"."<<respuestast<<"."<<pag<<"."<<numero1<<"."<<numero2<<"."<<tme<<"."
                                            <<"error"<<"."<<TiempoT<<"."<<TiempoB<<"."<<TiempoE<<"."<<TiempoR<<"."<<TiempoLL<<"."<<TiempoF<<endl;
                                        gotoxy(0,1+cuenta);
                                        cout<<id<<"\tERROR";
                                        gotoxy(24,1+cuenta);
                                        cout<<tme;
                                        gotoxy(48,1+cuenta);
                                        cout<<TiempoLL;
                                        gotoxy(68,1+cuenta);
                                        cout<<TiempoF;
                                        gotoxy(91,1+cuenta);
                                        cout<<TiempoF-TiempoLL;
                                        gotoxy(110,1+cuenta);
                                        cout<<TiempoR;
                                        gotoxy(130,1+cuenta);
                                        cout<<TiempoT;
                                        gotoxy(148,1+cuenta);
                                        cout<<TiempoE;
                                        gotoxy(171,1+cuenta);
                                        cout<<"-\t\t";
                                        gotoxy(200,1+cuenta);
                                        cout<<tme-TiempoE;
                                    }

                                    else{
                                        gotoxy(0,1+cuenta);
                                        tempmem<<"terminados"<<"."<<signo<<"."<<ress<<"."<<llegadast<<"."<<respuestast<<"."<<pag<<"."<<numero1<<"."<<numero2<<"."<<tme<<"."
                                        <<id<<"."<<TiempoT<<"."<<TiempoB<<"."<<TiempoE<<"."<<TiempoR<<"."<<TiempoLL<<"."<<TiempoF<<endl;
                                        cout<<id<<"\t"<<numero1<<signo<<numero2<<"="<<ress;
                                        gotoxy(24,1+cuenta);
                                        cout<<tme;
                                        gotoxy(48,1+cuenta);
                                        cout<<TiempoLL;
                                        gotoxy(68,1+cuenta);
                                        cout<<TiempoF;
                                        gotoxy(91,1+cuenta);
                                        cout<<TiempoF-TiempoLL;
                                        gotoxy(110,1+cuenta);
                                        cout<<TiempoR;
                                        gotoxy(130,1+cuenta);
                                        cout<<TiempoT;
                                        gotoxy(148,1+cuenta);
                                        cout<<TiempoE;
                                        gotoxy(171,1+cuenta);
                                        cout<<"-\t\t";
                                        gotoxy(200,1+cuenta);
                                        cout<<tme-TiempoE;
                                    }
                                    gotoxy(30,1+cuenta);
                                    cout<<"terminado"<<endl;
                                    cuenta++;

                                }
                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frentetem,fintem,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }
                                gotoxy(0,1+cuenta);
                                x=0;
                                fflush(stdin);
                                while(x==0){
                                    tec=getch();
                                    if(tec=='c'){
                                        x=1;
                                    }
                                    else{
                                        fflush(stdin);
                                    }
                                }
                                system("cls");
                                cout<<"Numero de procesos nuevos: "<<cantidad<<endl;
                                cout<<"tiempo transcurrido: "<<tt<<endl;
                                cout<<"Procesos listos\t\t";
                                cout<<"Proceso en ejecucion\t\t";
                                cout<<"Terminados"<<endl;
                                gotoxy(24,13);
                                cout<<"Procesos bloqueados"<<endl;
                                cuenta=0;

                                /*Momento de la reescritura y reinsercion*/
                                while(frentelistos!=NULL){
                                    vaciarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    gotoxy(0,5+cuenta);
                                    cout<<"id: "<<id<<" TME: "<<tme<<" TT: "<<TiempoE<<endl;
                                    cuenta++;
                                    insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }
                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }

                                vaciarLote(frenteejecucion,finejecucion,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);

                                gotoxy(25,5);
                                cout<<"                  "<<endl;
                                gotoxy(25,5);
                                cout<<"ID: "<<id<<endl;
                                gotoxy(25,6);
                                cout<<"Operacion "<<numero1<<signo<<numero2<<endl;
                                gotoxy(25,7);
                                tiempo=tme;
                                tp=0+TiempoE;
                                cout<<"TME: "<<tme<<endl;
                                gotoxy(25,8);
                                cout<<"                            "<<endl;
                                gotoxy(25,8);
                                cout<<"Tiempo de ejecucion: "<<TiempoE<<endl;
                                gotoxy(25,9);
                                cout<<"                           "<<endl;
                                gotoxy(25,9);
                                cout<<"Tiempo restante: "<<tme-TiempoE<<endl;
                                gotoxy(25,10);
                                cout<<"Tiempo de quantum: "<<quac<<endl;
                                gotoxy(25,11);
                                cout<<"                         "<<endl;
                                gotoxy(25,11);
                                cout<<"Paginas "<<pag<<endl;

                                insertarLote(frenteejecucion,finejecucion,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);

                                cuenta=0;
                                while(frentebloq!=NULL){
                                    vaciarLote(frentebloq,finbloq,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    gotoxy(24,14+cuenta);
                                    cout<<"id: "<<id<<" Tiempo en bloqueado: "<<TiempoB<<endl;
                                    cuenta++;
                                    insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }
                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frentebloq,finbloq,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }

                                    cuenta=0;
                                    while(frentetem!=NULL){
                                    vaciarLote(frentetem,fintem,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    auxi=1;
                                    x=0;
                                    while(x<ress.size()){
                                        if(isalpha(ress[x])==true){
                                            auxi=0;
                                        }
                                        x++;
                                    }
                                    gotoxy(56,5+cuenta);
                                    if(auxi==0){
                                        cout<<"id: "<<id<<" operacion: "<<numero1<<signo<<numero2<<" Resultado: Error"<<endl;
                                    }
                                    else{
                                         cout<<"id: "<<id<<" operacion: "<<numero1<<signo<<numero2<<" Resultado: "<<ress<<endl;
                                    }
                                    cuenta++;
                                    insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }

                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frentetem,fintem,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }
                                tempmem.close();

                                break;

                            case 't':
                                system("cls");
                                cout<<"numero de marco \tproceso en la pagina\tmumero de paginas ocupadas\testado"<<endl;
                                mostrarl();
                                x=0;
                                fflush(stdin);
                                while(x==0){
                                    tec=getch();
                                    if(tec=='c'){
                                        x=1;
                                    }
                                    else{
                                        fflush(stdin);
                                    }
                                }
                                system("cls");
                                cuenta=0;
                                cout<<"Numero de procesos nuevos: "<<cantidad<<endl;
                                cout<<"tiempo transcurrido: "<<tt<<endl;
                                cout<<"Procesos listos\t\t";
                                cout<<"Proceso en ejecucion\t\t";
                                cout<<"Terminados"<<endl;
                                gotoxy(24,13);
                                cout<<"Procesos bloqueados"<<endl;
                                while(frentelistos!=NULL){
                                    vaciarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    gotoxy(0,5+cuenta);
                                    cout<<"id: "<<id<<" TME: "<<tme<<" TT: "<<TiempoE<<endl;
                                    cuenta++;
                                    insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }
                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }

                                vaciarLote(frenteejecucion,finejecucion,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);

                                gotoxy(25,5);
                                cout<<"               "<<endl;
                                gotoxy(25,5);
                                cout<<"ID: "<<id<<endl;
                                gotoxy(25,6);
                                cout<<"Operacion "<<numero1<<signo<<numero2<<endl;
                                gotoxy(25,7);
                                tiempo=tme;
                                tp=0+TiempoE;
                                cout<<"TME: "<<tme<<endl;
                                gotoxy(25,8);
                                cout<<"                            "<<endl;
                                gotoxy(25,8);
                                cout<<"Tiempo de ejecucion: "<<TiempoE<<endl;
                                gotoxy(25,9);
                                cout<<"                           "<<endl;
                                gotoxy(25,9);
                                cout<<"Tiempo restante: "<<tme-TiempoE<<endl;
                                gotoxy(25,10);
                                cout<<"Tiempo de quantum: "<<quac<<endl;
                                gotoxy(25,11);
                                cout<<"                         "<<endl;
                                gotoxy(25,11);
                                cout<<"Paginas "<<pag<<endl;

                                insertarLote(frenteejecucion,finejecucion,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);

                                cuenta=0;
                                while(frentebloq!=NULL){
                                    vaciarLote(frentebloq,finbloq,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    gotoxy(24,14+cuenta);
                                    cout<<"id: "<<id<<" Tiempo en bloqueado: "<<TiempoB<<endl;
                                    cuenta++;
                                    insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }
                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frentebloq,finbloq,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }

                                    cuenta=0;
                                    while(frentetem!=NULL){
                                    vaciarLote(frentetem,fintem,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    auxi=1;
                                    x=0;
                                    while(x<ress.size()){
                                        if(isalpha(ress[x])==true){
                                            auxi=0;
                                        }
                                        x++;
                                    }
                                    gotoxy(56,5+cuenta);
                                    if(auxi==0){
                                        cout<<"id: "<<id<<" operacion: "<<numero1<<signo<<numero2<<" Resultado: Error"<<endl;
                                    }
                                    else{
                                         cout<<"id: "<<id<<" operacion: "<<numero1<<signo<<numero2<<" Resultado: "<<ress<<endl;
                                    }
                                    cuenta++;
                                    insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }

                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frentetem,fintem,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }


                                break;

                            case 's':
                                if(frentebloq!=NULL){
                                    suspendidos++;
                                    pendiente=0;
                                    gotoxy(24,14+pendiente);
                                    cout<<"                                "<<endl;
                                    vaciarLote(frentebloq,finbloq,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    pendiente++;
                                    escritura<<signo<<"."<<ress<<"."<<llegadast<<"."<<respuestast<<"."<<pag<<"."<<numero1<<"."<<numero2<<"."<<tme<<"."<<id<<"."<<TiempoB<<"."<<
                                    TiempoE<<"."<<TiempoR<<"."<<TiempoLL<<"."<<TiempoF<<endl;

                                    laux=lp;
                                    do{
                                        x=0;
                                        comprobador=0;
                                        prel=laux->getproceso();
                                        while(prel.length()>x){
                                            if(isalpha(prel[x])){
                                                comprobador++;
                                            }
                                            x++;
                                        }
                                        if(comprobador==0){
                                            nuevos=stoi(prel);
                                            if(nuevos==id){
                                                laux->setpagina(0);
                                                laux->setproceso("vacio");
                                                laux->setestado("vacio");
                                            }
                                        }
                                        laux=laux->getsiguiente();
                                    }while(laux!=lp);

                                    while(frentebloq!=NULL){
                                        gotoxy(24,14+pendiente);
                                        cout<<"                               "<<endl;
                                        vaciarLote(frentebloq,finbloq,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                        gotoxy(24,14+pendiente-1);
                                        cout<<"id: "<<id<<" Tiempo en bloqueado: "<<TiempoB<<endl;
                                        insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                        pendiente++;
                                    }

                                    gotoxy(30,0);
                                    cout<<"Procesos suspendidos: "<<suspendidos<<endl;
                                    primerosus=false;
                                    lectura.close();
                                    lectura.open("secundario.txt");
                                    while(!lectura.eof()){
                                        linea="";
                                        punto1=0;
                                        punto2=0;
                                        getline(lectura,linea);
                                        while(punto1>-1){
                                            punto1=linea.find(".");
                                            sub=linea.substr(punto1+1);
                                            avan=linea.substr(0,punto1);
                                            linea=sub;
                                            if(primerosus==false){
                                                switch (punto2){
                                                    case 4:
                                                        gotoxy(57,1);
                                                        cout<<"tamaño: "<<avan;
                                                    break;
                                                    case 8:
                                                        gotoxy(57,0);
                                                        cout<<"siguiente proceso: "<<avan;
                                                        primerosus=true;
                                                    break;
                                                }
                                            }
                                            punto2++;
                                        }

                                    }

                                    while(frenteim!=NULL){
                                        vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                        insertarLote(frentebloq,finbloq,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    }
                                    lleno=false;
                                    while(listasys<45){
                                        cout<<"                                                                                                                                "<<endl;
                                        gotoxy(70,15+listasys);
                                        listasys++;
                                    }
                                    listasys=0;
                                    gotoxy(70,15);
                                    mostrarl();

                                }

                                break;

                            case 'r':
                                lectura.close();
                                lectura.open("secundario.txt",ios::in);
                                tempesc.close();
                                tempesc.open("temporal.txt",ios::out);
                                primerosus=false;
                                while(!lectura.eof()){
                                    linea="";
                                    punto1=0;
                                    punto2=0;
                                    getline(lectura,linea);
                                    if(linea!=""){
                                    while(punto1>-1){
                                        punto1=linea.find(".");
                                        sub=linea.substr(punto1+1);
                                        avan=linea.substr(0,punto1);
                                        linea=sub;
                                        switch (punto2){
                                                    case 0:
                                                        signo=avan;
                                                    break;
                                                    case 1:
                                                        ress=avan;
                                                    break;
                                                    case 2:
                                                        llegadast=stoi(avan);
                                                    break;
                                                    case 3:
                                                        respuestast=stoi(avan);
                                                    break;
                                                    case 4:
                                                        pag=stoi(avan);
                                                    break;
                                                    case 5:
                                                        numero1=stoi(avan);
                                                    break;
                                                    case 6:
                                                        numero2=stoi(avan);
                                                    break;
                                                    case 7:
                                                        tme=stoi(avan);
                                                    break;
                                                    case 8:
                                                        id=stoi(avan);
                                                    break;
                                                    case 9:
                                                        TiempoB=stoi(avan);
                                                    break;
                                                    case 10:
                                                        TiempoE=stoi(avan);
                                                    break;
                                                    case 11:
                                                        TiempoR=stoi(avan);
                                                    break;
                                                    case 12:
                                                        TiempoLL=stoi(avan);
                                                    break;
                                                    case 13:
                                                        TiempoF=stoi(avan);
                                                    break;
                                                }
                                            punto2++;
                                            }

                                            laux=lp;
                                            if(primerosus!=true){

                                                if(pag%5!=0){
                                                    marcos=pag/5;
                                                    marcos++;
                                                }
                                                else{
                                                    marcos=pag/5;
                                                }
                                                do{
                                                    if(laux->getpagina()==0){
                                                        marcos--;
                                                    }
                                                    laux=laux->getsiguiente();
                                                }while(laux!=lp&&marcos>0);

                                                if(marcos>0){
                                                    primerosus=true;
                                                }

                                                else{
                                                if(nulo==true){
                                                    nulo=false;
                                                    tp=9999;
                                                    salto=true;
                                                    nuevo=true;
                                                }
                                                suspendidos--;
                                                gotoxy(30,0);
                                                cout<<"Procesos suspendidos: "<<suspendidos<<endl;
                                                marcos=pag;
                                                pagmod=pag%5;
                                                laux=lp;
                                                while(marcos>0){

                                                    if(laux->getpagina()==0){
                                                        if(marcos>=5){

                                                            laux->setpagina(5);
                                                            laux->setproceso(to_string(id));
                                                            laux->setestado("Listo");

                                                            marcos-=5;
                                                        }
                                                        else{
                                                            laux->setpagina(pagmod);
                                                            laux->setproceso(to_string(id));
                                                            laux->setestado("Listo");
                                                            marcos=0;
                                                            pagmod=0;
                                                        }
                                                    }
                                                    laux=laux->getsiguiente();


                                                }

                                                insertarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,tt-TiempoLL-TiempoE,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                            while(listasys<45){
                                                cout<<"                                                                                                                                "<<endl;
                                                gotoxy(70,15+listasys);
                                                listasys++;
                                            }
                                            listasys=0;
                                            gotoxy(70,15);
                                            mostrarl();
                                            }

                                        }

                                        if(primerosus==true){
                                            tempesc<<signo<<"."<<ress<<"."<<llegadast<<"."<<respuestast<<"."<<pag<<"."<<numero1<<"."<<numero2<<"."<<tme<<"."<<id<<"."<<TiempoB<<"."<<
                                            TiempoE<<"."<<TiempoR<<"."<<TiempoLL<<"."<<TiempoF<<endl;
                                        }
                                        primerosus=true;
                                        }

                                    }
                                    templec.close();
                                    templec.open("temporal.txt",ios::in);
                                    escritura.close();
                                    escritura.open("secundario.txt",ios::out);
                                    primerosus=false;
                                    vacio=true;
                                    while(!templec.eof()){
                                    linea="";
                                    punto1=0;
                                    punto2=0;
                                    getline(templec,linea);
                                    if(linea!=""){
                                    while(punto1>-1){
                                        vacio=false;
                                        punto1=linea.find(".");
                                        sub=linea.substr(punto1+1);
                                        avan=linea.substr(0,punto1);
                                        linea=sub;
                                        switch (punto2){
                                                    case 0:
                                                        signo=avan;
                                                    break;
                                                    case 1:
                                                        ress=avan;
                                                    break;
                                                    case 2:
                                                        llegadast=stoi(avan);
                                                    break;
                                                    case 3:
                                                        respuestast=stoi(avan);
                                                    break;
                                                    case 4:
                                                        pag=stoi(avan);
                                                    break;
                                                    case 5:
                                                        numero1=stoi(avan);
                                                    break;
                                                    case 6:
                                                        numero2=stoi(avan);
                                                    break;
                                                    case 7:
                                                        tme=stoi(avan);
                                                    break;
                                                    case 8:
                                                        id=stoi(avan);
                                                    break;
                                                    case 9:
                                                        TiempoB=stoi(avan);
                                                    break;
                                                    case 10:
                                                        TiempoE=stoi(avan);
                                                    break;
                                                    case 11:
                                                        TiempoR=stoi(avan);
                                                    break;
                                                    case 12:
                                                        TiempoLL=stoi(avan);
                                                    break;
                                                    case 13:
                                                        TiempoF=stoi(avan);
                                                    break;
                                                }
                                            punto2++;
                                            }
                                            if(primerosus==false){
                                                primerosus=true;
                                                gotoxy(57,1);
                                                cout<<"tamaño: "<<pag<<endl;
                                                gotoxy(57,0);
                                                cout<<"siguiente proceso: "<<id<<endl;

                                            }

                                            escritura<<signo<<"."<<ress<<"."<<llegadast<<"."<<respuestast<<"."<<pag<<"."<<numero1<<"."<<numero2<<"."<<tme<<"."<<id<<"."<<TiempoB<<"."<<
                                            TiempoE<<"."<<TiempoR<<"."<<TiempoLL<<"."<<TiempoF<<endl;

                                        }
                                    }
                                    cuenta=0;
                                    while(frentelistos!=NULL){
                                        vaciarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                        gotoxy(0,5+cuenta);
                                        cout<<"id: "<<id<<" TME: "<<tme<<" TT: "<<TiempoE<<endl;
                                        cuenta++;
                                        insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    }
                                    while(frenteim!=NULL){
                                        vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                        insertarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    }
                                    if(vacio==true){
                                        gotoxy(57,1);
                                        cout<<"                            "<<endl;
                                        gotoxy(57,0);
                                        cout<<"                            "<<endl;
                                        vacio=false;
                                    }
                                    break;
                                }


                        }

                    if(stop==true){
                        reloj--;
                    }

                    if(reloj==1000){
                        cuenta=0;
                        if(tt%5==0){

                                system("cls");
                                cout<<"Tiempo transcurrido "<<tt<<endl;
                                cout<<"ID\t"<<"resultado "<<"       TME  "<<"estado"<<"\tTiempo de llegada"<<"  Tiempo de finalizacion  "<<"Tiempo de retorno"<<" Tiempo de respuesta"<<"  Tiempo de espera  "
                                <<"Tiempo de servicio"<<"  Tiempo restante en bloqueo"<<"\tTiempo restante en CPU"<<endl;
                                cuenta=2;
                                tempmem.close();
                                tempmem.open("memo.txt",ios::out);
                                while(frentenuevo!=NULL){
                                        vaciarLote(frentenuevo,finnuevo,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                        gotoxy(0,1+cuenta);
                                        tempmem<<"nuevo"<<"."<<signo<<"."<<ress<<"."<<llegadast<<"."<<respuestast<<"."<<pag<<"."<<numero1<<"."<<numero2<<"."<<tme<<"."
                                            <<id<<"."<<TiempoT<<"."<<TiempoB<<"."<<TiempoE<<"."<<TiempoR<<"."<<TiempoLL<<"."<<TiempoF<<endl;
                                        insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                        cuenta++;
                                }

                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frentenuevo,finnuevo,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }

                                while(frenteejecucion!=NULL){
                                        vaciarLote(frenteejecucion,finejecucion,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                        insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                        tempmem<<"ejecucion"<<"."<<signo<<"."<<ress<<"."<<llegadast<<"."<<respuestast<<"."<<pag<<"."<<numero1<<"."<<numero2<<"."<<tme<<"."
                                            <<id<<"."<<TiempoT<<"."<<TiempoB<<"."<<TiempoE<<"."<<TiempoR<<"."<<TiempoLL<<"."<<TiempoF<<endl;
                                }

                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frenteejecucion,finejecucion,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }

                                while(frentelistos!=NULL){
                                        vaciarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                        insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                            gotoxy(0,1+cuenta);
                                            tempmem<<"listo"<<"."<<signo<<"."<<ress<<"."<<llegadast<<"."<<respuestast<<"."<<pag<<"."<<numero1<<"."<<numero2<<"."<<tme<<"."
                                            <<id<<"."<<TiempoT<<"."<<TiempoB<<"."<<TiempoE<<"."<<TiempoR<<"."<<TiempoLL<<"."<<TiempoF<<endl;

                                }

                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }



                                while(frentebloq!=NULL){
                                        vaciarLote(frentebloq,finbloq,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                        insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                        tempmem<<"bloqueados"<<"."<<signo<<"."<<ress<<"."<<llegadast<<"."<<respuestast<<"."<<pag<<"."<<numero1<<"."<<numero2<<"."<<tme<<"."
                                            <<id<<"."<<TiempoT<<"."<<TiempoB<<"."<<TiempoE<<"."<<TiempoR<<"."<<TiempoLL<<"."<<TiempoF<<endl;


                                        cuenta++;
                                }

                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frentebloq,finbloq,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);

                                }
                                while(frentetem!=NULL){
                                    vaciarLote(frentetem,fintem,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    auxi=1;
                                    x=0;
                                    while(x<ress.size()){
                                        if(isalpha(ress[x])==true){
                                            auxi=0;
                                        }
                                        x++;
                                    }
                                    if(auxi==0){
                                        tempmem<<"terminados"<<"."<<signo<<"."<<ress<<"."<<llegadast<<"."<<respuestast<<"."<<pag<<"."<<numero1<<"."<<numero2<<"."<<tme<<"."
                                            <<"error"<<"."<<TiempoT<<"."<<TiempoB<<"."<<TiempoE<<"."<<TiempoR<<"."<<TiempoLL<<"."<<TiempoF<<endl;
                                        gotoxy(0,1+cuenta);
                                    }

                                    else{
                                        gotoxy(0,1+cuenta);
                                        tempmem<<"terminados"<<"."<<signo<<"."<<ress<<"."<<llegadast<<"."<<respuestast<<"."<<pag<<"."<<numero1<<"."<<numero2<<"."<<tme<<"."
                                        <<id<<"."<<TiempoT<<"."<<TiempoB<<"."<<TiempoE<<"."<<TiempoR<<"."<<TiempoLL<<"."<<TiempoF<<endl;
                                        cout<<id<<"\t"<<numero1<<signo<<numero2<<"="<<ress;
                                    }

                                }
                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frentetem,fintem,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }
                                gotoxy(0,1+cuenta);
                                x=0;
                                fflush(stdin);
                                system("cls");
                                cout<<"Numero de procesos nuevos: "<<cantidad<<endl;
                                cout<<"tiempo transcurrido: "<<tt<<endl;
                                cout<<"Procesos listos\t\t";
                                cout<<"Proceso en ejecucion\t\t";
                                cout<<"Terminados"<<endl;
                                gotoxy(24,13);
                                cout<<"Procesos bloqueados"<<endl;
                                cuenta=0;

                                /*Momento de la reescritura y reinsercion*/
                                while(frentelistos!=NULL){
                                    vaciarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    gotoxy(0,5+cuenta);
                                    cout<<"id: "<<id<<" TME: "<<tme<<" TT: "<<TiempoE<<endl;
                                    cuenta++;
                                    insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }
                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }

                                vaciarLote(frenteejecucion,finejecucion,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);

                                gotoxy(25,5);
                                cout<<"                  "<<endl;
                                gotoxy(25,5);
                                cout<<"ID: "<<id<<endl;
                                gotoxy(25,6);
                                cout<<"Operacion "<<numero1<<signo<<numero2<<endl;
                                gotoxy(25,7);
                                tiempo=tme;
                                tp=0+TiempoE;
                                cout<<"TME: "<<tme<<endl;
                                gotoxy(25,8);
                                cout<<"                            "<<endl;
                                gotoxy(25,8);
                                cout<<"Tiempo de ejecucion: "<<TiempoE<<endl;
                                gotoxy(25,9);
                                cout<<"                           "<<endl;
                                gotoxy(25,9);
                                cout<<"Tiempo restante: "<<tme-TiempoE<<endl;
                                gotoxy(25,10);
                                cout<<"Tiempo de quantum: "<<quac<<endl;
                                gotoxy(25,11);
                                cout<<"                         "<<endl;
                                gotoxy(25,11);
                                cout<<"Paginas "<<pag<<endl;

                                insertarLote(frenteejecucion,finejecucion,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);

                                cuenta=0;
                                while(frentebloq!=NULL){
                                    vaciarLote(frentebloq,finbloq,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    gotoxy(24,14+cuenta);
                                    cout<<"id: "<<id<<" Tiempo en bloqueado: "<<TiempoB<<endl;
                                    cuenta++;
                                    insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }
                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frentebloq,finbloq,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }

                                    cuenta=0;
                                    while(frentetem!=NULL){
                                    vaciarLote(frentetem,fintem,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    auxi=1;
                                    x=0;
                                    while(x<ress.size()){
                                        if(isalpha(ress[x])==true){
                                            auxi=0;
                                        }
                                        x++;
                                    }
                                    gotoxy(56,5+cuenta);
                                    if(auxi==0){
                                        cout<<"id: "<<id<<" operacion: "<<numero1<<signo<<numero2<<" Resultado: Error"<<endl;
                                    }
                                    else{
                                         cout<<"id: "<<id<<" operacion: "<<numero1<<signo<<numero2<<" Resultado: "<<ress<<endl;
                                    }
                                    cuenta++;
                                    insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }

                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frentetem,fintem,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }
                                tempmem.close();

                        }
                        while(frentetem!=NULL){

                                    vaciarLote(frentetem,fintem,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    auxi=1;
                                    x=0;
                                    while(x<ress.size()){
                                        if(isalpha(ress[x])==true){
                                            auxi=0;
                                        }
                                        x++;
                                    }
                                    gotoxy(56,5+cuenta);
                                    if(auxi==0){
                                        cout<<"id: "<<id<<" Error"<<endl;
                                    }
                                    else{
                                         cout<<"id: "<<id<<" operacion: "<<numero1<<signo<<numero2<<" Resultado: "<<ress<<endl;
                                    }
                                    cuenta++;
                                    insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }

                                while(frenteim!=NULL){
                                    vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    insertarLote(frentetem,fintem,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                }

                        quac++;
                        tp++;
                        tt++;
                        gotoxy(0,1);
                        cout<<"tiempo transcurrido: "<<tt<<endl;
                        reloj=0;
                        pendiente=0;
                        while(pendiente<20){
                            gotoxy(24,14+pendiente);
                            cout<<"                                "<<endl;
                            pendiente++;
                        }
                        pendiente=0;
                        if(frentebloq!=NULL){
                            pendiente=0;
                            while(frentebloq!=NULL){
                                gotoxy(24,14+pendiente);
                                cout<<"                           "<<endl;
                                vaciarLote(frentebloq,finbloq,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                TiempoB++;
                                TiempoT++;

                                if(TiempoB<7){
                                    gotoxy(24,14+pendiente);
                                    cout<<"id: "<<id<<" Tiempo en bloqueado: "<<TiempoB<<endl;
                                    insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    pendiente++;
                                }

                                else{
                                    gotoxy(0,5+cuenta);
                                    cout<<"id: "<<id<<" TME: "<<tme<<" TT: "<<TiempoE<<endl;
                                    do{
                                        x=0;
                                        comprobador=0;
                                        prel=laux->getproceso();
                                        while(prel.length()>x){
                                            if(isalpha(prel[x])){
                                                comprobador++;
                                            }
                                            x++;
                                        }
                                        if(comprobador==0){
                                            nuevos=stoi(prel);
                                            if(nuevos==id){
                                                laux->setestado("Listo");
                                            }
                                        }
                                        laux=laux->getsiguiente();
                                    }while(laux!=lp);
                                    TiempoB=0;
                                    cuenta++;
                                    TiempoT--;
                                    insertarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                    if(nulo==true){
                                        nulo=false;
                                        impen=true;
                                        salto=true;
                                        tp=9999;
                                    }
                                }
                            }
                        }
                        while(frenteim!=NULL){
                                vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                insertarLote(frentebloq,finbloq,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                            }
                        cuenta=0;
                        while(cuenta<=22){
                            gotoxy(0,5+cuenta);
                            cout<<"                    "<<endl;
                            cuenta++;
                        }
                        cuenta=0;
                        while(frentelistos!=NULL){

                            vaciarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                            TiempoT++;
                            if(impen==false){
                                gotoxy(0,5+cuenta);
                                cout<<"id: "<<id<<" TME: "<<tme<<" TT: "<<TiempoE<<endl;
                            }

                            insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                            cuenta++;
                        }

                        cuenta=0;

                        while(frenteim!=NULL){
                            vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                            insertarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                        }
                        if(frenteejecucion!=NULL){
                            vaciarLote(frenteejecucion,finejecucion,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                            TiempoE++;
                        }

                        if(nulo==false){
                            gotoxy(25,5);
                            cout<<"                               "<<endl;
                            gotoxy(25,5);
                            cout<<"ID: "<<id<<endl;
                            gotoxy(25,8);
                            cout<<"                          "<<endl;
                            gotoxy(25,8);
                            cout<<"Tiempo de ejecucion: "<<TiempoE<<endl;
                            gotoxy(25,9);
                            cout<<"                         "<<endl;
                            gotoxy(25,9);
                            cout<<"Tiempo restante: "<<tme-TiempoE<<endl;
                            gotoxy(25,10);
                            cout<<"Tiempo de quantum: "<<quac<<endl;
                            gotoxy(25,11);
                            cout<<"                         "<<endl;
                            gotoxy(25,11);
                            cout<<"Paginas "<<pag<<endl;
                        }

                        insertarLote(frenteejecucion,finejecucion,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                        if(tp<tiempo&&nulo==false){
                            if(quac>=quantum){
                                salto=true;
                                impen=true;
                                quac=0;
                                tp=tiempo;
                                gotoxy(25,10);
                                cout<<"Tiempo de quantum: "<<quac<<endl;
                                gotoxy(25,5);
                                cout<<"                               "<<endl;
                                vaciarLote(frenteejecucion,finejecucion,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                                do{
                                    x=0;
                                    comprobador=0;
                                    prel=laux->getproceso();
                                    while(prel.length()>x){
                                        if(isalpha(prel[x])){
                                            comprobador++;
                                        }
                                        x++;
                                    }
                                    if(comprobador==0){
                                        nuevos=stoi(prel);
                                        if(nuevos==id){
                                            laux->setestado("Listo");
                                        }
                                    }
                                    laux=laux->getsiguiente();
                                }while(laux!=lp);
                                insertarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);

                            }
                        }
                        while(listasys<45){
                            cout<<"                                                                                                                                "<<endl;
                            gotoxy(70,15+listasys);
                            listasys++;
                        }
                        listasys=0;
                        gotoxy(70,15);
                        mostrarl();

                    }
                }
                quac=0;
                cuenta=0;
                if(frenteejecucion!=NULL){
                    vaciarLote(frenteejecucion,finejecucion,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                }

                if(salto==false){

                    gotoxy(56,5+ter);
                    if(error==false){
                        switch(signo[0]){
                            case '+':
                                res=numero1+numero2;
                                break;
                            case '-':
                                res=numero1-numero2;
                                break;
                            case '*':
                                res=numero1*numero2;
                                break;
                            case '/':
                                res=numero1/numero2;
                                break;
                            case '%':
                                res=numero1%numero2;
                                break;
                            case '^':
                                res=pow(numero1,numero2);
                                break;
                        }
                        cout<<"ID: "<<id<<" operacion: "<<numero1<<signo<<numero2<<" Resultado: "<<res;
                        ress=to_string(res);
                    }

                    else{
                        if(frenteejecucion==NULL&&frentelistos==NULL){
                            nulo=true;
                            gotoxy(25,5);
                            cout<<"                               "<<endl;
                            gotoxy(25,6);
                            cout<<"                               "<<endl;
                            gotoxy(25,7);
                            cout<<"                               "<<endl;
                            gotoxy(25,8);
                            cout<<"                           "<<endl;
                            gotoxy(25,8);
                            cout<<"                           "<<endl;
                            gotoxy(25,9);
                            cout<<"                           "<<endl;
                            gotoxy(25,9);
                            cout<<"                           "<<endl;
                            gotoxy(25,10);
                            cout<<"                           "<<endl;
                            gotoxy(25,11);
                            cout<<"                           "<<endl;
                        }
                        gotoxy(56,5+ter);
                        error=false;
                        ress="ERROR";
                        cout<<"ID: "<<id<<" "<<ress;
                    }
                    TiempoF=tt;
                    laux=lp;
                    do{
                        x=0;
                        comprobador=0;
                        prel=laux->getproceso();
                        while(prel.length()>x){
                            if(isalpha(prel[x])){
                                comprobador++;
                            }
                            x++;
                        }
                        if(comprobador==0){
                            nuevos=stoi(prel);
                            if(nuevos==id){
                                laux->setpagina(0);
                                laux->setproceso("vacio");
                                laux->setestado("vacio");
                            }
                        }
                        laux=laux->getsiguiente();
                    }while(laux!=lp);
                    lleno=false;
                    insertarLote(frentetem,fintem,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                    ter++;

                    if(nulo==false){
                        while(frentelistos!=NULL){
                            cuenta++;
                            vaciarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                            insertarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                        }
                        cuenta=0;
                        while(cuenta<=4){
                            gotoxy(0,5+cuenta);
                            cout<<"                             "<<endl;
                            cuenta++;
                        }
                        cuenta=0;
                        while(frenteim!=NULL){

                            vaciarLote(frenteim,finim,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                            gotoxy(0,5+cuenta);
                            cout<<"id: "<<id<<" TME: "<<tme<<" TT: "<<TiempoE<<endl;
                            insertarLote(frentelistos,finlistos,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
                            cuenta++;
                        }
                    }
                    cuenta--;
                    nprocesos--;
                }

                else {
                    salto=false;
                    if(nuevo==false){
                        if(impen==false){
                            insertarLote(frentebloq,finbloq,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,0,TiempoE,TiempoR,TiempoLL,TiempoF);
                            do{
                                x=0;
                                comprobador=0;
                                prel=laux->getproceso();
                                while(prel.length()>x){
                                    if(isalpha(prel[x])){
                                        comprobador++;
                                    }
                                    x++;
                                }
                                if(comprobador==0){
                                    nuevos=stoi(prel);
                                    if(nuevos==id){
                                        laux->setestado("Bloqueado");
                                    }
                                }
                                laux=laux->getsiguiente();
                            }while(laux!=lp);
                            cuenta=0;
                            while(cuenta<=22){
                                gotoxy(0,5+cuenta);
                                cout<<"                       "<<endl;
                                cuenta++;
                            }
                            gotoxy(24,14+pendiente);
                            cout<<"id: "<<id<<" Tiempo en bloqueado: "<<TiempoB<<endl;
                            if(frentelistos==NULL&&frenteejecucion==NULL){
                                nulo=true;
                            }
                        }
                        else{
                            impen=false;
                        }
                    }
                else{
                    nuevo=false;
                }
                }
            }
            cuenta++;
            gotoxy(0,0);
            cout<<"                             "<<endl;
            gotoxy(0,0);
            cout<<"Numero de procesos nuevos: "<<cantidad<<endl;
    }
    gotoxy(25,5);
    cout<<"                               "<<endl;
    gotoxy(25,6);
    cout<<"                               "<<endl;
    gotoxy(25,7);
    cout<<"                               "<<endl;
    gotoxy(25,8);
    cout<<"                               "<<endl;
    gotoxy(25,8);
    cout<<"                               "<<endl;
    gotoxy(25,9);
    cout<<"                               "<<endl;
    gotoxy(25,9);
    cout<<"                               "<<endl;
    gotoxy(25,10);
    cout<<"                               "<<endl;
    gotoxy(25,11);
    cout<<"                               "<<endl;

    gotoxy(0,0);
    cout<<"Numero de procesos nuevos: "<<cantidad<<endl;
    gotoxy(25,25);
    cout<<"presiona cualquier tecla para ver los tiempos"<<endl;
    fflush(stdin);
    x=0;
    while(x==0){
        x=getch();
    }

    system("cls");
    cout<<"ID\t"<<"resultado\t"<<"TME\t"<<"Tiempo de llegada\t"<<"Tiempo de finalizacion\t"<<"Tiempo de retorno\t"<<"Tiempo de respuesta\t"<<"Tiempo de espera\t"<<"Tiempo de servicio"<<endl;
    cuenta=0;
    while(frentetem!=NULL){
        vaciarLote(frentetem,fintem,signo,ress,llegadast,respuestast,pag,numero1,numero2,tme,id,TiempoT,TiempoB,TiempoE,TiempoR,TiempoLL,TiempoF);
        auxi=1;
        x=0;
        while(x<ress.size()){
            if(isalpha(ress[x])==true){
                auxi=0;
            }
            x++;
        }
        if(auxi==0){
            cout<<id<<"\tERROR";
            gotoxy(24,1+cuenta);
            cout<<tme;
            gotoxy(40,1+cuenta);
            cout<<TiempoLL;
            gotoxy(64,1+cuenta);
            cout<<TiempoF;
            gotoxy(87,1+cuenta);
            cout<<TiempoF-TiempoLL;
            gotoxy(111,1+cuenta);
            cout<<TiempoR;
            gotoxy(135,1+cuenta);
            cout<<TiempoT<<"\t\t"<<TiempoE<<endl;
        }

        else{
            cout<<id<<"\t"<<numero1<<signo<<numero2<<"="<<ress;
            gotoxy(24,1+cuenta);
            cout<<tme;
            gotoxy(40,1+cuenta);
            cout<<TiempoLL;
            gotoxy(64,1+cuenta);
            cout<<TiempoF;
            gotoxy(87,1+cuenta);
            cout<<TiempoF-TiempoLL;
            gotoxy(111,1+cuenta);
            cout<<TiempoR;
            gotoxy(135,1+cuenta);
            cout<<TiempoT<<"\t\t"<<TiempoE<<endl;
        }
        cuenta++;
    }
    gotoxy(0,1+cuenta);
     cout<<"presiona cualquier tecla para finalizar"<<endl;
    fflush(stdin);
    x=0;
    while(x==0){
        x=getch();
    }

    return 0;
}

bool lotevacio(lote *frente){
    return (frente==NULL)? true : false;
}

void insertarLote(lote *&frente,lote *&fin, string signo, string res, bool llegadast, bool respuestast, int pag,
                   int n1, int n2, int tme, int ID, int Tt, int Tb,int Te, int Tr, int TLL, int finali){
    lote *nuevolote= new lote();
    nuevolote->setsigno(signo);
    nuevolote->setres(res);
    nuevolote->setllegadast(llegadast);
    nuevolote->setrespuestast(respuestast);
    nuevolote->setn1(n1);
    nuevolote->setn2(n2);
    nuevolote->settme(tme);
    nuevolote->setid(ID);
    nuevolote->settiempot(Tt);
    nuevolote->settiempob(Tb);
    nuevolote->settiempoe(Te);
    nuevolote->settiempor(Tr);
    nuevolote->setllegada(TLL);
    nuevolote->settres(finali);
    nuevolote->setpagina(pag);


    nuevolote->siguiente=NULL;
    if(lotevacio(frente)){
            frente=nuevolote;
    }
    else{
        fin->siguiente=nuevolote;
    }

    fin=nuevolote;
}

void vaciarLote(lote *&frente,lote *&fin, string &signo, string &res, bool &llegadast, bool &respuestast, int &pag, int &n1,
                 int &n2, int &tme, int &ID, int &Tt, int &Tb,int &Te, int &Tr, int &TLL, int&finali){
    signo=frente->getsigno();
    res=frente->getres();
    llegadast=frente->getllegadast();
    respuestast=frente->getrespuestast();
    n1=frente->getn1();
    n2=frente->getn2();
    tme=frente->gettme();
    ID=frente->getid();
    Tt=frente->gettiempot();
    Tb=frente->gettiempob();
    Te=frente->gettiempoe();
    Tr=frente->gettiempor();
    TLL=frente->getllegada();
    finali=frente->getresp();
    pag=frente->getpagina();

    lote *aux=frente;

    if(frente==fin){
        frente=NULL;
        fin=NULL;
    }
    else{
        frente=frente->siguiente;
    }

    delete aux;
}


void buscarLote(lote *&frente,lote *&fin, string &signo, int &n1, int &n2, int &tme, int &ID, int aux, bool rep){
    lote *auxl=frente;
    lote *auxl1=auxl;
    while(auxl!=NULL){

        if(auxl->getid()==aux){
            rep=true;
            auxl1=auxl;
        }

        if(auxl==fin){
            auxl=NULL;
        }
        else{
            auxl=auxl->siguiente;
        }
    }
    if(rep==true){
        signo=auxl1->getsigno();
        n1=auxl1->getn1();
        n2=auxl1->getn2();
        tme=auxl1->gettme();
        ID=auxl1->getid();
    }
    else{
        ID=-2;
    }
    delete auxl;
}

void insertarenl(int marc){
    lista *nuevo=new lista;
    nuevo->setnmarco(marc);


    if(marc>39){
        nuevo->setproceso("SO");
        nuevo->setpagina(5);
        nuevo->setestado("en ejecucion");
    }
    else{
        nuevo->setproceso("vacio");
        nuevo->setpagina(0);
        nuevo->setestado("vacio");
    }
    if(lp==NULL){
        lp=nuevo;
        lp->setsiguiente(nuevo);
        lu=lp;
    }
    else{
        lu->setsiguiente(nuevo);
        nuevo->setsiguiente(lp);
        lu=nuevo;
    }
}

void gotoxy(int x, int y){
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void mostrarl(){
    lista *actual=new lista;
    actual=lp;
    int limp;
    limp=0;
    if(lp!=NULL){
        do{
            gotoxy(67,15);
            cout<<"Marco";
            gotoxy(77,15);
            cout<<"Proceso";
            gotoxy(87,15);
            cout<<"Paginas ocupadas";
            gotoxy(105,15);
            cout<<"Estado";

            gotoxy(70,16+limp);
            cout<<actual->getnmarco();
            gotoxy(80,16+limp);
            cout<<actual->getproceso();
            gotoxy(95,16+limp);
            cout<<actual->getpagina();
            gotoxy(105,16+limp);
            cout<<actual->getestado();
            limp++;
            actual=actual->getsiguiente();
        }while(actual!=lp);
    }
}


