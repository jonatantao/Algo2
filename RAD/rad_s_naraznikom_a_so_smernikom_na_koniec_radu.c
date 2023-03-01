//Rad s naraznikom a so smernikom na koniec radu
//V atomoch su ukladane informacie o osobe - znacka, OS, rok.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //pre pracu s retazcami
#define ML (ATOM*)malloc(sizeof(ATOM))

typedef struct{
    char znacka [20];
    char OS [10];
    int  rok;
    int  cena;
}MOBIL;

typedef struct atom{
    MOBIL c;
    struct atom *nasl;
}ATOM;

//pribudla nova struktura RAD
typedef struct{
    ATOM *zaciatok, *koniec;
}RAD;

//rad s naraznikom a so smernikom na koniec radu
void ini(RAD *);
int test(RAD);
void vloz(RAD *, MOBIL);
void odober(RAD *);
MOBIL hodnota(RAD);
void zrus(RAD*);

int main(){

    RAD rad; //rad je reprezentovany premennou typu RAD
    ini(&rad);
    MOBIL o;
    strcpy(o.znacka,"Xiaomi");
    strcpy(o.OS,"Android");
    o.rok = 2021;
    o.cena = 600;
    vloz(&rad,o);
    strcpy(o.znacka,"Samsung");
    strcpy(o.OS,"Android");
    o.rok = 2021;
    o.cena = 750;
    vloz(&rad,o);

    while(!test(rad)){
        o = hodnota(rad);
        odober(&rad);
        printf("%s %s %d %d\n",o.znacka,o.OS,o.rok,o.cena);
    }

    zrus(&rad);
    return 0;
}


//--------------------------------------Rad s naraznikom a so smernikom na koniec radu-------------------------------------------
void ini(RAD *r){
    r->koniec = ML;
    r->koniec->nasl = NULL;
    r->zaciatok = r->koniec;
}

int test(RAD r){
    return r.zaciatok->nasl == NULL;
}

void vloz(RAD *r, MOBIL x){
    r->koniec->c = x;
    //novy naraznik;
    r->koniec->nasl = ML;
    r->koniec = r->koniec->nasl;
    r->koniec->nasl = NULL;
}

void odober(RAD *r){
    if(!test(*r)){
        ATOM *pom = r->zaciatok;
        r->zaciatok = r->zaciatok->nasl;
        free((void*)pom);
    }
}

MOBIL hodnota(RAD r){
    if(!test(r)){
        return r.zaciatok->c;
    }
}

void zrus(RAD *r){
    while(!test(*r))
        odober(r);
    //odstranenie naraznika
    free((void*)r->zaciatok);
    r->koniec = r->zaciatok = NULL;
}