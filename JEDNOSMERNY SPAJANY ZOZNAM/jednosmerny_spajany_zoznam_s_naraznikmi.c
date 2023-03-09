//Jednosmerny spajany zoznam s naraznikmi
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

typedef struct{
    ATOM *zaciatok, *koniec, *index;
}ZOZNAM;

//Jednosmerny spajany zoznam s naraznikmi
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
        //na_zaciatok(&zoz);
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
        if(!test_zaciatok(zoz)){
           c = hodnota(zoz);
            printf("%s %s %d %d\n",c.znacka,c.OS,c.rok,c.cena);
        }
        posun_v_smere(&zoz);
    }

    na_zaciatok(&zoz);
    posun_v_smere(&zoz);posun_v_smere(&zoz);posun_v_smere(&zoz);
    odober(&zoz);

    na_zaciatok(&zoz);
    while(!test_koniec(zoz)){
        if(!test_zaciatok(zoz)){
           c = hodnota(zoz);
            printf("%s %s %d %d\n",c.znacka,c.OS,c.rok,c.cena);
        }
        posun_v_smere(&zoz);
    }

    zrus(&zoz);

    return 0;
}
//--------------------------------------Jednosmerny spajany zoznam s naraznikmi-------------------------------------------
void ini(ZOZNAM *z){
    z->koniec = ML;
    z->koniec->nasl = NULL;
    strcpy(z->koniec->c.znacka,"koniec");
    strcpy(z->koniec->c.OS,"koniec");
    z->koniec->c.rok = 0;
    z->koniec->c.cena = 0;
    z->zaciatok = ML;
    z->zaciatok->nasl = z->koniec;
    strcpy(z->zaciatok->c.znacka,"zaciatok");
    strcpy(z->zaciatok->c.OS,"zaciatok");
    z->zaciatok->c.rok = 0;
    z->zaciatok->c.cena = 0;
    z->index = z->koniec;
}

int test(ZOZNAM z){
    return z.zaciatok->nasl == z.koniec;
}

int test_koniec(ZOZNAM z){
    return z.index == z.koniec;
}

int test_zaciatok(ZOZNAM z){
    return z.index == z.zaciatok;
}

void vloz(ZOZNAM *z, MOBIL x){
    if(test_koniec(*z)){
        z->index->c = x;
        z->index->nasl = ML;
        z->koniec = z->index->nasl;
        z->index = z->koniec;
        z->koniec->nasl = NULL;
        strcpy(z->koniec->c.znacka,"koniec");
        strcpy(z->koniec->c.OS,"koniec");
        z->koniec->c.rok = 0;
        z->koniec->c.cena = 0;
    }
    else{
        ATOM *pom = ML;
        pom->c = x;
        pom->nasl = z->index->nasl;
        z->index->nasl = pom;
        z->index = pom;
    }
}

MOBIL hodnota(ZOZNAM z){
    //if(!test_koniec(z) && !test_zaciatok(z))
            return z.index->c;
}

void na_koniec(ZOZNAM *z){
    z->index = z->koniec;
}

void na_zaciatok(ZOZNAM *z){
    z->index = z->zaciatok;
}

void posun_v_smere(ZOZNAM *z){
    if(!test_koniec(*z))
        z->index = z->index->nasl;
}

void posun_proti_smeru(ZOZNAM *z){
    if(!test_zaciatok(*z)){
        ATOM *pom;
        pom = z->zaciatok;
        while(pom->nasl != z->index)
            pom = pom->nasl;
        z->index = pom;
    }
}

void odober(ZOZNAM *z){
    if(!test_koniec(*z))
        if(!test_zaciatok(*z)){
            ATOM *pom;
            pom = z->zaciatok;
            while(pom->nasl != z->index)
                pom = pom->nasl;
            pom->nasl = z->index->nasl;
            free((void*)z->index);
            z->index = pom->nasl;
        }
}

void zrus(ZOZNAM *z){
    while(!test(*z)){
        na_zaciatok(z);
        posun_v_smere(z);
        printf("Mazem atom %s.\n",z->index->c.znacka);
        odober(z);
    }
    printf("Mazem narazniky.\n");
    free((void*)z->zaciatok);
    free((void*)z->koniec);
    z->zaciatok = z->koniec = z->index = NULL;
}