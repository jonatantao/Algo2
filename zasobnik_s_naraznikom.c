//Zasobnik s naraznikom.
//V atomoch su ukladane informacie o osobe - meno, priezvisko, vek.
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
    MOBIL m;
    struct atom *nasl;
}ATOM;

//Zasobnik s naraznikom - z1_
void ini(ATOM **);
int test(ATOM*);
void vloz(ATOM **, MOBIL);
void odober(ATOM **);
MOBIL hodnota(ATOM*);
void zrus(ATOM**);

int main()
{

    ATOM *zas;
    ini(&zas);
    MOBIL p;
    strcpy(p.znacka,"Samsung");
    strcpy(p.OS,"Android");
    p.rok = 2017;
    p.cena = 150;
    vloz(&zas,p);
    strcpy(p.znacka,"Apple");
    strcpy(p.OS,"iOS");
    p.rok = 2018;
    p.cena = 220;
    vloz(&zas,p);

    while(!test(zas)){
        p = hodnota(zas);
        odober(&zas);
        printf("%s %s %d %d\n",p.znacka,p.OS,p.rok,p.cena);
    }

    zrus(&zas);
    return 0;
}


//--------------------------------------Zasobnik s naraznikom-------------------------------------------
void ini(ATOM **z){
    *z = ML;
    (*z)->nasl = NULL;
    //ostatne atributy nie je potrebne naplnat, lebo je to naraznik
}

int test(ATOM *z){
    return z->nasl == NULL;
}

void vloz(ATOM **z, MOBIL x){
    ATOM *pom;
    pom = ML;
    pom->m = x;
    pom->nasl = *z;
    *z = pom;
}

void odober(ATOM **z){
    if(!test(*z)){
        ATOM *pom = *z;
        *z = (*z)->nasl;
        free((void*)pom);
    }
}

MOBIL hodnota(ATOM *z){
    if(!test(z)){
        /*MOBIL pom_m;
        strcpy(pom_m.znacka,z->m.znacka);
        strcpy(pom_m.OS,z->m.OS);
        pom_m.rok = z->m.rok;
        pom_m.cena = z->m.cena;
        return pom_m;*/
        return z->m;
    }
    //aby nebol warning
    //MOBIL pom_m; strcpy(pom_m.znacka,"chyba"); //nechavam na dopracovanie
    //return pom_m;
}

void zrus(ATOM **z){
    while(!test(*z))
        odober(z);
    free((void*)*z);
    *z = NULL;
}
