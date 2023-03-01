#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(){

    ATOM *p_a;
    p_a=(ATOM*)malloc(sizeof(ATOM));
    strcpy(p_a->m.znacka,"Apple");
    strcpy(p_a->m.OS,"iOS");
    p_a->m.rok = 2016;
    p_a->m.cena = 200;
    p_a->nasl = NULL;

    printf("%s, %s, %d, %d", p_a->m.znacka,p_a->m.OS, p_a->m.rok, p_a->m.cena);

    return 0;
}