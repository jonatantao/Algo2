//Jednosmerny spajany zoznam cyklicky
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

//Jednosmerny spajany zoznam cyklicky
void ini(ATOM **);
int test(ATOM*);
void vloz(ATOM **, MOBIL);
void odober(ATOM **);
MOBIL hodnota(ATOM*);
void posun_v_smere(ATOM**);
void posun_proti_smeru(ATOM**); //"cuvanie"
void zrus(ATOM**);

int main()
{
    ATOM *zoz;
    MOBIL c;
    FILE *f;
    f = fopen("vstup.txt","r");
    if(f == NULL) return 1;
    ini(&zoz);
    while(!feof(f)){
        fscanf(f,"%s %s %d %d\n",c.znacka,c.OS,&c.rok,&c.cena);
        vloz(&zoz,c);
    }
    fclose(f);

    int i;
    /*while(!test(zoz)){
        for(i = 0; i < 20; i++){
            posun_proti_smeru(&zoz);
            c = hodnota(zoz);
            printf("%s %s %d\n", c.znacka,c.OS,c.rok);
        }
        odober(&zoz);
    }*/

    zrus(&zoz);
    return 0;
}
//--------------------------------------Jednosmerny spajany zoznam cyklicky-------------------------------------------
void ini(ATOM **z){
    *z = NULL;
}

int test(ATOM *z){
    return z == NULL;
}

void vloz(ATOM **z, MOBIL x){
    if(test(*z)){
        *z = ML;
        (*z)->c = x;
        (*z)->nasl = *z; //zacyklenie
    }
    else{
        ATOM *pom;
        pom = ML;
        pom->c = x;
        pom->nasl = (*z)->nasl;
        (*z)->nasl = pom;
        *z = pom; //posunutie na vlozeny atom
    }
}

MOBIL hodnota(ATOM *z){
    if(!test(z))
        return z->c;
}

void posun_v_smere(ATOM **z){
    if(!test(*z))
        *z = (*z)->nasl;
}

void posun_proti_smeru(ATOM **z){
    if(!test(*z)){
        ATOM *pom = *z;
        while(pom->nasl != *z)
            pom = pom->nasl;
        *z = pom;
    }
}

void odober(ATOM **z){
    if(!test(*z)){
        printf("Odoberam %s.\n", (*z)->c.znacka);
        if((*z)->nasl == *z){
            free((void*)*z);
            *z = NULL;
        }
        else{
            ATOM *pom = *z;
            while(pom->nasl != *z)
                pom = pom->nasl;
            pom->nasl = (*z)->nasl;
            free((void*)*z);
            *z = pom;
        }
    }
}

void zrus(ATOM **z){
    while(!test(*z))
        odober(z);
}