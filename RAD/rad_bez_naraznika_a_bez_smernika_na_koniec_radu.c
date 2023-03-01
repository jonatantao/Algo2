//Rad bez naraznika a bez smernika na koniec radu
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

//rad bez naraznika a bez smernika na koniec radu
void ini(ATOM **);
int test(ATOM*);
void vloz(ATOM **, MOBIL);
void odober(ATOM **);
MOBIL hodnota(ATOM*);
void zrus(ATOM**);

int main()
{

    ATOM *rad;
    ini(&rad);
    MOBIL o;
    strcpy(o.znacka,"Apple");
    strcpy(o.OS,"iOS");
    o.rok = 2022;
    o.cena = 900;
    vloz(&rad,o);
    strcpy(o.znacka,"Samsung");
    strcpy(o.OS,"Android");
    o.rok = 2021;
    o.cena = 850;
    vloz(&rad,o);

    while(!test(rad)){
        o = hodnota(rad);
        odober(&rad);
        printf("%s %s %d %d\n",o.znacka,o.OS,o.rok,o.cena);
    }

    zrus(&rad);
    return 0;
}


//--------------------------------------Rad bez naraznika a bez smernika na koniec radu-------------------------------------------
void ini(ATOM **r){
    *r = NULL;
    //ostatne atributy nie je potrebne naplnat, lebo je to naraznik
}

int test(ATOM *r){
    return r == NULL;
}

void vloz(ATOM **r, MOBIL x){
    if(test(*r)){
        //tato cast je ako inicializacia v rade s naraznikom bez smernika na koniec radu
        *r = ML;
        (*r)->c = x;
        (*r)->nasl = NULL;
    }else{
        ATOM *pom = *r;
        while(pom->nasl != NULL)
            pom = pom->nasl;
        //zmena oproti radu s naraznikom a bez smernika na koniec radu
        pom->nasl = ML;
        pom = pom->nasl;
        pom->c = x;
        pom->nasl = NULL;
    }
}

void odober(ATOM **r){
    if(!test(*r)){
        ATOM *pom = *r;
        *r = (*r)->nasl;
        free((void*)pom);
    }
}

MOBIL hodnota(ATOM *r){
    if(!test(r)){
        return r->c;
    }
}

void zrus(ATOM **r){
    while(!test(*r))
        odober(r);
}