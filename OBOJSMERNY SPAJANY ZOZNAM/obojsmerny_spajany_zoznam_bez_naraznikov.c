//Obojsmerny spajany zoznam bez naraznikov
//V atomoch su ukladane informacie o osobe - znacka, OS, rok.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //pre pracu s retazcami
#define ML (ATOM*)malloc(sizeof(ATOM))


typedef struct{
    char znacka[15];
    char OS[20];
    int rok;
    int cena;
}MOBIL;

typedef struct atom{
    MOBIL c;
    struct atom *nasl, *pred;
}ATOM;

typedef struct{
    ATOM *zaciatok, *koniec, *index;
}ZOZNAM;

//Obojsmerny spajany zoznam bez naraznikov
void ini(ZOZNAM *);
int test(ZOZNAM);
int test_zaciatok(ZOZNAM);
int test_koniec(ZOZNAM);
void vloz(ZOZNAM*, MOBIL);
void odober(ZOZNAM*);
MOBIL hodnota(ZOZNAM);
void posun_v_smere(ZOZNAM*);
void na_koniec(ZOZNAM*);
void posun_proti_smeru(ZOZNAM*); //"cuvanie"
void na_zaciatok(ZOZNAM*);
void zrus(ZOZNAM*);

int main()
{
    ZOZNAM zoz;
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


    /*ATOM *pom = zoz.zaciatok;
    while(pom!=NULL){
        printf("%s %s %d\n",pom->c.znacka,pom->c.OS,pom->c.rok);
        pom = pom->nasl;
    }*/
    na_zaciatok(&zoz);
    while(!test_koniec(zoz)){
        c = hodnota(zoz);
        printf("%s %s %d %d\n",c.znacka,c.OS,c.rok,c.cena);
        posun_v_smere(&zoz);
    }
    printf("--------------------------------\n");

    na_zaciatok(&zoz);
    odober(&zoz);
    na_zaciatok(&zoz);
    posun_v_smere(&zoz);posun_v_smere(&zoz);posun_v_smere(&zoz);
    odober(&zoz);
    na_koniec(&zoz);
    odober(&zoz);

    na_zaciatok(&zoz);
    while(!test_koniec(zoz)){
        c = hodnota(zoz);
        printf("%s %s %d\n",c.znacka,c.OS,c.rok);
        posun_v_smere(&zoz);
    }
    c = hodnota(zoz);
    printf("%s %s %d %d\n",c.znacka,c.OS,c.rok,c.cena);
    printf("--------------------------------\n");

    na_zaciatok(&zoz);
    strcpy(c.znacka,"Apple");
    strcpy(c.OS,"iOS");
    c.rok = 2018;
    c.cena = 500;
    vloz(&zoz,c);

    na_koniec(&zoz);
    while(!test_zaciatok(zoz)){
        c = hodnota(zoz);
        printf("%s %s %d %d\n",c.znacka,c.OS,c.rok,c.cena);
        posun_proti_smeru(&zoz);
    }
    c = hodnota(zoz);
    printf("%s %s %d %d\n",c.znacka,c.OS,c.rok,c.cena);
    printf("--------------------------------\n");


    na_koniec(&zoz);
    strcpy(c.znacka,"Samsung");
    strcpy(c.OS,"Huawei");
    c.rok = 2020;
    c.cena = 450;
    vloz(&zoz,c);


    na_koniec(&zoz);
    while(!test_zaciatok(zoz)){
        c = hodnota(zoz);
        printf("%s %s %d %d\n",c.znacka,c.OS,c.rok,c.cena);
        posun_proti_smeru(&zoz);
    }
    c = hodnota(zoz);
    printf("%s %s %d %d\n",c.znacka,c.OS,c.rok,c.cena);
    printf("--------------------------------\n");

    zrus(&zoz);

    return 0;
}
//--------------------------------------Jednosmerny spajany zoznam bez naraznikov-------------------------------------------
void ini(ZOZNAM *z){
    z->zaciatok = z->koniec = z->index = NULL;
}

int test(ZOZNAM z){
    return z.index == NULL;
}

int test_koniec(ZOZNAM z){
    return z.index == z.koniec;
}

int test_zaciatok(ZOZNAM z){
    return z.index == z.zaciatok;
}

void vloz(ZOZNAM *z, MOBIL x){
    if(test(*z)){
        z->index = ML;
        z->index->c = x;
        z->index->nasl = NULL;
        z->index->pred = NULL;
        z->zaciatok = z->koniec = z->index;
    }
    else{
        if(test_koniec(*z)){
            z->index->nasl = ML;
            z->koniec = z->index->nasl;
            z->koniec->nasl = NULL;
            z->koniec->pred = z->index;
            z->koniec->c = x;
            z->index = z->koniec;
        }
        else{
            ATOM *pom = ML;
            pom->c = x;
            pom->nasl = z->index->nasl;
            pom->pred = z->index;
            pom->nasl->pred = pom;
            z->index->nasl = pom;
            z->index = pom;
        }
    }
}

MOBIL hodnota(ZOZNAM z){
    if(!test(z))
            return z.index->c;
}

void na_koniec(ZOZNAM *z){
    z->index = z->koniec;
}

void na_zaciatok(ZOZNAM *z){
    z->index = z->zaciatok;
}

void posun_v_smere(ZOZNAM *z){
    if(!test(*z))
        if(!test_koniec(*z))
            z->index = z->index->nasl;
}

void posun_proti_smeru(ZOZNAM *z){
    if(!test(*z))
        if(!test_zaciatok(*z)){
            z->index = z->index->pred;
        }
}

void odober(ZOZNAM *z){
    if(!test(*z)){
        if(z->zaciatok == z->koniec){
            free((void*)z->koniec);
            free((void*)z->zaciatok);
            z->zaciatok = z->koniec = z->index = NULL;
        }
        else{
            if(test_koniec(*z)){
                z->koniec = z->koniec->pred;
                z->koniec->nasl = NULL;
                free((void*)z->index);
                z->index = z->koniec;
            }
            else{
                if(test_zaciatok(*z)){
                    z->zaciatok = z->zaciatok->nasl;
                    z->zaciatok->pred = NULL;
                    free((void*)z->index);
                    z->index = z->zaciatok;
                }
                else{
                    ATOM *pom = z->index->pred;
                    pom->nasl = z->index->nasl;
                    z->index->nasl->pred = pom;
                    free((void*)z->index);
                    z->index = pom->nasl;
                }
            }
        }
    }
}

void zrus(ZOZNAM *z){
    while(!test(*z)){
        na_zaciatok(z);
        printf("Mazem atom %s.\n",z->index->c.znacka);
        odober(z);
    }
}