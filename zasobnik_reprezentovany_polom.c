#include <stdio.h>
#include <stdlib.h>
#include <string.h> //pre pracu s retazcami
#define MAX 50 //maximalny rozmer pola

typedef struct{
    char znacka [20];
    char OS [10];
    int  rok;
    int  cena;
}MOBIL;

typedef struct{
    MOBIL *pole;
    int _pole;
}ZASOBNIK;

//Zasobnik bez naraznika
void ini(ZASOBNIK *);
int test_prazdny(ZASOBNIK);
int test_plny(ZASOBNIK);
void vloz(ZASOBNIK*, MOBIL);
void odober(ZASOBNIK*);
MOBIL hodnota(ZASOBNIK);
void zrus(ZASOBNIK*);

int main()
{

    ZASOBNIK zas;
    ini(&zas);
    MOBIL p;
    strcpy(p.znacka,"Apple");
    strcpy(p.OS,"iOS");
    p.rok = 2014;
    p.cena = 75;
    vloz(&zas,p);
    strcpy(p.znacka,"Samsung");
    strcpy(p.OS,"Android");
    p.rok = 2015;
    p.cena = 118;
    vloz(&zas,p);

    //ukazka pola
    int i;
    for(i = 0; i < zas._pole; i++)
        printf("%s %s %d %d\n", zas.pole[i].znacka,zas.pole[i].OS,zas.pole[i].rok,zas.pole[i].cena);

    while(!test_prazdny(zas)){
        p = hodnota(zas);
        odober(&zas);
        printf("%s %s %d %d\n", p.znacka,p.OS,p.rok,p.cena);
    }

    zrus(&zas);
    return 0;
}


//--------------------------------------Zasobnik polom-------------------------------------------
void ini(ZASOBNIK *z){
    z->pole = (MOBIL*)malloc(sizeof(MOBIL)*MAX);
    z->_pole = 0;
}

int test_prazdny(ZASOBNIK z){
    return z._pole == 0;
}

int test_plny(ZASOBNIK z){
    return z._pole >= MAX;
}

void vloz(ZASOBNIK *z, MOBIL x){
    if(!test_plny(*z)){
        z->pole[z->_pole] = x;
        z->_pole++;
    }
}
void odober(ZASOBNIK *z){
    if(!test_prazdny(*z))
        z->_pole--;
}

MOBIL hodnota(ZASOBNIK z){
    if(!test_prazdny(z))
        return z.pole[z._pole-1];
}

void zrus(ZASOBNIK *z){
    free((void*)z->pole);
    z->_pole = 0;
}
