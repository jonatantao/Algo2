//Rad s naraznikom a bez smernika na koniec radu

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

//rad s naraznikom a bez smernika na koniec radu
void ini(ATOM **);
int test(ATOM*);
void vloz(ATOM *, MOBIL); //jediny rozdiel oproti zasobniku s naraznikom je tu
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
    o.rok = 2018;
    o.cena = 250;
    vloz(rad,o);
    strcpy(o.znacka,"Huawei");
    strcpy(o.OS,"Android");
    o.rok = 2019;
    o.cena = 300;
    vloz(rad,o);

    while(!test(rad)){
        o = hodnota(rad);
        odober(&rad);
        printf("%s %s %d %d\n",o.znacka,o.OS,o.rok,o.cena);
    }

    zrus(&rad);
    return 0;
}


//--------------------------------------Rad s naraznikom a bez smernika na koniec radu-------------------------------------------
void ini(ATOM **r){
    *r = ML;
    (*r)->nasl = NULL;
    //ostatne atributy nie je potrebne naplnat, lebo je to naraznik
}

int test(ATOM *r){
    return r->nasl == NULL;
}

void vloz(ATOM *r, MOBIL x){
    ATOM *pom = r;
    while(pom->nasl != NULL)
        pom = pom->nasl;
    pom->c = x;
    pom->nasl = ML;
    pom = pom->nasl;
    pom->nasl = NULL;
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
    free((void*)*r);
    *r = NULL;
}