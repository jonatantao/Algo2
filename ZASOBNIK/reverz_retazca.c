//Zasobnik s naraznikom.
//Reverz retazca
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //pre pracu s retazcami
#define ML (ATOM*)malloc(sizeof(ATOM))

typedef struct atom{
    int h;
    struct atom *nasl;
}ATOM;

//Zasobnik s naraznikom - z1_
void ini(ATOM **);
int test(ATOM*);
void vloz(ATOM **, int);
void odober(ATOM **);
int hodnota(ATOM*);
void zrus(ATOM**);

int main()
{

    ATOM *zas;
    ini(&zas);
    char s[50];
    printf("Zadajte retazec:");
    scanf("%s",&s);
    int i;
    for(i = 0; i < strlen(s); i++)
        vloz(&zas, s[i]);

    char c;
    while(!test(zas)){
        c = hodnota(zas);
        odober(&zas);
        printf("%c\n",c);
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

void vloz(ATOM **z, int x){
    ATOM *pom;
    pom = ML;
    pom->h = x;
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

int hodnota(ATOM *z){
    if(!test(z)){

        return z->h;
    }
    //aby nebol warning
    //CLOVEK pom_c; strcpy(pom_c.meno,"chyba"); //nechavam na dopracovanie
    //return pom_c;
}

void zrus(ATOM **z){
    while(!test(*z))
        odober(z);
    free((void*)*z);
    *z = NULL;
}
