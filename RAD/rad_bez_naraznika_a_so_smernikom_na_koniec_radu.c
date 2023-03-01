//Rad bez naraznika a so smernikom na koniec radu
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

//rad bez naraznika a so smernikom na koniec radu
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
    strcpy(o.znacka,"Apple");
    strcpy(o.OS,"iOS");
    o.rok = 2021;
    o.cena = 850;
    vloz(&rad,o);
    strcpy(o.znacka,"Samsung");
    strcpy(o.OS,"Android");
    o.rok = 2023;
    o.cena = 1000;
    vloz(&rad,o);

    while(!test(rad)){
        o = hodnota(rad);
        odober(&rad);
        printf("%s %s %d %d\n",o.znacka,o.OS,o.rok,o.cena);
    }

    zrus(&rad);
    return 0;
}


//--------------------------------------Rad bez naraznika a so smernikom na koniec radu-------------------------------------------
void ini(RAD *r){
    r->koniec = NULL;
    r->zaciatok = NULL;
}

int test(RAD r){
    return r.zaciatok == NULL;
}

void vloz(RAD *r, MOBIL x){
    if(test(*r)){
        r->koniec = ML;
        r->koniec->c = x;
        r->koniec->nasl = NULL;
        r->zaciatok = r->koniec; //v rade je len jeden atom
    }else{
        r->koniec->nasl = ML;
        r->koniec = r->koniec->nasl;
        r->koniec->c = x;
        r->koniec->nasl = NULL;
    }
}

void odober(RAD *r){
    if(!test(*r)){
        if(r->zaciatok->nasl == NULL){
            free((void*)r->zaciatok);
            r->zaciatok = r->koniec = NULL;
        }else{
            ATOM *pom = r->zaciatok;
            r->zaciatok = r->zaciatok->nasl;
            free((void*)pom);
        }
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
}