//Rad implementovany jednorozmernym polom
//V atomoch su ukladane informacie o osobe - znacka, OS, rok.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //pre pracu s retazcami
#define MAX 5

typedef struct{
    char znacka [20];
    char OS [10];
    int  rok;
    int  cena;
}MOBIL;

//pribudla nova struktura RAD
typedef struct{
    MOBIL *pole;
    int zaciatok, koniec, pocet;
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
    FILE *f;
    f = fopen("vstup.txt","r");
    if(f== NULL){
        fprintf(stderr, "Subor vstup.txt sa nepodarilo otvorit.\n");
        return 1;
    }
    while(!feof(f)){
        fscanf(f,"%s %s %d %d\n", o.znacka, o.OS, &o.rok, &o.cena);
        vloz(&rad,o);
    }

    odober(&rad);
    printf("Odobral som %s %s %d %d\n",o.znacka,o.OS,o.rok,o.cena);

    fscanf(f,"%s %s %d %d\n", o.znacka, o.OS, &o.rok, &o.cena);
    printf("Vkladam %s %s %d %d\n", o.znacka,o.OS,o.rok,o.cena);
    vloz(&rad,o);

    while(!test_prazdny(rad)){
        o = hodnota(rad);
        odober(&rad);
        printf("%s %s %d %d\n", o.znacka,o.OS,o.rok,o.cena);
    }
    fclose(f);
    if(f == EOF){
            fprintf(stderr,"Subor vstup.txt sa nepodarilo korektne uzatvorit.\n");
            return 1;
    }

    zrus(&rad);
    return 0;
}


//--------------------------------------Rad implementovany jednorozmernym polom-------------------------------------------
void ini(RAD *r){
    r->pole = (MOBIL*)malloc(sizeof(MOBIL) * MAX);
    r->koniec = r->zaciatok = r->pocet = 0;
}

int test_prazdny(RAD r){
    return r.pocet == NULL;
}

int test_plny(RAD r){
    return r.pocet == MAX;
}

void vloz(RAD *r, MOBIL x){
    if(!test_plny(*r)){
        r->pole[r->koniec] = x;
        r->koniec = (r->koniec + 1) % MAX;
        r->pocet++;
    }
}

void odober(RAD *r){
    if(!test_prazdny(*r)){
        r->zaciatok = (r->zaciatok + 1) % MAX;
        r->pocet--;
    }
}

MOBIL hodnota(RAD r){
    if(!test_prazdny(r)){
        return r.pole[r.zaciatok];
    }
}

void zrus(RAD *r){
    free((void*)r->pole);
    r->pole = NULL;
    r->zaciatok = r->koniec = r->pocet = 0;
}